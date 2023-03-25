/************************************************************
** �ļ�����WriterProxy.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-11
** �޸��ˣ���
** ��  �ڣ���
** ��  ����WriterProxyͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_WRITERPROXY_H_INCLUDED_
#define _RTPS_WRITERPROXY_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "RTPS/Message.h"

class RequestScheduler;
class StatefulReader;
class Endpoint;

class WriterProxy 
{
public:
    //���캯��
    WriterProxy(GUID_t WriterGuid,
        _LOCATOR_LIST_T UnicastLocatorList,
        _LOCATOR_LIST_T MulticastLocatorList);

    //��������
    //virtual ~WriterProxy();

public:
	/* Nephalem �淶�ж���Ľӿ� */
	/* Nephalem ������������ݵı�� */
	SequenceNumber_t available_changes_max();

	ReturnCode_t irrelevant_change_set(SequenceNumber_t seqNum);

	/* Nephalem ��С�ڸñ����״̬ΪMISSING��UNKNOWN������״̬�޸�ΪLOST */
	ReturnCode_t lost_changes_update(SequenceNumber_t& fistAvailableSeqNum);

	///* Nephalem ��������״̬ΪMISSING�����ݵı�� */
	//vector<SequenceNumber_t> missing_changes();

	/* Nephalem ��С�ڸñ����״̬ΪUNKNOWN������״̬�޸�ΪMISSING */
	ReturnCode_t missing_changes_update(SequenceNumber_t& lastAvailableSeqNum);

	/* Nephalem ��ָ�����ݵ�״̬����ΪRECEIVED */
	ReturnCode_t received_change_set(SequenceNumber_t seqNum);

public:
	/* Nephalem �Զ���ӿ� */
	/* Nephalem ���CacheChang�������� */
	ReturnCode_t addCacheChange(_CACHE_CHANGE* pCacheChange);

	/* Nephalem ����HB���� ����First��Last�������Ƿ���ڣ������ڵ��򴴽�UNKNOWN״̬������ */
	ReturnCode_t checkCacheChange(SequenceNumber_t& fistAvailableSeqNum, SequenceNumber_t& lastAvailableSeqNum);

	/* Nephalem ����HB���� ���ݻ������е�MISS״̬����ReaderSNState */
	ReturnCode_t getReaderSNState(_SEQUENCE_NUMBER_SET& SeqNumSet);

	/* Nephalem ����HB���� �ж��Ƿ����ظ���HB���ģ��ظ��Ļ��ɺ��ԣ����ظ�����±��ؼ�¼��ֵ */
	bool ignoreHeartBeat(unsigned int heartBeatCount);

	/* Nephalem ��ȡ���õ����� */
	_CACHE_CHANGE* getAvailableChanges(SequenceNumber_t maxAvailableNum);

	/* Nephalem ��ȡָ����ŵ�ChangeFromWriter */
	ChangeFromWriter& getChangeFromWriter(SequenceNumber_t& SeqNumber);

	/* Nephalem �������ô�С�����������·�Ƭ���ݵĹ��ڻ�����Ҫ�ֶ��ͷ� */
	ReturnCode_t resize(int size);

	/* Nephalem ���ݷ�Ƭ������� ����NackFarg */
	ReturnCode_t CreateNackFragRequest(Endpoint *pEndpoint, RequestScheduler *pRequestScheduler);

	/* Nephalem �������ݱ��+1 */
	void addAvailableNum();

	/* Nephalem ��ȡwriter��guid */
	GUID_t getGuid();

	/* Nephalem ��ȡԶ�˷����ߵĵ������յ�ַ */
	_LOCATOR_LIST_T getUnicastLocatorList();

	ReturnCode_t SetDDSInfo(int iDomainCount,string TopicNames);

	/* Nephalem ת������Qos */
	ReturnCode_t setQos(DiscoveredWriterData & writerData);

	/* Nephalem ���´����״̬ʱ�� */
	ReturnCode_t updataLiveLinessTime(const Time_t& curTime);

	/* Nephalem ���ô����״̬ */
	ReturnCode_t setLiveLinessStatus(bool bAlive);

	/* Nephalem ����LifeSpan */
	ReturnCode_t setLifeSpan(Time_t& curTime);

	int checkLiveLiness(const Time_t& curTime, const Time_t& lease_duration);
	
	/* JD 20220720 ���ý��յ�HB���ĵ����  */
	void SetHeartbeatCount(unsigned int uiHeartBeatCount);
	
	/* JD 20220720 ��ȡ���յ�HB���ĵ���� */
	unsigned int GetHeartbeatCount();

private:
	/* Nephalem �淶�ж���ı��� */
	//Զ�˷����˵�GUID
	GUID_t m_RemoteWriterGuid;

	//������ַ�б�
	_LOCATOR_LIST_T m_UnicastLocatorList;

	//�ಥ��ַ�б�
	_LOCATOR_LIST_T m_MulticastLocatorList;

	/* Nephalem �洢writer���͵����ݣ����ǵ��ɿ�������Ҫ����ʹ��Map*/
	ChangeFromWriterMap m_ChangesFromWriter;

private:

	/* Nephalem */
	/* Nephalem ���ύ���ݵ�����ţ��ñ�ŵ����ݿ����Ѿ����ύ��  �����ݻᱻHB���� */
	SequenceNumber_t m_AvailableSeqNum;

	/* Nephalem �ϴν��յ���̬��ţ��ظ���ŵ�HB���Ĳ��ٽ��� */
	unsigned int m_uiHeartBeatCount;

	/* Nephalem DataWriterQos*/
	DataWriterQos m_stQos;

	/* Nephalem liveliness״̬ */
	bool m_bAlive;

	/* Nephalem �ϴμ�¼�Ĵ����Ϣʱ�� */
	Time_t m_stLiveLinessTime;

	/* ��־��¼�������Ϣ */
	int m_iDomainCount;

	string m_strTopicName;

};

#endif
