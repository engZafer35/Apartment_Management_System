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
EventPool::EventPool(void) : m_tEventProducer{NULL_PTR}
{}

EventPool::~EventPool(void)
{
    if (NULL_PTR != m_tEventProducer)
    {
        delete m_tEventProducer;
    }
}

RETURN_STATUS EventPool::buildEventProducer(void)
{
    RETURN_STATUS retVal = OK;

    m_tEventProducer = TimerEventProducer::getInstance(); /** < create timer event producer >*/
    m_tEventProducer->setQueue(&eventQueue);
    m_tEventProducer->pause();
    m_tEventProducer->stop();

    //TODO: create all event producers
    //TODO: give event queue handle to event producers
    //TODO: stop all event producers

    return retVal;
}

RETURN_STATUS EventPool::start(void)
{
    m_tEventProducer->start();

    //TODO: start all producers here

    return OK;
}

RETURN_STATUS EventPool::stop(void)
{
    m_tEventProducer->stop();

    //TODO: start all producers here

    return OK;
}

RETURN_STATUS EventPool::producerCommand(EVENT_PRODUCER_LIST list, EVENT_PRODUCER_COMMAND cmd)
{
    switch(list)
    {
        case EN_EVENT_TIMER:
        {
            (EN_PRODUCER_START == cmd) ? m_tEventProducer->start() : m_tEventProducer->stop();
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
