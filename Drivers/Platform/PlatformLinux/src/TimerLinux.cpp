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

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "TimerLinux.hpp"
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
        m_instance = new TimerLinux();
    }
    return m_instance;
}

/** \brief init TimerLinux */
RETURN_STATUS TimerLinux::init(void)
{
    RETURN_STATUS retVal = SUCCESS;

    m_hwTimerPeriod = 10; //TODO

    return retVal;
}

/**
 * \brief Delay ms
 * \param time ms
 */
void TimerLinux::delayMs(U32 timeMs) const
{
    //TODO: usleep(timeMs*1000);
}

/**
 * \brief  Get system tick counter value
 * \return current system tick counter value
 */
U32 TimerLinux::getSysTickCounter(void) const
{
    return 666;
}

}//namespace platform
/******************************** End Of File *********************************/
