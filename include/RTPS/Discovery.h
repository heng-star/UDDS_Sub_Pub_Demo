/************************************************************
** �ļ�����Discovery.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-13
** �޸��ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-03-05
** ��  ����Discoveryͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_DISCOVERY_H_INCLUDE_
#define _RTPS_DISCOVERY_H_INCLUDE_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ULINXAPI/uLinxTimer.h"
#include "ULINXAPI/uLinXSemMutex.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DomainParticipant;
class Topic;
class DataWriter;
class DataReader;
class ParticipantDataWriter;
class ParticipantDataReader;
class PublicationsDataWriter;
class PublicationsDataReader;
class SubscriptionsDataWriter;
class SubscriptionsDataReader;
class ParticipantMessageDataWriter;
class ParticipantMessageDataReader;
class Reader;

struct _StaticParticipantInfo_T;
struct _StaticDataWriter_T;
struct _StaticDataReader_T;

class Discovery{
public:
    Discovery(DomainParticipantImpl* pParticipant);

    virtual ~Discovery();

	//��ʼ������ģ��Ķ˵� ĿǰΪ6�����ö˵�
	ReturnCode_t DiscoveryInitiation(Duration_t ResendPeriod);

    //�㲥��Participant��Ϣ
    ReturnCode_t SendLocalParticipant(_ENTITY_STATUS_T Status = CREATION);

    //�㲥��Participant�˳�����Ϣ
    ReturnCode_t NotifyParticipantLogoff();

    //�����û�����ķ����˵���Ϣ
    ReturnCode_t SendPublicationData(DataWriterImpl* pDataWriter,_ENTITY_STATUS_T Status);

    //�����û�����Ķ��Ķ˵���Ϣ
    ReturnCode_t SendSubscriptionData(DataReaderImpl* pDataReader, _ENTITY_STATUS_T Status);

    //ƥ��DataReader
    //�����½�DataReader�����
    ReturnCode_t MatchDataReader(DataReaderImpl *pDataReaderImpl);

    //ƥ��DataWriter
    //�����½�DataWriter�����
    ReturnCode_t MatchDataWriter(DataWriterImpl *pDataWriterImpl);

	/* Nephalem ���ʹ������Ϣ */
	ReturnCode_t writeLivelinessMessage(EntityId_t& kind);

	/* Nephalem ��ȡSPDP���� */
	ReturnCode_t takeSPDPdiscoveredParticipantData();

	/* Nephalem ��ȡSEDP Writer����*/
	ReturnCode_t takeDiscoveredWriterData();

	/* Nephalem ��ȡSEDP Reader����*/
	ReturnCode_t takeDiscoveredReaderData();

	/* Nephalem ��ȡParticipantMessageData����*/
	ReturnCode_t takeParticipantMessageData();

	/* Nephalem ����writerGuid����ƥ��ı���reader */
	EntityId_t lookupMatchedReader(GUID_t& writerGuid);

	/* Nephalem ������inlineQos��Ϣ */
	ReturnCode_t takeinlineQoS(_PARAMETER_LIST & InlineQos);

	/* Nephalem �����Եķ���SPDPdiscoveredParticipantData */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static void CALLBACK sendSPDPdiscoveredParticipantDataPeriodically(void* discovery, unsigned char TimerOrWaitFired);

    static void CALLBACK checkRemoteParticipant(void* discovery, unsigned char TimerOrWaitFired);

	/* Nephalem ��������������� */
	static void CALLBACK writeAutomaticLiveliness(void* discovery, unsigned char TimerOrWaitFired);

	static void CALLBACK checkParticipantLiveLinessTask(void* discovery, unsigned char TimerOrWaitFired);

	static void CALLBACK checkLocalParticipantLiveLinessTask(void* discovery, unsigned char TimerOrWaitFired);

