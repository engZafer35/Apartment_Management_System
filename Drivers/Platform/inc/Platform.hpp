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
#include "Singleton.hpp"
#include "Utility.hpp"

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

class Platform : public Singleton<Platform>
{
public:
    IDevices    *devices;
    IConsole    *console;
    ISystem     *system;
    IFileSystem *fileSys;

public:
    RETURN_STATUS openDevices(void);
};

}//namespace platform
#endif /* __PLATFORM_INTERFACE_HPP__ */

/********************************* End Of File ********************************/
