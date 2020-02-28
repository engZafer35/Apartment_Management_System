/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 8:24:47 PM
* #File Name    : EventPool.hpp
* #File Path    : /GezGor/Application/inc/EventPool.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EVENT_POOL_HPP__
#define __EVENT_POOL_HPP__
/*********************************INCLUDES*************************************/
#include "EventQueue.hpp"
#include "Utility.hpp"

#include "TimerEventProducer.hpp"
#include "UiEventProducer.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/
#define EVENT_POOL() (event::EventPool::getInstance())
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

class EventPool : private NonCopyable // TODO: make singleton
{
public:
    /** \brief All supported event producers list*/
    typedef enum
    {
        EN_EVENT_TIMER, //EN_EVENT_TIMER
        EN_EVENT_PRODUCER_1, //EN_EVENT_KEYPAD
        EN_EVENT_PRODUCER_2, //EN_EVENT_UART
    }EVENT_PRODUCER_LIST;

    /** \brief event producer command */
    typedef enum
    {
        EN_PRODUCER_STOP,
        EN_PRODUCER_START,
    }EVENT_PRODUCER_COMMAND;

public:
    /**
     * \brief get singleton class instance
     * \return EventPool pointer
     */
    static EventPool* const getInstance(void);

    /**
     * \brief  build all event producers that system need
     * \return if everything is OK, return RET_SUCCES(0)
     *         otherwise return RET_FAILURE(-1)
     */
    RETURN_STATUS buildEventProducer(void);

    /** \brief start all producer to create event */
    RETURN_STATUS start(void);

    /** \brief stop all producer */
    RETURN_STATUS stop(void);

    /**
     * \brief send command to producer
     * \param producer list. User can send more than one producer
     * \param producer command
     * */
    RETURN_STATUS producerCommand(EVENT_PRODUCER_LIST list, EVENT_PRODUCER_COMMAND cmd);
private:
    /** \brief constructor */
    EventPool(void);

    ~EventPool(void);
public:
    /** Event Producers will load events in this event queue*/
    EventQueue *eventQueue;
private:
    TimerEventProducer *m_timerEventProd;
    UiEventProducer    *m_uiEventProd;

    static EventPool* m_instance;
    static platform::MutexLock *m_mutex;
};

}//namespace event

#endif /* __EVENT_POOL_HPP__ */

/********************************* End Of File ********************************/
