/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:51:35 PM
* #File Name    : AdcBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/AdcBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "AdcBareMetal.hpp"
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
AdcBareMetal* AdcBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
AdcBareMetal::AdcBareMetal(void)
{
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
AdcBareMetal::~AdcBareMetal(void)
{
    delete (m_instance);
    m_instance = NULL_PTR;
}
AdcBareMetal* AdcBareMetal::getInstance(void)
{
//    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "[I] AdcBareMetal Created";
        m_instance = new AdcBareMetal();
    }
    return m_instance;
}

/** \brief init ADC channel */
RETURN_STATUS AdcBareMetal::init(void)
{
    RETURN_STATUS retVal = OK;
    ZLOGF_IF(FAILURE == retVal) << "[I] AdcLinux init OK: !!";
    return retVal;
}

/** \brief read ADC value */
U32 AdcBareMetal::read(void)
{
    return 666;
}


}//namespace platform

#endif
/******************************** End Of File *********************************/
