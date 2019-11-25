/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:35:48 PM
* #File Name    : GpioLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/GpioLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#ifdef __linux
/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "GpioLinux.hpp"
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
GpioLinux* GpioLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
GpioLinux::GpioLinux(void)
{

}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
GpioLinux::~GpioLinux(void)
{
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
GpioLinux* GpioLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new GpioLinux();
    }
    return m_instance;
}

/** init all gpio */
RETURN_STATUS GpioLinux::init(void)
{
    RETURN_STATUS retVal = OK;
    ZLOGF_IF(FAILURE == retVal) << "GpioLinux init Error";
    return retVal;
}

/** read gpio*/
BOOL GpioLinux::read(void)
{
    BOOL retVal = TRUE;

    return retVal;
}

/** write gpio*/
RETURN_STATUS GpioLinux::write(BOOL status)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

/** set callback function for external interrupt*/
void GpioLinux::setCB(VoidCallback cbFunc)
{

}

}//namespace platform
#endif//#ifdef __linux
/******************************** End Of File *********************************/
