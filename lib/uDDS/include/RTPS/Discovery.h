/************************************************************
** 文件名：Discovery.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-13
** 修改人：Nephalem<250610346@qq.com>
** 日  期：2011-03-05
** 描  述：Discovery头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_DISCOVERY_H_INCLUDE_
#define _RTPS_DISCOVERY_H_INCLUDE_

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ULINXAPI/uLinxTimer.h"
#include "ULINXAPI/uLinXSemMutex.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
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

	//初始化发现模块的端点 目前为6个内置端点
	ReturnCode_t DiscoveryInitiation(Duration_t ResendPeriod);

    //广播本Participant信息
    ReturnCode_t SendLocalParticipant(_ENTITY_STATUS_T Status = CREATION);

    //广播本Participant退出的信息
    ReturnCode_t NotifyParticipantLogoff();

    //发送用户定义的发布端的信息
    ReturnCode_t SendPublicationData(DataWriterImpl* pDataWriter,_ENTITY_STATUS_T Status);

    //发送用户定义的订阅端的信息
    ReturnCode_t SendSubscriptionData(DataReaderImpl* pDataReader, _ENTITY_STATUS_T Status);

    //匹配DataReader
    //本地新建DataReader后调用
    ReturnCode_t MatchDataReader(DataReaderImpl *pDataReaderImpl);

    //匹配DataWriter
    //本地新建DataWriter后调用
    ReturnCode_t MatchDataWriter(DataWriterImpl *pDataWriterImpl);

	/* Nephalem 发送存活性信息 */
	ReturnCode_t writeLivelinessMessage(EntityId_t& kind);

	/* Nephalem 提取SPDP数据 */
	ReturnCode_t takeSPDPdiscoveredParticipantData();

	/* Nephalem 提取SEDP Writer数据*/
	ReturnCode_t takeDiscoveredWriterData();

	/* Nephalem 提取SEDP Reader数据*/
	ReturnCode_t takeDiscoveredReaderData();

	/* Nephalem 提取ParticipantMessageData数据*/
	ReturnCode_t takeParticipantMessageData();

	/* Nephalem 根据writerGuid查找匹配的本地reader */
	EntityId_t lookupMatchedReader(GUID_t& writerGuid);

	/* Nephalem 处理用inlineQos信息 */
	ReturnCode_t takeinlineQoS(_PARAMETER_LIST & InlineQos);

	/* Nephalem 周期性的发送SPDPdiscoveredParticipantData */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static void CALLBACK sendSPDPdiscoveredParticipantDataPeriodically(void* discovery, unsigned char TimerOrWaitFired);

    static void CALLBACK checkRemoteParticipant(void* discovery, unsigned char TimerOrWaitFired);

	/* Nephalem 周期性声明存活性 */
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

	/* Nephalem 检查participant是否还在线 */
	ReturnCode_t checkRemoteParticipantDisconnect();

	/* Nephalem 获取已发现的远端DomainParticipant列表 */
	ReturnCode_t get_discovered_participants(InstanceHandleSeq& participantHandles);

	/* Nephalem 获取指定远端DomainParticipant的数据 */
	ReturnCode_t get_discovered_participant_data(ParticipantBuiltinTopicData& participantData, const InstanceHandle_t& participantHandle);

	/* Nephalem 获取已发现的DataWriter列表 */
	ReturnCode_t get_publications(InstanceHandleSeq& publication_handles, bool include_contained_entities);

	/* Nephalem 获取指定的DataWriter信息 */
	ReturnCode_t get_publication_data(struct PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* Nephalem 获取已发现的DataReader列表 */
	ReturnCode_t get_subscriptions(InstanceHandleSeq& subscription_handles, bool include_contained_entities);

	/* Nephalem 获取指定的DataReader信息 */
	ReturnCode_t get_subscription_data(struct SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* Nephalem 中心发现模块 */
	/* Nephalem 创建用于中心发现的客户端datareader */
	ReturnCode_t  CreateClinetDataReader();


private:

	//删除内置端点
	ReturnCode_t DiscoveryRelease();

	//创建内置的端点
	ReturnCode_t BuiltinEntityCreation(Duration_t ResendPeriod, Duration_t LeaseDuration);

    /* Nephalem 创建内置主题 DCPSParticipant 以及相关数据写者和数据读者 */
    ReturnCode_t CreateParticipantTopic();
	/* Nephalem 创建内置主题 DCPSPublication */
    ReturnCode_t CreatePublicationsTopic();
	/* Nephalem 创建内置主题 DCPSSubscription */
    ReturnCode_t CreateSubscriptionsTopic();
	/* Nephalem 创建内置主题 DCPSParticipantMessage 多用途主题，用于存活性以及其他信息 */
	ReturnCode_t CreateParticipantMessageTopic();


	/* Nephalem 创建内置DCPSParticipant的数据写者 */
    ReturnCode_t CreateParticipantDataWriter();
    ReturnCode_t CreatePublicationsDataWriter();
    ReturnCode_t CreateSubscriptionsDataWriter();
	ReturnCode_t CreateParticipantMessageDataWriter();
    //创建内置订阅者
    ReturnCode_t CreateParticipantDataReader();
    ReturnCode_t CreatePublicationsDataReader();
    ReturnCode_t CreateSubscriptionsDataReader();
	ReturnCode_t CreateParticipantMessageDataReader();

	/*Nephalem 初始化ParticipantDataWriter的代理，用于发送发现报文 */
	ReturnCode_t initParticipantDataWriterReaderProxy(Locator_t & locator);

	/*Nephalem 初始化ParticipantMessageDataWriter的代理 */
	ReturnCode_t initParticipantMessageDataWriterReaderProxy();

	/* Nephalem 为SEDP端点配置代理 */
	ReturnCode_t configureSedpProxy(SPDPdiscoveredParticipantData& data);

	/* Nephalem 为SEDP端点移除指定远端参与者的代理 */
	ReturnCode_t removeSedpProxy(GUID_t & remoteGuid);

	/* Nephalem 接收SPDPdiscoveredParticipantData信息 */
	ReturnCode_t receiveSPDPdiscoveredParticipantData(SPDPdiscoveredParticipantData& SpdpData);

	ReturnCode_t removeRemoteParticipant(GUID_t guid);

	/* Nephalem 接收DiscoveredWriterData信息 */
	ReturnCode_t receiveRemoteWriterData(DiscoveredWriterData& writerData);

	/* Nephalem 添加新的远端Writer */
	ReturnCode_t addNewRemoteWriter(DiscoveredWriterData& writerData);

	/* Nephalem 远端writer已注销，删除相关匹配信息等 */
	ReturnCode_t removeRemoteWriter(GUID_t& writerGuid);

	/* Nephalem 接收DiscoveredReaderData信息 */
	ReturnCode_t receiveRemoteReaderData(DiscoveredReaderData& readerData);

	/* Nephalem 接收ParticipantMessageData信息 */
	ReturnCode_t receiveParticipantMessageData(ParticipantMessageData& stParticipantMessageData);

	/* Nephalem 添加新的远端Reader */
	ReturnCode_t addNewRemoteReader(DiscoveredReaderData& readerData);

	ReturnCode_t removeRemoteReader(GUID_t& readerGuid);

	/* Nephalem 本地创建的数据读者与远端同名的DataReader是否匹配 */
	ReturnCode_t localDataWriterMatchRemoteReader(DataWriterImpl* pDataWriterImpl, DiscoveredReaderData& readerData);

	/* Nephalem 本地创建的数据写者与远端同名的DataWriter是否匹配 */
	ReturnCode_t localDataReaderMatchRemoteWriter(DataReaderImpl* pDataReaderImpl, DiscoveredWriterData& writerData);

	/* Nephalem 更新远端节点状态信息 */
	ReturnCode_t upDataGuidStatusInfo(GUID_t& remoteGuid,char Flag);

	/* Nephalem 分区匹配 */
	bool matchPartition(PartitionQosPolicy& partitionA, PartitionQosPolicy& partitionB);

	/* JDXCZ 进行静态DataWriter的匹配 */
	int staticDataWriterMatch(_StaticParticipantInfo_T* pStaticParticipant, WriterProxy* pWriterProxy);

	/* JDXCZ 进行静态DataReader的匹配 */
	int staticDataReaderMatch(_StaticParticipantInfo_T* pStaticParticipant, WriterProxy* pWriterProxy);

	/* 将静态配置文件中DataReader转为DiscoveredReaderData */
	int StaticDataReaderToDiscoverReaderData(_StaticDataReader_T* pDR, DiscoveredReaderData& discoveredReaderData);

	/* 将静态配置文件中DataWriter转为DiscoveredWriterData */
	int StaticDataWriterToDiscoverWriterData(_StaticDataWriter_T* pDW, DiscoveredWriterData& discoveredWriterData);

	/* 将静态配置文件中DataReaderQos转为DiscoveredReaderData */
	int DataReaderQosToDiscoverReaderData(DataReaderQos& pDRQos, DiscoveredReaderData& discoveredReaderData);

	/* 将静态配置文件中DataWriterQos转为DiscoveredWriterData */
	int DataWriterQosToDiscoverReaderData(DataWriterQos& pDRQos, DiscoveredWriterData& discoveredWriterData);

private:
    //关联的DomainParticipant
	DomainParticipantImpl* m_pDomainParticipantImpl;

    //DDS层内置端点
    ParticipantDataWriter* m_pBuiltinParticipantDataWriter;
    PublicationsDataWriter* m_pBuiltinPublicationsDataWriter;
    SubscriptionsDataWriter* m_pBuiltinSubscriptionsDataWriter;
	ParticipantMessageDataWriter* m_pBuiltinParticipantMessageDataWriter;

    ParticipantDataReader* m_pBuiltinParticipantDataReader;
    PublicationsDataReader* m_pBuiltinPublicationsDataReader;
    SubscriptionsDataReader* m_pBuiltinSubscriptionsDataReader;
	ParticipantMessageDataReader* m_pBuiltinParticipantMessageDataReader;

    //内置主题
    Topic* m_pDcpsParticipantTopic;
    Topic* m_pDcpsPublicationsTopic;
	Topic* m_pDcpsSubscriptionsTopic;
	Topic* m_pDcpsParticipantMessageTopic;

	/* Nephalem 保存的远端participant数据 */
	map<GUID_t,SPDPdiscoveredParticipantData> m_RemoteParticipantList;
	/* Nephalem 保存的远端writer数据 */
	map<GUID_t, DiscoveredWriterData>		  m_RemoteWriterList;
	/* Nephalem 保存的远端reader数据 */
	map<GUID_t, DiscoveredReaderData>		  m_RemoteReaderList;

	/* Nephalem 远端participant的Guid,为了方便获取，单独保存 */
	InstanceHandleSeq						  m_ParticipantHandleSeq;

	/* Nephalem 远端DataWriter的Guid,为了方便获取，单独保存 */
	InstanceHandleSeq						  m_PublicationHandleSeq;

	/* Nephalem 远端DataReader的Guid,为了方便获取，单独保存 */
	InstanceHandleSeq						  m_SubscriptionHandleSeq;

	/* Nephalem 保存远端Writer的GUID与本地reader的对应关系 */
	map<GUID_t, EntityId_t>					  m_MatchedReader;

	/* Nephalem 保护远端participant的互斥锁 */
	uLinX_SemMutex*							  m_RemoteParticipantListMutex;

	/* Nephalem 保护远端DataWriter的互斥锁 */
	uLinX_SemMutex*							  m_RemoteWriterListMutex;

	/* Nephalem 保护远端DataReader的互斥锁 */
	uLinX_SemMutex*							  m_RemoteReaderListMutex;

	/* Nephalem 定时器，用于周期性发送SPDPdiscoveredParticipantData数据 */
	uLinxTimer*  m_SpdpTimer;

	uLinxTimer* m_SpdpCheckTimer;

	/* Nephalem 定时器，用于自动声明存活性 */
	uLinxTimer* m_AutoLiveLinessTimer;

	/* Nephalem 定时器，用于检测存活性 */
	uLinxTimer* m_LiveLinessCheckTimer;

	/* Nephalem 定时器，用于检测本地DataWriter存活性 */
	uLinxTimer* m_LocalLiveLinessCheckTimer;

	Time_t		m_AutoLiveLinessDuration;

	Time_t		m_AutoLiveLinessCheckDuration;

	Time_t		m_LocalLiveLinessCheckDuration;

	/* Nephalem 参与者上次声明存活的时间 */
	//map<GUID_t, Time_t>				m_MapParticipantliveTime;

};

#endif
