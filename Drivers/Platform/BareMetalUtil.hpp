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
    void _lock(void)
    { /* for Bare-Metal*/ }

    void _unlock(void)
    {  /* for Bare-Metal*/ }
};
}//namespace board
#endif /* __APPLICATION_INC_BAREMETALUTIL_HPP__ */

/********************************* End Of File ********************************/
