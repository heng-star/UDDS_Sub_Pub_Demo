#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/Entity.h"
#include "QoSPolicy.h"
#include "TINYXML/tinyxml.h"
/* Nephalem 系统头文件 */


/* Nephalem 前置声明 */
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
	/* Nephalem 构造函数*/
	DomainParticipantImpl(_DOMAINID_T domainId,
	const DomainParticipantQos& QoS,
	DomainParticipantListener* pDomainParticipantListener,
	StatusMask mask,
	char* pCompName = NULL);

	/* Nephalem 析构函数 */
	~DomainParticipantImpl();

public:
	/* Nephalem 此处为规范中定义的接口 */

	/* Nephalem 创建发布者者 */
	PublisherImpl* create_publisher(const PublisherQos& QoS, StatusMask mask,PublisherListener* pPublisherListener = NULL);

	/* Nephalem 删除发布者*/
	ReturnCode_t delete_publisher(PublisherImpl*& pPublisher);

	/* Nephalem 创建订阅者 */
	SubscriberImpl* create_subscriber(const SubscriberQos& QoS, StatusMask mask,SubscriberListener* pSubscriberListener = NULL);

	/* Nephalem 删除订阅者 */
	ReturnCode_t delete_subscriber(SubscriberImpl*& pSubscriber);

	/* Nephalem 创建Topic */
	TopicImpl* create_topic(const string& topicName, const string& typeName, const TopicQos& QoS, StatusMask mask, TopicListener * pTopicListener = NULL);

	/* Nephalem 删除指定主题，如果该主题还在被DataWriter、DataReader等使用，则删除失败 */
	ReturnCode_t delete_topic(TopicImpl*& pTopicImpl);

	/* Nephalem 创建基于内容过滤的主题 */
	ContentFilteredTopicImpl* create_contentfilteredtopic(const string& name, Topic* pRelatedTopic, const string& filterExpression, const StringSeq expressionParameters);

	/* Nephalem 删除基于内容过滤的主题 */
	ReturnCode_t delete_contentfilteredtopic(ContentFilteredTopicImpl*& pContentFilteredTopicImpl);

	/* Nephalem 创建复数主题 */
	//MultiTopic* create_multitopic(const string& topicName, const string& typeName, const string& subscriptionExpression, const vector<string>&expressionParameters);

	/* Nephalem 删除复数主题 */
	//ReturnCode_t delete_multitopic(const MultiTopic*& pMultiTopic);

	/* Nephalem 设置监听器 */
	ReturnCode_t set_listener(DomainParticipantListener* pDomainParticipantListener, StatusMask mask);

	/* Nephalem 根据主题名查找主题 */
	//TopicImpl* find_topic(const string& topicName, Duration_t timeout);

	/* Nephalem 根据主题名查找主题 */
	TopicDescriptionImpl* lookup_topicdescription(const string& topicName);

	/* Nephalem 获取内置订阅者 */
	SubscriberImpl* get_builtin_subscriber();

	///* Nephalem 忽略远端参与者 */
	//ReturnCode_t ignore_participant(InstanceHandle_t handle);

	///* Nephalem 忽略远端主题 */
	//ReturnCode_t ignore_topic(InstanceHandle_t handle);

	///* Nephalem 忽略远端发布者 */
	//ReturnCode_t ignore_publication(InstanceHandle_t handle);

	///* Nephalem 忽略远端订阅者 */
	//ReturnCode_t ignore_subscription(InstanceHandle_t handle);

	/* Nephalem 获取所属于的域 */
	_DOMAINID_T get_domain_id();

	/* Nephalem 删除用户创建的所有实体对象 */
	ReturnCode_t delete_contained_entities();

	/* Nephalem 手动断言存活性 */
	ReturnCode_t assert_liveliness();

	///* Nephalem 设置默认的发布者QoS */
	ReturnCode_t set_default_publisher_qos(const PublisherQos& QoS);

	///* Nephalem 获取默认的发布者QoS */
	ReturnCode_t get_default_publisher_qos(PublisherQos& QoS);

	///* Nephalem 设置默认的订阅者QoS */
	ReturnCode_t set_default_subscriber_qos(const SubscriberQos& QoS);

	///* Nephalem 获取默认的订阅者QoS */
	ReturnCode_t get_default_subscriber_qos(SubscriberQos& QoS);

	///* Nephalem 设置默认的主题QoS */
	ReturnCode_t set_default_topic_qos(const TopicQos& QoS);

	///* Nephalem 获取默认的主题QoS */
	ReturnCode_t get_default_topic_qos(TopicQos& QoS);

	/* Nephalem 获取已发现的远端DomainParticipant列表(Guid) */
	ReturnCode_t get_discovered_participants(InstanceHandleSeq& participantHandles);

	/* Nephalem 获取指定远端DomainParticipant的数据 */
	ReturnCode_t get_discovered_participant_data(ParticipantBuiltinTopicData& participantData, const InstanceHandle_t& participantHandle);

	///* Nephalem 获取已发现的远端主题列表 */
	//ReturnCode_t get_discovered_topics(vector<InstanceHandle_t>& topicHandles);

	///* Nephalem 获取指定主题的数据 */
	////ReturnCode_t get_discovered_topic_data(TopicBuiltinTopicData& topicData, const InstanceHandle_t& topicHandle);

	/* Nephalem 判断实体是否由该DomainParticipant创建 */
	bool contains_entity(const InstanceHandle_t& handle);

	/* Nephalem 获取当前时间 */
	static ReturnCode_t get_current_time(Time_t& currentTime);

	/* Nephalem 获取设置的监听器 */
	DomainParticipantListener* get_listener();

	/* Nephalem 设置默认的DomainParticipantQos，不兼容则设置失败 */
	ReturnCode_t set_qos(const DomainParticipantQos& QoS);

	/* Nephalem 获取DomainParticipantQos默认值 */
	ReturnCode_t get_qos(DomainParticipantQos& QoS);

