/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 12:35:38 AM
* #File Name    : Platform.cpp 
* #File Path    : /GezGor/Drivers/Platform/src/Platform.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "Platform.hpp"
#include <iostream>
/****************************** MACRO DEFINITIONS *****************************/

/********************************* NAME SPACE *********************************/

/******************************* LOCAL CLASSES ********************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

/***************************** CLASS VARIABLES ********************************/
namespace platform
{
Platform* Platform::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
Platform::Platform(void)
{}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
Platform::~Platform(void)
{
    delete (devices);
    delete (console);
    delete (system);
    delete (fileSys);
    delete (m_instance);

    m_instance = NULL_PTR;
}

/** \brief get instance, singleton class*/
Platform* Platform::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        m_instance = new Platform();
    }
    return m_instance;
}

RETURN_STATUS Platform::buildPlatform(void)
{
    RETURN_STATUS retVal = OK;

    retVal |= devices->openDevices();
    retVal |= console->init();

    return retVal;
}

}//namespace platform
/******************************** End Of File *********************************/
