/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Nov 19, 2019 - 4:10:52 PM
* #File Name    : DrvInterruptRegister.cpp
* #File Path    : /GezGor/Drivers/Platform/PlatformLinux/src/DrvInterruptRegister.cpp
*******************************************************************************/

/*********************************INCLUDES*************************************/
#ifdef __linux
#include <pthread.h>

#include "ProjectConf.hpp"
#include "DrvInterruptRegister.hpp"
#include "TimerLinux.hpp"

/******************************MACRO DEFINITIONS*******************************/
#define NUMBER_OF_FDS  (20)
#define INVALID_FD     (-1)

#define DEBUG_SELECT   (0)
/*******************************TYPE DEFINITIONS ******************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/**********************************VARIABLES***********************************/
static int  volatile highestFd = 0;
static pthread_t    stid;
static SelectStruct selectStructs[NUMBER_OF_FDS];
static fd_set       masterfs;

/*****************************PRIVATE FUNCTIONS********************************/
static void *listenFds(void *arg)
{
    int     i;
    static  fd_set  rfds;
    struct  timeval tvBackup;
    struct  timeval tv;
    int     retVal;

    FD_ZERO(&rfds);

    tvBackup.tv_sec = 0;
    tvBackup.tv_usec = TIMER_CHECK_CYCLE * 1000; // ms

    tv  = tvBackup;

    while(1)
    {
        if (highestFd > 0)
        {
            rfds = masterfs;

            // listen
            retVal = select(highestFd +1, &rfds, NULL, NULL, &tv);

            if (retVal == -1)
            {
                // error
            }
            else if (retVal)
            {
                for (i = 0; i < NUMBER_OF_FDS; i++)
                {
                    if (selectStructs[i].fd != INVALID_FD)
                    {
                        ZLOG << "FD: " << selectStructs[i].fd;

                        if (FD_ISSET(selectStructs[i].fd, &rfds))
                        {
                            FD_CLR(selectStructs[i].fd, &rfds); //

                            ZLOG << "Signal To" << selectStructs[i].fd;

                            if (selectStructs[i].Vcb != NULL)
                            {
                                selectStructs[i].Vcb(selectStructs[i].fd); // send signal
                            }
                        }
                    }
                }
            }
            else  // it is because of timeout
            {
                platform::delayMs(TIMER_CHECK_CYCLE);
                platform::Platform::getInstance()->devices->timer->runCallback();

                /* tv value cleared so reset time tick value */
                tv = tvBackup;
            }        }
        else
        {
            platform::delayMs(TIMER_CHECK_CYCLE);
            platform::Platform::getInstance()->devices->timer->runCallback();
        }
    }

    return NULL;
}

/*******************************PUBLIC FUNCTIONS*******************************/
int drvIntRegisterInit(void)
{
    int i;

    FD_ZERO(&masterfs);

    for (i = 0; i < NUMBER_OF_FDS; i++)
    {
        selectStructs[i].fd  = INVALID_FD;
        selectStructs[i].Vcb = NULL;
    }

    highestFd = 0; //

    // create Thread
    pthread_create(&stid, NULL, &listenFds, NULL);

    return OK;
}

int drvIntRegisterFd(SelectStruct selectStruct)
{
    int i;
    int retVal;
    int freeIndex = -1;

    for (i = 0; i < NUMBER_OF_FDS; i++)
    {
        /* check it is exist */
        if (selectStructs[i].fd == selectStruct.fd)
        {
            break; // it is exist so go overwrite it
        }
        /* check is there free */
        else if (selectStructs[i].Vcb == NULL)
        {
            if (freeIndex == -1)
            {
                freeIndex = i;
            }
        }
    }

    if (i != NUMBER_OF_FDS)
    {
        freeIndex = i; // it is exist so overwrite it
    }

    if (freeIndex != -1)
    {
        selectStructs[freeIndex].Vcb = selectStruct.Vcb;
        selectStructs[freeIndex].fd  = selectStruct.fd;

        if (selectStructs[freeIndex].fd > highestFd)
        {
            highestFd = selectStructs[freeIndex].fd;
        }

        // set fd
        FD_SET(selectStructs[freeIndex].fd, &masterfs);

        retVal = OK;
    }
    else
    {
        retVal = FAILURE; // not registered
    }

    return  retVal;
}

int drvIntUnregisterFd(int fd)
{
    int i;
    int retVal;
    int isFind = 0;
    int maxFd = 0;

    for (i = 0; i < NUMBER_OF_FDS; i++)
    {
        if (selectStructs[i].fd ==  fd)
        {
            selectStructs[i].Vcb = NULL;
            selectStructs[i].fd  = INVALID_FD;
            isFind = 1;
            //
            FD_CLR(fd, &masterfs); //
        }
        else
        {
            if (selectStructs[i].fd > maxFd)
            {
                maxFd = selectStructs[i].fd;
            }
        }
    }

    if (isFind)
    {
        highestFd = maxFd; // new max point
        retVal    = OK;
    }
    else
    {
        retVal = FAILURE;
    }

    return  retVal;
}

#endif//#ifdef __linux
