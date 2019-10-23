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
#include <EventProducer.hpp>
#include <vector>

#include "EventQueue.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

class EventPool // TODO: make singleton
{

public:
    void loadEventProducer(IEventPoroducer *producer);
    void startProducers(void);
    void stopProducers(void);

    void throwEvent(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter = NULL_PTR, U32 leng = 0);

private:
    EventQueue m_eventQueue;
    std::vector<IEventPoroducer *> evetProducerList;
};

}//namespace event

#endif /* __EVENT_POOL_HPP__ */

/********************************* End Of File ********************************/
