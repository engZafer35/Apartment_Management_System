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
#include "ProjectConf.hpp"
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
    virtual ~NonCopyable(void){}

private:
    NonCopyable(const NonCopyable&);
    NonCopyable& operator=(const NonCopyable&);
};

class MutexLock : private platform::Mutex, private NonCopyable
{
public:
    MutexLock(void){}
    ~MutexLock(void){}

    void lock(void)
    {
        _lock();
    }

    void unlock(void)
    {
        _unlock();
    }
};

//class MutexLock : NonCopyable
//{
//public:
//    MutexLock(Mutex& mutex) : m_mutex(mutex)
//    {
//        m_mutex.lock();
//    }
//
//    ~MutexLock()
//    {
//        m_mutex.unlock();
//    }
//
//private:
//    Mutex& m_mutex;
//};

class MutexLockFunc : virtual platform::Mutex, private NonCopyable
{
public:
    MutexLockFunc()
    {
        _lock();
    }

    ~MutexLockFunc()
    {
        _unlock();
    }
};

#endif /* __UTILITY_HPP__ */

/********************************* End Of File ********************************/
