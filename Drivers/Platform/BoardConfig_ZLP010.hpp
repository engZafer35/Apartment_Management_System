/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 31, 2019 - 3:21:13 PM
* #File Name    : BoardConfig_ZLP010.hpp
* #File Path    : /GezGor/Application/inc/BoardConfig_ZLP010.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __BOARD_CONFIG_ZLP010_HPP__
#define __BOARD_CONFIG_ZLP010_HPP__
/******************************************************************************/
namespace platform
{
#define BOARD_NAME              "GEZGOR-MOTION"
#define BOARD_VERSION           "V0.1.0"
#define BOARD_FILE_NAME         "BoardConfig_ZLP010.hPP"
#define WORKING_PLATFORM_PC     (001)
#define _WORKING_PLATFORM       WORKING_PLATFORM_PC
#define _PLATFORM_NAME          "LINUX-PC"
#define _MCU_BIT_SIZE           (64)
#define MCU_CORE                "Linux-PC"
#define MCU_PART_NUM            "Linux-PC"
#define LINUX_PLATFORM

}//namespace platform

/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/
namespace platform
{
typedef enum
{
    EN_TIMER_1,
    EN_TIMER_2,
    EN_TIMER_3
}SYSTEM_TIMERS;
}//namespace platform
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __BOARD_CONFIG_ZLP010_HPP__ */

/********************************* End Of File ********************************/
