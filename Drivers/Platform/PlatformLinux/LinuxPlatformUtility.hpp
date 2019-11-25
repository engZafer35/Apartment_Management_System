/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 1, 2019 - 10:54:57 AM
* #File Name    : LinuxPlatformUtility.hpp
* #File Path    : /GezGor/Application/inc/LinuxPlatformUtility.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __LINUX_PLATFORM_UTILITY_HPP__
#define __LINUX_PLATFORM_UTILITY_HPP__
/*********************************INCLUDES*************************************/
#ifdef __linux
#include <mutex>

/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace platform
{
class Mutex
{
public:
    Mutex(void){}

    virtual ~Mutex(void){}

public:
    void _lock(void)
    {
        mtx.lock();
    }

    void _unlock(void)
    {
        mtx.unlock();
    }

private:
    std::mutex mtx;
};


class MutexLock : private Mutex
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
private:
    MutexLock(const MutexLock&);
    MutexLock& operator=(const MutexLock&);
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

class MutexLockFunc : virtual Mutex
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
private:
    MutexLockFunc(const MutexLockFunc&);
    MutexLockFunc& operator=(const MutexLockFunc&);
};

}//namespace platform

#endif //#ifdef __linux
#endif /* __LINUX_PLATFORM_UTILITY_HPP__ */

/********************************* End Of File ********************************/
