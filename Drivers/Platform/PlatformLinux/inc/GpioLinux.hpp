/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:24:42 PM
* #File Name    : GpioLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/GpioLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __GPIO_LINUX_HPP__
#define __GPIO_LINUX_HPP__
/*********************************INCLUDES*************************************/
#include "IGPIO.hpp"
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
class GpioLinux : public IGPIO, private NonCopyable
{
public:
    ~GpioLinux(void);

    /** \brief get instance, singleton class*/
    static GpioLinux* getInstance(void);

    /** init all gpio */
    RETURN_STATUS init(void) override;

    /** read gpio*/
    BOOL read(void) override;

    /** write gpio*/
    RETURN_STATUS write(BOOL status) override;

    /** set callback function for external interrupt*/
    void setCB(VoidCallback cbFunc) override;

private:
     GpioLinux(void);

private:
     static GpioLinux* m_instance;

};
}//namespace platform

#endif /* __GPIO_LINUX_HPP__ */

/********************************* End Of File ********************************/
