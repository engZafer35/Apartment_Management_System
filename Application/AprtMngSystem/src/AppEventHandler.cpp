/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 4:15:01 PM
* #File Name    : AppEventHandler.cpp 
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/src/AppEventHandler.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
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

AppEventHandler::AppEventHandler(void)
{}

AppEventHandler::~AppEventHandler(void)
{}

RETURN_STATUS AppEventHandler::handleEvent(event::EventMsg &event)
{
    RETURN_STATUS retVal = OK;

    switch(event.getEvent())
    {
        case event::EN_EVENT_PER_JOB_1:
        {
            ZLOG << " >[I] AppEventHandler::EN_EVENT_PER_JOB_1" << "\n";
            break;
        }
        case event::EN_EVENT_PER_JOB_2:
        {
            ZLOG << " >[I] AppEventHandler::EN_EVENT_PER_JOB_2" << "\n";
            break;
        }
        default:
            break;
    }

    return retVal;
}

}//namespace redbird
/******************************** End Of File *********************************/
