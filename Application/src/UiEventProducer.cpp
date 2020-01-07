/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Dec 2, 2019 - 9:58:06 AM
* #File Name    : UiEventProducer.cpp 
* #File Path    : /GezGor/Application/src/UiEventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "UiEventProducer.hpp"
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
namespace event
{
UiEventProducer *UiEventProducer::m_instance = NULL_PTR;
}//namespace event
/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/
namespace event
{
/***************************** CLASS PRIVATE METHOD ***************************/
UiEventProducer::UiEventProducer(void) : m_start{FALSE}
{
}
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
UiEventProducer::~UiEventProducer(void)
{
    m_mutex.lock(); // lock section

    delete (m_instance);
    m_instance = NULL_PTR;

    m_mutex.unlock();// unlock section
}

/**
 * \brief  create TimerEventProducer(singleton)
 * \return address of TimerEventProducer
 */
UiEventProducer *UiEventProducer::getInstance(void)
{
    platform::MutexLockFunc mutex; /** < guarantee that only one object is created. >*/
    if (NULL_PTR == m_instance)
    {
        m_instance = new UiEventProducer();
    }
    return m_instance;
}

/** \brief start event producer */
void UiEventProducer::start(void)
{
    m_mutex.lock();
    m_start = TRUE;
    m_mutex.unlock();
}

/** \brief stop event producer */
void UiEventProducer::stop(void)
{
    m_mutex.lock();
    m_start = FALSE;
    m_mutex.unlock();
}

/** \brief pause event producer */
void UiEventProducer::pause(void)
{
    m_mutex.lock();
    m_start = FALSE;
    m_mutex.unlock();
}

/** \brief run event producer */
void UiEventProducer::loop(void)
{
}

}//namespace event
/******************************** End Of File *********************************/
