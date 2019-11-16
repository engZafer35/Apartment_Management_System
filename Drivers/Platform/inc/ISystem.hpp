/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:34:33 PM
* #File Name    : ISystem.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/ISystem.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __DRIVERS_PLATFORM_INC_ISYSTEM_HPP__
#define __DRIVERS_PLATFORM_INC_ISYSTEM_HPP__
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
class ISystem
{
public:
    virtual ~ISystem(void){}

    /** \brief update system */
    virtual RETURN_STATUS update(void) = 0;

    /** \brief restart */
    virtual void restart(void) = 0;

    /** \brief enter sleep mode */
    virtual void sleepMode(void) = 0;
};
}//namespace platform
#endif /* __DRIVERS_PLATFORM_INC_ISYSTEM_HPP__ */

/********************************* End Of File ********************************/
