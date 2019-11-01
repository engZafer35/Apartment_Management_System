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
//namespace event
//{
//static void *threadControlFunction(void *arg)
//{
//    IEventProducer *producer = (IEventProducer *)arg;
//    if (producer)
//    {
//        producer->loopControl();
//    }
//
//#ifdef LINUX_PLATFORM
//    pthread_exit(NULL);
//#endif
//}
//
//}//namespace event
/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/
namespace event
{
/** \brief throw event */
void IEventProducer::throwEvent(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *parameter, U32 leng)
{
    if (NULL_PTR != m_pQueue)
    {
        m_pQueue->throwEvent(new EventMsg(event, source, priority, parameter, leng));
    }
}

}//namespace event
/***************************** CLASS PUBLIC METHOD ****************************/
namespace event
{
IEventProducer::IEventProducer(void): m_pQueue{0} {}

IEventProducer::~IEventProducer(void) {}

/** \brief All event producer will load its event into event queue */
void IEventProducer::setQueue(EventQueue *eventQueue)
{
    // don't need to check null pointer. Because it will checked in throwEvent()
    m_pQueue = eventQueue;
}

}//namespace event
/******************************** End Of File *********************************/
