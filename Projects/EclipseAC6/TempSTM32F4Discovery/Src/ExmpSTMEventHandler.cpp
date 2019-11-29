/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 29, 2019 - 10:43:53 AM
* #File Name    : ExmpSTMEventHandler.cpp 
* #File Path    : /GezGor/Application/src/ExmpSTMEventHandler.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "ExmpSTMEventHandler.hpp"
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
/***************************** CLASS PUBLIC METHOD ****************************/
RETURN_STATUS ExmpSTMEventHandler::handleEvent(event::EventMsg &event)
{
    switch(event.getEvent())
    {
        case event::EN_EVENT_TIMEOUT_TIMER:
        {
            HAL_GPIO_TogglePin(Led1_GPIO_Port, Led1_Pin);
            ZLOG << "event::EN_EVENT_TIMEOUT_TIMER:";
            break;
        }

        case event::EN_EVENT_PER_JOB_1:
        {
            HAL_GPIO_TogglePin(Led2_GPIO_Port, Led2_Pin);
            ZLOG << "event::EN_EVENT_PER_JOB_1:";
            break;
        }

        case event::EN_EVENT_PER_JOB_2:
        {
            HAL_GPIO_TogglePin(Led3_GPIO_Port, Led3_Pin);
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
