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
#include "ProjectConf.hpp"

#include "TimerEventProducer.hpp"
#include "EventPool.hpp"

#include <iostream>

/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

class MyCB
{
public:
    void foo(void){ std::cout << "my callback " << counter++ << std::endl;}

private:
    int counter;
};

int main(void)
{
    zlogger::loggerInit(zlogger::EN_LOG_LEVEL_VERBOSE); //Firstly Init logger

    platform::Platform *device = platform::Platform::getInstance();

//    MyCB cb;


    if (SUCCESS == device->buildPlatform())
    {
        ZLOGW << "[I] Building Platform SUCCESS, Thanks $$$";

        event::EventPool eventPool;
    //
        eventPool.buildEventProducer();
        TIMER_1(event::EN_TIMER_BIT, 1000, NULL, event::EN_PRIORITY_HIG);
        TIMER_1(1500);
//        TIMER_1(1000);
//        TIMER_1(1000);


            event::EventMsg *event = NULL_PTR;
        //


                while(1)
                {
                    event = eventPool.eventQueue.waithEvent(200, event::EN_SOURCE_3);

                    if (NULL_PTR != event)
                    {
                        std::cout << "get event " << event->getEvent() << std::endl;
                        std::cout << "get getEventPriority " << event->getEventPriority() << std::endl;
                        std::cout << "get getEventSource " << event->getEventSource() << std::endl;
                        std::cout << "get getLeng " << event->getLeng() << std::endl;
                        eventPool.eventQueue.deleteEvent(&event);
                    }
                }


        while(1);
        //TODO: Application app(device);
        //TODO: app.run();
    }
    else
    {
        ZLOGF << "[E] Building Platform Error !!!";
    }

//    event::EventPool eventPool;
//    event::EventMsg *event = NULL_PTR;
////
//    eventPool.buildEventProducer();
//
//    TIMER(event::TIMER_ENG_1)(400);
//
//    TIMER_1(100);
//    TIMER_1(500, foo, event::EN_PRIORITY_MED);
//
//    TIMER_1(event::EN_TIMER_BIT, 500);
//    TIMER_1(event::EN_TIMER_BIT, 500, foo, event::EN_PRIORITY_MED);

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
