/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:18:56 PM
* #File Name    : DevicesBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/DevicesBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/

#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "DevicesBareMetal.hpp"

#include "TimerBareMetal.hpp"
#include "UartBareMetal.hpp"
#include "GpioBareMetal.hpp"
#include "AdcBareMetal.hpp"

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
DevicesBareMetal* DevicesBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
DevicesBareMetal::DevicesBareMetal(void) : isDevicesInit{FALSE}
{
    //create and load peripheral devices
    gpio  = GpioBareMetal::getInstance();
    uart  = UartBareMetal::getInstance();
    timer = TimerBareMetal::getInstance();
    adc   = AdcBareMetal::getInstance();
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
DevicesBareMetal::~DevicesBareMetal(void)
{
    delete (gpio);
    delete (uart);
    delete (timer);
    delete (adc);
    delete (m_instance);

    m_instance = NULL_PTR;
}

DevicesBareMetal* DevicesBareMetal::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new DevicesBareMetal();
    }
    return m_instance;
}

RETURN_STATUS DevicesBareMetal::openDevices(void)
{
    RETURN_STATUS retVal = OK;

    if (FALSE == isDevicesInit)
    {
        // init all peripherals here
        retVal |= gpio->init();
        retVal |= uart->init();
        retVal |= timer->init();
        retVal |= adc->init();

        drvIntRegisterInit();

        ZLOGF_IF(FAILURE == retVal) << "[E] DevicesBareMetal::openDevices !! Retval: " << retVal;

        isDevicesInit = TRUE;
    }

    return retVal;
}

}

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
/******************************** End Of File *********************************/
