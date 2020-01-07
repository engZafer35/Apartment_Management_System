/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 4:13:36 PM
* #File Name    : AppEventHandler.hpp
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/inc/AppEventHandler.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_EVENT_HANDLER_HPP__
#define __APP_EVENT_HANDLER_HPP__
/*********************************INCLUDES*************************************/
#include "IEventHandler.hpp"
#include "GlobalDefinitions.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace redbird
{
/** \brief class system normal working mode event handler */
class AppEventHandler : public IEventHandler
{
public:
    AppEventHandler(void);
    ~AppEventHandler(void);

    RETURN_STATUS handleEvent(event::EventMsg &event) override;

private:
};

}//namespace redbird
#endif /* __APP_EVENT_HANDLER_HPP__ */

/********************************* End Of File ********************************/
