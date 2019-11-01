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
#include "ProjectConf.hpp"

#include "EventQueue.hpp"
#include "EventList.hpp"
#include "Utility.hpp"


/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{
//TODO: saf sanal sınıf yapılıp linux ve Bare metale göre bu sınıf türeyecek
class IEventProducer : private virtual NonCopyable
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

protected:
    EventQueue *m_pQueue;

    BOOL m_exit;
    BOOL m_paused;
    BOOL m_started;

private:
    MutexLock m_mutex;

#ifdef LINUX_PLATFORM
    pthread_t       m_threadControl;
#endif


};

}//namespace event


#endif /* __EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
