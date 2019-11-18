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
#include "ICommPeripheral.hpp"
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
class UartLinux : public ICommPeripheral, private NonCopyable
{
public:
    ~UartLinux(void);

    /** \brief get instance, singleton class*/
    static UartLinux* getInstance(void);

    /** \brief init uart*/
    RETURN_STATUS init(void) override;

    /** \brief send data*/
    RETURN_STATUS send(const void *buff, U32 size, U32 timeout) override;

    /** \brief receive data*/
    RETURN_STATUS receive(void *buff, U32 size, U32 timeout) override;

private:
    UartLinux(void);

    /** \brief hardware receive interrupt callback function */
    void cbReceive(void) override;

    /** \brief hardware send interrupt callback function */
    void cbSend(void) override;

private:
    static UartLinux* m_instance;
};

}//namespace platform
#endif /* __UART_LINUX_HPP__ */

/********************************* End Of File ********************************/
