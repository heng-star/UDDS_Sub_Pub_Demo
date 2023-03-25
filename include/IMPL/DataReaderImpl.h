#pragma once
/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"
#include "ULINXAPI/uLinxTimer.h"
#include "DDS/DataReader.h"
#include "DDS/Listener/DataReaderListener.h"
/* Nephalem 系统头文件 */


/* Nephalem 前置声明 */
class DataReaderListener;
class TopicDescriptionImpl;
class Reader;
class HistoryCache;
class DDSContentFilter;

class DataReaderImpl : public DomainEntity
{
public:
	//构造函数
	DataReaderImpl(SubscriberImpl* pSubscriberImpl,
		TopicDescriptionImpl* pTopic,
		const DataReaderQos& QoS,
		StatusMask mask,
		DataReaderListener* pDataReaderListener = NULL);
	//析构函数
	virtual ~DataReaderImpl();
public:
	/* JDXCZ 此处为规范中定义的接口 */

	/* JDXCZ 设置DataReader的值，不兼容则设置失败 */
	//ReturnCode_t set_qos(const DataReaderQos& QoS);

	/* JDXCZ 获取DataReader的值 */
	ReturnCode_t get_qos(DataReaderQos& QoS);

	///* JDXCZ 设置DataReaderListener的值 */
	ReturnCode_t set_listener(DataReaderListener* pListener, StatusMask mask);

	/* JDXCZ 设置DataReaderListener的值 */
	DataReaderListener* get_listener();

	///* JDXCZ    创建一个ReadCondition，绑定到并属于DataReader*/
	//ReaderCondition* create_readcondition(SampleStateKind smaple_states[], ViewStateKind  view_states[], InstanceStateKind  instance_states[]);

	///* JDXCZ    创建一个QueryCondition,绑定到并属于DataReader。*/
	//QueryCondition create_querycondition(SampleStateKind smaple_states[], ViewStateKind  view_states[], InstanceStateKind  instance_states[], const string& query_expression, string query_parameters);

	///* JDXCZ    删除附加到DataReader的ReadCondition*/
	//ReturnCode_t delete_readcondition(ReaderCondition* condition);

