/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:42:25 PM
* #File Name    : ITimer.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/ITimer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ITIMER_HPP__
#define __ITIMER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"

/******************************* NAME SPACE ***********************************/
namespace event
{
class IEventProducer;
}
/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
namespace platform
{
/**
 * \brief Delay ms, just function definitions,
 *        User need to declaration this function in own platform Timer devices file
 * \param time ms
 */
void delayMs(U32 timeMs);

/**
 * \brief  Get system tick counter value
 * \return current system tick counter value
 */
U32 getSysTickCounter(void);
}
/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
/**
 * \brief interface class for hardware timer
 */
class ITimer
{
public:
    ITimer(void) : m_cbClass{NULL_PTR}, m_hwTimerPeriod{0} {}
    virtual ~ITimer(void){}

    /**
     * \brief  init hardware timer
     * \return if everything is OK, return SUCCES
     *         otherwise return FAILURE
     */
    virtual RETURN_STATUS init(void) = 0;

    /**
     * \brief load event producer for callback
     * \param any event producer pointer
     * \note  Timer will invoke IEventProducer::loop method
     */
    inline void loadCallback(event::IEventProducer *cbClass){m_cbClass = cbClass;}

    /**
     * \brief invoke callback function
     * \note  just do little jobs in your callback function
     */
    void runCallback(void);

    /**
     * \brief  get Timer period
     * \return Ms value
     */
    inline U32 getPeriod(void) const {return m_hwTimerPeriod;}

protected:
    event::IEventProducer *m_cbClass;
    U32 m_hwTimerPeriod;
};
}//namespace platform

#endif /* __ITIMER_HPP__ */

/********************************* End Of File ********************************/
