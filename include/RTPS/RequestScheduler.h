/************************************************************
** 文件名：RequestScheduler.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-13
** 修改人：无
** 日  期：无
** 描  述：RequestScheduler头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_REQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_REQUESTEDSCHEDULER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"



#define SCHEDULER_LENGTH 10000
#include "ULINXAPI/uLinXSemMutex.h"
//声明
class MessageProcessor;
class MessageTransmitter;
class Request;
class WriterProxy;
class ReaderProxy;
typedef list<Request *> _REQUEST_LIST_T;

class RequestScheduler
{
public:
    RequestScheduler(MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter);
	virtual ~RequestScheduler();

    //添加调度请求
    virtual ReturnCode_t RequestAdd(Request *pRequest) = 0;

    //删除一个调度请求
    virtual ReturnCode_t RequestRemove(Request *pRequest) = 0;

 //   //清除由某Endpoint所提出的调度请求
 //   virtual ReturnCode_t RequestClean(Endpoint *pEndpoint) = 0;

	////删除调度队列里面与readerProxy相关的Request
	//virtual ReturnCode_t RequestClean(ReaderProxy *pReaderProxy) = 0;

	////删除调度队列里面与wtiterProxy相关的Request
	//virtual ReturnCode_t RequestClean(WriterProxy *pWriterProxy) = 0;

    //进行调度
    //ReturnCode_t RequestScheduling();

    MessageProcessor *GetMessageProcessor()
    {
        return m_pMessageProcessor;
    }

    MessageTransmitter *GetMessageTransmitter ()
    {
        return m_pMessageTransmitter;
    }

//private:
//    virtual ReturnCode_t RequestExecute(Request *pRequest) = 0;
	bool  isRun();

	void setRunFlag(bool flag);

	bool isStop();

	void setStopFlag();

protected:
    //报文处理端
    MessageProcessor *m_pMessageProcessor;

    MessageTransmitter *m_pMessageTransmitter;
    //调度队列
    _REQUEST_LIST_T m_RequestList;

    //wangyi 2021/8/25 HeartBeat调度队列
    _REQUEST_LIST_T m_RequestHeartBeatList;
	uLinX_SemMutex* m_pRequestListMutex;

	uLinX_SemAphore* m_pRequestListAphore;

private:
	bool m_bRunFlag;

	bool m_bStopFlag;
};

#endif
