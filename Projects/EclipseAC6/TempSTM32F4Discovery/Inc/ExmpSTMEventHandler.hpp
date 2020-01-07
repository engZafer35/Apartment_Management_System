/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 29, 2019 - 10:43:09 AM
* #File Name    : ExmpSTMEventHandler.hpp
* #File Path    : /GezGor/Application/inc/ExmpSTMEventHandler.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __EXMP_STM_EVENT_HANDLER_HPP__
#define __EXMP_STM_EVENT_HANDLER_HPP__
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
class ExmpSTMEventHandler : public IEventHandler
{
public:
    virtual RETURN_STATUS handleEvent(event::EventMsg &event) override;
};
#endif /* __EXMP_STM_EVENT_HANDLER_HPP__ */

/********************************* End Of File ********************************/
