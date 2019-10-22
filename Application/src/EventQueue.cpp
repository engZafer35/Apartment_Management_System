/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 4:25:10 PM
* #File Name    : EventQueue.cpp 
* #File Path    : /GezGör/Application/src/EventQueue.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventQueue.hpp"
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
/** \brief constructor */
EventQueue::EventQueue(void)
{}

/** \brief throw event */
EventMsg *EventQueue::waithEvent(U32 timeoutMs, U32 eventSource)
{
    EventMsg *retEvent = NULL_PTR;

    return retEvent;
}

/** \brief throw event */
RETURN_STATUS EventQueue::throwEvent(EventMsg *event)
{
    RETURN_STATUS retVal = RET_SUCCECC;

    event->m_queueNum = 0; // TODO: set queue number

    return retVal;
}

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(U32 queNum)
{
    RETURN_STATUS retVal = RET_SUCCECC;

    return retVal;
}

/** \brief delete all event that have same event ID */
RETURN_STATUS EventQueue::deleteEvents(EVENTS eventID)
{
    RETURN_STATUS retVal = RET_SUCCECC;

    return retVal;
}

/** \brief delete all pending events*/
RETURN_STATUS EventQueue::deleteAllEvent(void)
{
    RETURN_STATUS retVal = RET_SUCCECC;

    return retVal;
}

}//namespace event

/******************************** End Of File *********************************/
