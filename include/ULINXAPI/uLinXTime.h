#pragma once

#include "uLinxDataType.h"

#if (defined( ULINX_WIN) ||  defined(_WIN32)) 

typedef LARGE_INTEGER ULINX_MS64;

#elif defined ULINX_LINUX

typedef long long ULINX_MS64;   //������ 64λ

#elif defined ULINX_VXWORKS

typedef long long ULINX_MS64;   //������ 64λ

#endif 

//typedef long long ULINX_MS64;   //������ 64λ

namespace uLinX
{
	class TimeDifference_us
	{
	public:
		TimeDifference_us();
		~TimeDifference_us();

		//��ȡ���ϴε��øú���֮���ʱ����λΪ΢��
		static ULINX_INT64 getTimeDifference();

		//��ȡ��ǰ��Tick
		static ULINX_INT64 getCurrentTick();
		//��������Tick֮���ʱ����λ΢��
		static ULINX_INT64 getTimeDifference(ULINX_INT64 FirstTick, ULINX_INT64 SecTick);

	private:
		static ULINX_MS64 m_StartPoint;
	};
}
