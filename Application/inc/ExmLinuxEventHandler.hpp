/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 29, 2019 - 10:40:59 AM
* #File Name    : ExmLinuxEventHandler.hpp
* #File Path    : /GezGor/Application/inc/ExmLinuxEventHandler.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EXM_LINUX_EVENT_HANDLER_HPP__
#define __EXM_LINUX_EVENT_HANDLER_HPP__
/*********************************INCLUDES*************************************/
#include "IEventHandler.hpp"
#include "EventMessage.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
class ExmLinuxEventHandler : public IEventHandler
{
public:
    virtual RETURN_STATUS handleEvent(event::EventMsg &event) override;
};
#endif /* __EXM_LINUX_EVENT_HANDLER_HPP__ */

/********************************* End Of File ********************************/
