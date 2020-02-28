/******************************************************************************
*                       "THE BEER-WARE LICENSE" (Revision 2020)
* ZS wrote this file. As long as you retain this notice you can do whatever
* you want with this stuff. If we meet some day, and you think this stuff
* is worth it, you can buy me a beer in return
*
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:43:17 PM
* #File Name    : main.cpp 
* #File Path    : /GezGor/Application/src/main.cpp
*******************************************************************************/
/******************************************************************************
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ExmLinuxEventHandler.hpp"
#include "ProjectConf.hpp"

#include "AppRedBirdLoop.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
int main(void)
{
    //    zlogger::loggerInit(zlogger::EN_LOG_LEVEL_VERBOSE); //Firstly Init logger

        platform::Platform *platform = platform::Platform::getInstance();

        if (OK == platform->buildPlatform())
        {
            ZLOGW << "[I] Building Platform SUCCESS, Thanks $$$";

            redbird::AppRedBird redBird(*platform);

            if (OK == redBird.eggs())
            {
                redBird.fly();
            }
        }
        else
        {
            ZLOGF << "[E] Building Platform Error !!!";
        }

    return 0;
}
/******************************** End Of File *********************************/
