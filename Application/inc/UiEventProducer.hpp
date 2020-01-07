/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Dec 2, 2019 - 9:01:55 AM
* #File Name    : UiEventProducer.hpp
* #File Path    : /GezGor/Application/inc/UiEventProducer.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UI_EVENT_PRODUCER_HPP__
#define __UI_EVENT_PRODUCER_HPP__
/*********************************INCLUDES*************************************/
#include "ProjectConf.hpp"
#include "EventProducer.hpp"
#include "EventList.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{

class UiEventProducer : public IEventProducer
{
public:
    ~UiEventProducer(void);

    /**
     * \brief  create TimerEventProducer(singleton)
     * \return address of TimerEventProducer
     */
    static UiEventProducer *getInstance(void);

    /** \brief start event producer */
    void start(void) override;

    /** \brief stop event producer */
    void stop(void) override;

    /** \brief pause event producer */
    void pause(void) override;

    /** \brief run event producer */
    void loop(void) override;

private:
    UiEventProducer(void);

private:
    static UiEventProducer *m_instance;
    volatile BOOL m_start;

//    platform::Platform *m_platform;
    platform::MutexLock m_mutex;
};

}
#endif /* __UI_EVENT_PRODUCER_HPP__ */

/********************************* End Of File ********************************/
