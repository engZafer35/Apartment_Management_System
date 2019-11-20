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
#include "ProjectConf.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
template<typename T>
class Singleton : virtual NonCopyable
{
public:
    virtual ~Singleton(void)
    {
        m_instance = nullptr;
    }

    static T* getInstance(void)
    {
        platform::MutexLockFunc mutex; //guarantee to create just one object
        if(NULL_PTR == m_instance)
        {
            m_instance = new T;
        }
        return m_instance;
    }

private:
    static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance = nullptr;


#endif /* __UTILITY_SINGLETON_HPP__ */

/********************************* End Of File ********************************/
