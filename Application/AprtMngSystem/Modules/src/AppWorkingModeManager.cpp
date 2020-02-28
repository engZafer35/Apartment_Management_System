/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 3:22:31 PM
* #File Name    : AppWorkingModeManager.cpp 
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/Modules/src/src/AppWorkingModeManager.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "AppWorkingModeManager.hpp"
#include "EventPool.hpp"
/****************************** MACRO DEFINITIONS *****************************/
/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/
namespace redbird
{
WorkingMode::SYSTEM_MODE WorkingMode::m_mode = EN_MODE_WORKING;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace redbird
{
RETURN_STATUS WorkingMode::setWorkingMode(void)
{
    RETURN_STATUS retVal = OK;
    return retVal;
}

RETURN_STATUS WorkingMode::setMaintenanceMode(void)
{
    RETURN_STATUS retVal = OK;
    return retVal;
}

RETURN_STATUS WorkingMode::setFailureMode(void)
{
    RETURN_STATUS retVal = OK;
    return retVal;
}
}//namespace redbird
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace redbird
{
WorkingMode::WorkingMode(void)
{}

WorkingMode::~WorkingMode(void)
{}

RETURN_STATUS WorkingMode::setMode(SYSTEM_MODE mode)
{
    RETURN_STATUS retVal = FAILURE;
    event::EventPool *eventPool = EVENT_POOL();

    switch(mode)
    {
        case EN_MODE_WORKING:
        {
            eventPool->eventQueue->deleteEvents(event::EN_SOURCE_CB_TIMER);
            eventPool->eventQueue->deleteEvents(event::EN_SOURCE_EXT_BOAR);
            eventPool->eventQueue->deleteEvents(event::EN_SOURCE_SERIAL_LINE);

            //todo load job, load event handler

            break;
        }
        case EN_MODE_MAINTENANCE:
        {
            break;
        }
        case EN_MODE_FAILURE:
        {
            break;
        }
    }

    if (OK == retVal)
    {
        m_mode = mode;
    }

    return retVal;
}

}//namespace redbird
/******************************** End Of File *********************************/
