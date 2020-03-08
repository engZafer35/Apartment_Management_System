/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 12:48:31 PM
* #File Name    : TimerLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/TimerLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#ifdef __linux
/********************************* INCLUDES ***********************************/
#include <unistd.h>

#include "ProjectConf.hpp"
#include "TimerLinux.hpp"
#include "DrvInterruptRegister.hpp"

/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
namespace platform
{
/**
 * \brief Delay ms
 * \param time ms
 */
void delayMs(U32 timeMs)
{
    ::usleep(timeMs*1000);
}
/**
 * \brief  Get system tick counter value
 * \return current system tick counter value
 */
U32 getSysTickCounter(void)
{
    return 666;
}
}
/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{

}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
TimerLinux::TimerLinux(void)
{}

TimerLinux::~TimerLinux(void)
{}

/** \brief init TimerLinux */
RETURN_STATUS TimerLinux::init(void)
{
    RETURN_STATUS retVal = OK;

    m_hwTimerPeriod = TIMER_CHECK_CYCLE;

    ZLOG << "TimerLinux init : " << (int)m_hwTimerPeriod <<"ms";
    ZLOGF_IF(FAILURE == retVal) << "TimerLinux init Error";

    return retVal;
}

}//namespace platform

#endif//#ifdef __linux
/******************************** End Of File *********************************/
