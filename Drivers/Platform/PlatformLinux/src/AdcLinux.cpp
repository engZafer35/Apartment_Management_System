/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:51:35 PM
* #File Name    : AdcLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/AdcLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#ifdef __linux
/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "AdcLinux.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
AdcLinux::AdcLinux(void) : m_adcPort{0}, m_adcChnl{0}
{}

AdcLinux::~AdcLinux(void)
{}

/** \brief init ADC channel */
RETURN_STATUS AdcLinux::init(void)
{
    RETURN_STATUS retVal = OK;
    ZLOGF_IF(FAILURE == retVal) << "[E] AdcLinux init Error: !!";
    return retVal;
}

/** \brief read ADC value */
U32 AdcLinux::read(void)
{
    //TODO: implement
    return 666;
}

}//namespace platform
#endif//#ifdef __linux
/******************************** End Of File *********************************/
