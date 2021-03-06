/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 2:46:36 PM
* #File Name    : EventList.hpp
* #File Path    : /GezGör/Application/inc/EventList.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EVENT_LIST_HPP__
#define __EVENT_LIST_HPP__
/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/
namespace event
{
/** \brief Events ID */
typedef enum _EVENTS
{
    EN_EVENT_NO_EVENT,
    EN_EVENT_TIMEOUT_TIMER,
    EN_EVENT_PER_JOB_1,
    EN_EVENT_PER_JOB_2,
}EVENTS;

/** \brief Event Priority */
typedef enum _EVENT_PRIORITY
{
    EN_PRIORITY_LOW,
    EN_PRIORITY_MED,
    EN_PRIORITY_HIG,
    EN_PRIORITY_EMG
}EVENT_PRIORITY;

/** \brief Event Source */
typedef enum _EVENT_SOURCE
{
    EN_SOURCE_PER_TIMER     = 0x01, //periodic timer
    EN_SOURCE_ONE_TIMER     = 0x02, //one-shot timer
    EN_SOURCE_CB_TIMER      = 0x04, //
    EN_SOURCE_EXT_BOAR      = 0X08, //ext board event.(can message)
    EN_SOURCE_SERIAL_LINE   = 0X10, //ext board event.(can message)

    EN_SOURCE_EVENT_ALL = 0xFF,

}EVENT_SOURCE;

/** * \brief to create periodic timer use this enum list */
typedef enum
{
    EN_TIMER_BIT,
    #define BIT_TIME        (WAIT_10_SEC)//ms

    EN_TIMER_2,
    #define TIMER_2_TIME      (WAIT_6_SEC)//ms

    EN_TIMER_3,
    #define TIMER_3_TIME      (WAIT_1_SEC)//ms

    EN_TIMER_4,
    #define TIMER_4_TIME      (WAIT_8_SEC)//ms

    EN_TIMER_5,
    #define TIMER_5_TIME      (WAIT_4_SEC)//ms

    EN_TIMER_6,
    #define TIMER_6_TIME      (WAIT_1_MIN)//ms

    EN_TIMER_7,
    #define TIMER_TIME     (WAIT_1_MIN)//ms max 1 min

    EN_TIMER_8,
    #define TIMER_8_TIME      (WAIT_30_SEC)

    EN_TIMER_MAX_NUM
}TimerID;

}//namespace event


/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/

#endif /* __EVENT_LIST_HPP__ */

/********************************* End Of File ********************************/
