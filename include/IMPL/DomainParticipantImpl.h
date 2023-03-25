#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/Entity.h"
#include "QoSPolicy.h"
#include "TINYXML/tinyxml.h"
/* Nephalem ϵͳͷ�ļ� */


/* Nephalem ǰ������ */
class DomainParticipantListener;
class PublisherImpl;
class PublisherListener;
class SubscriberImpl;
class SubscriberListener;
class TopicImpl;
class TopicDescription;
class TopicListener;
class MultiTopic;
class TopicDescriptionImpl;
class ContentFilteredTopicImpl;
class Participant;
class Discovery;

class uLinX_SemMutex;
class TypeSupport;

class StaticDomainParticipant;

class DomainParticipantImpl : public Entity
{
public:
	/* Nephalem ���캯��*/
	DomainParticipantImpl(_DOMAINID_T domainId,
	const DomainParticipantQos& QoS,
	DomainParticipantListener* pDomainParticipantListener,
	StatusMask mask,
	char* pCompName = NULL);

	/* Nephalem �������� */
	~DomainParticipantImpl();

public:
	/* Nephalem �˴�Ϊ�淶�ж���Ľӿ� */

	/* Nephalem ������������ */
	PublisherImpl* create_publisher(const PublisherQos& QoS, StatusMask mask,PublisherListener* pPublisherListener = NULL);

	/* Nephalem ɾ��������*/
	ReturnCode_t delete_publisher(PublisherImpl*& pPublisher);

	/* Nephalem ���������� */
	SubscriberImpl* create_subscriber(const SubscriberQos& QoS, StatusMask mask,SubscriberListener* pSubscriberListener = NULL);

	/* Nephalem ɾ�������� */
	ReturnCode_t delete_subscriber(SubscriberImpl*& pSubscriber);

	/* Nephalem ����Topic */
	TopicImpl* create_topic(const string& topicName, const string& typeName, const TopicQos& QoS, StatusMask mask, TopicListener * pTopicListener = NULL);

	/* Nephalem ɾ��ָ�����⣬��������⻹�ڱ�DataWriter��DataReader��ʹ�ã���ɾ��ʧ�� */
	ReturnCode_t delete_topic(TopicImpl*& pTopicImpl);

	/* Nephalem �����������ݹ��˵����� */
	ContentFilteredTopicImpl* create_contentfilteredtopic(const string& name, Topic* pRelatedTopic, const string& filterExpression, const StringSeq expressionParameters);

	/* Nephalem ɾ���������ݹ��˵����� */
	ReturnCode_t delete_contentfilteredtopic(ContentFilteredTopicImpl*& pContentFilteredTopicImpl);

	/* Nephalem ������������ */
	//MultiTopic* create_multitopic(const string& topicName, const string& typeName, const string& subscriptionExpression, const vector<string>&expressionParameters);

	/* Nephalem ɾ���������� */
	//ReturnCode_t delete_multitopic(const MultiTopic*& pMultiTopic);

	/* Nephalem ���ü����� */
	ReturnCode_t set_listener(DomainParticipantListener* pDomainParticipantListener, StatusMask mask);

	/* Nephalem ������������������ */
	//TopicImpl* find_topic(const string& topicName, Duration_t timeout);

	/* Nephalem ������������������ */
	TopicDescriptionImpl* lookup_topicdescription(const string& topicName);

	/* Nephalem ��ȡ���ö����� */
	SubscriberImpl* get_builtin_subscriber();

	///* Nephalem ����Զ�˲����� */
	//ReturnCode_t ignore_participant(InstanceHandle_t handle);

	///* Nephalem ����Զ������ */
	//ReturnCode_t ignore_topic(InstanceHandle_t handle);

	///* Nephalem ����Զ�˷����� */
	//ReturnCode_t ignore_publication(InstanceHandle_t handle);

	///* Nephalem ����Զ�˶����� */
	//ReturnCode_t ignore_subscription(InstanceHandle_t handle);

	/* Nephalem ��ȡ�����ڵ��� */
	_DOMAINID_T get_domain_id();

	/* Nephalem ɾ���û�����������ʵ����� */
	ReturnCode_t delete_contained_entities();

	/* Nephalem �ֶ����Դ���� */
	ReturnCode_t assert_liveliness();

	///* Nephalem ����Ĭ�ϵķ�����QoS */
	ReturnCode_t set_default_publisher_qos(const PublisherQos& QoS);

	///* Nephalem ��ȡĬ�ϵķ�����QoS */
	ReturnCode_t get_default_publisher_qos(PublisherQos& QoS);

	///* Nephalem ����Ĭ�ϵĶ�����QoS */
	ReturnCode_t set_default_subscriber_qos(const SubscriberQos& QoS);

