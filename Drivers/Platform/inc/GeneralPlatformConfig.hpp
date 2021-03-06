/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 31, 2019 - 3:02:23 PM
* #File Name    : GeneralBoardConfig.hpp
* #File Path    : /GezGor/Drivers/Platform/GeneralPlatformConfig.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __GENERAL_PLATFORM_CONFIG_HPP__
#define __GENERAL_PLATFORM_CONFIG_HPP__

/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/
#define PLATFORM_LINUX_PC       (1)
#define PLATFORM_LINUX_EMB      (2)
#define PLATFORM_FREERTOS       (3)
#define PLATFORM_BARE_METAL     (4)
/* add new platform, don't change queue*/

/** ******* < select platform > ******* */
#ifdef __linux
#define CURRENT_PLATFORM    (PLATFORM_LINUX_PC)
#else
#define CURRENT_PLATFORM    (PLATFORM_BARE_METAL)
#endif

#if (CURRENT_PLATFORM == PLATFORM_LINUX_PC)
    #include "PlatformLinuxPC.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_LINUX_EMB)
    #include "BoardConfig_ZLE010.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
    #include "PlatformBareMetal.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_FREERTOS)
    #include "BoardConfig_ZFR010.hpp"
#else
    #error "!!! Current Platform is undefined. Check GeneralBoardConfig.h file !!!"
#endif

#include "Platform.hpp"

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __GENERAL_PLATFORM_CONFIG_HPP__ */

/********************************* End Of File ********************************/
