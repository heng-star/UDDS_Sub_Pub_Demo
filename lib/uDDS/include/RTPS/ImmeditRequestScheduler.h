/************************************************************
** 文件名：ImmeditRequestScheduler.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-11-14
** 修改人：无
** 日  期：无
** 描  述：ImmeditRequestScheduler头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_IMMEDITREQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_IMMEDITREQUESTEDSCHEDULER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/RequestScheduler.h"
#include "uLinxDataType.h"


//声明
class MessageProcessor;
class MessageTransmitter;
class Request;

class ImmeditRequestScheduler : public RequestScheduler
{
public:
	ImmeditRequestScheduler(MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter);
	virtual ~ImmeditRequestScheduler();

	//添加调度请求
	ReturnCode_t RequestAdd(Request *pRequest);

	//删除一个调度请求
	ReturnCode_t RequestRemove(Request *pRequest);

	////清除由某Endpoint所提出的调度请求
	//ReturnCode_t RequestClean(Endpoint *pEndpoint);

	////删除调度队列里面与pReaderProxy相关的Request
	//ReturnCode_t RequestClean(ReaderProxy *pReaderProxy);

	////删除调度队列里面与pWtiterProxy相关的Request
	//ReturnCode_t RequestClean(WriterProxy *pWriterProxy);

	//进行调度
	ReturnCode_t RequestScheduling();

//	ReturnCode_t RequestLastScheduling();

    static DWORD WINAPI ScheduleRun(void* lpRequestScheduler);
};
#endif
