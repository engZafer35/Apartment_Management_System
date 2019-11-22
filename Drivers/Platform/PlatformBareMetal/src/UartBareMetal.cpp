/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:11:49 PM
* #File Name    : UartBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/UartBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "UartBareMetal.hpp"
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
UartBareMetal* UartBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
UartBareMetal::UartBareMetal(void)
{

}

/** \brief hardware receive interrupt callback function */
void UartBareMetal::cbReceive(void)
{

}

/** \brief hardware send interrupt callback function */
void UartBareMetal::cbSend(void)
{

}

}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
UartBareMetal::~UartBareMetal(void)
{
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
UartBareMetal* UartBareMetal::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "UartBareMetal Created";
        m_instance = new UartBareMetal();
    }
    return m_instance;
}

/** \brief init uart*/
RETURN_STATUS UartBareMetal::init(void)
{
    RETURN_STATUS retVal = OK;

    ZLOGF << "[I] UartBareMetal init OK !!";
    return retVal;
}

/** \brief send data*/
RETURN_STATUS UartBareMetal::send(const void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

/** \brief receive data*/
RETURN_STATUS UartBareMetal::receive(void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

}//namespace platform

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
/******************************** End Of File *********************************/
