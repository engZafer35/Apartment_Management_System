/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:22:36 PM
* #File Name    : EventQueue.hpp
* #File Path    : /GezGör/Application/inc/EventQueue.hpp
*******************************************************************************/
/******************************************************************************
* 
*******************************************************************************/
/******************************IFNDEF & DEFINE*********************************/
#ifndef __EVENT_QUEUE_HPP__
#define __EVENT_QUEUE_HPP__
/*********************************INCLUDES*************************************/
#include <deque>

#ifdef __linux
#include <pthread.h>
#endif

#include "GlobalDefinitions.hpp"
#include "EventMessage.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{
class EventQueue
{
public:
    /** \brief constructor */
    EventQueue(void);

    /** \brief throw event */
    EventMsg *waithEvent(U32 timeoutMs, U32 eventSource) const;

    /** \brief create new event*/
    RETURN_STATUS throwEvent(EventMsg *event);

    /** \brief delete event with queue number*/
    RETURN_STATUS deleteEvent(U32 queNum);

    /** \brief delete event with queue number*/
    RETURN_STATUS deleteEvent(EventMsg *event);

    /** \brief delete all event that have same event ID */
    RETURN_STATUS deleteEvents(EVENTS eventID);

    /** \brief delete all pending events*/
    RETURN_STATUS deleteAllEvent(void);
private:
    void enterSection(void);

    void leaveSection(void);

private:
    typedef std::deque<EventMsg *> QEvents;
    QEvents qEvents;
    pthread_mutex_t *m_mutexEvent;
};

}//namespace event

#endif /* __EVENT_QUEUE_HPP__ */

/********************************* End Of File ********************************/
