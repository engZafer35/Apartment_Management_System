/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 2:25:42 PM
* #File Name    : MyEventInterpreter.hpp
* #File Path    : /GezGor/Application/inc/MyEventInterpreter.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __MY_EVENT_INTERPRETER_HPP__
#define __MY_EVENT_INTERPRETER_HPP__
/*********************************INCLUDES*************************************/
#include "IEventInterpreter.hpp"
#include "EventMessage.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
class MyEventInterpreter : public event::IEventInterpreter
{
public:
    RETURN_STATUS handleEvent(event::EventMsg &event);
};
#endif /* __MY_EVENT_INTERPRETER_HPP__ */

/********************************* End Of File ********************************/
