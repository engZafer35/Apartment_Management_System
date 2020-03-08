/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Mar 8, 2020 - 7:29:41 PM
* #File Name    : CanBusFrame.hpp
* #File Path    : /ApartmentManagementSystem/Drivers/Platform/inc/CanBusFrame.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __CANBUS_FRAME_HPP__
#define __CANBUS_FRAME_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class CanBusFrame
{
public:
    enum FRAME_TYPE
    {
        EN_CAN_FRAME_UNKNOW,
        EN_CAN_FRAME_DATA,
        EN_CAN_FRAME_REQUEST,
        EN_CAN_FRAME_ERROR,
        EN_CAN_FRAME_INVALID
    };

    struct Identifier
    {
        U32 id  : 29; /** !< can bus msg ide, supports can-bus CAN2.0B */
        U32 rtr : 1;  /** !< 0 for data message, 1 for request message */
        U32 ide : 1;  /** !< 0 for CAN2.0A (11 bit ide), 1 for CAN2.0B(29 bit ide) */
    };

public:
    explicit CanBusFrame(Identifier ide, const U8 data[8]);
    explicit CanBusFrame(const CanBusFrame &rc) = default;

    ~CanBusFrame(void);

    void setFrameType(FRAME_TYPE type);
    void setFremeID(U32 id);

    bool isValidFrame(void) const ;

    FRAME_TYPE getFrameType(void) const;
    U32 getFrameID(void) const;

    bool isExtendedFrame(void) const;

    void setData(const U8 data[8]);
    void getData(U8 data[8]) const;

private:
    Identifier m_ide = {0};
    U8 m_data[8] = {0};
    FRAME_TYPE m_type;
};

}//namespace platform

#endif /* __CANBUS_FRAME_HPP__ */

/********************************* End Of File ********************************/
