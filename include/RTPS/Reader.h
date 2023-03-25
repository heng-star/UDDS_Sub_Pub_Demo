/************************************************************
** �ļ�����Reader.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-11
** �޸��ˣ���
** ��  �ڣ���
** ��  ����Readerͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_READER_H_INCLUDED_
#define _RTPS_READER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Endpoint.h"
#include "Message.h"

//����
class DataReaderImpl;
class HistoryCache;
class RequestScheduler;
class DDSContentFilter;

class Reader : public Endpoint 
{
public:
    //���캯��
    Reader (GUID_t Guid,
        const DataReaderQos& pQos,
        RequestScheduler** pRequestScheduler);

    //��������
    ~Reader ();

	/* Nephalem �����û����ݱ��� */
	virtual ReturnCode_t DataMessageReceive(
		_RECEIVER& MessageReceiver,
		_DATA_SUBMESSAGE& DataMessage,
		_PARAMETER_LIST& InlineQos,
		SerializedPayload serializedPayload,
		unsigned int uiDataLen
	) = 0;

	/* Nephalem �����û����ݷ�Ƭ���� */
	virtual ReturnCode_t DataFragMessageReceive(
		_RECEIVER& MessageReceiver,
		_DATA_FRAG_SUBMESSAGE& DataFragMessage,
		_DATA_FRAG& DataFrag,
		_PARAMETER_LIST& InlineQos,
		SerializedPayload serializedPayload,
		unsigned int uiDataLen
	) = 0;

	/* Nephalem �����û�HeartBeat���� */
	virtual ReturnCode_t HeartBeatMessageReceive(
		_RECEIVER& MessageReceiver,
		_HEARTBEAT_SUBMESSAGE& HeartBeatMessage
	) = 0;

	/* Nephalem �����û�GAP���� */
	virtual ReturnCode_t GapMessageReceive(
		_RECEIVER& MessageReceiver,
		_GAP_SUBMESSAGE& HeartBeatMessage
	) = 0;

	void setRelatedDataReader(DataReaderImpl* pDataReaderImpl);

	DataReaderImpl* getRelatedDataReader();

	void setReaderHistoryCache(HistoryCache* pHistoryCache);

    //����_CACHE_CHANGE
    _CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);
    _CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, SequenceNumber_t SeqNum, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);
	
	//JDXCZ ������cache�����һ���ֶΣ��жϴ�С�ˣ�
	//_CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle,_SUBMESSAGE_FLAG Flag);
	//_CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, SequenceNumber_t SeqNum, _CHANGE_KIND_T Kind, InstanceHandle_t Handle,_SUBMESSAGE_FLAG Flag);

    //֪ͨDDS DataReader���ݵ���
    //ReturnCode_t DataNotify(SequenceNumber_t LocalSeqNum);

    //��ȡ�����ظ�Heartbeat���ĵ�ʱ��
    Duration_t HeartbeatSuppressionDuration() 
    {
        return m_HeartbeatSuppressionDuration;
    }

    //��ȡHeartbeat���Ļظ���ʱ
    Duration_t HearbeatResponseDelay() 
    {
        return m_HeartbeatResponseDelay;
    }

    //��ȡ���ձ��ĵĽ�ֹ��Deadline
    Duration_t Deadline() {
        return m_Deadline;
    }

    //��ʼ�����ȶ���
    virtual ReturnCode_t ScheduleListInit() 
    {
        return RETCODE_OK;
    }

    //����Ƿ�����Ӧ��Writer�ڷ��͸�ʵ��
    //bool noWriters(InstanceHandle_t Handle);

 //   //��ȡʵ��״̬
 //   ReturnCode_t GetInstanceState(InstanceHandle_t Handle, InstanceStateKind& InstanceState);

	////����ʵ��״̬
	//ReturnCode_t InstanceUpdate(GUID_t WriterGuid, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);

    SequenceNumber_t GetNewChangeSeqNum() 
    {
        return ++m_LastChangeSeqNum;
    }

	//void SetSeqNumNotify(SequenceNumber_t SeqNum);

protected:
	/* Nephalem �淶�ж���ı��� */

	/* Nephalem �Ƿ�ʹ��inlineQoS */
	bool			m_bExpectsInlineQos;
    /* Heartbeat���Ļظ���ʱ */
    Duration_t		m_HeartbeatResponseDelay;
    /* �����ظ���Heartbeat���ĵ�ʱ�� */
    Duration_t		m_HeartbeatSuppressionDuration;

	/* Nephalem ���߻����� */
	HistoryCache *m_pReaderCache;

	/* Nephalem ��Ƭ������ */
	HistoryCache *m_pFragDataCache;

protected:
    //�����±��ĵĽ�ֹ��
    Duration_t m_Deadline;

    //�������ɵ�Change�����к�
    SequenceNumber_t m_LastChangeSeqNum;

    //���ȶ��У�0ΪImmeditRequestScheduler��1ΪPeriodRequestScheduler
    RequestScheduler** m_pScheduleList;

	/* Nephalem ������ݶ���*/
	DataReaderImpl *m_pRelatedDataReaderImpl;

    //�Ͻ���SequenceNumber
    SequenceNumber_t m_HighestSeqNumNotify;

	DataReaderQos m_dataReaderQos;
};

#endif
