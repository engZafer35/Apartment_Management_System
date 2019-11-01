/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 1, 2019 - 11:32:01 AM
* #File Name    : BoardConfig_ZBM010.hpp
* #File Path    : /GezGor/Application/inc/BoardConfig_ZBM010.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APPLICATION_INC_BOARDCONFIG_ZBM010_HPP__
#define __APPLICATION_INC_BOARDCONFIG_ZBM010_HPP__
/*****************************************************************************/
namespace platform
{
#define BOARD_NAME              "GEZGOR-MOTION"
#define BOARD_VERSION           "V0.1.0"
#define BOARD_FILE_NAME         "BoardConfig_ZBMP010.hPP"
#define WORKING_PLATFORM_PC     (001)
#define _WORKING_PLATFORM       WORKING_PLATFORM_STM
#define _PLATFORM_NAME          "Bare-Metal_STM"
#define _MCU_BIT_SIZE           (32)
#define MCU_CORE                "CORTEX-M4"
#define MCU_PART_NUM            "STM32F405RGT6"
#define BARE_METAL

}//namespace board

/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __APPLICATION_INC_BOARDCONFIG_ZBM010_HPP__ */

/********************************* End Of File ********************************/
