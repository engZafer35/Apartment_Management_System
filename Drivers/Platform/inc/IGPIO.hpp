/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:41:10 PM
* #File Name    : IGPIO.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IGPIO.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IGPIO_HPP__
#define __IGPIO_HPP__
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
 * \brief interface class for GPIO operations
 */
class IGPIO
{
public:
    virtual ~IGPIO(void){}

    /** init all gpio */
    virtual RETURN_STATUS init(void) = 0;

    /** read gpio*/
    virtual BOOL read(void) = 0;

    /** write gpio*/
    virtual RETURN_STATUS write(BOOL status) = 0;

    /** set callback function for external interrupt*/
    virtual void setCB(VoidCallback cbFunc) = 0;
};
}//namespace platform
#endif /* __IGPIO_HPP__ */

/********************************* End Of File ********************************/
