/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 4:09:38 PM
* #File Name    : AppRedBirdLoop.cpp 
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/src/AppRedBirdLoop.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "AppRedBirdLoop.hpp"

#include "IEventHandler.hpp"
#include "EventPool.hpp"
#include "AppEventHandler.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace redbird
{

AppRedBird::AppRedBird(platform::Platform &platform) : m_isFlying{FALSE}, m_platform{platform}, m_eventHandler{NULL}
{}

AppRedBird::~AppRedBird(void)
{}

RETURN_STATUS AppRedBird::eggs(void)
{
    RETURN_STATUS retVal = OK;

    m_eventHandler = new AppEventHandler; //todo get last system status and load related event handler

    retVal = m_eventPool.buildEventProducer();

    return retVal;
}

RETURN_STATUS AppRedBird::fly(void)
{
    RETURN_STATUS retVal = OK;

    m_isFlying = TRUE;
    m_eventPool.start();

    TIMER(event::EN_TIMER_5, 3000, event::EN_EVENT_PER_JOB_1, /*std::bind(&MyCB::foo, &cb),*/NULL_PTR, event::EN_PRIORITY_HIG);
    TIMER(event::EN_TIMER_2, 1000, event::EN_EVENT_NO_EVENT, [](void){ZLOG << "#### Hi, I am Lambda ####" << "\n" ;}, event::EN_PRIORITY_MED);
    TIMER(event::EN_TIMER_3, 2000, event::EN_EVENT_PER_JOB_2);

    event::EventMsg *event = NULL_PTR;

    while(1)
    {
        event = m_eventPool.eventQueue.waithEvent(0, event::EN_SOURCE_EVENT_ALL); //no timeout, accept all event
        if (NULL_PTR != event)
        {
            m_eventHandler->handleEvent(*event);

            m_eventPool.eventQueue.deleteEvent(&event);
        }
    }

    return retVal;
}

RETURN_STATUS AppRedBird::roost(void)
{
    m_isFlying = FALSE;

    m_eventPool.stop(); // bird won't see any event anymore
    return OK;
}

}//namespace redbird


//TIMER(event::EN_TIMER_5, 3000, event::EN_EVENT_PER_JOB_1, /*std::bind(&MyCB::foo, &cb),*/NULL_PTR, event::EN_PRIORITY_HIG);
//TIMER(event::EN_TIMER_2, 1000, event::EN_EVENT_NO_EVENT, [](void){ZLOG << "#### Hi, I am Lambda #### ";}, event::EN_PRIORITY_MED);
//TIMER(event::EN_TIMER_3, 2000, event::EN_EVENT_PER_JOB_2);
//
//event::EventMsg *event = NULL_PTR;
//U32 tid = TIMER(4000);
//while(1)
//{
//    event = eventPool.eventQueue.waithEvent(0, event::EN_SOURCE_PER_TIMER | event::EN_SOURCE_ONE_TIMER);
//    if (NULL_PTR != event)
//    {
//        ehandler.handleEvent(*event);
//
//        if (event::EN_SOURCE_ONE_TIMER == event->getEventSource())
//        {
//            CANCEL_TIMER(tid);
//            tid = TIMER(4000);
//        }
//
//        eventPool.eventQueue.deleteEvent(&event);
//    }
//}
/******************************** End Of File *********************************/
