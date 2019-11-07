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
******* Examples:
*                      Create One Shot Timer
* TIMER_1(100);
* TIMER_1(500, foo, event::EN_PRIORITY_MED);
*
*                      Create Periodic Timer
* TIMER_1(event::EN_TIMER_BIT, 500);
* TIMER_1(event::EN_TIMER_BIT, 500, foo, event::EN_PRIORITY_MED);
*
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_EVENT_PRODUCER_HPP___ //todo:
#define __TIMER_EVENT_PRODUCER_HPP___
/*********************************INCLUDES*************************************/
#include "ProjectConf.hpp"
#include "Utility.hpp"
#include "EventProducer.hpp"

#include <deque>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
namespace event
{
/**
 * \brief after created periodic Timer, load to timer event producer
 * \note  return type is TimerEventProducer
 */
#define TIMER(id) (*(event::TimerEventProducer::getInstance<id>()))

#define TIMER_1   TIMER(event::TIMER_ENG_1) /** <! load timer to timer engine 1*/
#define TIMER_2   TIMER(event::TIMER_ENG_2) /** <! load timer to timer engine 2*/
#define TIMER_3   TIMER(event::TIMER_ENG_3) /** <! load timer to timer engine 3*/
}
/*******************************TYPE DEFINITIONS ******************************/
namespace event
{
typedef enum _TIMER_ID
{
    TIMER_ENG_1,
    TIMER_ENG_2,
    TIMER_ENG_3,
}TIMER_ENG;
}//namespace event
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

class TimerEventProducer : public IEventProducer
{
public:
    /**
     * \brief  create TimerEventProducer(singleton)
     * tparam  create different timer with ID. if system
     *         has more than one timer(TIMER1, TIMER2, ..)
     *         user can create other timer.
     * \return address of TimerEventProducer
     */
    template<TIMER_ENG ID>
    static TimerEventProducer *getInstance(void);

    /**
     * \brief create one shot timer
     * \param timeMs
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     */
    U32 operator ()(U32 timeMs, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    /**
     * \brief create periodic timer
     * \param timer ID
     * \param timeMs
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     */
    void operator ()(TimerID tmID, U32 timeMs, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    /** \brief delete timer */
    RETURN_STATUS cancelTimer(S32 tmID);

    /** \brief start event producer */
    void start(void) override;

    /** \brief stop event producer */
    void stop(void) override;

    /** \brief pause event producer */
    void pause(void) override;

public:
    /** \brief run event producer */
    void loop(void) override;

    TimerEventProducer(/*const Platform *pl*/);
private:

    struct TimerData
    {
        U32   m_timeMs;
        BOOL  m_isContinue;
        S32   m_timerID;
        U32   m_timeMsCopy;
        EVENT_PRIORITY m_priority;
        VoidCallback cbFunc;
    };

    /** All user timer will stored here*/
    typedef std::deque<struct TimerData *> QTimers;
    QTimers m_qTimers;

    const U32 m_timerEnginePeriod;

    //TODO:Const Platform *m_pl;

    /** pointer for each timer */
    template<TIMER_ENG ID>
    static TimerEventProducer *m_producer;

    MutexLock m_mutex;

    BOOL volatile m_started;
    BOOL volatile m_exit;
};

template<TIMER_ENG ID>
TimerEventProducer *TimerEventProducer::m_producer = NULL_PTR;

template<TIMER_ENG ID>
extern inline TimerEventProducer *TimerEventProducer::getInstance(/*const Platform *pl*/)
{
    MutexLockFunc mutex; /** < guarantee that only one object is created. >*/

    if (NULL_PTR == m_producer<ID>)
    {
        m_producer<ID> = new TimerEventProducer(/*const Platform *pl*/);
    }

    return m_producer<ID>;
}

}//namespace event
#endif /* __TIMER_EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
