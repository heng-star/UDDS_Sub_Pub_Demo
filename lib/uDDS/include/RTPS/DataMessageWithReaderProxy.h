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
#ifndef _RTPS_DATAMESSAGEMULTI_REQUEST_H_INCLUDED_
#define _RTPS_DATAMESSAGEMULTI_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"

class ReaderProxy;

/* Nephalem ���ָ��ReaderProx���Ƿ���ڱ������͵����ݣ�һ�����ڽ��յ�Ack���ĺ󣬽��������ش� */
class DataMessageWithReaderProxy : public Request
{
public:
    DataMessageWithReaderProxy (const EntityId_t entityId,
		ReaderProxy *m_pReaderProxy,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "DataMessageWithReaderProxy")
		, m_pReaderProxy(m_pReaderProxy)
    {
    };

    ReturnCode_t Execute();

	ReturnCode_t sendDataMessage(unsigned int & uiShift, _CACHE_CHANGE*  pCacheChange, Endpoint* pEndpoint);

	ReturnCode_t sendDataFragMessage(unsigned int & uiShift, _CACHE_CHANGE*  pCacheChange, Endpoint* pEndpoint);

private:
    ReaderProxy *m_pReaderProxy;
};

#endif
