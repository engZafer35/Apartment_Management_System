/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Jan 7, 2020 - 3:16:55 PM
* #File Name    : AppWorkingModeManager.hpp
* #File Path    : /ApartmentManagementSystem/Application/AprtMngSystem/Modules/inc/inc_/AppWorkingModeManager.hpp
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_WORKING_MODE_MANAGER_HPP__
#define __APP_WORKING_MODE_MANAGER_HPP__
/*********************************INCLUDES*************************************/
#include "GlobalDefinitions.hpp"
/******************************* NAME SPACE ***********************************/

/**************************** MACRO DEFINITIONS *******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/********************************* CLASS **************************************/
namespace redbird
{
class WorkingMode
{
public:
    typedef enum _SYSTEM_MODE
    {
        EN_MODE_WORKING,
        EN_MODE_MAINTENANCE,
        EN_MODE_FAILURE,
    }SYSTEM_MODE;
public:
    WorkingMode(void);
    ~WorkingMode(void);

    /**
     * \brief  set mode
     * \param  mode type
     * \return if everything is OK, return RET_SUCCES(0)
     *         otherwise return RET_FAILURE(-1)
     */
    RETURN_STATUS setMode(SYSTEM_MODE mode);
    RETURN_STATUS operator =(SYSTEM_MODE mode);

    /**
     * \brief  get current mode type
     * \return mode type
     */
    inline SYSTEM_MODE getMode(void) const
    {
        return m_mode;
    }

private:
    RETURN_STATUS setWorkingMode(void);
    RETURN_STATUS setMaintenanceMode(void);
    RETURN_STATUS setFailureMode(void);

private:
    static SYSTEM_MODE m_mode;
};

}//namespace redbird
#endif /* __APP_WORKING_MODE_MANAGER_HPP__ */

/********************************* End Of File ********************************/
