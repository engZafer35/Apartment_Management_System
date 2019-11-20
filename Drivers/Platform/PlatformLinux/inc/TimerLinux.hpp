/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 12:43:24 PM
* #File Name    : TimerLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/TimerLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_LINUX_HPP__
#define __TIMER_LINUX_HPP__
/*********************************INCLUDES*************************************/
#ifdef __linux

#include <unistd.h>
#include "ITimer.hpp"

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class TimerLinux : public ITimer, private NonCopyable
{
#define TIMER_CHECK_CYCLE    (100) //hardware timer period Ms
public:
    ~TimerLinux(void);

    /** \brief get instance, singleton class*/
    static TimerLinux* getInstance(void);

    /** \brief init TimerLinux */
    RETURN_STATUS init(void) override;

private:
     TimerLinux(void);

private:
     static TimerLinux* m_instance;
};

}//namespace platform

#endif
#endif /* __TIMER_LINUX_HPP__ */

/********************************* End Of File ********************************/
