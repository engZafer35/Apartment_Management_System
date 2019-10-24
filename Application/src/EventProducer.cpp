/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 9:25:53 PM
* #File Name    : EventProducer.cpp 
* #File Path    : /GezGor/Application/src/EventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventProducer.hpp"
#include "EventMessage.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/
namespace event
{
static void *threadControlFunction(void *arg)
{
    IEventProducer *producer = (IEventProducer *)arg;
    if (producer)
    {
        producer->loopControl();
    }

#ifdef __linux__
    pthread_exit(NULL);
#endif
}

}//namespace event
/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/
namespace event
{
/** \brief lock section */
void IEventProducer::enterSection(void)
{
#ifdef __linux
    ::pthread_mutex_lock(&m_mutexEvent);
#endif
}

/** \brief unlock section */
void IEventProducer::leaveSection(void)
{
#ifdef __linux
    ::pthread_mutex_unlock(&m_mutexEvent);
#endif
}

/** \brief throw event */
void IEventProducer::throwEvent(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter, U32 leng)
{
    if (NULL_PTR != m_pQueue)
    {
        m_pQueue->throwEvent(new EventMsg(event, source, priority, parameter, leng));
    }
}

}//namespace event
/***************************** CLASS PUBLIC METHOD ****************************/
namespace event
{
IEventProducer::IEventProducer(void): m_pQueue{0}, m_exit{0}, m_paused{0}, m_started{0}
{
#ifdef __linux
    m_threadControl = 0;
    ::pthread_mutex_init(&m_mutexEvent, 0);
#endif

}

IEventProducer::~IEventProducer(void)
{
    stop();
#ifdef __linux
    ::pthread_mutex_destroy(&m_mutexEvent);
#endif
}

/** \brief All event producer will load its event into event queue */
void IEventProducer::setQueue(EventQueue *eventQueue)
{
    // don't need to check null pointer. Because it will checked in throwEvent()
    m_pQueue = eventQueue;
}

void IEventProducer::loopControl(void)
{
    while (true)
    {
        enterSection();
        if (m_exit)
        {
            leaveSection();
            break;
        }
        leaveSection();

        doControl();
    }
}

void IEventProducer::start(void)
{
    if (FALSE == m_started)
    {
        m_started = TRUE;
        m_exit    = FALSE;

#ifdef __linux
//        std::thread uartListenerThread = std::thread(&IEventProducer::run, this);
        ::pthread_create(&m_threadControl, 0, threadControlFunction, this);
#endif
    }
}
/** \brief stop event producer */
void IEventProducer::stop(void)
{
    if (TRUE == m_started)
    {
        m_started = FALSE;
        if (m_paused == FALSE)
        {
            enterSection();
        }

        m_exit = TRUE;
        leaveSection();

#ifdef __linux
    ::pthread_join(m_threadControl, NULL);
#endif
    }
}

/** \brief pause event producer */
void IEventProducer::pause(void)
{
    if (m_paused == FALSE)
    {
        enterSection();
        m_paused = TRUE;
    }
}

/** \brief resume event producer */
void IEventProducer::resume(void)
{
    if (m_paused == TRUE)
    {
        leaveSection();
        m_paused = FALSE;
    }
}

}//namespace event
/******************************** End Of File *********************************/
