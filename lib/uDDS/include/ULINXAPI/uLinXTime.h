#pragma once

#include "uLinxDataType.h"

#if (defined( ULINX_WIN) ||  defined(_WIN32)) 

typedef LARGE_INTEGER ULINX_MS64;

#elif defined ULINX_LINUX

typedef long long ULINX_MS64;   //毫秒数 64位

#elif defined ULINX_VXWORKS

typedef long long ULINX_MS64;   //毫秒数 64位

#endif 

//typedef long long ULINX_MS64;   //毫秒数 64位

namespace uLinX
{
	class TimeDifference_us
	{
	public:
		TimeDifference_us();
		~TimeDifference_us();

		//获取与上次调用该函数之间的时间差，单位为微秒
		static ULINX_INT64 getTimeDifference();

		//获取当前的Tick
		static ULINX_INT64 getCurrentTick();
		//计算两次Tick之间的时间差，单位微秒
		static ULINX_INT64 getTimeDifference(ULINX_INT64 FirstTick, ULINX_INT64 SecTick);

	private:
		static ULINX_MS64 m_StartPoint;
	};
}
