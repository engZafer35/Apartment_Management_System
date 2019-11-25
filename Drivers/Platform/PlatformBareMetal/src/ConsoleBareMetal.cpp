/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Nov 17, 2019 - 11:28:42 PM
* #File Name    : ConsoleBareMetal.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformBareMetal/src/ConsoleBareMetal.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "ProjectConf.hpp"
#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
#include "ConsoleBareMetal.hpp"
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
ConsoleBareMetal* ConsoleBareMetal::m_instance = NULL_PTR;
}
/***************************** CLASS PRIVATE METHOD ***************************/
namespace platform
{
ConsoleBareMetal::ConsoleBareMetal(void)
{
}
}//namespace platform
/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace platform
{
ConsoleBareMetal::~ConsoleBareMetal(void)
{
    m_instance = NULL_PTR;
}

ConsoleBareMetal* ConsoleBareMetal::getInstance(void)
{
    MutexLockFunc mutex; //guarantee to create just one object
    if(NULL_PTR == m_instance)
    {
        ZLOG << "ConsoleBareMetal Created";
        m_instance = new ConsoleBareMetal();
    }
    return m_instance;
}

/** \brief init console */
RETURN_STATUS ConsoleBareMetal::init(void)
{
    RETURN_STATUS retVal = OK;
    ZLOGF_IF(FAILURE == retVal) << "[I] ConsoleBareMetal init OK !!";
    return retVal;
}

/**
 * \brief set console status
 *  \param set TRUE to active console
 */
RETURN_STATUS ConsoleBareMetal::consoleStatus(BOOL status)
{
    RETURN_STATUS retVal = OK;

    return retVal;
}

}
#endif //#if (CURRENT_PLATFORM == PLATFORM_BARE_METAL)
/******************************** End Of File *********************************/
