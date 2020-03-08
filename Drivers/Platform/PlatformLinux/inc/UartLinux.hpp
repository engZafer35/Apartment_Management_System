/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:08:29 PM
* #File Name    : UartLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/UartLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UART_LINUX_HPP__
#define __UART_LINUX_HPP__

/*********************************INCLUDES*************************************/
#ifdef __linux
#include "ISerialBus.hpp"
#include "Utility.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class UartLinux : public ISerialBus, private NonCopyable
{
public:
    UartLinux(void);
    ~UartLinux(void);

    /** \brief open uart*/
    RETURN_STATUS open(void) override;

    /** \brief close uart*/
    RETURN_STATUS close(void) override;

    /** \brief send data*/
    RETURN_STATUS send(const void *buff, U32 size, U32 timeout) override;

    /** \brief receive data*/
    RETURN_STATUS receive(void *buff, U32 size, U32 timeout) override;

private:


    /** \brief hardware receive interrupt callback function */
    void cbReceive(void) override;

    /** \brief hardware send interrupt callback function */
    void cbSend(void) override;

};

}//namespace platform
#endif// if __linux
#endif /* __UART_LINUX_HPP__ */

/********************************* End Of File ********************************/
