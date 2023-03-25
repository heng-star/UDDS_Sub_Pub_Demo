/************************************************************
** 文件名：RequestFactory.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-20
** 修改人：无
** 日  期：无
** 描  述：RequestFactory头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_REQUESTFACTORY_H_INCLUDED_
#define _RTPS_REQUESTFACTORY_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"

class Endpoint;
class WriterProxy;
class RequestScheduler;
class MessageProcessor;
class MessageTransmitter;
struct _FRAGMENT_NUMBER_SET;

class RequestFactory 
{
public:
    //生成新的请求
    static Request *CreateDataMessageRequest (
        Endpoint *pEndpoint,
		_READER_PROXY_LIST ReaderProxyList,
		_CACHE_CHANGE*  pCacheChange,
        RequestScheduler *pRequestScheduler);

    static Request *CreateDataMessageWithReaderProxy (
        Endpoint *pEndpoint,
		ReaderProxy *m_pReaderProxy,
        RequestScheduler *pRequestScheduler);

	static Request *CreateDataMessageRequest_L (
		Endpoint *pEndpoint,
        _CACHE_CHANGE *pCacheChange,
        RequestScheduler *pRequestScheduler);

    static Request *CreateHeartbeatMessageRequest (
		Endpoint *pEndpoint,
		_READER_PROXY_LIST ReaderProxyList,
        RequestScheduler *pRequestScheduler);

    static Request *CreateAcknackMessageRequest (
        Endpoint *pEndpoint,
        WriterProxy *pWriterProxy,
		_SEQUENCE_NUMBER_SET& seqNumSet,
        RequestScheduler *pRequestScheduler);

	static Request* CreateNackFragMessageRequest(
		Endpoint *pEndpoint,
		WriterProxy *pWriterProxy,
		SequenceNumber_t & writerSN,
		_FRAGMENT_NUMBER_SET& FragMentNumSet,
		RequestScheduler *pRequestScheduler);

    //static Request *CreateDeadlineRequest (
    //    Endpoint *pEndpoint,
    //    RequestScheduler *pRequestScheduler);

	static Request *CreateFragRepairRequest(
		Endpoint *pEndpoint,
        ReaderProxy * pReaderProxy,
		SequenceNumber_t & WriterSN,
		_FRAGMENT_NUMBER_SET & FragmentNumberSet,
        RequestScheduler *pRequestScheduler);
};


#endif
