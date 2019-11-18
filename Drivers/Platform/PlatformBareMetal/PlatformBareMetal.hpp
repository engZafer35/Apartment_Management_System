/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 1, 2019 - 11:30:48 AM
* #File Name    : PlatformBareMetal.hpp
* #File Path    : /GezGor/Application/inc/PlatformBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __PLATFORM_BARE_METAL_HPP__
#define __PLATFORM_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#include "BareMetalUtil.hpp"
#include "BoardConfig_ZBM010.hpp"

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
class HwTimer10Ms : public ITimer
{
     RETURN_STATUS init(void) override;

};

}//namespace platform



#endif /* __PLATFORM_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
