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
EventPool::EventPool(void) : m_timerEventProd{NULL_PTR}
{}

EventPool::~EventPool(void)
{
    if (NULL_PTR != m_timerEventProd)
    {
        delete m_timerEventProd;
    }
}

RETURN_STATUS EventPool::buildEventProducer(void)
{
    RETURN_STATUS retVal = OK;

    m_timerEventProd = TimerEventProducer::getInstance(); /** < create timer event producer >*/
    m_timerEventProd->setQueue(&eventQueue);
    m_timerEventProd->pause();
    m_timerEventProd->stop();

    //TODO: create all event producers
    //TODO: give event queue handle to event producers
    //TODO: stop all event producers

    return retVal;
}

RETURN_STATUS EventPool::start(void)
{
    m_timerEventProd->start();

    //TODO: start all producers here

    return OK;
}

RETURN_STATUS EventPool::stop(void)
{
    m_timerEventProd->stop();

    //TODO: start all producers here

    return OK;
}

RETURN_STATUS EventPool::producerCommand(EVENT_PRODUCER_LIST list, EVENT_PRODUCER_COMMAND cmd)
{
    switch(list)
    {
        case EN_EVENT_TIMER:
        {
            (EN_PRODUCER_START == cmd) ? m_timerEventProd->start() : m_timerEventProd->stop();
            break;
        }
        case EN_EVENT_PRODUCER_1:
        {
            break;
        }
        case EN_EVENT_PRODUCER_2:
        {
            break;
        }

        //TODO: other event producer
    }

    return OK;
}

}//namespace event
/******************************** End Of File *********************************/
