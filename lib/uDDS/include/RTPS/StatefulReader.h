/************************************************************
** �ļ�����StatefulReader.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-11
** �޸��ˣ���
** ��  �ڣ���
** ��  ����StatefulReaderͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_STATEFULREADER_H_INCLUDED_
#define _RTPS_STATEFULREADER_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPS/Reader.h"
#include "RTPS/Message.h"
#include "RTPS/Request.h"

class WriterProxy;
class RequestScheduler;

class StatefulReader : public Reader 
{
public:
    //���캯��
    StatefulReader (
        GUID_t Guid,
        const DataReaderQos& pQos,
        RequestScheduler** pRequestScheduler);

    //��������
    virtual ~StatefulReader ();

	/* Nephalem �淶�ж���Ľӿ� */
	//����ƥ��ķ����˴���
   ReturnCode_t matched_writer_add (WriterProxy *pWriterProxy);

   //ɾ��ƥ��ķ����˴���
   ReturnCode_t matched_writer_remove (WriterProxy *pWriterProxy);

   //�����ض�ǰ׺�ķ����˴���
    WriterProxy* matched_writer_lookup (GUID_t writerGuid);

public:
	/* Nephalem �Զ���ӿ� */
	/* Nephalem �����û����� */
	virtual ReturnCode_t DataMessageReceive(_RECEIVER& MessageReceiver, _DATA_SUBMESSAGE& DataMessage, _PARAMETER_LIST& InlineQos, SerializedPayload serializedPayload,unsigned int uiDataLen);

	/* Nephalem �ɿ����ݽ��մ��� */
	ReturnCode_t ReliableDataMessageReceive(_CACHE_CHANGE* pCacheChange);

	/* Nephalem �����������ݽ��մ��� */
	ReturnCode_t BestEffortDataMessageReceive(_CACHE_CHANGE* pCacheChange);

	/* Nephalem �����û�HeartBeat���� */
	virtual ReturnCode_t HeartBeatMessageReceive(_RECEIVER& MessageReceiver,_HEARTBEAT_SUBMESSAGE& HeartBeatMessage) ;

	/* Nephalem �����û����ݷ�Ƭ���� */
	virtual ReturnCode_t DataFragMessageReceive(_RECEIVER& MessageReceiver, _DATA_FRAG_SUBMESSAGE& DataFragMessage, _DATA_FRAG& DataFrag, _PARAMETER_LIST& InlineQos, SerializedPayload serializedPayload, unsigned int uiDataLen);

	/* Nephalem �����û�GAP���� */
	virtual ReturnCode_t GapMessageReceive(_RECEIVER& MessageReceiver,_GAP_SUBMESSAGE& stGapMessage);

	RequestScheduler** GetRequestScheduler() 
    {
		return m_pScheduleList;
	}

	/* Nephalem ����Զ��д�ߴ����״̬ */
	ReturnCode_t setRemoteWriterLiveLiness(const GUID_t& Guid, const Time_t& curTime, LivelinessQosPolicyKind kind);

	/* Nephalem ���Զ��д�ߴ����״̬ */
	ReturnCode_t checkRemoteWriterLiveLiness(const Time_t& curTime);

	/* Nephalem ����Ƿ��п������ݲ��ύ��DataReader */
	ReturnCode_t submitAvailableData(WriterProxy* pWriterProxy);
	
	/* JD ����һ����ʱ���͵�AckRequest������  */
	int CreateAckNackRequest(WriterProxy* pWriterProxy, _SEQUENCE_NUMBER_SET seqNumSet);

private:

	_WRITER_PROXY_LIST_T m_MatchedWriter;

	/* Nephalem �Ѿ��ύ�������� */
	SequenceNumber_t m_LastChangeSequence;

	/* Nephalem �����Խ���Deadline�������� */
	Request* m_pDeadlineRequest;

};

#endif
