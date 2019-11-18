/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:18:56 PM
* #File Name    : DevicesLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/DevicesLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "DevicesLinux.hpp"

#include "TimerLinux.hpp"
#include "UartLinux.hpp"
#include "GpioLinux.hpp"
#include "AdcLinux.hpp"

#include <iostream>
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
DevicesLinux* DevicesLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
DevicesLinux::DevicesLinux(void) : isDevicesInit{FALSE}
{
    //create and load peripheral devices
    timer = TimerLinux::getInstance();
    uart  = UartLinux::getInstance();
    gpio  = GpioLinux::getInstance();
    adc   = AdcLinux::getInstance();
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
DevicesLinux::~DevicesLinux(void)
{
    m_instance = NULL_PTR;
}

DevicesLinux* DevicesLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new DevicesLinux();
    }
    return m_instance;
}

RETURN_STATUS DevicesLinux::openDevices(void)
{
    RETURN_STATUS retVal = SUCCESS;

    if (FALSE == isDevicesInit)
    {
        // init all peripherals here
        if ((FAILURE == gpio->init())  || (FAILURE == timer->init()) || (FAILURE == uart->init()) || (FAILURE == adc->init()))
        {
            retVal = FAILURE;
        }

        isDevicesInit = TRUE;
    }

    return retVal;
}

}
/******************************** End Of File *********************************/
