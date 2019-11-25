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
#if (CURRENT_PLATFORM == PLATFORM_LINUX_PC)
#include "ZLogger.h" //TODO: complete ZLogger for bare metal
#endif

#include "GlobalDefinitions.hpp"
#include "IDevices.hpp"
#include "IConsole.hpp"
#include "ISystem.hpp"
#include "IFileSystem.hpp"

#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)

#include <iostream> //todo

#define ZLOG std::cout << "\n\r", std::cout //todo
#define ZLOGW std::cout << "\n\r",std::cout //todo
#define ZLOGF std::cout << "\n\r",std::cout //todo
#define ZLOGV_IF(X) std::cout << "\n\r", std::cout //todo
#define ZLOGF_IF(X) std::cout << "\n\r", std::cout //todo

//#include "DevicesBareMetal.hpp"
//#include "ConsoleBareMetal.hpp"

#endif
/**************************************************/

/**************************************************/


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
    IDevices * const devices = DevicesBareMetal::getInstance(); /** < All platform devices */
    IConsole * const console = ConsoleBareMetal::getInstance(); /** < Manage system console */
    ISystem  * const system  = NULL_PTR;                    /** < Manage system status */
    IFileSystem * const fileSys = NULL_PTR;                 /** < Platform file system */
#endif

private:
    Platform(void);

private:
    static Platform* m_instance;
};

}//namespace platform
#endif /* __PLATFORM_INTERFACE_HPP__ */

/********************************* End Of File ********************************/
