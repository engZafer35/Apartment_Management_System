/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 4, 2019 - 4:28:04 PM
* #File Name    : TimerEventProducer.cpp
* #File Path    : /GezGor/Application/src/TimerEventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include <TimerEventProducer.hpp>
#include <iostream> //TODO:
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/
namespace event
{

TimerEventProducer::TimerEventProducer(/*const Platform *pl*/): m_timerEnginePeriod{0}, m_started{FALSE}, m_exit{FALSE}
{
}

/**
 * \brief this method invoked by time engine system. It can be hardware timer unit,
 *        so don't handle alot of jobs in callback function. If you Just set a flag
 *        in callback function, we will be happy. Thanks
 */
void TimerEventProducer::cbProducer(void)
{
    if(TRUE == m_started)
    {
        if (FALSE == m_qTimers.empty())
        {
            U32 size = m_qTimers.size();

            for (U32 i = 0; i < size; i++)
            {
                if (m_qTimers[i]->m_timeMs > 0)
                {
                    m_qTimers[i]->m_timeMs -= m_timerEnginePeriod; //decrease timer value

                    if (m_qTimers[i]->m_timeMs < m_timerEnginePeriod) //check timer done
                    {
                        throwEvent(EN_EVENT_USER_TIMER, EN_SOURCE_TIMER, m_qTimers[i]->m_priority, \
                                   &(m_qTimers[i]->m_timerID), sizeof(m_qTimers[i]->m_timerID));

                        //if periodic timer, reload timer
                        m_qTimers[i]->m_timeMs = m_qTimers[i]->m_isContinue ? m_qTimers[i]->m_timeMsCopy : 0;

                        if (NULL_PTR != m_qTimers[i]->cbFunc)
                        {
                            m_qTimers[i]->cbFunc(); //invoke callback function.
                        }
                    }
                }
            }
        }
    }
}

}//namespace event
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/

namespace event
{
/** \brief run event producer */
void TimerEventProducer::loopControl(void)
{
}

/** \brief start event producer */
void TimerEventProducer::start(void)
{
    m_mutex.lock();

    m_started = TRUE;
    m_exit    = FALSE;

    m_mutex.unlock();
}
/** \brief stop event producer */
void TimerEventProducer::stop(void)
{
    m_mutex.lock();

    m_started = FALSE;

    //TODO: unregister from timer driver. if success set m_exit TRUE
    m_exit    = TRUE;

    m_mutex.unlock();
}

/** \brief pause event producer */
void TimerEventProducer::pause(void)
{
    m_mutex.lock();

    m_started = FALSE;
    m_exit    = FALSE;

    m_mutex.unlock();
}

/** \brief doControl event producer */
void TimerEventProducer::doControl(void)
{
}

/** \brief add new timer(copy) */
TimerEventProducer &TimerEventProducer::operator <<(Timer *timer)
{

    //TODO: add list
    return *this;
}

/** \brief add new timer(copy) */
TimerEventProducer &TimerEventProducer::operator <<(Timer timer)
{
    /** just allow to copy periodic timer */
    if (TRUE == timer.m_isContinue)
    {
        Timer *tm = new Timer(timer); //copy constructor

        std::cout << tm->m_timeMs << std::endl;

        *this << tm;
    }

    return *this;
}

/** \brief delete timer */
TimerEventProducer &TimerEventProducer::deleteTimer(Timer *timer)
{
    //TODO: find and delete timer from queue
    //TODO: set timerID = 0;
    return *this;
}

TimerEventProducer &TimerEventProducer::deleteTimer(TimerID tmID)
{
    //TODO: find and delete timer from queue
    //TODO: set timerID = 0;
    return *this;
}

}//namespace event
/******************************** End Of File *********************************/
