/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:38:50 PM
* #File Name    : ICommPeripheral.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/ICommPeripheral.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ICOMMPERIPHERAL_HPP__
#define __ICOMMPERIPHERAL_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
#include "Singleton.hpp"
#include "Utility.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
/**
 *  \brief interface class for all communication peripheral.
 *         for example UART, CAN
 */
class ICommPeripheral
{
public:
    virtual ~ICommPeripheral(void){}

    /** \brief init related communication peripheral*/
    virtual RETURN_STATUS init(void) = 0;

    /** \brief send data*/
    virtual RETURN_STATUS send(const void *buff, U32 size, U32 timeout) = 0;

    /** \brief receive data*/
    virtual RETURN_STATUS receive(void *buff, U32 size, U32 timeout) = 0;

protected:
    /** \brief hardware receive interrupt callback function */
    virtual void cbReceive(void) = 0;

    /** \brief hardware send interrupt callback function */
    virtual void cbSend(void) = 0;
};
}//namespace platform
#endif /* __ICOMMPERIPHERAL_HPP__ */

/********************************* End Of File ********************************/
