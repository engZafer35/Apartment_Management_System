/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:08:29 PM
* #File Name    : UartBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/inc/UartBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UART_BARE_METAL_HPP__
#define __UART_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
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
class UartBareMetal : public ICommPeripheral, private NonCopyable
{
public:
    ~UartBareMetal(void);

    /** \brief get instance, singleton class*/
    static UartBareMetal* getInstance(void);

    /** \brief init uart*/
    RETURN_STATUS init(void) override;

    /** \brief send data*/
    RETURN_STATUS send(const void *buff, U32 size, U32 timeout) override;

    /** \brief receive data*/
    RETURN_STATUS receive(void *buff, U32 size, U32 timeout) override;

private:
    UartBareMetal(void);

    /** \brief hardware receive interrupt callback function */
    void cbReceive(void) override;

    /** \brief hardware send interrupt callback function */
    void cbSend(void) override;

private:
    static UartBareMetal* m_instance;
};

}//namespace platform

#endif// #if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#endif /* __UART_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
