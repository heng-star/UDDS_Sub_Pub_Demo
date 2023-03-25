/************************************************************
** �ļ�����AcknackMessageRequest.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����AcknackMessageRequestͷ�ļ�
** ��  ����Version 0.1
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
    
	/* Nephalem �����в����Ӵ�����ֹ��������߳���ռ��Դ */
	GUID_t pWriterGuid;

	_SEQUENCE_NUMBER_SET m_seqNumSet;

	RequestScheduler* m_pRequestScheduler;

};

#endif
