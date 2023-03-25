/************************************************************
** �ļ�����HeartbeatMessageRequest.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����HeartbeatMessageRequestͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_HEARTBEATMESSAGE_REQUEST_H_INCLUDED_
#define _RTPS_HEARTBEATMESSAGE_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPSBasicTypes.h"

class ReaderProxy;
class HeartbeatMessageRequest : public Request
{
public:
	HeartbeatMessageRequest(
		const EntityId_t entityId,
		_READER_PROXY_LIST ReaderProxyList,
		MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter,
		Time_t StartTime,
		Time_t EndTime) :
	Request (entityId,pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "HeartBeat")
		, m_bForcedSend(false)
	{
	};

	ReturnCode_t Execute();

	/* JD ����ǿ�Ʒ���HB���� */
	ReturnCode_t SetForcedSendFlag(bool bFlag);
	/* JD ��ȡǿ�ƻظ��ı�־λ */
	bool GetForcedSendFlag();
private:
	/* Nephalem ʹ�ø��Ƶ����ݣ����������߳�ʹ�ù�����Դ */
	_READER_PROXY_LIST m_ReaderProxyList;

	/* JDXCZ ǿ�ƻظ�HB���� */
	bool m_bForcedSend;
};

#endif
