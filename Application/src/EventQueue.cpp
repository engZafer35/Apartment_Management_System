/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 4:25:10 PM
* #File Name    : EventQueue.cpp 
* #File Path    : /GezGör/Application/src/EventQueue.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "EventQueue.hpp"
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

/** \brief throw event */
EventMsg *EventQueue::waithEvent(U32 timeoutMs, U32 eventSource) const
{
    EventMsg *retEvent = NULL_PTR;

    if (FALSE == qEvents.empty()) // is not empty
    {
        retEvent = qEvents.front();
    }

    return retEvent;
}

/** \brief throw event */
RETURN_STATUS EventQueue::throwEvent(EventMsg *event)
{
    RETURN_STATUS retVal = SUCCESS;

    m_mutex.lock(); //lock section

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

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(U32 queNum)
{
    m_mutex.lock(); // lock section
    RETURN_STATUS retVal = SUCCESS;

    m_mutex.unlock();// unlock section
    return retVal;
}

/** \brief delete all event that have same event ID */
RETURN_STATUS EventQueue::deleteEvents(EVENTS eventID)
{
    m_mutex.lock(); // lock section
    RETURN_STATUS retVal = SUCCESS;

    m_mutex.unlock();// unlock section
    return retVal;
}

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(EventMsg **event)
{
    RETURN_STATUS retVal = FAILURE;

    m_mutex.lock(); // lock section

    if (FALSE == qEvents.empty()) // is not empty
    {
        std::deque<EventMsg *>::iterator it = qEvents.begin();
        U32 size = qEvents.size();

        for (U32 i = 0; i < size; i++)
        {
            if ((*it) == (*event))
            {
                qEvents.erase(it);           
                *event = NULL_PTR;
                retVal = SUCCESS;
                break;
            }
            it++;
        }
    }

    m_mutex.unlock();// unlock section
    return retVal;
}

/** \brief delete all pending events*/
RETURN_STATUS EventQueue::deleteAllEvent(void)
{
    m_mutex.lock(); // lock section
    RETURN_STATUS retVal = SUCCESS;

    m_mutex.unlock();// unlock section
    return retVal;
}

}//namespace event

/******************************** End Of File *********************************/
