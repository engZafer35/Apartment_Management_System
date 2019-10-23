/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 3:56:23 PM
* #File Name    : Utility.hpp
* #File Path    : /GezGör/Application/inc/Utility.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UTILITY_HPP__
#define __UTILITY_HPP__
/*********************************INCLUDES*************************************/
#include <pthread.h>
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
class NonCopyable
{
protected:
    NonCopyable(void){}

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};

class Mutex : NonCopyable
{
public:
    Mutex(void)
    {
        ::pthread_mutex_init(&m_sync, 0);
    }

    ~Mutex(void)
    {
        ::pthread_mutex_destroy(&m_sync);
    }

    friend class MutexLock;

private:
    void lock(void)
    {
        ::pthread_mutex_lock(&m_sync);
    }

    void unlock(void)
    {
        ::pthread_mutex_unlock(&m_sync);
    }

private:
    pthread_mutex_t m_sync;
};

class MutexLock : NonCopyable
{
public:
    MutexLock(Mutex& mutex) : m_mutex(mutex)
    {
        m_mutex.lock();
    }

    ~MutexLock()
    {
        m_mutex.unlock();
    }

private:
    Mutex& m_mutex;
};

#endif /* __UTILITY_HPP__ */

/********************************* End Of File ********************************/
