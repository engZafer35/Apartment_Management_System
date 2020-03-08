/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 3, 2019 - 9:16:46 PM
* #File Name    : TimerEventProducer.hpp
* #File Path    : /GezGor/Application/inc/TimerEventProducer.hpp
*******************************************************************************/

/******************************************************************************
* How To Use:
* 1- TimerEventProducer is singleton class. When timer producer created, it can
*    register to hardware timer itself by given platform argument.
* 2- After initialize, invoke setQueue() function. If timer event occur timer
*    producer will load related event in this queue
* 3- Last, invoke start() function to start timer event producer
* 4- TIMER_1, TIMER_2, TIMER_3, TIMER macros can be used create new timer.
* 
* note: don't cancel timer in callback function
******* Examples:
*                      Create One Shot Timer
* TIMER_1(100);
* TIMER_1(500, foo, event::EN_PRIORITY_MED);
*
*                      Create Periodic Timer
* TIMER_1(event::EN_TIMER_BIT, 500);
* TIMER_1(event::EN_TIMER_BIT, 500, foo, event::EN_PRIORITY_MED);
*
*                      Create One Shot Timer with callback functions
* U32 timerID = TIMER_1(2500, std::bind(&MyCB::foo, &cb));
* U32 timer2 = TIMER_1(2700, [](void){std::cout << "This is my little lambda" << std::endl;});
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_EVENT_PRODUCER_HPP__
#define __TIMER_EVENT_PRODUCER_HPP__
/*********************************INCLUDES*************************************/
#include <deque>

#include "ProjectConf.hpp"
#include "EventProducer.hpp"
#include "EventList.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
namespace event
{
/**
 * \brief after created periodic Timer, load to timer event producer
 * \note  return type is TimerEventProducer
 */
#define TIMER                   (*(event::TimerEventProducer::getInstance()))
#define CANCEL_TIMER(timerID)   TIMER.cancelTimer(timerID)

}
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

/** \brief Timer event producer. Singleton design. */
class TimerEventProducer : public IEventProducer
{
public:
    ~TimerEventProducer(void);
/**
 * \brief  create TimerEventProducer(singleton)
 * \return address of TimerEventProducer
 */
static TimerEventProducer *getInstance(void);

    /**
     * \brief create one shot timer
     * \param timeMs
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     * \return timer ID
     * \note: if user want to cancel timer, cancelTimer() method can be invoke by timer ID
     *        so don't lost timer ID
     * \note: don't cancel timer in callback function
     */
    U32 operator ()(U32 timeMs, EVENTS event = EN_EVENT_TIMEOUT_TIMER, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    /**
     * \brief create periodic timer
     * \param timer ID, use ID just one time, dont create timer with same ID !!!
     * \param timeMs
     * \param event load timer ID, if you use callback func, event id will not use
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     * \note: don't cancel timer in callback function
     */
    void operator ()(TimerID tmID, U32 timeMs, EVENTS event, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    /** \brief delete timer */
    RETURN_STATUS cancelTimer(U32 tmID);

    /** \brief start event producer */
    void start(void) override;

    /** \brief stop event producer */
    void stop(void) override;

    /** \brief pause event producer */
    void pause(void) override;

    /** \brief run event producer */
    void loop(void) override;
private:
    TimerEventProducer(void);
private:
    struct TimerData
    {
        U32    timeMs;
        U32    timerID;
        U32    timeMsCopy;
        EVENTS event;
        EVENT_PRIORITY priority;
        VoidCallback cbFunc;
    };

    U32 idCounter; /** < Timer id Counter */

    /** All user timer will stored here*/
    typedef std::deque<struct TimerData *> QTimers;
    QTimers m_qTimers;

    U32 m_timerEnginePeriod;

    platform::Platform *m_platform;

    /** pointer for each timer */
    static TimerEventProducer *m_instance;

    static platform::MutexLock m_mutex;

    volatile BOOL m_start;
};


}//namespace event
#endif /* __TIMER_EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
