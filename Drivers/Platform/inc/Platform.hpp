/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 11, 2019 - 1:21:34 PM
* #File Name    : Platform.hpp
* #File Path    : /GezGor/Drivers/Platform/Platform.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __PLATFORM_INTERFACE_HPP__
#define __PLATFORM_INTERFACE_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"

#if (CURRENT_PLATFORM == PLATFORM_LINUX_PC)
    #include "PlatformLinuxPC.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_LINUX_EMB)
    #include "BoardConfig_ZLE010.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
    #include "PlatformBareMetal.hpp"
#elif (CURRENT_PLATFORM == PLATFORM_FREERTOS)
    #include "BoardConfig_ZFR010.hpp"
#endif

#include "IDevices.hpp"
#include "IConsole.hpp"
#include "ISystem.hpp"
#include "IFileSystem.hpp"

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{

class Platform //: public Singleton<Platform>
{
public:
    ~Platform(void);

    /** \brief get instance, singleton class*/
    static Platform* getInstance(void);

    RETURN_STATUS openDevices(void);

public:
    IDevices * const devices = DevicesLinux::getInstance();
    IConsole * const console = ConsoleLinux::getInstance();
    ISystem  * const system  = NULL_PTR;
    IFileSystem * const fileSys = NULL_PTR;

private:
    Platform(void);

private:
    static Platform* m_instance;
};

}//namespace platform
#endif /* __PLATFORM_INTERFACE_HPP__ */

/********************************* End Of File ********************************/
