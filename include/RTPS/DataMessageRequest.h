/************************************************************
** �ļ�����DataMessageRequest.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����DataMessageRequestͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_DATAMESSAGE_REQUEST_H_INCLUDED_
#define _RTPS_DATAMESSAGE_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPSBasicTypes.h"

class ReaderProxy;

/* Nephalem ����ߴ����б��е����д�����ָ������ һ�����û����÷��ͽӿں�ʹ�� */
/* ReaderProxyList Ϊ��Ҫ���͵��Ĵ����б� */
/* _CACHE_CHANGE   Ϊ��Ҫ���͵�����       */
/* �ɿ�����						          */

class DataMessageRequest : public Request
{
public:
	DataMessageRequest(const EntityId_t entityId,
		_READER_PROXY_LIST ReaderProxyList,
		_CACHE_CHANGE*  pCacheChange ,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "Data")
		, m_ReaderProxyList(ReaderProxyList),m_pCacheChange(pCacheChange)
    {
    };

    ReturnCode_t Execute();

	ReturnCode_t sendDataMessage(unsigned int & uiShift);

	ReturnCode_t sendDataFragMessage(unsigned int & uiShift);

private:
	_READER_PROXY_LIST m_ReaderProxyList;

	_CACHE_CHANGE*  m_pCacheChange;

};

#endif
