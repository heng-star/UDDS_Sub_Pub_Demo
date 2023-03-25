/************************************************************
** 文件名：PeriodRequestScheduler.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-11-14
** 修改人：无
** 日  期：无
** 描  述：PeriodRequestScheduler头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_PERIODREQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_PERIODREQUESTEDSCHEDULER_H_INCLUDED_

/* Nephalem 用户头文件 */
#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/RequestScheduler.h"
#include "ULINXAPI/uLinxTimer.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */


//声明
class MessageProcessor;
class MessageTransmitter;
class Request;
class TimerManager;

class PeriodRequestScheduler : public RequestScheduler
{
public:
	PeriodRequestScheduler(MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter);
	//virtual ~PeriodRequestScheduler();

	//添加调度请求
	ReturnCode_t RequestAdd(Request *pRequest);

	//删除一个调度请求
	ReturnCode_t RequestRemove(Request *pRequest);

	////清除由某Endpoint所提出的调度请求
	//ReturnCode_t RequestClean(Endpoint *pEndpoint);

	////删除调度队列里面与readerProxy相关的Request
	//ReturnCode_t RequestClean(ReaderProxy *pReaderProxy);

	////删除调度队列里面与wtiterProxy相关的Request
	//ReturnCode_t RequestClean(WriterProxy *pWriterProxy);


//	//检查m_RequestList是否存在相应request
//	bool RequestExist(Request *pRequest);
//
#if (defined( ULINX_WIN) ||  defined(_WIN32))
	static VOID CALLBACK TimeRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired = false);
#elif defined ULINX_LINUX
    static void  TimeRoutine(union sigval lpParam);
#elif defined ULINX_VXWORKS
    static void  TimeRoutine(timer_t timerid,int lpParam);
#endif

private:
	//ReturnCode_t RequestExecute(Request *pRequest);
	map<Request*,uLinxTimer*> m_pTimerMap;
};
#endif
