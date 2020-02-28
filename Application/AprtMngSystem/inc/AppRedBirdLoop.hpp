/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 4:08:21 PM
* #File Name    : AppRedBirdLoop.hpp
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/inc/AppRedBirdLoop.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_RED_BIRD_LOOP_HPP__
#define __APP_RED_BIRD_LOOP_HPP__
/*********************************INCLUDES*************************************/

/******************************* NAME SPACE ***********************************/
#include "EventPool.hpp"
#include "Platform.hpp"
#include "IEventHandler.hpp"
/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace redbird
{
class AppRedBird
{
public:

    AppRedBird(platform::Platform &platform);
    ~AppRedBird();

    RETURN_STATUS eggs(void); //init app
    RETURN_STATUS fly(void);
    RETURN_STATUS roost(void);

private:
    BOOL m_isFlying;

    platform::Platform &m_platform;
    event::EventPool * m_eventPool;
    IEventHandler *m_eventHandler;
};
}//namespace redbird
#endif /* __APP_RED_BIRD_LOOP_HPP__ */

/********************************* End Of File ********************************/
