/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 9:11:06 AM
* #File Name    : EventHandler.hpp
* #File Path    : /GezGor/Application/inc/EventHandler.hpp
*******************************************************************************/

/******************************************************************************
* Event handler interface class
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EVENT_HANDLER_HPP__
#define __EVENT_HANDLER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "EventMessage.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/
enum WORKING_MODE
{
    EN_WORKING_MODE_NORMAL,
    EN_WORKING_MODE_BLACKOUT,
    EN_WORKING_MODE_SW_UPDATE,
    EN_WORKING_MODE_MAINTENCE,
};
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
class IEventHandler
{
public:
    virtual ~IEventHandler(void){}
    virtual RETURN_STATUS handleEvent(event::EventMsg &event) = 0;
};

#endif /* __EVENT_HANDLER_HPP__ */

/********************************* End Of File ********************************/
