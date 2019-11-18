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
#include "TimerEventProducer.hpp"
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

TimerEventProducer::TimerEventProducer(void) : m_timerEnginePeriod{0}, m_started{FALSE}, m_exit{FALSE}
{
    m_platform = platform::Platform::getInstance(); //get platform instance
    m_timerEnginePeriod = m_platform->devices->timer->getPeriod();
    m_platform->devices->timer->callback(reinterpret_cast<VoidCallback>(&TimerEventProducer::loop));
}
/***************************** CLASS PROTECTED METHOD *************************/
/**
 * \brief this method invoked by time engine system. It can be hardware timer unit,
 *        so don't handle alot of jobs in callback function. If you Just set a flag
 *        in callback function, we will be happy. Thanks
 */
void TimerEventProducer::loop(void)
{
    m_mutex.lock(); //enter section, don't allow to add new timer when checking the timers status.

    if(TRUE == m_started)
    {
        QTimers::iterator it = m_qTimers.begin();
        U32 index = 0;

        while(it != m_qTimers.end())
        {
            ++index; //for next iterator
            if ((*it)->m_timeMs > 0)
            {
                (*it)->m_timeMs -= m_timerEnginePeriod; //decrease timer value

                if ((*it)->m_timeMs < m_timerEnginePeriod) //check timer done
                {
                    throwEvent(EN_EVENT_USER_TIMER, EN_SOURCE_TIMER, (*it)->m_priority, \
                                &((*it)->m_timerID), sizeof((*it)->m_timerID) );

                    if (NULL_PTR != (*it)->cbFunc)
                    {
                        (*it)->cbFunc(); //invoke callback function.
                    }

                    if ((*it)->m_isContinue) //if periodic timer, reload timer
                    {
                        (*it)->m_timeMs = (*it)->m_timeMsCopy;
                    }
                    else
                    {
                        delete((*it));
                        m_qTimers.erase(it); //delete one shot timer.
                        --index; //deleted one member, so decrease index again
                    }
                }
            }

            it = m_qTimers.begin() + index; //set next timer
        }//end of while()
    }

    m_mutex.unlock(); //leave section
}
/***************************** CLASS PUBLIC METHOD ****************************/
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

/**
 * \brief create one shot timer
 * \param timeMs
 * \param cb when timer done, timer producer will invoke callback function
 * \param priority
 */
U32 TimerEventProducer::operator ()(U32 timeMs, VoidCallback cb, EVENT_PRIORITY priority)
{
    m_mutex.lock(); //enter section

    struct TimerData *td = new struct TimerData;

    td->cbFunc       = cb;
    td->m_timeMs     = timeMs;
    td->m_timeMsCopy = timeMs;
    td->m_priority   = priority;
    td->m_isContinue = FALSE;

    m_qTimers.push_back(td); //add timer to list

    //give timer ID for one shot timer, periodic timer ID reserved
    td->m_timerID = EN_TIMER_MAX_NUM + m_qTimers.size();

    m_mutex.unlock();//leave section

    return SUCCESS;
}

/**
 * \brief create periodic timer
 * \param timer ID
 * \param timeMs
 * \param cb when timer done, timer producer will invoke callback function
 * \param priority
 */
void TimerEventProducer::operator ()(TimerID tmID, U32 timeMs, VoidCallback cb, EVENT_PRIORITY priority)
{
    m_mutex.lock(); //enter section

    struct TimerData *td = new struct TimerData;

    td->cbFunc       = cb;
    td->m_timeMs     = timeMs;
    td->m_timeMsCopy = timeMs;
    td->m_priority   = priority;
    td->m_isContinue = FALSE;
    td->m_timerID    = tmID;

    m_qTimers.push_back(td); //add timer to list

    m_mutex.unlock(); //leave section
}

RETURN_STATUS TimerEventProducer::cancelTimer(S32 tmID)
{
    m_mutex.lock(); //enter section

    RETURN_STATUS retVal = FAILURE;

    QTimers::iterator it = m_qTimers.begin();
    U32 size = m_qTimers.size();

    for (U32 i = 0; i < size; i++)
    {
        if ((*it)->m_timerID == tmID) //find timer
        {
            m_qTimers.erase(it);
            retVal = SUCCESS;
            break;
        }
        it++;
    }

    m_mutex.unlock(); //leave section

    return retVal;
}

}//namespace event
/******************************** End Of File *********************************/
