/************************************************************
** �ļ�����ReaderProxy.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-12
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ReaderProxyͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef RTPS_READERPROXY_INCLUDED_H
#define RTPS_READERPROXY_INCLUDED_H

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

class Writer;
class HistoryCache;
class StatefulWriter;

typedef list<ChangeForReader> ChangeForReaderList;

/* Nephalem Զ��Reader���������̷߳������ݡ�����HB�����̡߳������߳�ack���Ĵ��� */
/* �ж����漰���ʱ���ʹ�û��������б��� */
class ReaderProxy
{
public:
    //���캯��
    ReaderProxy( GUID_t ReaderGuid,
		_LOCATOR_LIST_T UnicastLocatorList,
		_LOCATOR_LIST_T MulticastLocatorList,
		bool bIsActive);

    //��������
    //virtual ~ReaderProxy();

	/* Nephalem �淶�ж���ķ��� */
	/* Nephalem ���ֵС�ڵ���committed_seq_num��״̬��ΪACKNOWLEDGED */
	ReturnCode_t acked_changes_set(SequenceNumber_t& committed_seq_num);

	/* Nephalem ����״̬ΪREQUESTED����С���е�ChangeForReader */
	ChangeForReader next_requested_change();

	///* Nephalem ����״̬ΪUNSENT����С���е�ChangeForReader */
	//ChangeForReader& next_unsent_change();

	///* Nephalem ����״̬ΪUNSENT������ChangeForReader */
	//_CHANGE_FOR_READER_LIST unsent_changes();

	///* Nephalem ����״̬ΪREQUESTED������ChangeForReader */
	//_CHANGE_FOR_READER_LIST requested_changes();

	/* Nephalem ��ָ������ŵ�״̬ȫ����Ϊ���� */
	ReturnCode_t requested_changes_set(_SEQUENCE_NUMBER_SET& req_seq_num_set);

	/* Nephalem ����״̬ΪUNACKNOWLEDGED������ChangeForReader */
	ChangeForReaderList unacked_changes();

public:
	/* Nephalem �Զ��巽�� */
	/* Nephalem ����HistoryCache��ʼ��ChangesForReaderList �����µĴ���ʱ��ִ�д˲��� */
	ReturnCode_t initChangesForReaderList(HistoryCache* pWriterCache);

	/* Nephalem ���ò���ص����� */
	ReturnCode_t setIrrelevantChange(SequenceNumber_t& unacked_seq_num);

	/* Nephalem ��ȡԶ��reader��GUID */
	GUID_t getGuid();

	/* Nephalem ��ȡ��С��δ��ȷ�ϵ����ݵ���� ���ڷ���HeartBeat���� */
	SequenceNumber_t getUnacknowledgedMinSeq();

	/* Nephalem ��ȡ����������� ���ڷ���HeartBeat����  */
	SequenceNumber_t getMaxSeq();

	/* Nephalem ��������ִ�к� ����Ӧ����������״̬��Ϊδȷ�� */
	ReturnCode_t unacked_changes_set(SequenceNumber_t& unacked_seq_num);

	/* Nephalem �Ƿ񱻴���ȷ���ѽ��յ� */
	bool isAckedByReader(SequenceNumber_t & seq);

	/* Nephalem ��ȡԶ��reader�Ľ��յ�����ַ */
	_LOCATOR_LIST_T getUnicastLocatorList();

    //���ChangeForReader����
    ChangeForReader* ChangeForReaderAdd(const _CACHE_CHANGE* pCacheChange );

    /* Nephalem ������ɾ��ָ����ŵ�ChangeForReader */
    ReturnCode_t ChangeForReaderRemove(SequenceNumber_t& Seq);

	/* Nephalem ��ָ������ŵ�״̬ȫ����Ϊ����undeway */
	ReturnCode_t undeway_changes_set(SequenceNumber_t& undeway_seq_num);

	ReturnCode_t setQos(DiscoveredReaderData & readerData);

    //���ý��յ�AckNack���ı��
    ReturnCode_t SetAckNackLastCount (_COUNT_T Count) 
    {
        m_AckNackLastCount = Count;

        return RETCODE_OK;
    }

    SequenceNumber_t HighestSeqNumAcked() 
    {
        return m_HighestSeqNumAcked;
    }

    //�Ƿ���ڶಥ��ַ
    bool MulticastExist() 
    {
        if (m_MulticastLocatorList.size() == 0)
            return false;
        return true;
    }

	//��ȡ��Ըö��Ķ˴����͵��������ĸ���
	unsigned long GetHBSendTimes()
	{
		return m_ulHBSendTimes;
	}

	//���Ӷ��Ķ˴����͵��������ĸ���
	void IncreaseHBSendTimes()
	{
		m_ulHBSendTimes++;
	}

	/* Nephalem Զ��reader�Ƿ��writer������Ӧ */
	bool isActive();

	/* JD ������־��¼��Ҫ����Ϣ*/
	int SetDDSInfo(const int iDomainCount,const string TopicName);

	/* �ж��Ƿ���Ҫ�ظ�������HB���� */
	bool GetSendUnicastHeartbeatFlag();
	
	int SetSendUnicastHeartbeatFlag(bool bFlag);

private:
	/* Nephalem �淶�ж���ı��� */
    /* Զ�˶��Ķ˵��GUID */
    GUID_t					m_RemoteReaderGuid;
    /* Զ�˶��Ķ˵�����ַ�б� */
	_LOCATOR_LIST_T         m_UnicastLocatorList;
    /*  Զ�˶��Ķ˶ಥ��ַ�б� */
    _LOCATOR_LIST_T         m_MulticastLocatorList;
    /* ReaderProxy��ChangeForReader�б� */
	ChangeForReaderMap		m_ChangesForReader;//�޸�
	/* Nephalem �Ƿ���inlineQos */
	bool					m_bExpectsInlinesQos;
	/* Nephalem Զ��reader�Ƿ��writer������Ӧ */
    bool					m_bIsActive;
private:

	/* Nephalem ����������ChangesForReader���ж�д���� */
	uLinX_SemMutex		ChangesForReaderMutex;
    //������յ���AckNack���ĵ����к�
    _COUNT_T             m_AckNackLastCount;

    //�ѷ���_CACHE_CHANGE��������к�
    SequenceNumber_t    m_HighestSeqNumSent;

    //�ѱ�ȷ�ϵ�_CACHE_CHANGE��������к�
    SequenceNumber_t    m_HighestSeqNumAcked;

    //��һ�ο��Խ���Nack��ʱ��
    Time_t              m_NextNackAllowedTime;

    //�´��ط�Data���ĵ�ʱ��
    Time_t              m_NextRepairTime;

	//��Ըö��Ķδ����͵��������ĸ���
	unsigned long m_ulHBSendTimes;

	/* JD 2021 �����־ʱ����Ҫ��ȡ����Ϣ*/
	int m_iDomainCount;

	string m_strTopicName;

	DataReaderQos m_stQos;
	/* JDXCZ 2022-07-14 ��̬ƥ����Ҫ�ж��Ƿ���Ҫ�ظ��������������� true-�ظ���false-���ظ� */
	bool m_bUnicastHeartbeatFlag;

};

#endif
