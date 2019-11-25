/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:16:29 PM
* #File Name    : DevicesBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/inc/DevicesBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __DEVICES_BARE_METAL_HPP__
#define __DEVICES_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "Utility.hpp"
#include "IDevices.hpp"

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
/**
 * \brief Linux Pc peripheral devices, Singleton Class
 */
class DevicesBareMetal : public IDevices, private NonCopyable
{
public:
    ~DevicesBareMetal(void);

    /** brief Open devices to use it */
    RETURN_STATUS openDevices(void) override;

public:
    /** \brief get instance, singleton class*/
    static DevicesBareMetal* getInstance(void);

private:
    DevicesBareMetal(void);

private:
    static DevicesBareMetal* m_instance;
    BOOL isDevicesInit;
};

}//namespace platform

#endif //#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#endif /* __DEVICES_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
