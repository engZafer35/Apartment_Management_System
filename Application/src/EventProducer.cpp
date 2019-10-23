/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 9:25:53 PM
* #File Name    : EventProducer.cpp 
* #File Path    : /GezGor/Application/src/EventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventProducer.hpp"
#include "EventMessage.hpp"
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
namespace event
{

IEventPoroducer::~IEventPoroducer(void)
{}

void IEventPoroducer::setQueue(EventQueue *eventQueue)
{
    // don't need to check null pointer. Because it will checked in throwEvent()
    m_pQueue = eventQueue;
}

void IEventPoroducer::throwEvent(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter, U32 leng)
{
    if (NULL_PTR != m_pQueue)
    {
        m_pQueue->throwEvent(new EventMsg(event, source, priority, parameter, leng));
    }
}


//void IEventPoroducer::start(void)
//{
//    if (FALSE == m_started)
//    {
//        m_started = TRUE;
//        m_exit = FALSE;
//    }
//}

}//namespace event
/******************************** End Of File *********************************/
