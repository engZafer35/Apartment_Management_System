/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Mar 8, 2020 - 7:31:13 PM
* #File Name    : CanBusLinux.hpp
* #File Path    : /ApartmentManagementSystem/Drivers/Platform/PlatformLinux/inc/CanBusLinux.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __CANBUS_LINUX_HPP__
#define __CANBUS_LINUX_HPP__
/*********************************INCLUDES*************************************/
#ifdef __linux
#include <vector>
#include "GlobalDefinitions.hpp"
#include "ISerialBus.hpp"
#include "CanBusFrame.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/
namespace platform
{
typedef enum _CANBUS_LIST
{
    EN_CANBUS_INTERNAL_LINE,
    EN_CANBUS_VEHICLE_LINE
}CANBUS_LIST;
}
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
#ifdef USE_EXPORT_KEYWORD
export
#else
#define INLINE_CANBUS extern inline
#endif

template <CANBUS_LIST ID>
class CanBusDevice : public ISerialBus
{
public:
    struct Filter
    {
        U32 frameID = 0;
        U32 frameMask = 0;
    };

public:
    CanBusDevice(void);//load device
    ~CanBusDevice(void);//unregister from HW interrupt

    RETURN_STATUS open(void)  override;
    RETURN_STATUS close(void) override; //unregister from HW interrupt

    RETURN_STATUS send(const CanBusFrame &msg);
    RETURN_STATUS send(const CanBusFrame &msg, U32 period);
    RETURN_STATUS send(const CanBusFrame &msg, U32 period, U32 forTime);

    RETURN_STATUS stopSendingMsg(void);
    RETURN_STATUS deleteSendingMsg(U32 msgID);
    RETURN_STATUS deleteSendingMsg(const CanBusFrame &msg);

    bool isFrameAvailable(void) const;
    RETURN_STATUS receive(CanBusFrame &msg, U32 timeout);

    RETURN_STATUS addFilter(Filter &filter);
    RETURN_STATUS removeFilter(Filter &filter);
    RETURN_STATUS clearFilters(void);

private:
    RETURN_STATUS send(const void *buff, U32 size, U32 timeout) override;
    RETURN_STATUS receive(void *buff, U32 size, U32 timeout) override;

    /** \brief hardware receive interrupt callback function */
    void cbReceive(void) override;

    /** \brief hardware send interrupt callback function */
    void cbSend(void) override;

private:
    bool isOpened;
    CANBUS_LIST deviceNum;
    //todo: add vector list
    platform::MutexLock m_mutex;
};
}

#ifndef USE_EXPORT_KEYWORD //include cpp file to solve undefined reference problem
#include "../../Platform/PlatformLinux/src/CanBusLinux.cpp"
#endif

#endif /* __CANBUS_LINUX_HPP__ */
#endif /* __linux */
/********************************* End Of File ********************************/
