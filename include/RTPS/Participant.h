/************************************************************
** �ļ�����participant.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-11
** �޸��ˣ���
** ��  �ڣ���
** ��  ����participantͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "QoSPolicy.h"
#include "RTPS/RTPSEntity.h"
#include "ULINXAPI/uLinXThread.h"
#include "ULINXAPI/uLinXSemMutex.h"
/* Nephalem ϵͳͷ�ļ� */


/* Nephalem ǰ������ */
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
    //���캯��
    Participant (GUID_t Guid,DomainParticipantImpl *pDomainParticipant);

    //��������
    virtual ~Participant ();

	/* Nephalem ��ʼ��participant�ĸ�����Դ */
	ReturnCode_t initParticipant();

    //����������ӳ�� Writer
    Writer *CreateWriter (const DataWriterQos& dataWriterQoS, EntityId_t EntityID = ENTITYID_UNKNOW);

    //ɾ��������ӳ�� Writer
    ReturnCode_t DeleteWriter (Writer *pWriter);

    //�������Ķ�ӳ�� Reader
	Reader *CreateReader(const DataReaderQos & dataReaderQoS, EntityId_t EntityID = ENTITYID_UNKNOW);

    //ɾ�����Ķ�ӳ�� Reader
    ReturnCode_t DeleteReader (Reader *pReader);

	/* Nephalem �ж�Ҫ���ҵ�Endpoint�Ƿ���� */
	bool isEndpointExist(const EntityId_t& entityId);

    //����entityId ȡ�߶�Ӧ�Ķ˵㣬����Writer��Reader��ʹ�������Ҫʹ��return �ӿڷ���
    Endpoint * takeEndpoint(const EntityId_t& entityId);

	ReturnCode_t returnEndpoint(Endpoint * pEndpoint);

	/* Nephalem ����writerGuid����ƥ��ı���reader */
	Reader* lookupMatchedReader(GUID_t& writerGuid);

	/* Nephalem ��ȡSPDP�鲥���ֵ�ַ */
	_LOCATOR_LIST_T getDefaultMulticastLocatorList();

	/* Nephalem ��ȡ����ʹ�õĵ�����ַ�б�*/
	_LOCATOR_LIST_T getDefaultUnicastLocatorList();

    //��ȡЭ��汾��
	ProtocolVersion_t getProtocolVersion();

    //��ȡ���̱��
	VendorId_t getVendorId();

	/* Nephalem ��ȡʹ�õ��ڲ��˵� */
	BuiltinEndpointSet_t getAvailableBuiltinEndpoints();
	
		/* JD 2021.10.08 ��ӻ�ȡDomainParticipant �ӿ�*/
	DomainParticipantImpl* getDomainParticipantImpl();

	/* Nephalem ��������ִ���̡߳����ݽ����̡߳����ݴ����߳� */
	ReturnCode_t startThread();

	/* Nephalem �����ڲ��߳� */
	ReturnCode_t stopThread();

	ReturnCode_t stoppRecvThread();

	ReturnCode_t stopDispatchThread();

	ReturnCode_t stopSendThread();

	/* Nephalem ����Զ��д�ߴ��ʱ�� */
	ReturnCode_t setRemoteWriterLiveLiness(const GUID_t& Guid, const Time_t& curTime, LivelinessQosPolicyKind kind);

	/* Nephalem ���Զ��д�ߴ��ʱ�� */
	ReturnCode_t checkRemoteWriterLiveLiness(const Time_t& curTime);

	/* Nephalem ��鱾��д�ߴ��ʱ�� */
	ReturnCode_t checkLocalWriterLiveLiness(const Time_t& curTime);

	/* Nephalem ���±���д�ߴ��ʱ�� */
	ReturnCode_t upDataLocalWriterLiveLiness(LivelinessQosPolicyKind kind);
private:

	/* Nephalem ��ʼ������������Դ */
	ReturnCode_t initLoaclNet();
	
    //��ʼ��Locator
 //   ReturnCode_t LocatorInitial(_IP_LIST_T DefaultIpList);

	//HANDLE SendTaskStart();
	//HANDLE ReceiveTaskStart();
	//HANDLE DispatchTaskStart();

private:
    //RTPSЭ�� �汾
    ProtocolVersion_t m_ProtocolVersion;

    //�������̱��
    VendorId_t m_VendorId;

	/* Nephalem ʹ�õ��ڲ��˵� */
	BuiltinEndpointSet_t	m_AvailableBuiltinEndpoints;

    //Ĭ�ϵ�����ַ�б�  ���ڽ������ݵĵ�����ַ
    _LOCATOR_LIST_T m_DefaultUnicastLocatorList;

    /* Nephalem Ĭ�϶ಥ��ַ�б�  ���ڽ��պͷ���SPDP���� */
    _LOCATOR_LIST_T m_DefaultMulticastLocatorList;

private:
    //��Ӧ��DDS DomainParticipant
    DomainParticipantImpl* m_pRelatedDomainParticipantImpl;

	/* Nephalem ����Writerʱ���õ�Entityֵ��ÿ��ʹ�ú���� */
	unsigned int m_uiWriterEntityKey;
	/* Nephalem ����Readerʱ���õ�Entityֵ��ÿ��ʹ�ú���� */
	unsigned int m_uiReaderEntityKey;

    /* Nephalem ���ش�����Writer��Reader */
	_ENDPOINT_MAP_T m_EndpointMap;

	/* Nephalem ���ڱ���m_EndpointMap */
	uLinX_SemMutex* m_EndpointMutex;

    //���ȶ��У�0ΪImmeditRequestScheduler��1ΪPeriodRequestScheduler
    RequestScheduler* m_pScheduleList[2];

    //���ջ�����
    ReceiveBuffer* m_pReceiveBuffer;

    //���Ĵ����
    MessageProcessor* m_pMessageProcessor;

    //���Ĵ����
    MessageTransmitter *m_pMessageTransmitter;


	uLinXThread* m_pSendThread;
	uLinXThread* m_pRecvThread;
	uLinXThread* m_pDispatchThread;
	
};

