/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 24, 2019 - 8:34:58 AM
* #File Name    : TimerEventProducer.cpp 
* #File Path    : /GezGor/Application/src/TimerEventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "TimerEventProducer.hpp"
#include <unistd.h>
#include <iostream>
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
namespace event
{
TimerEventProducer *TimerEventProducer::producer = NULL_PTR;
}//namespace event
/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace event
{

TimerEventProducer::TimerEventProducer(void) : m_exit{0}, m_paused{0}, m_started{0} , m_threadControl{0} {}

void TimerEventProducer::loopControl(void)
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


void TimerEventProducer::start(void)
{
    if (FALSE == m_started)
    {
        m_started = TRUE;
        m_exit    = FALSE;

        //TODO: if platform bare-metal, register interrupt system

#ifdef LINUX_PLATFORM
//        std::thread uartListenerThread = std::thread(&IEventProducer::run, this);
        ::pthread_create(&m_threadControl, 0, threadControlFunction, this);
#endif
    }
}
/** \brief stop event producer */
void TimerEventProducer::stop(void)
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
void TimerEventProducer::pause(void)
{
    if (m_paused == FALSE)
    {
        m_mutex.lock();
        m_paused = TRUE;
    }
}

/** \brief resume event producer */
void TimerEventProducer::resume(void)
{
    if (m_paused == TRUE)
    {
        m_mutex.unlock();
        m_paused = FALSE;
    }
}

TimerEventProducer *TimerEventProducer::getInstance(void)
{
    MutexLockFunc mutex; /** < guarantee that only one object is created. >*/

    if (NULL_PTR == producer)
    {
        producer = new TimerEventProducer();
    }

    return producer;
}

//void TimerEventProducer::start(void)
//{
//
//}

void TimerEventProducer::doControl(void)
{
    static int z[256];
    static int x = 0;
    ::sleep(1);

    z[x] = x;

    std::cout << x << " timer event throw" << std::endl;
    throwEvent(EN_EVENT_1, EN_SOURCE_3, EN_PRIORITY_2, &(z[x]), sizeof(x));
    x++;
}

//void TimerEventProducer::run(void)
//{
//
//}

}//namespace event
/******************************** End Of File *********************************/
