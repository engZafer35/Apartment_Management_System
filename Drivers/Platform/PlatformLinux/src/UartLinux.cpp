/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 10:11:49 PM
* #File Name    : UartLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/UartLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#ifdef __linux
/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "UartLinux.hpp"
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
UartLinux* UartLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
UartLinux::UartLinux(void)
{

}

/** \brief hardware receive interrupt callback function */
void UartLinux::cbReceive(void)
{

}

/** \brief hardware send interrupt callback function */
void UartLinux::cbSend(void)
{

}

}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
UartLinux::~UartLinux(void)
{
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
UartLinux* UartLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "UartLinux Created";
        m_instance = new UartLinux();
    }
    return m_instance;
}

/** \brief init uart*/
RETURN_STATUS UartLinux::init(void)
{
    RETURN_STATUS retVal = SUCCESS;

    ZLOGF_IF(FAILURE == retVal) << "[E] UartLinux init Error: !!";
    return retVal;
}

/** \brief send data*/
RETURN_STATUS UartLinux::send(const void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

/** \brief receive data*/
RETURN_STATUS UartLinux::receive(void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

}//namespace platform

#endif//#ifdef __linux
/******************************** End Of File *********************************/
