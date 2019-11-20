/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:16:29 PM
* #File Name    : DevicesLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/DevicesLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __DEVICES_LINUX_HPP__
#define __DEVICES_LINUX_HPP__
/*********************************INCLUDES*************************************/
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
#ifdef __linux
/**
 * \brief Linux Pc peripheral devices, Singleton Class
 */
class DevicesLinux : public IDevices, private NonCopyable
{
public:
    ~DevicesLinux(void);

    /** brief Open devices to use it */
    RETURN_STATUS openDevices(void) override;

public:
    /** \brief get instance, singleton class*/
    static DevicesLinux* getInstance(void);

private:
    DevicesLinux(void);

private:
    static DevicesLinux* m_instance;
    BOOL isDevicesInit;
};
#endif
}//namespace platform
#endif /* __DEVICES_LINUX_HPP__ */

/********************************* End Of File ********************************/
