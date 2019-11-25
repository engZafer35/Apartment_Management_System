/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:23:14 PM
* #File Name    : ConsoleBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/inc/ConsoleBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __CONSOLE_BARE_METAL_HPP__
#define __CONSOLE_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
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
class ConsoleBareMetal : public IConsole, private NonCopyable
{
public:
    ~ConsoleBareMetal(void);

    /** \brief get instance, singleton class*/
    static ConsoleBareMetal* getInstance(void);

    /** \brief init console */
    RETURN_STATUS init(void) override;

    /**
     * \brief set console status
     * \param set TRUE to active console
     */
    RETURN_STATUS consoleStatus(BOOL status) override;

private:
    ConsoleBareMetal(void);

private:
    static ConsoleBareMetal* m_instance;
};

}//namespace platform

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#endif /* __CONSOLE_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
