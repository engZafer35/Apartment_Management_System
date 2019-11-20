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
#include "ZLogger.h"
#include "GlobalDefinitions.hpp"

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

class Platform
{
public:
    ~Platform(void);

    /** \brief get instance, singleton class*/
    static Platform* getInstance(void);

    /**
     * \brief  build platform
     * \return if everything is OK, return SUCCES
     *         otherwise return FAILURE
     * \note:  In failure case don't run application
     */
    RETURN_STATUS buildPlatform(void);

public:
#if (CURRENT_PLATFORM == PLATFORM_LINUX_PC)
    IDevices * const devices = DevicesLinux::getInstance(); /** < All platform devices */
    IConsole * const console = ConsoleLinux::getInstance(); /** < Manage system console */
    ISystem  * const system  = NULL_PTR;                    /** < Manage system status */
    IFileSystem * const fileSys = NULL_PTR;                 /** < Platform file system */

#elif (CURRENT_PLATFORM == PLATFORM_LINUX_EMB)

#elif (CURRENT_PLATFORM == PLATFORM_FREERTOS)

#elif (CURRENT_PLATFORM == PLATFORM_BARE_METAL)

#endif

private:
    Platform(void);

private:
    static Platform* m_instance;
};

}//namespace platform
#endif /* __PLATFORM_INTERFACE_HPP__ */

/********************************* End Of File ********************************/
