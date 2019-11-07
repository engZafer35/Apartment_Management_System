/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:43:17 PM
* #File Name    : main.cpp 
* #File Path    : /GezGör/Application/src/main.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "TimerEventProducer.hpp"
#include <iostream>
#include <unistd.h>
#include "EventPool.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
void foo(void)
{

}
int main(void)
{

    std::cout << "Hello --- GezGor" << std::endl;

    event::EventPool eventPool;
    event::EventMsg *event = NULL_PTR;

    eventPool.buildEventProducer();

    TIMER(event::TIMER_ENG_1)(400);

    TIMER_1(100);
    TIMER_1(500, foo, event::EN_PRIORITY_MED);

    TIMER_1(event::EN_TIMER_BIT, 500);
    TIMER_1(event::EN_TIMER_BIT, 500, foo, event::EN_PRIORITY_MED);

//    while(1)
//    {
//        if (!event)
//        ::sleep(5);
//
//        event = eventPool.eventQueue.waithEvent(200, event::EN_SOURCE_3);
//        while(NULL_PTR != event)
//        {
//            if (NULL_PTR != event)
//            {
//    //            std::cout <<"event ıd" << event->getEvent() << std::endl;
//    //            std::cout <<"event source" << event->getEventSource() << std::endl;
//    //            std::cout << "event pr" <<event->getEventPriority() << std::endl;
//                std::cout << "add: " << event <<" event value: " << *(static_cast<int*>(event->getValue())) << std::endl;
//
//                eventPool.eventQueue.deleteEvent(&event);
//                event = eventPool.eventQueue.waithEvent(200, event::EN_SOURCE_3);
//            }
//        }
//
//    }

    return 0;
}
/******************************** End Of File *********************************/
