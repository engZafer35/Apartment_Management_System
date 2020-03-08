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

/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
/** \brief hardware receive interrupt callback function */
void UartLinux::cbReceive(void)
{}

/** \brief hardware send interrupt callback function */
void UartLinux::cbSend(void)
{}

}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
UartLinux::UartLinux(void)
{}

UartLinux::~UartLinux(void)
{}

/** \brief init uart*/
RETURN_STATUS UartLinux::open(void)
{
    RETURN_STATUS retVal = OK;

    ZLOGF_IF(FAILURE == retVal) << "[E] UartLinux init Error: !!";
    return retVal;
}
/** \brief init uart*/
RETURN_STATUS UartLinux::close(void)
{
    RETURN_STATUS retVal = OK;

    ZLOGF_IF(FAILURE == retVal) << "[E] UartLinux init Error: !!";
    return retVal;
}

/** \brief send data*/
RETURN_STATUS UartLinux::send(const void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

/** \brief receive data*/
RETURN_STATUS UartLinux::receive(void *buff, U32 size, U32 timeout)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

}//namespace platform

#endif//#ifdef __linux
/******************************** End Of File *********************************/
