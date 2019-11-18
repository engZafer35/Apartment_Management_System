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
#include "ITimer.hpp"
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
class TimerLinux : public ITimer, private NonCopyable
{
public:
    ~TimerLinux(void);

    /** \brief get instance, singleton class*/
    static TimerLinux* getInstance(void);

    /** \brief init TimerLinux */
    RETURN_STATUS init(void) override;

    /**
     * \brief Delay ms
     * \param time ms
     */
    void delayMs(U32 timeMs) const override;

    /**
     * \brief  Get system tick counter value
     * \return current system tick counter value
     */
    U32 getSysTickCounter(void) const override;

private:
     TimerLinux(void);

private:
     static TimerLinux* m_instance;

};

}//namespace platform
#endif /* __TIMER_LINUX_HPP__ */

/********************************* End Of File ********************************/
