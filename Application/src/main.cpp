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
int main(void)
{

    std::cout << "Hello --- GezGor" << std::endl;

    event::EventPool eventPool;
    event::EventMsg *event = NULL_PTR;


    eventPool.buidSysEventProducer();

    while(1)
    {
        if (!event)
        ::sleep(5);

        event = eventPool.eventQueue.waithEvent(200, EN_SOURCE_3);
        while(NULL_PTR != event)
        {

            if (NULL != event)
            {
    //            std::cout <<"event ıd" << event->getEvent() << std::endl;
    //            std::cout <<"event source" << event->getEventSource() << std::endl;
    //            std::cout << "event pr" <<event->getEventPriority() << std::endl;
                std::cout << "add: " << event <<" event value: " << *(static_cast<int*>(event->getValue())) << std::endl;

                eventPool.eventQueue.deleteEvent(&event);
                event = eventPool.eventQueue.waithEvent(200, EN_SOURCE_3);
            }
        }

    }

    return 0;
}
/******************************** End Of File *********************************/
