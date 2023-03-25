/************************************************************
** 文件名：AcknackMessageRequest.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-13
** 修改人：无
** 日  期：无
** 描  述：AcknackMessageRequest头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_ACKNACKMESSAGE_REQUEST_H_INCLUDED_
#define _RTPS_ACKNACKMESSAGE_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPS/Message.h"
#include "RTPS/WriterProxy.h"

class WriterProxy;
class MessageProcessor;
class MessageTransmitter;

class AcknackMessageRequest : public Request
{
public:
	AcknackMessageRequest(const EntityId_t entityId,
		WriterProxy *pWriterProxy,
		_SEQUENCE_NUMBER_SET& seqNumSet,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "Acknack")
		,m_seqNumSet(seqNumSet)
    {
		memcpy(pWriterGuid.guidPrefix, pWriterProxy->getGuid().guidPrefix, sizeof(GUID_t));
	};

    ReturnCode_t Execute();

	void SetRequestScheduler(RequestScheduler* pRequestScheduler)
	{
		m_pRequestScheduler = pRequestScheduler;
	}
	RequestScheduler* GetRequestScheduler()
	{
		return m_pRequestScheduler;
	}

private:
    
	/* Nephalem 请求中不增加代理，防止线与解析线程抢占资源 */
	GUID_t pWriterGuid;

	_SEQUENCE_NUMBER_SET m_seqNumSet;

	RequestScheduler* m_pRequestScheduler;

};

#endif
