/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Jun 21, 2019 - 3:07:02 PM
* #File Name    : GlobalDefinitions.hpp
* #File Path    :
*
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __GLOBAL_DEFINITIONS_H__
#define __GLOBAL_DEFINITIONS_H__

/*********************************INCLUDES*************************************/
#include <functional>
/******************************MACRO DEFINITIONS*******************************/
#define MCU_16BIT   (16)
#define MCU_32BIT   (32)

//Select project mcu bit size
#define MCU_BIT_SIZE_DEF (MCU_32BIT)

#define OK (0)
#define FAILURE (-1)

#ifndef FALSE
    #define FALSE 0
    #define TRUE  1
#endif

#ifndef PASSIVE
    #define PASSIVE (0)
#endif
#ifndef ACTIVE
    #define ACTIVE (1)
#endif

#define WAIT_100_MS     (100)
#define WAIT_200_MS     (200)
#define WAIT_500_MS     (500)
#define WAIT_1_SEC      (1000)
#define WAIT_2_SEC      (2000)
#define WAIT_3_SEC      (3000)
#define WAIT_4_SEC      (4000)
#define WAIT_5_SEC      (5000)
#define WAIT_6_SEC      (6000)
#define WAIT_7_SEC      (7000)
#define WAIT_8_SEC      (8000)
#define WAIT_9_SEC      (9000)
#define WAIT_10_SEC     (10000)
#define WAIT_15_SEC     (15000)
#define WAIT_20_SEC     (20000)
#define WAIT_30_SEC     (30000)
#define WAIT_40_SEC     (40000)
#define WAIT_50_SEC     (50000)
#define WAIT_1_MIN      (60000)
#define WAIT_5_MIN      (300000)
#define WAIT_10_MIN     (600000)
#define WAIT_20_MIN     (1200000)
#define WAIT_30_MIN     (1800000)
#define WAIT_40_MIN     (2400000)
#define WAIT_50_MIN     (3000000)
#define WAIT_1_HOUR     (6600000)

#define TIME_OUT_10MS   (10)
#define TIME_OUT_20MS   (20)
#define TIME_OUT_50MS   (50)
#define TIME_OUT_75MS   (75)
#define TIME_OUT_100MS  (100)
#define TIME_OUT_200MS  (200)
#define TIME_OUT_500MS  (500)
#define TIME_OUT_1000MS (1000)
#define TIME_OUT_2000MS (2000)

#define NULL_PTR_C ((void *)0) //Null pointer C style

#if (__cplusplus >= 201103L)
    #define NULL_PTR   (nullptr)   //Null pointer C++11
#else
    #define NULL_PTR (NULL)      //Null pointer C++ legacy
#endif

#define IS_NULL_PTR(x)     (NULL_PTR == x)
#define IS_SAFELY_PTR(x)   (NULL_PTR != x)

#define SAFE_FREE(x)   do{ if(x) { free(x); x = NULL_PTR; } }while(0)
#define SAFE_DELETE(x) do{ if(x) { delete(x); x = NULL_PTR; } }while(0)

typedef std::function<void(void)> VoidCallback;

#if (MCU_BIT_SIZE_DEF == MCU_16BIT)
    typedef signed char         S8;
    typedef unsigned char       U8;
    typedef int                 S16;
    typedef S16                 SSS; //signed system size
    typedef unsigned int        U16;
    typedef U16                 USS; //unsigned system size
    typedef long                S32;
    typedef unsigned long       U32;
    typedef long long           S64;
    typedef unsigned long long  U64;
    typedef float               FLOAT;
    typedef double              DOUBLE;
    typedef USS                 BOOL;
    typedef BOOL                FLAG;

    typedef SSS                 RETURN_STATUS;
    #define MAX_USS_NUM         (0xFFFF) //max 16bit unsigned value

#elif (MCU_BIT_SIZE_DEF == MCU_32BIT)
    typedef signed char         S8;
    typedef unsigned char       U8;
    typedef short int           S16;
    typedef unsigned short int  U16;
    typedef int                 S32;
    typedef S32                 SSS; //signed system size
    typedef unsigned int        U32;
    typedef U32                 USS; //unsigned system size
    typedef long long           S64;
    typedef unsigned long long  U64;
    typedef float               FLOAT;
    typedef double              DOUBLE;
    typedef USS                 BOOL;
    typedef BOOL                FLAG;

    typedef SSS                 RETURN_STATUS;
    #define MAX_USS_VAL         (0xFFFFFFFF) //max 32bit unsigned value

#else
    #error "Firstly define MCU bit size in GlobalTypedef.h"
#endif


/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* __GLOBAL_DEFINITIONS_H__ */

/********************************* End Of File ********************************/
