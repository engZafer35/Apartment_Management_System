/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:23:14 PM
* #File Name    : ConsoleLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/ConsoleLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __CONSOLE_LINUX_HPP__
#define __CONSOLE_LINUX_HPP__
/*********************************INCLUDES*************************************/
#ifdef __linux
#include "IConsole.hpp"
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
 * \brief Manage Linux console
 */
class ConsoleLinux : public IConsole, private NonCopyable
{
public:
    ~ConsoleLinux(void);

    /** \brief get instance, singleton class*/
    static ConsoleLinux* getInstance(void);

    /** \brief init console */
    RETURN_STATUS init(void) override;

    /**
     * \brief set console status
     * \param set TRUE to active console
     */
    RETURN_STATUS consoleStatus(BOOL status) override;

private:
    ConsoleLinux(void);

private:
    static ConsoleLinux* m_instance;
};

}//namespace platform
#endif//#ifdef __linux
#endif /* __CONSOLE_LINUX_HPP__ */

/********************************* End Of File ********************************/
