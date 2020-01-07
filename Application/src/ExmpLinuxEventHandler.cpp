/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 2:35:36 PM
* #File Name    : ExmpLinuxEventHandler.cpp
* #File Path    : /GezGor/Application/src/ExmpLinuxEventHandler.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "ExmLinuxEventHandler.hpp"
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
RETURN_STATUS ExmLinuxEventHandler::handleEvent(event::EventMsg &event)
{
    switch(event.getEvent())
    {
        case event::EN_EVENT_TIMEOUT_TIMER:
        {
            ZLOG << "event::EN_EVENT_TIMEOUT_TIMER:";
            break;
        }

        case event::EN_EVENT_PER_JOB_1:
        {
            ZLOG << "event::EN_EVENT_PER_JOB_1:";
            break;
        }

        case event::EN_EVENT_PER_JOB_2:
        {
            ZLOG << "event::EN_EVENT_PER_JOB_2:";
            break;
        }

        case event::EN_EVENT_NO_EVENT:
        default:
        {break;}
    }
    return OK;
}
/******************************** End Of File *********************************/
