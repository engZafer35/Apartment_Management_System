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
#include "EventHandler.hpp"
#include "MyEventInterpreter.hpp"
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

    MyEventInterpreter inp;
    event::EventHandler eh(inp);

    MyCB cb;

    if (OK == device->buildPlatform())
    {
        ZLOGW << "[I] Building Platform SUCCESS, Thanks $$$";

        event::EventPool eventPool;
        eventPool.buildEventProducer();
        eventPool.start();

//        TIMER(event::EN_TIMER_5, 3000, event::EN_EVENT_PER_JOB_1, /*std::bind(&MyCB::foo, &cb),*/NULL_PTR, event::EN_PRIORITY_HIG);
//        TIMER(event::EN_TIMER_2, 1000, event::EN_EVENT_NO_EVENT, [](void){ZLOG << "Timer Event Callback Funct Timer:1000ms";}, event::EN_PRIORITY_MED);

        TIMER(2000);

        event::EventMsg *event = NULL_PTR;

        while(1)
        {
            U32 tid = TIMER(1000);
            event = eventPool.eventQueue.waithEvent(0, event::EN_SOURCE_PER_TIMER | event::EN_SOURCE_ONE_TIMER);
            if (NULL_PTR != event)
            {
                eh.handleEVent(*event);
                eventPool.eventQueue.deleteEvent(&event);
            }
            CANCEL_TIMER(tid);

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
