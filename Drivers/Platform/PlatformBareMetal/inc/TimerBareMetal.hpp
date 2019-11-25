/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 12:43:24 PM
* #File Name    : TimerBareMetal.hpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/inc/TimerBareMetal.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __TIMER_BareMetal_HPP__
#define __TIMER_BareMetal_HPP__
/*********************************INCLUDES*************************************/
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include <unistd.h>
#include "ITimer.hpp"

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class TimerBareMetal : public ITimer, private NonCopyable
{
#define TIMER_CHECK_CYCLE    (10) //ms hardware timer period Ms
public:
    ~TimerBareMetal(void);

    /** \brief get instance, singleton class*/
    static TimerBareMetal* getInstance(void);

    /** \brief init TimerBareMetal */
    RETURN_STATUS init(void) override;

private:
     TimerBareMetal(void);

private:
     static TimerBareMetal* m_instance;
};

}//namespace platform

#endif
#endif /* __TIMER_BareMetal_HPP__ */

/********************************* End Of File ********************************/
