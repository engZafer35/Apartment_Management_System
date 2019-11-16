/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:36:37 PM
* #File Name    : IFileSystem.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IFileSystem.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IFILESYSTEM_HPP__
#define __IFILESYSTEM_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "Singleton.hpp"
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
class IFileSystem
{
public:
    virtual ~IFileSystem(void){}

    virtual RETURN_STATUS init(void) = 0;

    virtual RETURN_STATUS open(void) = 0;

    virtual RETURN_STATUS close(void) = 0;

    virtual U32 write(const void *buff, U32 len) = 0;

    virtual U32 read(void *buff, U32 len) = 0;

    virtual RETURN_STATUS seek(void) = 0;

    virtual RETURN_STATUS rename(void) = 0;
};
}//namespace platform

#endif /* __IFILESYSTEM_HPP__ */

/********************************* End Of File ********************************/
