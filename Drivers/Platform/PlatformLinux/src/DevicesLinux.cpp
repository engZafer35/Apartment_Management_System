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
#ifdef __linux

#include "ProjectConf.hpp"
#include "DevicesLinux.hpp"

#include "TimerLinux.hpp"
#include "UartLinux.hpp"
#include "GpioLinux.hpp"
#include "AdcLinux.hpp"

#include "DrvInterruptRegister.hpp"
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
    gpio  = new GpioLinux();
    uart  = new UartLinux();
    timer = new TimerLinux();
    adc   = new AdcLinux();
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
DevicesLinux::~DevicesLinux(void)
{
    delete (gpio);
    delete (uart);
    delete (timer);
    delete (adc);
    delete (m_instance);

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
    RETURN_STATUS retVal = OK;

    if (FALSE == isDevicesInit)
    {
        // init all peripherals here
        retVal |= gpio->init();
        retVal |= uart->open();
        retVal |= timer->init();
        retVal |= adc->init();

        drvIntRegisterInit();

        ZLOGF_IF(FAILURE == retVal) << "[E] DevicesLinux::openDevices !! Retval: " << retVal;

        isDevicesInit = TRUE;
    }

    return retVal;
}

}

#endif//#ifdef __linux
/******************************** End Of File *********************************/
