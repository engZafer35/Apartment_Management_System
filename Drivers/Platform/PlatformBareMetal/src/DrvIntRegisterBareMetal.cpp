/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 19, 2019 - 4:10:52 PM
* #File Name    : DrvIntRegisterBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/DrvIntRegisterBareMetal.cpp
*******************************************************************************/

/*********************************INCLUDES*************************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "DrvInterruptRegister.hpp"
#include "TimerBareMetal.hpp"

/******************************MACRO DEFINITIONS*******************************/
#define NUMBER_OF_FDS  (20)
#define INVALID_FD     (-1)

#define DEBUG_SELECT   (0)
/*******************************TYPE DEFINITIONS ******************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/**********************************VARIABLES***********************************/

/*****************************PRIVATE FUNCTIONS********************************/

/*******************************PUBLIC FUNCTIONS*******************************/

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)
    {
        platform::TimerBareMetal::getInstance()->runCallback();
    }
}

int drvIntRegisterInit(void)
{
    HAL_TIM_Base_Start_IT(&htim6);
    return OK;
}

int drvIntRegisterFd(SelectStruct selectStruct)
{

    return  OK;
}

int drvIntUnregisterFd(int fd)
{


    return  OK;
}

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
