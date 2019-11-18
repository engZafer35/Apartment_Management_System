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
namespace platform
{
AdcLinux* AdcLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
AdcLinux::AdcLinux(void)
{

}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
AdcLinux::~AdcLinux(void)
{
    m_instance = NULL_PTR;
}
AdcLinux* AdcLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new AdcLinux();
    }
    return m_instance;
}

/** \brief init ADC channel */
RETURN_STATUS AdcLinux::init(void)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

/** \brief read ADC value */
U32 AdcLinux::read(void)
{
    return 666;
}


}//namespace platform
/******************************** End Of File *********************************/
