/************************************************************
** �ļ�����StatefulWriter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-12
** �޸��ˣ���
** ��  �ڣ���
** ��  ����StatefulWriterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_STATEFULWRITER_INCLUDED_H
#define _RTPS_STATEFULWRITER_INCLUDED_H

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Writer.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

class RequestScheduler;
class ReaderProxy;
class Request;

class StatefulWriter : public Writer
{
public:
    //���캯��
    StatefulWriter(GUID_t Guid,
        const DataWriterQos& dataWriterQoS,
        RequestScheduler  **pScheduleList);

    /* �������� */
    virtual ~StatefulWriter();

	/* Nephalem �淶�ж���Ľӿ� */
	 //���ƥ��Ķ��Ķ˴���
    ReturnCode_t matched_reader_add( ReaderProxy* pReaderProxy);

    //ɾ��ƥ��Ķ��Ķ˴���
    ReturnCode_t matched_reader_remove( ReaderProxy* pReaderProxy);

    //ɾ���ض�ǰ׺�Ķ��Ķ˴���
	ReaderProxy* matched_reader_lookup(GUID_t guid);

	/* Nephalem �շ����ݱ����ж���ȷ�Ͻ��յ�,
	����Ack����ʱ���ã�ɾ������ʱ ����*/
	bool is_acked_by_all(/*_CACHE_CHANGE* a_change*/ SequenceNumber_t & Seq);

public:

	/* Nephalem �Զ���ӿ� */
	_READER_PROXY_LIST getMatchedReaderProxy();

	/* Nephalem ����AckNack���� */ 
    ReturnCode_t AckNackMessageReceive(_RECEIVER& MessageReceiver, _ACKNACK_SUBMESSAGE& ackSubMessage);

	/* Nephalem ����NackFrag���� */
	ReturnCode_t NackFragMessageReceive(_RECEIVER& MessageReceiver, _NACK_FRAG_SUBMESSAGE& NackFragSubMessage);


	//������ 2013-09-04 �޸�
	unsigned int GetMatchDataReaderNum();

	//�����ݷ����������������� �麯�� �ṩ�ӿ�
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange);

	/* Nephalem �Ƴ�ָ��Change �ɿ������»���������ʱ��
	���������ѱ����д���ȷ�Ͻ��յ�ʱ���Ƴ�������
	ͬʱ�Ƴ�������ChangForReader  */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq);

	/* JD 20211014 ���� heartbeat ���������������������� */
	ReturnCode_t SetHeartBeatRequest(const int iDomainCount,string TopicName);

private:

	/* Nephalem ����ѱ�ȷ�Ͻ��յ������� */
	ReturnCode_t removeAckedChange();

private:
    //ƥ��Ķ��Ķ˴����б�
    _READER_PROXY_LIST m_MatchedReaderList; //�޸�

	/* Nephalem �����Է������������� */
	Request* m_pHeartBeatRequest;

	/* Nephalem ���ڱ���m_MatchedReaderList */
	uLinX_SemMutex* m_MatchedReaderMutex;
};

#endif
