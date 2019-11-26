/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 12:48:31 PM
* #File Name    : TimerBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/TimerBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "TimerBareMetal.hpp"
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
//    ::usleep(timeMs*1000);
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
TimerBareMetal* TimerBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
TimerBareMetal::TimerBareMetal(void)
{
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
TimerBareMetal::~TimerBareMetal(void)
{
    delete (m_instance);
    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
TimerBareMetal* TimerBareMetal::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "TimerBareMetal Created";
        m_instance = new TimerBareMetal();
    }
    return m_instance;
}

/** \brief init TimerBareMetal */
RETURN_STATUS TimerBareMetal::init(void)
{
    RETURN_STATUS retVal = OK;

    m_hwTimerPeriod = TIMER_CHECK_CYCLE;

    ZLOG << "Hardware Timer Init : " << (int)m_hwTimerPeriod <<"ms";

    return retVal;
}

}//namespace platform

#endif//#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
/******************************** End Of File *********************************/
