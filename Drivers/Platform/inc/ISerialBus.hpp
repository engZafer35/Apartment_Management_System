/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 16, 2019 - 11:38:50 PM
* #File Name    : ISerialBus.hpp
* #File Path    : /GezGor/Drivers/Platform/inc/ISerialBus.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __ISERIAL_BUS_HPP__
#define __ISERIAL_BUS_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
namespace event
{
class IEventProducer;
}
/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
/**
 *  \brief interface class for all communication peripheral.
 *         for example UART, CAN
 */
class ISerialBus
{
public:
    virtual ~ISerialBus(void){}

    /** \brief open/init related communication peripheral*/
    virtual RETURN_STATUS open(void) = 0;

    /** \brief close related communication peripheral*/
    virtual RETURN_STATUS close(void) = 0;

    /** \brief send data*/
    virtual RETURN_STATUS send(const void *buff, U32 size, U32 timeout) = 0;

    /** \brief receive data*/
    virtual RETURN_STATUS receive(void *buff, U32 size, U32 timeout) = 0;

    /**
     * \brief load event producer for callback
     * \param any event producer pointer
     * \note  Related serialBus will invoke IEventProducer::loop method
     */
    virtual void loadCallback(event::IEventProducer *cbClass){m_cbClass = cbClass;}

protected:
    event::IEventProducer *m_cbClass;

    /** \brief hardware receive interrupt callback function */
    virtual void cbReceive(void) = 0;

    /** \brief hardware send interrupt callback function */
    virtual void cbSend(void) = 0;

    /**
     * \brief invoke callback function
     * \note  just do little jobs in your callback function
     */
    void runCallback(void);
};
}//namespace platform
#endif /* __ISERIAL_BUS_HPP__ */

/********************************* End Of File ********************************/
