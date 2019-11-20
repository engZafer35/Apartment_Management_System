/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:28:42 PM
* #File Name    : ConsoleLinux.cpp 
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/ConsoleLinux.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#include "ConsoleLinux.hpp"
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
ConsoleLinux* ConsoleLinux::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
ConsoleLinux::ConsoleLinux(void)
{
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
ConsoleLinux::~ConsoleLinux(void)
{
    m_instance = NULL_PTR;
}

ConsoleLinux* ConsoleLinux::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "ConsoleLinux Created";
        m_instance = new ConsoleLinux();
    }
    return m_instance;
}

/** \brief init console */
RETURN_STATUS ConsoleLinux::init(void)
{
    RETURN_STATUS retVal = SUCCESS;
    ZLOGF_IF(FAILURE == retVal) << "[E] ConsoleLinux init Error: !!";
    return retVal;
}

/**
 * \brief set console status
 *  \param set TRUE to active console
 */
RETURN_STATUS ConsoleLinux::consoleStatus(BOOL status)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

}
/******************************** End Of File *********************************/
