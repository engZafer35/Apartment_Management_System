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
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

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
        EN_EVENT_PRODUCER_1, //EN_EVENT_KEYPAD
        EN_EVENT_PRODUCER_2, //EN_EVENT_UART
        EN_EVENT_PRODUCER_3, //EN_EVENT_TIMER
    }EVENT_PRODUCER_LIST;

    /** \brief event producer command */
    typedef enum
    {
        EN_PRODUCER_STOP,
        EN_PRODUCER_START,
        EN_PRODUCER_PAUSE,
        EN_PRODUCER_RESUME,
    }EVENT_PRODUCER_COMMAND;

public:
    /** \brief constructor */
    EventPool(void);

    ~EventPool(void);

    /**
     * \brief  build all event producers that system need
     * \return if everything is OK, return RET_SUCCES(0)
     *         otherwise return RET_FAILURE(-1)
     */
    RETURN_STATUS buildEventProducer(void);

    /** \brief start all producer to create event */
    RETURN_STATUS startProducers(void);

    /** \brief stop all producer */
    RETURN_STATUS stopProducers(void);

    /**
     * \brief send command to producer
     * \param producer list. User can send more than one producer
     * \param producer command
     * */
    RETURN_STATUS producerCommand(EVENT_PRODUCER_LIST list, EVENT_PRODUCER_COMMAND cmd);

public:
    /** Event Producers will load events in this event queue*/
    EventQueue eventQueue;
private:
    TimerEventProducer *m_tEventProducer;
};

}//namespace event

#endif /* __EVENT_POOL_HPP__ */

/********************************* End Of File ********************************/
