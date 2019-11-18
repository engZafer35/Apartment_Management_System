/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:48:19 PM
* #File Name    : AdcLinux.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/inc/AdcLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ADC_LINUX_HPP__
#define __ADC_LINUX_HPP__
/*********************************INCLUDES*************************************/
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
class AdcLinux : public IADC, private NonCopyable
{
public:
    ~AdcLinux(void);

    /** \brief get instance, singleton class*/
    static AdcLinux* getInstance(void);

    /** \brief init ADC channel */
    RETURN_STATUS init(void) override;

    /** \brief read ADC value */
    U32 read(void) override;

private:
    AdcLinux(void);

private:
    static AdcLinux* m_instance;

};
}//namespace platform
#endif /* __ADC_LINUX_HPP__ */

/********************************* End Of File ********************************/
