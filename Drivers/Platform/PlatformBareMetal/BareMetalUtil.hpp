/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 1, 2019 - 11:32:52 AM
* #File Name    : BareMetalUtil.hpp
* #File Path    : /GezGor/Application/inc/BareMetalUtil.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APPLICATION_INC_BAREMETALUTIL_HPP__
#define __APPLICATION_INC_BAREMETALUTIL_HPP__
/*********************************INCLUDES*************************************/

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
    Mutex(void)
    { /* for Bare-Metal*/}

    virtual ~Mutex(void)
    { /* for Bare-Metal*/}

public:
    inline void _lock(void)
    { /* for Bare-Metal*/ }

    inline void _unlock(void)
    {  /* for Bare-Metal*/ }
};


class MutexLock : private virtual Mutex
{
public:
    MutexLock(void){}
    ~MutexLock(void){}

    inline void lock(void)
    {
        _lock();
    }

    inline void unlock(void)
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

class MutexLockFunc : virtual private  Mutex
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
}//namespace board
#endif /* __APPLICATION_INC_BAREMETALUTIL_HPP__ */

/********************************* End Of File ********************************/
