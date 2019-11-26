/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:35:48 PM
* #File Name    : GpioBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/GpioBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "GpioBareMetal.hpp"
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
GpioBareMetal* GpioBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
GpioBareMetal::GpioBareMetal(void)
{

}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
GpioBareMetal::~GpioBareMetal(void)
{
    delete (m_instance);
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
GpioBareMetal* GpioBareMetal::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new GpioBareMetal();
    }
    return m_instance;
}

/** init all gpio */
RETURN_STATUS GpioBareMetal::init(void)
{
    RETURN_STATUS retVal = OK;
    ZLOGF_IF(FAILURE == retVal) << "[I] GpioBareMetal init OK";
    return retVal;
}

/** read gpio*/
BOOL GpioBareMetal::read(void)
{
    BOOL retVal = TRUE;

    return retVal;
}

/** write gpio*/
RETURN_STATUS GpioBareMetal::write(BOOL status)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

/** set callback function for external interrupt*/
void GpioBareMetal::setCB(VoidCallback cbFunc)
{

}

}//namespace platform
#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
/******************************** End Of File *********************************/
