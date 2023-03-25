#pragma once
#include "uLinxDataType.h"

#if (defined( ULINX_WIN) ||  defined(_WIN32))
#include <winnt.h>

/* Nephalem 即 VOID  (*callBackFun)(PVOID lpParam, BOOLEAN TimerOrWaitFired ); */
typedef WAITORTIMERCALLBACK callBackFun;

#elif defined ULINX_LINUX

#include <signal.h>
#include <time.h>
typedef void (*callBackFun)(union sigval v);
#elif defined ULINX_VXWORKS
#include <time.h>

typedef void (*callBackFun)(timer_t timerid,int v);
#endif

class uLinxTimer
{
public:

	uLinxTimer();
	~uLinxTimer();

	/* Nephalem 设置定时器参数，win平台下 */
	int Settimer(int iSecond,int iMilliSecond, callBackFun TimerFun,void* arg);
	int CloseTimer();

private:
#if (defined( ULINX_WIN) ||  defined(_WIN32))
	HANDLE	m_hTimerQueue;
	HANDLE	m_hTimerQueueTimer;
#elif defined ULINX_LINUX || defined ULINX_VXWORKS
    timer_t m_timer;
#elif ULINX_VXWORKS

#endif

};
