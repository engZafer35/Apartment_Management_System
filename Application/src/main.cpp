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
#include "ExmLinuxEventHandler.hpp"
#include "IEventHandler.hpp"
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
//    zlogger::loggerInit(zlogger::EN_LOG_LEVEL_VERBOSE); //Firstly Init logger

    platform::Platform *device = platform::Platform::getInstance();

    ExmLinuxEventHandler ehandler;

    MyCB cb;

    if (OK == device->buildPlatform())
    {
        ZLOGW << "[I] Building Platform SUCCESS, Thanks $$$";

        event::EventPool eventPool;
        eventPool.buildEventProducer();
        eventPool.start();

        TIMER(event::EN_TIMER_5, 300, event::EN_EVENT_PER_JOB_1, /*std::bind(&MyCB::foo, &cb),*/NULL_PTR, event::EN_PRIORITY_HIG);
        TIMER(event::EN_TIMER_2, 100, event::EN_EVENT_NO_EVENT, [](void){ZLOG << "#### Hi, I am Lambda #### ";}, event::EN_PRIORITY_MED);
        TIMER(event::EN_TIMER_3, 200, event::EN_EVENT_PER_JOB_2);

        event::EventMsg *event = NULL_PTR;
        U32 tid = TIMER(400);

        while(1)
        {

            event = eventPool.eventQueue.waithEvent(0, event::EN_SOURCE_PER_TIMER | event::EN_SOURCE_ONE_TIMER);
            if (NULL_PTR != event)
            {
                ehandler.handleEvent(*event);

                if (event::EN_SOURCE_ONE_TIMER == event->getEventSource())
                {
                    CANCEL_TIMER(tid);
                    tid = TIMER(400);
                }

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
