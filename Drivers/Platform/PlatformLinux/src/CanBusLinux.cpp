/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Mar 8, 2020 - 7:32:31 PM
* #File Name    : CanBusLinux.cpp 
* #File Path    : /ApartmentManagementSystem/Drivers/Platform/PlatformLinux/src/CanBusLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#ifdef __linux
#ifdef INLINE_CANBUS //include guard for template class
#include "ProjectConf.hpp"
#include "CanBusLinux.hpp"

/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/

/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
template <CANBUS_LIST ID>
CanBusDevice<ID>::CanBusDevice(void) : isOpened(false), deviceNum{ID}
{}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::send(const void *buff, U32 size, U32 timeout)
{
    //not using
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::receive(void *buff, U32 size, U32 timeout)
{
    //not using
    return OK;
}

/** \brief hardware receive interrupt callback function */
template <CANBUS_LIST ID>
void CanBusDevice<ID>::cbReceive(void)
{
}

/** \brief hardware send interrupt callback function */
template <CANBUS_LIST ID>
void CanBusDevice<ID>::cbSend(void)
{
}

}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
template <CANBUS_LIST ID>
CanBusDevice<ID>::~CanBusDevice(void)
{
    clearFilters();
    stopSendingMsg();
    close();
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::open(void)
{
    //TODO open device
    isOpened = true;
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::close(void)
{
    m_mutex.lock();
    //TODO: close device
    isOpened = false;
    m_mutex.unlock();
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::send(const CanBusFrame &msg)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::send(const CanBusFrame &msg, U32 period)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::send(const CanBusFrame &msg, U32 period, U32 forTime)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::stopSendingMsg(void)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::deleteSendingMsg(U32 msgID)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::deleteSendingMsg(const CanBusFrame &msg)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
bool CanBusDevice<ID>::isFrameAvailable(void) const
{
    //TODO implement
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::receive(CanBusFrame &msg, U32 timeout)
{
    //TODO implement
    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::addFilter(Filter &filter)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::removeFilter(Filter &filter)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

template <CANBUS_LIST ID>
RETURN_STATUS CanBusDevice<ID>::clearFilters(void)
{
    m_mutex.lock();
    //TODO implement
    m_mutex.unlock();

    return OK;
}

}//namespace platform
#endif //#ifdef INLINE_CANBUS //include guard for template class
#endif //#ifdef __linux
/******************************** End Of File *********************************/
