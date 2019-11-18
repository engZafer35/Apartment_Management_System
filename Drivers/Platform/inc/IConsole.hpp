/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:33:30 PM
* #File Name    : IConsole.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IConsole.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ICONSOLE_HPP__
#define __ICONSOLE_HPP__
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
class IConsole
{
public:
    virtual ~IConsole(void){}

    /** \brief init console */
    virtual RETURN_STATUS init(void) = 0;

    /**
     * \brief set console status
     *  \param set TRUE to active console
     */
    virtual RETURN_STATUS consoleStatus(BOOL status) = 0;
};
}//namespace platform

#endif /* __ICONSOLE_HPP__ */
/********************************* End Of File ********************************/
