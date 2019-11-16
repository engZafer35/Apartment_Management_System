/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:43:48 PM
* #File Name    : IDevices.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IDevices.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IDEVICES_HPP__
#define __IDEVICES_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "Singleton.hpp"
#include "Utility.hpp"

#include "IClock.hpp"
#include "ICommPeripheral.hpp"
#include "IADC.hpp"
#include "IGPIO.hpp"
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
/**
 * \brief All system devices will created in this class
 */
class IDevices
{
public:
    virtual ~IDevices(void){}
    virtual RETURN_STATUS openDevices(void) = 0;

public:
    IClock          *clock;
    ICommPeripheral *uart;
    IADC            *adc;
    IGPIO           *gpio;
    ITimer          *timer;
};
}//namespace platform
#endif /* __IDEVICES_HPP__ */

/********************************* End Of File ********************************/