	///* JDXCZ    通过DataReader访问Data值的合集*/
	//ReturnCode_t read(Data data_values[], SampleInfo sample_infos[], long max_samples, SampleStateKind sample_states[], ViewStateKind view_states[], InstanceStateKind instance_states);
	ReturnCode_t read(UserDataVector& data_values, SampleInfoSeq& sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	/* JDXCZ    访问DataReader中的数据样本合集以及相应的SampleInfo结构合集*/
	/* Nephalem data_values max_len = 0 使用零拷贝 使用完后需通过return_loan归还 */
	/* Nephalem data_values max_len > 0 使用深拷贝 */
	/* Nephalem data_values sample_infos的数据数量必须相同 */
	/* Nephalem take方法读取的数据不能再被take */
	//ReturnCode_t take(Data data_values[], SampleInfoSeq sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);
	ReturnCode_t take(UserDataVector& data_values, SampleInfoSeq& sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	///* JDXCZ    访问与ReadCondition中指定的条件匹配的样本*/
	//ReturnCode_t read_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, const ReaderCondition& readcondition);

	///* JDXCZ    访问与ReadCondition中指定的条件匹配的样本*/
	//ReturnCode_t take_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, const ReaderCondition& readcondition);

	///* JDXCZ    从DataReader复制下一个之前未访问过的Data值*/
	//ReturnCode_t read_next_sample(Data data_values[], SampleInfo sample_infos[]);
	ReturnCode_t read_next_sample(UserData& data_value, SampleInfo& sample_info);

	/* JDXCZ    从DataReader复制下一个之前未访问过的Data值，并从DataReader中“删除”它，使其不再可访问*/
	//ReturnCode_t take_next_sample(Data& data_values, SampleInfo& sample_info);
	ReturnCode_t take_next_sample(UserData& data_value, SampleInfo& sample_info);

	///* JDXCZ    从DataReader访问Data值的合集 */
	//ReturnCode_t read_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    从DataReader访问Data值的合集*/
	//ReturnCode_t take_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    从DataReader复制下一个之前未访问过的Data值 */
	//ReturnCode_t reaad_next_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t previous_handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    从DataReader复制下一个之前未访问过的Data值，并从DataReader中“删除”它，使其不再可访问*/
	//ReturnCode_t take_next_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t previous_handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    从DataReader访问Data值的集合，行为与read_next_instance相同，只是返回的所有样本都必须满足指定的条件*/
	//ReturnCode_t read_next_instance_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, InstanceHandle_t previous_handle, ReadCondition* pReadCondition);

	///* JDXCZ    DataReader访问Data值合集，并从DataReader中“删除”它们 */
	//ReturnCode_t take_next_instance_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, InstanceHandle_t previous_handle, ReadCondition* pReadCondition);

	///* JDXCZ    向DataReader通知应用程序已完成访问data_values和sample_infos的合集，这些合集是较早前通过DataReader的read或take方法获得的 */
	//ReturnCode_t return_loan(Data data_values[], SampleInfo sample_infos[]);

	///* JDXCZ    允许访问LIVELINESS_CHANGED通信状态 */
	//ReturnCode_t get_liveliness_changed_status(LivelinessChangedStatus& status);

	///* JDXCZ    允许访问REQUESTED_DEADLINE_MISSED通信状态 */
	//ReturnCode_t get_requested_deadline_missed_status(_REQUESTED_DEADLINE_MISSED_STATUS& status);

	///* JDXCZ    允许访问REQUESTED_INCOMPATIBLE_QOS通信状态 */
	//ReturnCode_t get_requested_incompatible_qos_status(RequestedIncompatibleQosStatus& status);

	///* JDXCZ    允许访问SAMPLE_LOST通信状态 */
	//ReturnCode_t get_sample_lost_status(SampleLostStatus& status);

	///* JDXCZ    允许访问SAMPLE_REJECTED通信状态 */
	//ReturnCode_t get_sample_rejected_statu(SampleRejectedStatus& status);

	/* JDXCZ    允许访问SUBSCRIPTION_MATCHED通信状态 */
	ReturnCode_t get_subscription_matched_status(SubscriptionMatchedStatus& status);

	/* JDXCZ    返回与DataReader关联的TopicDescription */
	TopicDescriptionImpl* get_topicdescription();

	/* JDXCZ    返回与DataReader关联的Subscriber */
	SubscriberImpl* get_subscriber();

	///* JDXCZ    获取与instance_handle对应的实例关键字ke，仅填充key_holder实例内组成关键字key的字段 */
	//ReturnCode_t get_key_value(Data key_holder, InstanceHandle_t handle);

	///* JDXCZ    实例instance作为参数，并返回一个句柄 */
	//InstanceHandle_t lookup_instance(Data instance);

	///* JDXCZ    删除通过DataReader对象的“创建”方法创建的所有实体,删除QueryCondition 和ReadCondition对象 */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ    阻塞调用线程，直到接收到所有“历史”数据，或者max_wait参数指定的时间已到期 */
	//ReturnCode_t wait_for_historical_data(const Duration_t max_wait);

	/* JDXCZ    获取当前与DataReader “关联”的发布信息 */
	ReturnCode_t get_matched_publication_data(PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* JDXCZ    获取当前与DataReader “关联”的发布列表 */
	InstanceHandle_t get_matched_publications(InstanceHandleSeq& publication_handles);

public:
	/* Nephalem 自定义接口 */

	/* Nephalem 发送该节点的状态信息，创建、修改、删除、已存在 */
	virtual ReturnCode_t SendInfo(_ENTITY_STATUS_T Status);

	/* Nepalem 设置对用户展示的DataReader */
	void setUserDataReader(DataReader* pDataReader);

	/* Nepalem 获取对用户展示的pPublisher */
	DataReader* getUserDataReader();

	/* Nephalem 设置相关的RTPS层Reader 并设置HistoyrCache */
	void setRelatedReader(Reader* pReader);

	/* Nephalem 获取相关的RTPS层Reader */
	Reader* getRelatedReader();

	/* Nephalem 数据到达通知 */
	ReturnCode_t DataReceive(_CACHE_CHANGE * pCacheChange);

	/* Nephalem 从Cache中读取数据 */
	ReturnCode_t ReadFromCache(char*& pMyDataValue, unsigned int& uiLeng, InstanceHandle_t& Handle, _CHANGE_KIND_T& Kind);

	/* Nephalem DeadLine相关 */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static void deadlineCheck(void* pDataReader, unsigned char TimerOrWaitFired);
#elif defined ULINX_LINUX
    static void deadlineCheck(union sigval pDataReader);
#elif defined ULINX_VXWORKS
    static void deadlineCheck(timer_t timerid,int pDataReader);
#endif

	bool isDeadlineMissed();

	void setDeadlineMissed(bool flag);

	/* Nephalem 清除所有权记录 */
	void clearOwnerShipWriter();

	void setOwnerShipWriter(DiscoveredWriterData& remoteWriter);

	/* Nephalem 检查lifespan存活时间 */
	void checkLifeSpan();

	GUID_t getOwnerShipWriter();

	RequestedDeadlineMissedStatus& getDeadlineStatus();

	SubscriptionMatchedStatus& getSubscriptionMatchedStatus();

	LivelinessChangedStatus& getLivelinessChangedStatus();

	/* Nephalem 新增存活数量 */
	ReturnCode_t updataLiveLinessChangedStatus();
	/* Nephalem 更新现有状态 */
	ReturnCode_t updataLiveLinessChangedStatus(bool bAlive);

	/* 调用on_subscription_matched listener */
	void on_subscription_matched();

	/* Nephalem rti独有的接口，兼容rti */
	ReturnCode_t get_matched_publication_participant_data(ParticipantBuiltinTopicData& participant_data, const InstanceHandle_t& publication_handle);

	ReturnCode_t SetDataFilter(DDSContentFilter* pDataFilter);
private:
	/* Nephalem 对用户展示的DataReader */
	DataReader* m_pUserDataReader;

	SubscriberImpl* m_pSubscriberImpl;

	TopicDescriptionImpl* m_pTopicDescriptionImpl;

	DataReaderQos m_DataReaderQos;

	DataReaderListener* m_pDataReaderListener;

	StatusMask m_StatusMask;

	Reader* m_pReatedReader;

	HistoryCache* m_pReaderCache;

	uLinxTimer* m_pDeadlineTimer;

	bool m_bDeadlineMiss;

	GUID_t m_OwnerShipWriter;

	unsigned int m_uiOwnerShipStrength;

	/* wangyi 2022/2/21 前一次提交数据时间 */
	ULINX_INT64 m_LastTime;

	RequestedDeadlineMissedStatus m_DeadlineStatus;

	/* Nephalem 匹配状态 */
	SubscriptionMatchedStatus	m_SubscriptionMatchedStatus;

	LivelinessChangedStatus		m_LiveLinessChangeStatus;

	/* JDXCZ 数据过滤器，按照条件过滤数据  void*  **/
	DDSContentFilter* m_pDataFilter;
public:
	/* JD 当前接收报文的序列号 */
	SequenceNumber_t	m_CurrentSeqNum;
};
