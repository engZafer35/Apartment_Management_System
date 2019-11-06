/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 3, 2019 - 9:16:46 PM
* #File Name    : TimerEventProducer.hpp
* #File Path    : /GezGor/Application/inc/TimerEventProducer.hpp
*******************************************************************************/

/******************************************************************************
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
#define TIMER_EVENT(id) (*(event::TimerEventProducer::getInstance<id>()))

}
/*******************************TYPE DEFINITIONS ******************************/
namespace event
{
typedef enum _TIMER_ID
{
    TIMER_ENG_1,
    TIMER_ENG_2,
    TIMER_ENG_3,
}TIMER_ID;
}//namespace event
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{
class TimerEventProducer;

/**
 * \brief class timer. when user need timer, Timer object should be created
 */
class Timer
{
public:
    /**
     * \brief one shot timer Constructor
     * \param timeMs
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     */
    Timer(U32 timeMs, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    /**
     * \brief periodic timer constructor
     * \param timer ID
     * \param timeMs
     * \param cb when timer done, timer producer will invoke callback function
     * \param priority
     */
    Timer(TimerID tmID, U32 timeMs, VoidCallback cb = NULL_PTR, EVENT_PRIORITY priority = EN_PRIORITY_LOW);

    virtual ~Timer(void);

    /** \brief delete timer */
    static RETURN_STATUS deleteTimer(Timer *tm);

    /**
     * \brief get created timer ID
     * \return if timer could not be created return -1 ID
     */
    U32 getTimerID(void) const;

    /** \brief check manually timer Done */
    BOOL isTimerOK(void) const;

private:
    U32         m_timeMs;
    BOOL        m_isContinue;
    U32         m_timerID;
    const U32   m_timeMsCopy;
    EVENT_PRIORITY m_priority;

    VoidCallback cbFunc;

    /** \brief timer producer need to reach m_timeMs, m_isContinue, m_timerID, cbFunc */
    friend TimerEventProducer;
};




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
    template<TIMER_ID ID>
    static TimerEventProducer *getInstance(void);

    /** \brief add new timer(copy) */
    TimerEventProducer &operator <<(Timer *timer);

    /** \brief add new timer(copy) */
    TimerEventProducer &operator <<(Timer timer);

    /** \brief delete timer */
    TimerEventProducer &deleteTimer(Timer *timer);

    /** \brief delete timer */
    TimerEventProducer &deleteTimer(TimerID tmID);

    /** \brief run event producer */
    void loopControl(void) override;

    /** \brief start event producer */
    void start(void) override;

    /** \brief stop event producer */
    void stop(void) override;

    /** \brief pause event producer */
    void pause(void) override;

    /** \brief doControl event producer */
    void doControl(void) override;

private:
    TimerEventProducer(/*const Platform *pl*/);
    void cbProducer(void); //This function will be invoked by timer engine

private:
    /** All user timer will stored here*/
    typedef std::deque<Timer *> QTimers;
    QTimers m_qTimers;

    const U32 m_timerEnginePeriod;

    //TODO:Const Platform *m_pl;

    /** pointer for each timer */
    template<TIMER_ID ID>
    static TimerEventProducer *m_producer;

    MutexLock m_mutex;

    BOOL m_started;
    BOOL m_exit;
};

template<TIMER_ID ID>
TimerEventProducer *TimerEventProducer::m_producer = NULL_PTR;

template<TIMER_ID ID>
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
