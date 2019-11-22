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
namespace platform
{
TimerLinux* TimerLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
TimerLinux::TimerLinux(void)
{
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
TimerLinux::~TimerLinux(void)
{
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
TimerLinux* TimerLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "TimerLinux Created";
        m_instance = new TimerLinux();
    }
    return m_instance;
}

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
