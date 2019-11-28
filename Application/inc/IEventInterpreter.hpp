/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 28, 2019 - 2:21:55 PM
* #File Name    : IEventInterpreter.hpp
* #File Path    : /GezGor/Application/inc/IEventInterpreter.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __IEVENT_INTERPRETER_HPP__
#define __IEVENT_INTERPRETER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "EventMessage.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace event
{
class IEventInterpreter
{
public:
    virtual ~IEventInterpreter(void){}
    virtual RETURN_STATUS handleEvent(EventMsg &event) = 0;
};
}//namespace event
#endif /* __IEVENT_INTERPRETER_HPP__ */

/********************************* End Of File ********************************/
