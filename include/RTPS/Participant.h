/************************************************************
** 文件名：participant.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-11
** 修改人：无
** 日  期：无
** 描  述：participant头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "QoSPolicy.h"
#include "RTPS/RTPSEntity.h"
#include "ULINXAPI/uLinXThread.h"
#include "ULINXAPI/uLinXSemMutex.h"
/* Nephalem 系统头文件 */


/* Nephalem 前置声明 */
class DomainParticipantImpl;
class Topic;
class TopicDescription;
class DataWriter;
class DataReader;
class HistoryCache;
class Endpoint;
class Writer;
class Reader;
class MessageProcessor;
class MessageTransmitter;
class RequestScheduler;
class ReceiveBuffer;
struct _DATA_SUBMESSAGE;
struct _DATA_FRAG_SUBMESSAGE;
struct _HEARTBEAT_SUBMESSAGE;
struct _ACKNACK_SUBMESSAGE;
struct _NACK_FRAG_SUBMESSAGE;

typedef map<EntityId_t, Endpoint*>_ENDPOINT_MAP_T;
class Participant : public RTPSEntity 
{
public:
    //构造函数
    Participant (GUID_t Guid,DomainParticipantImpl *pDomainParticipant);

    //析构函数
    virtual ~Participant ();

	/* Nephalem 初始化participant的各项资源 */
	ReturnCode_t initParticipant();

    //创建发布端映射 Writer
    Writer *CreateWriter (const DataWriterQos& dataWriterQoS, EntityId_t EntityID = ENTITYID_UNKNOW);

    //删除发布端映射 Writer
    ReturnCode_t DeleteWriter (Writer *pWriter);

    //创建订阅端映射 Reader
	Reader *CreateReader(const DataReaderQos & dataReaderQoS, EntityId_t EntityID = ENTITYID_UNKNOW);

    //删除订阅端映射 Reader
    ReturnCode_t DeleteReader (Reader *pReader);

	/* Nephalem 判断要查找的Endpoint是否存在 */
	bool isEndpointExist(const EntityId_t& entityId);

    //根据entityId 取走对应的端点，包括Writer和Reader，使用完后需要使用return 接口返回
    Endpoint * takeEndpoint(const EntityId_t& entityId);

	ReturnCode_t returnEndpoint(Endpoint * pEndpoint);

	/* Nephalem 根据writerGuid查找匹配的本地reader */
	Reader* lookupMatchedReader(GUID_t& writerGuid);

	/* Nephalem 获取SPDP组播发现地址 */
	_LOCATOR_LIST_T getDefaultMulticastLocatorList();

	/* Nephalem 获取本地使用的单播地址列表*/
	_LOCATOR_LIST_T getDefaultUnicastLocatorList();

    //获取协议版本号
	ProtocolVersion_t getProtocolVersion();

    //获取厂商编号
	VendorId_t getVendorId();

	/* Nephalem 获取使用的内部端点 */
	BuiltinEndpointSet_t getAvailableBuiltinEndpoints();
	
		/* JD 2021.10.08 添加获取DomainParticipant 接口*/
	DomainParticipantImpl* getDomainParticipantImpl();

	/* Nephalem 启动请求执行线程、数据接收线程、数据处理线程 */
	ReturnCode_t startThread();

	/* Nephalem 结束内部线程 */
	ReturnCode_t stopThread();

	ReturnCode_t stoppRecvThread();

	ReturnCode_t stopDispatchThread();

	ReturnCode_t stopSendThread();

	/* Nephalem 更新远端写者存活时间 */
	ReturnCode_t setRemoteWriterLiveLiness(const GUID_t& Guid, const Time_t& curTime, LivelinessQosPolicyKind kind);

	/* Nephalem 检查远端写者存活时间 */
	ReturnCode_t checkRemoteWriterLiveLiness(const Time_t& curTime);

	/* Nephalem 检查本地写者存活时间 */
	ReturnCode_t checkLocalWriterLiveLiness(const Time_t& curTime);

	/* Nephalem 更新本地写者存活时间 */
	ReturnCode_t upDataLocalWriterLiveLiness(LivelinessQosPolicyKind kind);
private:

	/* Nephalem 初始化本地网络资源 */
	ReturnCode_t initLoaclNet();
	
    //初始化Locator
 //   ReturnCode_t LocatorInitial(_IP_LIST_T DefaultIpList);

	//HANDLE SendTaskStart();
	//HANDLE ReceiveTaskStart();
	//HANDLE DispatchTaskStart();

private:
    //RTPS协议 版本
    ProtocolVersion_t m_ProtocolVersion;

    //生产厂商编号
    VendorId_t m_VendorId;

	/* Nephalem 使用的内部端点 */
	BuiltinEndpointSet_t	m_AvailableBuiltinEndpoints;

    //默认单播地址列表  用于接收数据的单播地址
    _LOCATOR_LIST_T m_DefaultUnicastLocatorList;

    /* Nephalem 默认多播地址列表  用于接收和发送SPDP数据 */
    _LOCATOR_LIST_T m_DefaultMulticastLocatorList;

private:
    //对应的DDS DomainParticipant
    DomainParticipantImpl* m_pRelatedDomainParticipantImpl;

	/* Nephalem 创建Writer时设置的Entity值，每次使用后递增 */
	unsigned int m_uiWriterEntityKey;
	/* Nephalem 创建Reader时设置的Entity值，每次使用后递增 */
	unsigned int m_uiReaderEntityKey;

    /* Nephalem 本地创建的Writer和Reader */
	_ENDPOINT_MAP_T m_EndpointMap;

	/* Nephalem 用于保护m_EndpointMap */
	uLinX_SemMutex* m_EndpointMutex;

    //调度队列，0为ImmeditRequestScheduler，1为PeriodRequestScheduler
    RequestScheduler* m_pScheduleList[2];

    //接收缓冲区
    ReceiveBuffer* m_pReceiveBuffer;

    //报文处理端
    MessageProcessor* m_pMessageProcessor;

    //报文传输端
    MessageTransmitter *m_pMessageTransmitter;


	uLinXThread* m_pSendThread;
	uLinXThread* m_pRecvThread;
	uLinXThread* m_pDispatchThread;
	
};

