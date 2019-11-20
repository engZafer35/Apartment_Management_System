/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:37:47 PM
* #File Name    : IClock.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IClock.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __DRIVERS_PLATFORM_INC_ICLOCK_HPP__
#define __DRIVERS_PLATFORM_INC_ICLOCK_HPP__
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
 *  \brief interface class for MCU clock
 */
class IClock
{
public:
    virtual ~IClock(void){}
    /** \brief init mcu clock */
    virtual RETURN_STATUS init(void) = 0;
};

}//namespace platform

#endif /* __DRIVERS_PLATFORM_INC_ICLOCK_HPP__ */

/********************************* End Of File ********************************/
