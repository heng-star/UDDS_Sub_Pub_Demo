/************************************************************
** �ļ�����Writer.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-12
** �޸��ˣ���
** ��  �ڣ���
** ��  ����DataWriterͷ�ļ�
** ��  ����Writer 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_WRITER_INCLUDED_H
#define _RTPS_WRITER_INCLUDED_H

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Endpoint.h"


class HistoryCache;
class RequestScheduler;
class DataWriter;

class Writer : public Endpoint
{
public:
    //���캯��
    Writer( GUID_t            Guid,
		const DataWriterQos&	dataWriterQoS,
        RequestScheduler  **pScheduleList );

    //��������
    virtual ~Writer();

	//����һ��_CACHE_CHANGE
	_CACHE_CHANGE* new_change(const char *pData, int iLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);

public:
	/* Nephalem �Զ���ӿ� */
	/* Nephalem ����writer��HistoryCache */
	void setWriterHistoryCache(HistoryCache* pHistoryCache);

	/* Nephalem LastChangeSequence���ݱ�� + 1*/
	void addLastChangeSequence();

	/* Nephalem ��ȡƥ���ϵ�DataReader������ */
	virtual unsigned int GetMatchDataReaderNum() = 0;

	//�����ݷ����������������� �麯�� �ṩ�ӿ�
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange) = 0;

	/* Nephalem �Ƴ�ָ��Change statelesswriter��ʱ����  */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq) = 0;

	/* Nephalem ���ݷ�����Ĵ����� */
	//virtual ReturnCode_t DataSendFindish(SequenceNumber_t Seq) = 0;





    //��ȡWriter����Ϣ
    //_WRITER_PROXY_DATA* getWriterInfo();
    //virtual HistoryCache* GetWriterCache();
    //virtual Duration_t* GetNackResponseDelay();
    //virtual RequestScheduler* GetScheduleList();

    //���ض�Ӧ�Ļ�����ָ��
    HistoryCache* GetWriterCache() 
    {
        return m_pWriterCache;
    }

    //��ȡ�����±��ĵĽ�ֹ��
    Time_t Deadline() 
    {
        return m_Deadline;
    }

    //��ȡHeartbeat���ķ�������
    Duration_t HeartbeatPeriod() 
    {
        return m_HeartbeatPeriod;
    }

    Duration_t GetNackResponseDelay() 
    {
        return m_NackResponseDelay;
    };

    Duration_t GetNackSuppressionDuration() 
    {
        return m_NackSuppressionDuration;
    };


	RequestScheduler** Request_Scheduler() 
    {
		return m_pScheduleList;
	}

	void setRelatedDataWriter(DataWriterImpl* pDataWriter);

	DataWriterImpl* GetRelatedDataWriter()
    {
		return m_pRelatedDataWriterImpl;
	}

	/* Nephalem ���´����״̬ʱ�� */
	ReturnCode_t updataLiveLinessTime(LivelinessQosPolicyKind kind);

	/* Nephalem ���ô����״̬ */
	int checkLiveLiness(const Time_t& curTime);


protected:
    /* Nephalem �淶�ж���ĵı��� */
	/* Nephalem true��ֱ�ӷ��� false��ͨ��HB-ACK���� */
    bool             m_bPushMode;
    //Heartbeat��������
    Duration_t       m_HeartbeatPeriod;
    //�ظ�Nack���ĵ���ʱ
    Duration_t       m_NackResponseDelay;
    //����һ��ʱ���ڵ��ظ�Nack����
    Duration_t       m_NackSuppressionDuration;
	/* ��һ�����ɵ�Change�����к� */
	SequenceNumber_t m_LastChangeSequence;

	//��Ӧ�Ļ�����
	HistoryCache     *m_pWriterCache;

    //��һ�η��ͱ��ĵ�ʱ��
    Time_t           m_DataSendTime;
    //�����±��ĵĽ�ֹ��
    Duration_t       m_Deadline;
    //�Ѿ��ɹ����͵�Change�����к�
    SequenceNumber_t m_HighestSeqNumFinished;
    //��Ӧ��DDS DataWriter
    DataWriterImpl     *m_pRelatedDataWriterImpl;
    //���ȶ��У�0ΪImmeditRequestScheduler��1ΪPeriodRequestScheduler
    RequestScheduler **m_pScheduleList;

	DataWriterQos   m_dataWriterQoS;

	/* Nephalem �ϴμ�¼�Ĵ��ʱ�� */
	Time_t			m_stLiveLinessTime;

	/* Nephalem liveliness״̬ */
	bool m_bAlive;
};

#endif
