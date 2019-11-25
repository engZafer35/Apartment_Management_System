/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:43:17 PM
* #File Name    : main.cpp 
* #File Path    : /GezGor/Application/src/main.cpp
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
    MyCB() : counter{666}{}
    void foo(void)
    {

        std::cout <<std::endl<< " ---------> my callback <----------------" << counter++ << std::endl;
    }

private:
    int counter;
};

int main(void)
{
    zlogger::loggerInit(zlogger::EN_LOG_LEVEL_VERBOSE); //Firstly Init logger

    platform::Platform *device = platform::Platform::getInstance();

    MyCB cb;

    if (OK == device->buildPlatform())
    {
        ZLOGW << "[I] Building Platform SUCCESS, Thanks $$$";

        event::EventPool eventPool;
        eventPool.buildEventProducer();
        eventPool.startProducers();

        TIMER_1(event::EN_TIMER_5, 1000, /*std::bind(&MyCB::foo, &cb),*/NULL_PTR, event::EN_PRIORITY_HIG);
        TIMER_1(event::EN_TIMER_2, 1000, [](void){ZLOG << "Timer Event Callback Funct Timer:1500ms";}, event::EN_PRIORITY_MED);

        event::EventMsg *event = NULL_PTR;

        while(1)
        {
            event = eventPool.eventQueue.waithEvent(0, event::EN_SOURCE_3);

            if (NULL_PTR != event)
            {
                std::cout << "get event " << event->getEvent() << std::endl;
                std::cout << "get getEventPriority " << event->getEventPriority() << std::endl;
                std::cout << "get getEventSource " << event->getEventSource() << std::endl;
                std::cout << "get event data leng " << event->getLeng() << std::endl;
                U32 *timerID = static_cast<U32*>(event->getValue());
                std::cout << "Timer ID " << *timerID << std::endl;

                eventPool.eventQueue.deleteEvent(&event);
            }

            //TODO: Application app(device);
            //TODO: app.run();
        }
    }
    else
    {
        ZLOGF << "[E] Building Platform Error !!!";
    }

    return 0;
}
/******************************** End Of File *********************************/
