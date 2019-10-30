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

void EventQueue::enterSection(void)
{
#ifdef __linux
    ::pthread_mutex_lock(m_mutexEvent);
#endif
}

void EventQueue::leaveSection(void)
{
#ifdef __linux
    ::pthread_mutex_unlock(m_mutexEvent);
#endif
}
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/

/** \brief constructor */
EventQueue::EventQueue(void)
{
    m_mutexEvent = new ::pthread_mutex_t();
    ::pthread_mutex_init(m_mutexEvent, 0);
}

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

    enterSection();

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
                //event priority smaller, push end of list
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

    leaveSection();
    return retVal;
}

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(U32 queNum)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

/** \brief delete all event that have same event ID */
RETURN_STATUS EventQueue::deleteEvents(EVENTS eventID)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

/** \brief delete event with queue number*/
RETURN_STATUS EventQueue::deleteEvent(EventMsg **event)
{

    enterSection();

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
                break;
            }

            it++;
        }
    }

    leaveSection();

    return SUCCESS;
}

/** \brief delete all pending events*/
RETURN_STATUS EventQueue::deleteAllEvent(void)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

}//namespace event

/******************************** End Of File *********************************/
