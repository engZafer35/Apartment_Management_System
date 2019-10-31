/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Oct 22, 2019 - 11:20:44 PM
* #File Name    : Singleton.hpp
* #File Path    : /GezGor/Resources/inc/Singleton.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __UTILITY_SINGLETON_HPP__
#define __UTILITY_SINGLETON_HPP__
/*********************************INCLUDES*************************************/
#include "Utility.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
template<class T>
class Singleton : NonCopyable
{
public:
    Singleton(void)
    {
        MutexLockFunc mutex;
        if(nullptr == m_instance)
        {
            m_instance = static_cast<T*>(this);
        }
    }

    ~Singleton(void)
    {
        m_instance = nullptr;
    }

    static T* getInstance(void)
    {
        return m_instance;
    }

private:
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = nullptr;


#endif /* __UTILITY_SINGLETON_HPP__ */

/********************************* End Of File ********************************/
