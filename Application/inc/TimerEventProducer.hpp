/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 23, 2019 - 5:19:34 PM
* #File Name    : TimerEventProducer_L.hpp
* #File Path    : /GezGor/Application/inc/TimerEventProducer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_EVENT_PRODUCER_HPP__
#define __TIMER_EVENT_PRODUCER_HPP__
/*********************************INCLUDES*************************************/
#include "ProjectConf.hpp"
#include "EventProducer.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
namespace event
{

class TimerEventProducer : public IEventProducer
{

private:
    /** Constructor */
    TimerEventProducer(void);

public:
    /**
     * \brief  create TimerEventProducer_L(singleton)
     * tparam  create different timer with ID. if system
     *         has more than one timer(TIMER1, TIMER2, ..)
     *         user can create other timer.
     * \return address of TimerEventProducer_L
     */
    template<int ID>
    static TimerEventProducer *getInstance(void);

    /** \brief pause event producer */
     void pause(void) override;

    /** \brief resume event producer */
     void resume(void) override;

    /** \brief start event producer */
     void start(void) override;

    /** \brief stop event producer */
     void stop(void) override;

private:
     /** \brief doControl event producer */
     void doControl(void) override;

     /** \brief run event producer */
     void loopControl(void) override;

private:
    /** pointer for each timer */
    template<int ID>
    static TimerEventProducer *producer;

#ifdef LINUX_PLATFORM
    MutexLock m_mutex;
    BOOL m_exit;
    BOOL m_paused;
    BOOL m_started;
    pthread_t m_threadControl;
#endif
};

template<int ID>
TimerEventProducer *TimerEventProducer::producer = NULL_PTR;

template<int ID>
extern inline TimerEventProducer *TimerEventProducer::getInstance(void)
{
    MutexLockFunc mutex; /** < guarantee that only one object is created. >*/

    if (NULL_PTR == producer<ID>)
    {
        producer<ID> = new TimerEventProducer();
    }

    return producer<ID>;
}
}//namespace timer
/********************************* CLASS **************************************/

#endif /* __TIMER_EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
