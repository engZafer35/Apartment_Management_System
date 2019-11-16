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
/**
 * \brief interface class for hardware timer
 */
class ITimer
{
public:
    virtual ~ITimer(void){}

    virtual RETURN_STATUS init(void) = 0;

    virtual void loadCallback(VoidCallback cbFunc) = 0;

    U32 getPeriod(void);

protected:
    U32 m_hwTimerPeriod;
};
}//namespace platform

#endif /* __ITIMER_HPP__ */

/********************************* End Of File ********************************/
