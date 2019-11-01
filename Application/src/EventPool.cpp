/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 9:16:01 PM
* #File Name    : EventPool.cpp 
* #File Path    : /GezGor/Application/src/EventPool.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventPool.hpp"
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

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace event
{

RETURN_STATUS EventPool::buildEventProducer(void)
{
    RETURN_STATUS retVal = SUCCESS;

    m_tEventProducer = TimerEventProducer::getInstance<platform::EN_TIMER_1>(); /** < create timer event producer >*/
    m_tEventProducer->setQueue(&eventQueue);
    m_tEventProducer->pause();
    m_tEventProducer->start();
    m_tEventProducer->resume();

    //TODO: create all event producers
    //TODO: give event queue handle to event producers
    //TODO: stop all event producers

    return retVal;
}

RETURN_STATUS EventPool::startProducers(void)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

RETURN_STATUS EventPool::stopProducers(void)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

RETURN_STATUS EventPool::producerCommand(EVENT_PRODUCER_LIST list, EVENT_PRODUCER_COMMAND cmd)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

}//namespace event
/******************************** End Of File *********************************/
