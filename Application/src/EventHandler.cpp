/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 10:50:00 AM
* #File Name    : EventHandler.cpp 
* #File Path    : /GezGor/Application/src/EventHandler.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventHandler.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/
namespace event
{
/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/
EventHandler::EventHandler(IEventInterpreter &interpreter) : m_interpreter{interpreter}, m_mode{EN_WORKING_MODE_NORMAL}
{}

RETURN_STATUS EventHandler::handleEVent(EventMsg &event)
{
    RETURN_STATUS retVal = OK;

    switch(m_mode)
    {
        case EN_WORKING_MODE_NORMAL:
        {
            m_interpreter.handleEvent(event);
            break;
        }

        case EN_WORKING_MODE_BLACKOUT:
        {
            break;
        }

        case EN_WORKING_MODE_SW_UPDATE:
        {
            break;
        }

        case EN_WORKING_MODE_MAINTENCE:
        {
            break;
        }
    }

    return retVal;
}

void EventHandler::setWorkingMode(enum WORKING_MODE mode)
{
    m_mode = mode;
}

/***************************** CLASS PUBLIC METHOD ****************************/
}//namespace event
/******************************** End Of File *********************************/
