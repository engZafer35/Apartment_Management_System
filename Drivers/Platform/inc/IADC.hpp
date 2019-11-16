/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:40:05 PM
* #File Name    : IADC.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/IADC.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IADC_HPP__
#define __IADC_HPP__
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
 * \brief interface class for ADC
 */
class IADC
{
public:
    virtual ~IADC(void){}

    /** \brief init ADC channel */
    virtual RETURN_STATUS init(void) = 0;

    /** \brief read ADC value */
    virtual U32 read(void) = 0;
};

}//namespace platform
#endif /* __IADC_HPP__ */

/********************************* End Of File ********************************/
