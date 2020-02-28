/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 4:25:10 PM
* #File Name    : EventQueue.cpp 
* #File Path    : /GezGor/Application/src/EventQueue.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "EventQueue.hpp"
#include "TimerEventProducer.hpp"
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
namespace event
{
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/

/** \brief constructor */
EventQueue::EventQueue(void)
{}

EventQueue::~EventQueue(void)
{
    deleteAllEvent();
}

/** \brief throw event */
EventMsg *EventQueue::waithEvent(U32 timeoutMs, U32 eventSource)
{
    EventMsg *retEvent = NULL_PTR;
    U32 timer = -1;

    if (timeoutMs > 0)
    {
        timer = TIMER(timeoutMs);
        eventSource |= EN_SOURCE_ONE_TIMER;
    }

    while(1)
    {
        if (FALSE == qEvents.empty()) // is not empty
        {
            m_mutex.lock(); //lock section
            for(U32 i = 0; i < qEvents.size(); ++i)
            {
                if (eventSource & qEvents[i]->getEventSource())
                {
                    retEvent = qEvents[i];
                }
            }
            m_mutex.unlock(); //lock section

            if (NULL_PTR != retEvent)
            {
                if ( (timer > 0) && (EN_EVENT_TIMEOUT_TIMER == retEvent->getEvent()) && (timer == *(static_cast<U32*>(retEvent->getValue()))) )
                {
                    deleteEvent(&retEvent); //timeout event. clear event
                    retEvent = NULL_PTR;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }

    if (timeoutMs > 0) //cancel timer if it set
    {
        CANCEL_TIMER(timer);
    }

    return retEvent;
}

/** \brief throw event */
RETURN_STATUS EventQueue::throwEvent(EventMsg *event)
{
    m_mutex.lock(); //lock section
    RETURN_STATUS retVal = OK;

    if (FALSE == qEvents.empty()) // is not empty
    {
        std::deque<EventMsg *>::iterator it = qEvents.begin();
        EVENT_PRIORITY np = event->getEventPriority();
        U32 size = qEvents.size();

        for (U32 i = 0; i < size; i++)
        {
            //find position
            if ( qEvents.at(i)->getEventPriority() < np)
            {
                it += i;
                qEvents.insert(it,event);
                break;
            }
            else if (i == (size-1))
            {
                //event priority smallest, push end of list
                qEvents.push_back(event);
                break;
            }
        }
    }
    else
    {
        //event priority smaller, push end of list
        qEvents.push_back(event);
    }

    m_mutex.unlock(); //unlock section
    return retVal;
}

/** \brief delete all event that have same event ID */
RETURN_STATUS EventQueue::deleteEvents(EVENT_SOURCE eventID)
{
    m_mutex.lock(); // lock section
    RETURN_STATUS retVal = OK;

    //TODO:

    m_mutex.unlock();// unlock section
    return retVal;
}

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(EventMsg **event)
{
    m_mutex.lock(); // lock section
    RETURN_STATUS retVal = FAILURE;

    for (QEvents::iterator it = qEvents.begin(); it != qEvents.end(); ++it)
    {
        if ((*it) == (*event))
        {
            qEvents.erase(it); //delete from queue
            delete (*event);   //delete from memory
            *event = NULL_PTR;
            retVal = OK;
            break;
        }
    }

    m_mutex.unlock();// unlock section
    return retVal;
}

/** \brief delete all pending events*/
RETURN_STATUS EventQueue::deleteAllEvent(void)
{
    m_mutex.lock(); // lock section

    for (QEvents::iterator it = qEvents.begin(); it != qEvents.end(); ++it)
    {
        delete (*it); //delete from memory
    }

    qEvents.clear(); //clear queue

    m_mutex.unlock();// unlock section
    return OK;
}

}//namespace event

/******************************** End Of File *********************************/
