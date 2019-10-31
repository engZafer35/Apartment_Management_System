/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Oct 24, 2019 - 8:34:58 AM
* #File Name    : TimerEventProducer.cpp 
* #File Path    : /GezGor/Application/src/TimerEventProducer.cpp
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/

/********************************* INCLUDES ***********************************/
#include "TimerEventProducer.hpp"
#include <unistd.h>
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

/***************************** CLASS PRIVATE METHOD ***************************/

/***************************** CLASS PROTECTED METHOD *************************/

/***************************** CLASS PUBLIC METHOD ****************************/
namespace event
{

TimerEventProducer::TimerEventProducer(void){}

//void TimerEventProducer::start(void)
//{
//
//}

void TimerEventProducer::doControl(void)
{
    static int z[256];
    static int x = 0;
    ::sleep(1);

    z[x] = x;

    std::cout << x << " timer event throw" << std::endl;
    throwEvent(EN_EVENT_1, EN_SOURCE_3, EN_PRIORITY_2, &(z[x]), sizeof(x));
    x++;
}

//void TimerEventProducer::run(void)
//{
//
//}

}//namespace event
/******************************** End Of File *********************************/
