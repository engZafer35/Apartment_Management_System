/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 2:35:36 PM
* #File Name    : MyEventInterpreter.cpp 
* #File Path    : /GezGor/Application/src/MyEventInterpreter.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "MyEventInterpreter.hpp"
#include "ProjectConf.hpp"
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
RETURN_STATUS MyEventInterpreter::handleEvent(event::EventMsg &event)
{
    switch(event.getEvent())
    {
        case event::EN_EVENT_TIMEOUT_TIMER:
        {
            ZLOG << "event::EN_EVENT_TIMEOUT_TIMER:";
            HAL_GPIO_TogglePin(Led1_GPIO_Port, Led1_Pin);
            break;
        }

        case event::EN_EVENT_PER_JOB_1:
        {
            ZLOG << "event::EN_EVENT_PER_JOB_1:";
            HAL_GPIO_TogglePin(Led2_GPIO_Port, Led2_Pin);
            break;
        }

        case event::EN_EVENT_PER_JOB_2:
        {
            ZLOG << "event::EN_EVENT_PER_JOB_2:";
            HAL_GPIO_TogglePin(Led3_GPIO_Port, Led3_Pin);
            break;
        }

        case event::EN_EVENT_NO_EVENT:
        default:
        {break;}
    }
    return OK;
}
/******************************** End Of File *********************************/
