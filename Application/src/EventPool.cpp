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
#include "EventMessage.hpp"
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

RETURN_STATUS EventPool::buidSysEventProducer(void)
{
    RETURN_STATUS retVal = SUCCESS;

    tEventProducer = new TimerEventProducer();
    tEventProducer->setQueue(&eventQueue);
    tEventProducer->pause();
    tEventProducer->start();
    tEventProducer->resume();

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