#elif defined ULINX_LINUX
    static void sendSPDPdiscoveredParticipantDataPeriodically(union sigval lpParam);

    static void checkRemoteParticipant(union sigval lpParam);

	static void writeAutomaticLiveliness(union sigval lpParam);

	static void checkParticipantLiveLinessTask(union sigval lpParam);

	static void checkLocalParticipantLiveLinessTask(union sigval lpParam);
#elif defined ULINX_VXWORKS
    static void sendSPDPdiscoveredParticipantDataPeriodically(timer_t timerid,int lpParam);

    static void checkRemoteParticipant(timer_t timerid,int lpParam);

	static void writeAutomaticLiveliness(timer_t timerid, int lpParam);

	static void checkParticipantLiveLinessTask(timer_t timerid, int lpParam);

	static void checkLocalParticipantLiveLinessTask(timer_t timerid, int lpParam);
#endif

	ReturnCode_t checkSPDPdiscoveredParticipantDataDeadline();

	ReturnCode_t startAutoLiveLinessWriteTask(const Time_t& lease_duration);

	ReturnCode_t startRemoteParticipantLiveLinessCheck(const Time_t& lease_duration);

	ReturnCode_t checkParticipantLiveLiness();

	ReturnCode_t startLocalParticipantLiveLinessCheck(const Time_t& lease_duration);

	ReturnCode_t checkLocalParticipantLiveLiness();

	/* Nephalem ���participant�Ƿ����� */
	ReturnCode_t checkRemoteParticipantDisconnect();

	/* Nephalem ��ȡ�ѷ��ֵ�Զ��DomainParticipant�б� */
	ReturnCode_t get_discovered_participants(InstanceHandleSeq& participantHandles);

	/* Nephalem ��ȡָ��Զ��DomainParticipant������ */
	ReturnCode_t get_discovered_participant_data(ParticipantBuiltinTopicData& participantData, const InstanceHandle_t& participantHandle);

	/* Nephalem ��ȡ�ѷ��ֵ�DataWriter�б� */
	ReturnCode_t get_publications(InstanceHandleSeq& publication_handles, bool include_contained_entities);

	/* Nephalem ��ȡָ����DataWriter��Ϣ */
	ReturnCode_t get_publication_data(struct PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* Nephalem ��ȡ�ѷ��ֵ�DataReader�б� */
	ReturnCode_t get_subscriptions(InstanceHandleSeq& subscription_handles, bool include_contained_entities);

	/* Nephalem ��ȡָ����DataReader��Ϣ */
	ReturnCode_t get_subscription_data(struct SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* Nephalem ���ķ���ģ�� */
	/* Nephalem �����������ķ��ֵĿͻ���datareader */
	ReturnCode_t  CreateClinetDataReader();


private:

	//ɾ�����ö˵�
	ReturnCode_t DiscoveryRelease();

	//�������õĶ˵�
	ReturnCode_t BuiltinEntityCreation(Duration_t ResendPeriod, Duration_t LeaseDuration);

    /* Nephalem ������������ DCPSParticipant �Լ��������д�ߺ����ݶ��� */
    ReturnCode_t CreateParticipantTopic();
	/* Nephalem ������������ DCPSPublication */
    ReturnCode_t CreatePublicationsTopic();
	/* Nephalem ������������ DCPSSubscription */
    ReturnCode_t CreateSubscriptionsTopic();
	/* Nephalem ������������ DCPSParticipantMessage ����;���⣬���ڴ�����Լ�������Ϣ */
	ReturnCode_t CreateParticipantMessageTopic();


	/* Nephalem ��������DCPSParticipant������д�� */
    ReturnCode_t CreateParticipantDataWriter();
    ReturnCode_t CreatePublicationsDataWriter();
    ReturnCode_t CreateSubscriptionsDataWriter();
	ReturnCode_t CreateParticipantMessageDataWriter();
    //�������ö�����
    ReturnCode_t CreateParticipantDataReader();
    ReturnCode_t CreatePublicationsDataReader();
    ReturnCode_t CreateSubscriptionsDataReader();
	ReturnCode_t CreateParticipantMessageDataReader();

	/*Nephalem ��ʼ��ParticipantDataWriter�Ĵ������ڷ��ͷ��ֱ��� */
	ReturnCode_t initParticipantDataWriterReaderProxy(Locator_t & locator);

	/*Nephalem ��ʼ��ParticipantMessageDataWriter�Ĵ��� */
	ReturnCode_t initParticipantMessageDataWriterReaderProxy();

	/* Nephalem ΪSEDP�˵����ô��� */
	ReturnCode_t configureSedpProxy(SPDPdiscoveredParticipantData& data);

	/* Nephalem ΪSEDP�˵��Ƴ�ָ��Զ�˲����ߵĴ��� */
	ReturnCode_t removeSedpProxy(GUID_t & remoteGuid);

	/* Nephalem ����SPDPdiscoveredParticipantData��Ϣ */
	ReturnCode_t receiveSPDPdiscoveredParticipantData(SPDPdiscoveredParticipantData& SpdpData);

	ReturnCode_t removeRemoteParticipant(GUID_t guid);

	/* Nephalem ����DiscoveredWriterData��Ϣ */
	ReturnCode_t receiveRemoteWriterData(DiscoveredWriterData& writerData);

	/* Nephalem ����µ�Զ��Writer */
	ReturnCode_t addNewRemoteWriter(DiscoveredWriterData& writerData);

	/* Nephalem Զ��writer��ע����ɾ�����ƥ����Ϣ�� */
	ReturnCode_t removeRemoteWriter(GUID_t& writerGuid);

	/* Nephalem ����DiscoveredReaderData��Ϣ */
	ReturnCode_t receiveRemoteReaderData(DiscoveredReaderData& readerData);

	/* Nephalem ����ParticipantMessageData��Ϣ */
	ReturnCode_t receiveParticipantMessageData(ParticipantMessageData& stParticipantMessageData);

	/* Nephalem ����µ�Զ��Reader */
	ReturnCode_t addNewRemoteReader(DiscoveredReaderData& readerData);

	ReturnCode_t removeRemoteReader(GUID_t& readerGuid);

	/* Nephalem ���ش��������ݶ�����Զ��ͬ����DataReader�Ƿ�ƥ�� */
	ReturnCode_t localDataWriterMatchRemoteReader(DataWriterImpl* pDataWriterImpl, DiscoveredReaderData& readerData);

	/* Nephalem ���ش���������д����Զ��ͬ����DataWriter�Ƿ�ƥ�� */
	ReturnCode_t localDataReaderMatchRemoteWriter(DataReaderImpl* pDataReaderImpl, DiscoveredWriterData& writerData);

	/* Nephalem ����Զ�˽ڵ�״̬��Ϣ */
	ReturnCode_t upDataGuidStatusInfo(GUID_t& remoteGuid,char Flag);

	/* Nephalem ����ƥ�� */
	bool matchPartition(PartitionQosPolicy& partitionA, PartitionQosPolicy& partitionB);

	/* JDXCZ ���о�̬DataWriter��ƥ�� */
	int staticDataWriterMatch(_StaticParticipantInfo_T* pStaticParticipant, WriterProxy* pWriterProxy);

	/* JDXCZ ���о�̬DataReader��ƥ�� */
	int staticDataReaderMatch(_StaticParticipantInfo_T* pStaticParticipant, WriterProxy* pWriterProxy);

	/* ����̬�����ļ���DataReaderתΪDiscoveredReaderData */
	int StaticDataReaderToDiscoverReaderData(_StaticDataReader_T* pDR, DiscoveredReaderData& discoveredReaderData);

	/* ����̬�����ļ���DataWriterתΪDiscoveredWriterData */
	int StaticDataWriterToDiscoverWriterData(_StaticDataWriter_T* pDW, DiscoveredWriterData& discoveredWriterData);

	/* ����̬�����ļ���DataReaderQosתΪDiscoveredReaderData */
	int DataReaderQosToDiscoverReaderData(DataReaderQos& pDRQos, DiscoveredReaderData& discoveredReaderData);

	/* ����̬�����ļ���DataWriterQosתΪDiscoveredWriterData */
	int DataWriterQosToDiscoverReaderData(DataWriterQos& pDRQos, DiscoveredWriterData& discoveredWriterData);

private:
    //������DomainParticipant
	DomainParticipantImpl* m_pDomainParticipantImpl;

    //DDS�����ö˵�
    ParticipantDataWriter* m_pBuiltinParticipantDataWriter;
    PublicationsDataWriter* m_pBuiltinPublicationsDataWriter;
    SubscriptionsDataWriter* m_pBuiltinSubscriptionsDataWriter;
	ParticipantMessageDataWriter* m_pBuiltinParticipantMessageDataWriter;

    ParticipantDataReader* m_pBuiltinParticipantDataReader;
    PublicationsDataReader* m_pBuiltinPublicationsDataReader;
    SubscriptionsDataReader* m_pBuiltinSubscriptionsDataReader;
	ParticipantMessageDataReader* m_pBuiltinParticipantMessageDataReader;

    //��������
    Topic* m_pDcpsParticipantTopic;
    Topic* m_pDcpsPublicationsTopic;
	Topic* m_pDcpsSubscriptionsTopic;
	Topic* m_pDcpsParticipantMessageTopic;

	/* Nephalem �����Զ��participant���� */
	map<GUID_t,SPDPdiscoveredParticipantData> m_RemoteParticipantList;
	/* Nephalem �����Զ��writer���� */
	map<GUID_t, DiscoveredWriterData>		  m_RemoteWriterList;
	/* Nephalem �����Զ��reader���� */
	map<GUID_t, DiscoveredReaderData>		  m_RemoteReaderList;

	/* Nephalem Զ��participant��Guid,Ϊ�˷����ȡ���������� */
	InstanceHandleSeq						  m_ParticipantHandleSeq;

	/* Nephalem Զ��DataWriter��Guid,Ϊ�˷����ȡ���������� */
	InstanceHandleSeq						  m_PublicationHandleSeq;

	/* Nephalem Զ��DataReader��Guid,Ϊ�˷����ȡ���������� */
	InstanceHandleSeq						  m_SubscriptionHandleSeq;

	/* Nephalem ����Զ��Writer��GUID�뱾��reader�Ķ�Ӧ��ϵ */
	map<GUID_t, EntityId_t>					  m_MatchedReader;

	/* Nephalem ����Զ��participant�Ļ����� */
	uLinX_SemMutex*							  m_RemoteParticipantListMutex;

	/* Nephalem ����Զ��DataWriter�Ļ����� */
	uLinX_SemMutex*							  m_RemoteWriterListMutex;

	/* Nephalem ����Զ��DataReader�Ļ����� */
	uLinX_SemMutex*							  m_RemoteReaderListMutex;

	/* Nephalem ��ʱ�������������Է���SPDPdiscoveredParticipantData���� */
	uLinxTimer*  m_SpdpTimer;

	uLinxTimer* m_SpdpCheckTimer;

	/* Nephalem ��ʱ���������Զ���������� */
	uLinxTimer* m_AutoLiveLinessTimer;

	/* Nephalem ��ʱ�������ڼ������ */
	uLinxTimer* m_LiveLinessCheckTimer;

	/* Nephalem ��ʱ�������ڼ�Ȿ��DataWriter����� */
	uLinxTimer* m_LocalLiveLinessCheckTimer;

	Time_t		m_AutoLiveLinessDuration;

	Time_t		m_AutoLiveLinessCheckDuration;

	Time_t		m_LocalLiveLinessCheckDuration;

	/* Nephalem �������ϴ���������ʱ�� */
	//map<GUID_t, Time_t>				m_MapParticipantliveTime;

};

#endif
