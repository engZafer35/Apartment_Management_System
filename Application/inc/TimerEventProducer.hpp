/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 23, 2019 - 5:19:34 PM
* #File Name    : TimerEventProducer.hpp
* #File Path    : /GezGor/Application/inc/TimerEventProducer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_EVENT_PRODUCER_HPP__
#define __TIMER_EVENT_PRODUCER_HPP__
/*********************************INCLUDES*************************************/
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

    /**
     * \brief create TimerEventProducer
     *        just one timer producer should be created.
     *        So that all event producer will created in the
     *        template function.
     * \return address of TimerEventProducer
     */

public:
    /**
     * \brief  create TimerEventProducer(singleton)
     * \return address of TimerEventProducer
     */
    static TimerEventProducer *getInstance(void);

//    void start(void) override;

    /** \brief doControl event producer */
    void doControl(void) override;

//    /** \brief loopControl event producer */
//    void run(void) override;
    /** \brief pause event producer */
     void pause(void) override;

    /** \brief resume event producer */
     void resume(void) override;

  /** ****** Pure virtual Functions ****** */
    /** \brief start event producer */
     void start(void) override;

    /** \brief stop event producer */
     void stop(void) override;

    /** \brief run event producer */
     void loopControl(void) override;

private:
    static TimerEventProducer *producer;
    BOOL m_exit;
    BOOL m_paused;
    BOOL m_started;

private:
    MutexLock m_mutex;

#ifdef LINUX_PLATFORM
    pthread_t       m_threadControl;
#endif
};

}//namespace timer
/********************************* CLASS **************************************/

#endif /* __TIMER_EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