public:
	/* Nephalem 自定义接口*/

	/* Nepalem 设置对用户展示的DomainParticipant */
	void setUserDomainParticipant(DomainParticipant* pDomainParticipant);

	/* Nepalem 获取对用户展示的DomainParticipant */
	DomainParticipant* getUserDomainParticipant();

	/* Nephalem 注册数据类型，注册完成后才能用于创建主题 */
	ReturnCode_t register_type(const string & typeName, TypeSupport* pTypeSupport = NULL);

	///* Nephalem 查找Agent */
	//Agent* LookupRegisteredType(string strTypeName);

	/* Nephalem 获取发现模块对象 */
	Discovery* GetRelatedDiscovery();

	/* Nephalem 获取内置发布者，该接口只能在DDS内部使用 所以对外显示类中无该接口 */
	PublisherImpl* get_builtin_publisher();

	/* Nephalem 获取RTPS层的Participant */
	Participant* getRelatedParticipant();

	/* Nephalem 从所有创建的Publisher中根据主题名查找datawriter */
	_DATA_WRITER_IMPL_LIST_T lookup_datawriter(string topicname);

	/* Nephalem 从所有创建的Subscriber中根据主题名查找datareader */
	DataReaderImpl* lookup_datareader(string topicname);

	/* Nephalem 获取已发现的DataWriter列表 */
	ReturnCode_t get_publications(InstanceHandleSeq& publication_handles, bool include_contained_entities);

	/* Nephalem 获取指定的DataWriter信息 */
	ReturnCode_t get_publication_data(struct PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* Nephalem 获取已发现的DataReader列表 */
	ReturnCode_t get_subscriptions(InstanceHandleSeq& subscription_handles, bool include_contained_entities);

	/* Nephalem 获取指定的DataReader信息 */
	ReturnCode_t get_subscription_data(struct SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* Nephalem 设置监控代理监听器 */
	ReturnCode_t set_monitor_listener(DomainParticipantListener* pMonitorListener, StatusMask mask);

	/* JD  获取Domainpaticipant Count 的值*/
	int GetDomainParticipantCount();
	/* JD 获取DomainId 和 Domainpaant的值 */
	ReturnCode_t GetDomainParticipantCount(_DOMAINID_T& DomainId,unsigned int DomainParticipantCount);

	/* JD 2022-04-06 查找ContentFilterTopicImpl 主题 */
	ContentFilteredTopicImpl* look_ContentFilteredTopicImpl(string ContentFilteredTopicName);
	
	/* JD 2022-04-11 将IDL文件中的信息解析保存到内存中 */
	int analyse_idl(list<string> idl_info);	
		/* JD 获取静态匹配信息 */
	StaticDomainParticipant*	GetStaticDomainParticipant();

	/* JD 获取发送单播报文的标志位 */
	bool GetSendUnicastBeartbeatFlag();
	/* JD 设置发送单播报文的标志位 */
	int SetSendUnicastHeartbeatFlag(bool bFlag);

	//wangyi 2022/2/24 获取当前的UTC时间
	static ReturnCode_t get_Current_Time_UTC(Duration_t &time);
	
	///* Nephalem 设置默认的数据读者QoS */
	ReturnCode_t set_default_datareader_qos(const DataReaderQos& QoS);

	///* Nephalem 获取默认的数据读者QoS */
	ReturnCode_t get_default_datareader_qos(DataReaderQos& QoS);

	///* Nephalem 设置默认的数据写者QoS */
	ReturnCode_t set_default_datawriter_qos(const DataWriterQos& QoS);

	///* Nephalem 获取默认的数据写者QoS */
	ReturnCode_t get_default_datawriter_qos(DataWriterQos& QoS);

	///* Nephalem 设置默认的主题QoS */
	ReturnCode_t set_default_participant_qos(const DomainParticipantQos& QoS);

	///* Nephalem 获取默认的主题QoS */
	ReturnCode_t get_default_participant_qos(DomainParticipantQos& QoS);
	
	static unsigned int ParticipantCount;
private:
	/* Nephalem 创建内置发布者、订阅者，初始化发现模块 */
	ReturnCode_t BuiltinEndpointInitialize();

	/* Nephalem 加载配置文件 */
	ReturnCode_t load_configXML();

	/* Nephalem 创建rtps层Participant*/
	ReturnCode_t create_participant();

private:
	DomainParticipant* m_pUserDomainParticipant;

	/* Nephalem 域ID*/
	_DOMAINID_T m_DomainId;

	/* Nephalem QoS设置 */
	DomainParticipantQos m_DomainParticipantQoS;

	/* Nephalem 监听器 */
	DomainParticipantListener* m_pDomainParticipantListener;

	/* Nephalem 内置发布者 */
	PublisherImpl* m_pBuiltinPublisherImpl;

	/* Nephalem 内置订阅者 */
	SubscriberImpl* m_pBuiltinSubscriberImpl;

	/* Nephalem 发布者链表 */ 
	_PUBLISHER_IMPL_LIST_T m_PublisherImplList;

	/* Nephalem 订阅者链表 */
	_SUBSCRIBER_IMPL_LIST_T m_SubscriberImplList;

	/* Nephalem 已注册的数据类型 */
	_TYPE_SET_T m_RegisteredTypeSet;

	/* Nephalem 已创建的主题列表 */
	_TOPIC_IMPL_LIST_T m_TopicImplList;

	///* JD 已经创建过的主题名 */
	//_TYPE_SET_T m_ContentFilteredTopicNameSet;

	/* JD 已经创建的基于内容过滤的主题 */
	_CONTENT_FILTERED_TOPIC_IMPL_LIST_T m_ContentFilteredTopicImplList;

	DomainParticipantListener* m_pMonitorListener;

	/* JD 静态信息管理者，不使用静态匹配时为NULL */
	StaticDomainParticipant* m_pStaticDomainParticipant;

	/* JD 创建静态配置文件以外主题为true 判断本地节点是否需要回复单播的HB报文,true-发送，false-不发送*/
	bool m_bSendUnicastHeartbeatFlag;
private:
	/* Nephalem PTPS层 */
	/* Nephalem PTPS层相对应Participant对象 */
	Participant* m_pRelatedParticipant;

	/* Nephalem PTPS层相对应P发现模块对象 */
	Discovery* m_pRelatedDiscovery;

	//已经创建的内置端点
	//_BUILTIN_ENDPOINT_SET_T m_BuiltinEndpoint;

	//主题类型和TypeCode对应关系
	//_TYPE_CODE_LIST_T m_TypecodeList;

	//默认IP地址链表
	_IP_LIST_T  m_DefaultIpList;

	Duration_t m_ResendPeriod;

	/* JD 记录日志-打算用 unsigned int 的 前两个字节保存Count的值，用后两各字节保存 DomainId 的值*/
	unsigned int m_uiDomainParticipantCount;
	static unsigned int DomainParticipantCount;
	/* JD 确保没有Domianparticipant的值不变*/
	static uLinX_SemMutex	m_CounMutex;

};