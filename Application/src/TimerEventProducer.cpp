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
namespace event
{
TimerEventProducer *TimerEventProducer::m_instance = NULL_PTR;
}//namespace event
/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/
namespace event
{

TimerEventProducer::TimerEventProducer(void) : idCounter{EN_TIMER_MAX_NUM}, m_timerEnginePeriod{0}, m_start{FALSE}
{
    m_platform = platform::Platform::getInstance(); //get platform instance
    m_timerEnginePeriod = m_platform->devices->timer->getPeriod();
    m_platform->devices->timer->loadCallback(this);
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

    if(TRUE == m_start)
    {
        QTimers::iterator it = m_qTimers.begin();
        U32 index = 0;

        while(it != m_qTimers.end())
        {
            ++index; //for next iterator
            if ((*it)->timeMs > 0)
            {
                (*it)->timeMs -= m_timerEnginePeriod; //decrease timer value

                if ((*it)->timeMs < m_timerEnginePeriod) //check timer done
                {
                    if (NULL_PTR != (*it)->cbFunc)
                    {
                        (*it)->cbFunc(); //invoke callback function.
                    }
                    else //don't throw event if callback function exist
                    {
                        EVENT_SOURCE src;
                        if((*it)->timeMsCopy > 0)
                        {
                            src = EN_SOURCE_PER_TIMER;
                        }
                        else
                        {
                            src = EN_SOURCE_ONE_TIMER;
                        }

                        throwEvent((*it)->event, src, (*it)->priority, &((*it)->timerID), sizeof((*it)->timerID) );
                    }

                    (*it)->timeMs = (*it)->timeMsCopy;
                }
            }

            it = m_qTimers.begin() + index; //set next timer
        }//end of while()
    }

    m_mutex.unlock(); //leave section
}
/***************************** CLASS PUBLIC METHOD ****************************/
TimerEventProducer::~TimerEventProducer(void)
{
    m_mutex.lock(); // lock section

    for (QTimers::iterator it = m_qTimers.begin(); it != m_qTimers.end(); ++it)
    {
        delete (*it);   //delete from memory
    }

    m_qTimers.clear();

    delete (m_instance);
    m_instance = NULL_PTR;

    m_mutex.unlock();// unlock section
}

/** \brief  create TimerEventProducer(singleton)*/
TimerEventProducer *TimerEventProducer::getInstance(void)
{
    platform::MutexLockFunc mutex; /** < guarantee that only one object is created. >*/
    if (NULL_PTR == m_instance)
    {
        m_instance = new TimerEventProducer();
    }
    return m_instance;
}

/** \brief start event producer */
void TimerEventProducer::start(void)
{
    m_mutex.lock();

    m_start = TRUE;

    m_mutex.unlock();
}
/** \brief stop event producer */
void TimerEventProducer::stop(void)
{
    m_mutex.lock();

    m_start = FALSE;

    //TODO: unregister from timer driver. if success set m_exit TRUE

    m_mutex.unlock();
}

/** \brief pause event producer */
void TimerEventProducer::pause(void)
{
    m_mutex.lock();

    m_start = FALSE;

    m_mutex.unlock();
}

/**
 * \brief create one shot timer
 * \param timeMs
 * \param cb when timer done, timer producer will invoke callback function
 * \param priority
 * \return timer ID
 * \note: if user want to cancel timer, cancelTimer() method can be invoke by timer ID
 *        so don't lost timer ID
 */
U32 TimerEventProducer::operator ()(U32 timeMs, EVENTS event, VoidCallback cb, EVENT_PRIORITY priority)
{
    m_mutex.lock(); //enter section
    U32 ru;
    struct TimerData *td = new struct TimerData;

    //round up
    ru = (timeMs % m_timerEnginePeriod);
    if (0 != ru)
    {
        timeMs += m_timerEnginePeriod - ru;
    }

    td->cbFunc      = cb;
    td->timeMs      = timeMs;
    td->timeMsCopy  = 0;
    td->event       = event;
    td->priority    = priority;

    //give timer ID for one shot timer, periodic timer ID reserved
    td->timerID = idCounter++; //dot care overload

    m_qTimers.push_back(td); //add timer to list

    ZLOG << "[I] New One-Shot Timer created: " << timeMs << "ms" << " ID:"<< td->timerID << std::endl;

    m_mutex.unlock();//leave section

    return td->timerID;
}

/**
 * \brief create periodic timer
 * \param timer ID, use ID just one time, dont create timer with same ID !!
 * \param timeMs
 * \param cb when timer done, timer producer will invoke callback function
 * \param priority
 */
void TimerEventProducer::operator ()(TimerID tmID, U32 timeMs, EVENTS event, VoidCallback cb, EVENT_PRIORITY priority)
{
    m_mutex.lock(); //enter section
    U32 ru;
    struct TimerData *td = new struct TimerData;

    //round up
    ru = (timeMs % m_timerEnginePeriod);
    if (0 != ru)
    {
        timeMs += m_timerEnginePeriod - ru;
    }

    td->cbFunc     = cb;
    td->timeMs     = timeMs;
    td->timeMsCopy = timeMs;
    td->event      = event;
    td->priority   = priority;
    td->timerID    = tmID;

    m_qTimers.push_back(td); //add timer to list

    ZLOG << "[I] New Periodic Timer created: " << timeMs << "ms" << " ID:"<< td->timerID;
    m_mutex.unlock(); //leave section
}

RETURN_STATUS TimerEventProducer::cancelTimer(U32 tmID)
{
    m_mutex.lock(); //enter section

    RETURN_STATUS retVal = FAILURE;

    QTimers::iterator it = m_qTimers.begin();
    U32 size = m_qTimers.size();

    for (U32 i = 0; i < size; i++)
    {
        if ((*it)->timerID == tmID) //find timer
        {
            delete((*it));
            m_qTimers.erase(it);
            retVal = OK;
            break;
        }
        it++;
    }
    ZLOGV_IF(OK == retVal) << "[I] Timer Canceled " << " ID:" << tmID;
    m_mutex.unlock(); //leave section

    return retVal;
}

}//namespace event
/******************************** End Of File *********************************/
