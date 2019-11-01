/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 1, 2019 - 10:54:57 AM
* #File Name    : LinuxPlatformUtil.hpp
* #File Path    : /GezGor/Application/inc/LinuxPlatformUtil.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LINUX_PLATFORM_UTIL_HPP__
#define __LINUX_PLATFORM_UTIL_HPP__
/*********************************INCLUDES*************************************/
#include <mutex>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class Mutex
{
public:
    Mutex(void){}

    virtual ~Mutex(void){}

public:
    void _lock(void)
    {
        mtx.lock();
    }

    void _unlock(void)
    {
        mtx.unlock();
    }

private:
    std::mutex mtx;
};
}//namespace platform
#endif /* __LINUX_PLATFORM_UTIL_HPP__ */

/********************************* End Of File ********************************/