	///* Nephalem ��ȡĬ�ϵĶ�����QoS */
	ReturnCode_t get_default_subscriber_qos(SubscriberQos& QoS);

	///* Nephalem ����Ĭ�ϵ�����QoS */
	ReturnCode_t set_default_topic_qos(const TopicQos& QoS);

	///* Nephalem ��ȡĬ�ϵ�����QoS */
	ReturnCode_t get_default_topic_qos(TopicQos& QoS);

	/* Nephalem ��ȡ�ѷ��ֵ�Զ��DomainParticipant�б�(Guid) */
	ReturnCode_t get_discovered_participants(InstanceHandleSeq& participantHandles);

	/* Nephalem ��ȡָ��Զ��DomainParticipant������ */
	ReturnCode_t get_discovered_participant_data(ParticipantBuiltinTopicData& participantData, const InstanceHandle_t& participantHandle);

	///* Nephalem ��ȡ�ѷ��ֵ�Զ�������б� */
	//ReturnCode_t get_discovered_topics(vector<InstanceHandle_t>& topicHandles);

	///* Nephalem ��ȡָ����������� */
	////ReturnCode_t get_discovered_topic_data(TopicBuiltinTopicData& topicData, const InstanceHandle_t& topicHandle);

	/* Nephalem �ж�ʵ���Ƿ��ɸ�DomainParticipant���� */
	bool contains_entity(const InstanceHandle_t& handle);

	/* Nephalem ��ȡ��ǰʱ�� */
	static ReturnCode_t get_current_time(Time_t& currentTime);

	/* Nephalem ��ȡ���õļ����� */
	DomainParticipantListener* get_listener();

	/* Nephalem ����Ĭ�ϵ�DomainParticipantQos��������������ʧ�� */
	ReturnCode_t set_qos(const DomainParticipantQos& QoS);

	/* Nephalem ��ȡDomainParticipantQosĬ��ֵ */
	ReturnCode_t get_qos(DomainParticipantQos& QoS);

public:
	/* Nephalem �Զ���ӿ�*/

	/* Nepalem ���ö��û�չʾ��DomainParticipant */
	void setUserDomainParticipant(DomainParticipant* pDomainParticipant);

	/* Nepalem ��ȡ���û�չʾ��DomainParticipant */
	DomainParticipant* getUserDomainParticipant();

	/* Nephalem ע���������ͣ�ע����ɺ�������ڴ������� */
	ReturnCode_t register_type(const string & typeName, TypeSupport* pTypeSupport = NULL);

	///* Nephalem ����Agent */
	//Agent* LookupRegisteredType(string strTypeName);

	/* Nephalem ��ȡ����ģ����� */
	Discovery* GetRelatedDiscovery();

	/* Nephalem ��ȡ���÷����ߣ��ýӿ�ֻ����DDS�ڲ�ʹ�� ���Զ�����ʾ�����޸ýӿ� */
	PublisherImpl* get_builtin_publisher();

	/* Nephalem ��ȡRTPS���Participant */
	Participant* getRelatedParticipant();

	/* Nephalem �����д�����Publisher�и�������������datawriter */
	_DATA_WRITER_IMPL_LIST_T lookup_datawriter(string topicname);

	/* Nephalem �����д�����Subscriber�и�������������datareader */
	DataReaderImpl* lookup_datareader(string topicname);

	/* Nephalem ��ȡ�ѷ��ֵ�DataWriter�б� */
	ReturnCode_t get_publications(InstanceHandleSeq& publication_handles, bool include_contained_entities);

