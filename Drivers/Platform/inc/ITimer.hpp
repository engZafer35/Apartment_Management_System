/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:42:25 PM
* #File Name    : ITimer.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/ITimer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ITIMER_HPP__
#define __ITIMER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
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
 * \brief interface class for hardware timer
 */
class ITimer
{
public:
    virtual ~ITimer(void){}

    virtual RETURN_STATUS init(void) = 0;

    inline void callback(VoidCallback cbFunc) {m_cbFunc = cbFunc;}

    inline U32 getPeriod(void) const {return m_hwTimerPeriod;}

    /**
     * \brief Delay ms
     * \param time ms
     */
    virtual void delayMs(U32 timeMs) const = 0;

    /**
     * \brief  Get system tick counter value
     * \return current system tick counter value
     */
    virtual U32 getSysTickCounter(void) const = 0;

protected:
    U32 m_hwTimerPeriod;
    VoidCallback m_cbFunc;
};
}//namespace platform

#endif /* __ITIMER_HPP__ */

/********************************* End Of File ********************************/
