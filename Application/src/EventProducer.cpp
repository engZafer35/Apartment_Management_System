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

#ifdef LINUX_PLATFORM
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
IEventProducer::IEventProducer(void): m_pQueue{0}, m_exit{0}, m_paused{0}, m_started{0}, m_threadControl{0}
{}

IEventProducer::~IEventProducer(void)
{}

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
        m_mutex.lock();
        if (m_exit)
        {
            m_mutex.unlock();
            break;
        }
        m_mutex.unlock();

        doControl();
    }
}

void IEventProducer::start(void)
{
    if (FALSE == m_started)
    {
        m_started = TRUE;
        m_exit    = FALSE;

#ifdef LINUX_PLATFORM
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
            m_mutex.lock();
        }

        m_exit = TRUE;
        m_mutex.unlock();

#ifdef LINUX_PLATFORM
    ::pthread_join(m_threadControl, NULL);
#endif
    }
}

/** \brief pause event producer */
void IEventProducer::pause(void)
{
    if (m_paused == FALSE)
    {
        m_mutex.lock();
        m_paused = TRUE;
    }
}

/** \brief resume event producer */
void IEventProducer::resume(void)
{
    if (m_paused == TRUE)
    {
        m_mutex.unlock();
        m_paused = FALSE;
    }
}

}//namespace event
/******************************** End Of File *********************************/