	/* Nephalem ��ȡָ����DataWriter��Ϣ */
	ReturnCode_t get_publication_data(struct PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* Nephalem ��ȡ�ѷ��ֵ�DataReader�б� */
	ReturnCode_t get_subscriptions(InstanceHandleSeq& subscription_handles, bool include_contained_entities);

	/* Nephalem ��ȡָ����DataReader��Ϣ */
	ReturnCode_t get_subscription_data(struct SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* Nephalem ���ü�ش�������� */
	ReturnCode_t set_monitor_listener(DomainParticipantListener* pMonitorListener, StatusMask mask);

	/* JD  ��ȡDomainpaticipant Count ��ֵ*/
	int GetDomainParticipantCount();
	/* JD ��ȡDomainId �� Domainpaant��ֵ */
	ReturnCode_t GetDomainParticipantCount(_DOMAINID_T& DomainId,unsigned int DomainParticipantCount);

	/* JD 2022-04-06 ����ContentFilterTopicImpl ���� */
	ContentFilteredTopicImpl* look_ContentFilteredTopicImpl(string ContentFilteredTopicName);
	
	/* JD 2022-04-11 ��IDL�ļ��е���Ϣ�������浽�ڴ��� */
	int analyse_idl(list<string> idl_info);	
		/* JD ��ȡ��̬ƥ����Ϣ */
	StaticDomainParticipant*	GetStaticDomainParticipant();

	/* JD ��ȡ���͵������ĵı�־λ */
	bool GetSendUnicastBeartbeatFlag();
	/* JD ���÷��͵������ĵı�־λ */
	int SetSendUnicastHeartbeatFlag(bool bFlag);

	//wangyi 2022/2/24 ��ȡ��ǰ��UTCʱ��
	static ReturnCode_t get_Current_Time_UTC(Duration_t &time);
	
	///* Nephalem ����Ĭ�ϵ����ݶ���QoS */
	ReturnCode_t set_default_datareader_qos(const DataReaderQos& QoS);

	///* Nephalem ��ȡĬ�ϵ����ݶ���QoS */
	ReturnCode_t get_default_datareader_qos(DataReaderQos& QoS);

	///* Nephalem ����Ĭ�ϵ�����д��QoS */
	ReturnCode_t set_default_datawriter_qos(const DataWriterQos& QoS);

	///* Nephalem ��ȡĬ�ϵ�����д��QoS */
	ReturnCode_t get_default_datawriter_qos(DataWriterQos& QoS);

	///* Nephalem ����Ĭ�ϵ�����QoS */
	ReturnCode_t set_default_participant_qos(const DomainParticipantQos& QoS);

	///* Nephalem ��ȡĬ�ϵ�����QoS */
	ReturnCode_t get_default_participant_qos(DomainParticipantQos& QoS);
	
	static unsigned int ParticipantCount;
private:
	/* Nephalem �������÷����ߡ������ߣ���ʼ������ģ�� */
	ReturnCode_t BuiltinEndpointInitialize();

	/* Nephalem ���������ļ� */
	ReturnCode_t load_configXML();

	/* Nephalem ����rtps��Participant*/
	ReturnCode_t create_participant();

private:
	DomainParticipant* m_pUserDomainParticipant;

	/* Nephalem ��ID*/
	_DOMAINID_T m_DomainId;

	/* Nephalem QoS���� */
	DomainParticipantQos m_DomainParticipantQoS;

	/* Nephalem ������ */
	DomainParticipantListener* m_pDomainParticipantListener;

	/* Nephalem ���÷����� */
	PublisherImpl* m_pBuiltinPublisherImpl;

	/* Nephalem ���ö����� */
	SubscriberImpl* m_pBuiltinSubscriberImpl;

	/* Nephalem ���������� */ 
	_PUBLISHER_IMPL_LIST_T m_PublisherImplList;

	/* Nephalem ���������� */
	_SUBSCRIBER_IMPL_LIST_T m_SubscriberImplList;

	/* Nephalem ��ע����������� */
	_TYPE_SET_T m_RegisteredTypeSet;

	/* Nephalem �Ѵ����������б� */
	_TOPIC_IMPL_LIST_T m_TopicImplList;

	///* JD �Ѿ��������������� */
	//_TYPE_SET_T m_ContentFilteredTopicNameSet;

	/* JD �Ѿ������Ļ������ݹ��˵����� */
	_CONTENT_FILTERED_TOPIC_IMPL_LIST_T m_ContentFilteredTopicImplList;

	DomainParticipantListener* m_pMonitorListener;

	/* JD ��̬��Ϣ�����ߣ���ʹ�þ�̬ƥ��ʱΪNULL */
	StaticDomainParticipant* m_pStaticDomainParticipant;

	/* JD ������̬�����ļ���������Ϊtrue �жϱ��ؽڵ��Ƿ���Ҫ�ظ�������HB����,true-���ͣ�false-������*/
	bool m_bSendUnicastHeartbeatFlag;
private:
	/* Nephalem PTPS�� */
	/* Nephalem PTPS�����ӦParticipant���� */
	Participant* m_pRelatedParticipant;

	/* Nephalem PTPS�����ӦP����ģ����� */
	Discovery* m_pRelatedDiscovery;

	//�Ѿ����������ö˵�
	//_BUILTIN_ENDPOINT_SET_T m_BuiltinEndpoint;

	//�������ͺ�TypeCode��Ӧ��ϵ
	//_TYPE_CODE_LIST_T m_TypecodeList;

	//Ĭ��IP��ַ����
	_IP_LIST_T  m_DefaultIpList;

	Duration_t m_ResendPeriod;

	/* JD ��¼��־-������ unsigned int �� ǰ�����ֽڱ���Count��ֵ���ú������ֽڱ��� DomainId ��ֵ*/
	unsigned int m_uiDomainParticipantCount;
	static unsigned int DomainParticipantCount;
	/* JD ȷ��û��Domianparticipant��ֵ����*/
	static uLinX_SemMutex	m_CounMutex;

};