/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:48:19 PM
* #File Name    : AdcBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/AdcBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ADC_BARE_METAL_HPP__
#define __ADC_BARE_METAL_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "IADC.hpp"
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
class AdcBareMetal : public IADC, private NonCopyable
{
public:
    ~AdcBareMetal(void);

    /** \brief get instance, singleton class*/
    static AdcBareMetal* getInstance(void);

    /** \brief init ADC channel */
    RETURN_STATUS init(void) override;

    /** \brief read ADC value */
    U32 read(void) override;

private:
    AdcBareMetal(void);

private:
    static AdcBareMetal* m_instance;

};
}//namespace platform

#endif// #if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#endif /* __ADC_BARE_METAL_HPP__ */

/********************************* End Of File ********************************/
