/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:45:12 PM
* #File Name    : EventMessage.hpp
* #File Path    : /GezGör/Application/inc/EventMessage.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EVENT_MESSAGE_HPP__
#define __EVENT_MESSAGE_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "EventList.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{
class EventMsg
{
public:
    /**
     * \brief create EventMsg
     * \param event ID
     * \param event source
     * \param address of value,
     * \param value leng
     */
    EventMsg(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter, U32 leng);

    /** \brief get event ID */
    EVENTS          getEvent(void) const;

    /** \brief get event source */
    EVENT_SOURCE    getEventSource(void) const;

    /** \brief get event priority */
    EVENT_PRIORITY  getEventPriority(void) const;

    /** \brief get value */
    void*           getValue(void);

    /** \brief get value length */
    U32             getLeng(void) const;

    /** \brief get queue number*/
    U32             getQueueNum(void) const;

private:

    /** \note EventQueue::throwEvent() will set m_queueNum */
    friend class EventQueue;

    EVENTS          m_event;
    EVENT_SOURCE    m_source;
    EVENT_PRIORITY  m_priority;
    void*           m_value;
    U32             m_leng;
    S32             m_queueNum;
};

}//namespace event
#endif /* __EVENT_MESSAGE_HPP__ */

/********************************* End Of File ********************************/
