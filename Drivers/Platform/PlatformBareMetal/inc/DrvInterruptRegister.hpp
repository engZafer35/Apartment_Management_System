/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 19, 2019 - 4:10:52 PM
* #File Name    : DrvInterruptRegister.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/DrvInterruptRegister.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __DRV_INTERRUPT_REGISTER_HPP__
#define __DRV_INTERRUPT_REGISTER_HPP__

#ifdef __cplusplus
extern "C" {
#endif
/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/
typedef void (*SelectCb)(int fd);

typedef struct _SelectStruct
{
    int      fd;
    SelectCb Vcb;
} SelectStruct;

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
 * \brief register interrupt
 */
int drvIntRegisterInit(void);

int drvIntRegisterFd(SelectStruct selectStruct);

int drvIntUnregisterFd(int fd);
/********************************* CLASS **************************************/
#ifdef __cplusplus
}
#endif
#endif /* __DRV_INTERRUPT_REGISTER_HPP__ */

/********************************* End Of File ********************************/
