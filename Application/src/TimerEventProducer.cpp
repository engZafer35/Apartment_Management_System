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

    pthread_exit(NULL);
}

}//namespace event
/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/
namespace event
{

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
        ::pthread_create(&m_threadControl, 0, threadControlFunction, this);
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

    ::pthread_join(m_threadControl, NULL);
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

}//namespace event
/******************************** End Of File *********************************/
