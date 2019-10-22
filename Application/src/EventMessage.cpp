/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 4:36:16 PM
* #File Name    : EventMessage.cpp 
* #File Path    : /GezGör/Application/src/EventMessage.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
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
EventMsg::EventMsg(EVENTS event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *value, U32 leng)
                   : m_event{event}, m_source{source}, m_priority{priority}, m_value{value}, m_leng{leng}, m_queueNum{-1}
{

}

EVENTS EventMsg::getEvent(void) const
{
    return m_event;
}

EVENT_SOURCE EventMsg::getEventSource(void) const
{
    return m_source;
}

EVENT_PRIORITY EventMsg::getEventPriority(void) const
{
    return m_priority;
}

void* EventMsg::getValue(void)
{
    return m_value;
}


U32 EventMsg::getLeng(void) const
{
    return m_leng;
}

U32 EventMsg::getQueueNum(void) const
{
    return m_queueNum;
}

///** \brief set queue number */
//void EventMsg::setQueueNum(S32 num)
//{
//    m_queueNum = num;
//}

}//namespace event

/******************************** End Of File *********************************/
