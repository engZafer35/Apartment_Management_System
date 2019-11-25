/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:24:42 PM
* #File Name    : GpioBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/inc/GpioBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __GPIO_BARE_METAL_HPP__
#define __GPIO_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
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
class GpioBareMetal : public IGPIO, private NonCopyable
{
public:
    ~GpioBareMetal(void);

    /** \brief get instance, singleton class*/
    static GpioBareMetal* getInstance(void);

    /** init all gpio */
    RETURN_STATUS init(void) override;

    /** read gpio*/
    BOOL read(void) override;

    /** write gpio*/
    RETURN_STATUS write(BOOL status) override;

    /** set callback function for external interrupt*/
    void setCB(VoidCallback cbFunc) override;

private:
     GpioBareMetal(void);

private:
     static GpioBareMetal* m_instance;
};

}//namespace platform

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#endif /* __GPIO_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
