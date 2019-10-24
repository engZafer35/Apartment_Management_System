/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 8:30:25 PM
* #File Name    : EventProducerInterface.hpp
* #File Path    : /GezGor/Application/inc/EventProducer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EVENT_PRODUCER_HPP__
#define __EVENT_PRODUCER_HPP__
/*********************************INCLUDES*************************************/
#include "EventQueue.hpp"
#include "EventList.hpp"
#include "Singleton.hpp"

#ifdef __linux
#include <pthread.h>
#include <thread>
#endif
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

class IEventProducer // todo: make singletons
{
public:
    IEventProducer(void);
    /** \brief destructor */
    virtual ~IEventProducer(void);

    /** \brief All event producer will load its event into event queue */
    void setQueue(EventQueue *eventQueue);

    /** \brief pause event producer */
    virtual void pause(void);

    /** \brief resume event producer */
    virtual void resume(void);

public:  /** ****** Pure virtual Functions ****** */
    /** \brief start event producer */
    virtual void start(void);

    /** \brief stop event producer */
    virtual void stop(void);

    /** \brief doControl event producer */
    virtual void doControl(void) = 0;

    /** \brief run event producer */
    void loopControl(void);

protected:
    /** \brief throw event */
    void throwEvent(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter = NULL_PTR, U32 leng = 0);

    /** \brief lock section */
    void enterSection(void);

    /** \brief unlock section */
    void leaveSection(void);

protected:
    EventQueue *m_pQueue;

private:

#ifdef __linux
    pthread_mutex_t m_mutexEvent;
    pthread_t       m_threadControl;
#endif

    bool m_exit;
    bool m_paused;
    bool m_started;
};

}//namespace event


#endif /* __EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
