#pragma once
/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"
#include "QoSPolicy.h"
#include "IMPL/DomainEntity.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinxTimer.h"
#include "DDS/Listener/DataWriterListener.h"
/* Nephalem 系统头文件 */


/* Nephalem 前置声明 */
class DataWriter;
class PublisherImpl;
class DataWriterListener;
class Writer;
class HistoryCache;

typedef  void Data;
class DataWriterImpl : public DomainEntity
{
public:
	/* Nephalem 构造函数 */
	DataWriterImpl(PublisherImpl* pPublisherImpl,
		TopicImpl* pTopic,
		const DataWriterQos& Qos,
		StatusMask mask,
		DataWriterListener* pDataWriterListener = NULL);

	/* Nephalem 析构函数 */
	virtual ~DataWriterImpl();

public:
	/* JDXCZ 此处为规范中定义的接口 */

	///* JDXCZ    通知服务应用程序将修改特定数据实例 */
	//InstanceHandle_t register_instance(const Data* instance);

	///* JDXCZ    通知服务应用程序将修改特定数据实例，并修改source_timestamp的值 */
	//InstanceHandle_t register_instance_w_timestamp(const Data* instance, const Time_t& timestamp);

	///* JDXCZ    访问OFFERED_DEADLINE_MISSED通信状态 */
	//ReturnCode_t unregister_instance(const Data* instance, const InstanceHandle_t& handle);

	///* JDXCZ    访问OFFERED_DEADLINE_MISSED通信状态 */
	//ReturnCode_t  unregister_instance_w_timestamp(const Data* instance, const InstanceHandle_t& handle, const Time_t& timestamp);

	///* JDXCZ    取与instance_handle对应的实例关键字值 */
	//ReturnCode_t get_key_value(const Data* key_holder, const InstanceHandle_t& handle);

	///* JDXCZ    返回DataWriter实例 */
	//InstanceHandle_t lookup_instance(const Data* instance);

	/* JDXCZ    修改数据实例的值 由于数据类型Data未确定，Data 类型改为char* */
	//ReturnCode_t write(const Data* data, const InstanceHandle_t& handle);

	/* Nephalem 替代上方write接口，子类将数据转化为char*后 传入 */
	ReturnCode_t write(const char* pData, unsigned int length, const InstanceHandle_t& handle, _PARAMETER_LIST & InlineQos, GUID_t stReaderGuid = GUID_UNKNOWN);

	/* JDXCZ    修改数据实例的值，通过SampleInfo中source_timestamp属性提供可供DataReader对象使用的source_timestamp的值 */
	ReturnCode_t write_w_timestamp(const char* pData, unsigned int length, const InstanceHandle_t& handle, _PARAMETER_LIST & InlineQos, const Time_t& timestamp, GUID_t stReaderGuid = GUID_UNKNOWN);

	///* JDXCZ    请求中间价删除数据，通过SampleInfo中source_timestamp属性提供可供DataReader对象使用的source_timestamp的值。*/
	//ReturnCode_t dispose(const Data* data, const InstanceHandle_t& handle);

	///* JDXCZ    请求中间价删除数据 ，设置*/
	//ReturnCode_t dispose_w_timestamp(const Data* data, const InstanceHandle_t& handle, const Time_t& timestamp);

	///* JDXCZ    阻塞调用线程，知道DataWriter发送的数据被所有RELIABLE的DataReader实体确认 */
	//ReturnCode_t wait_for_acknowledgments(const Duration_t& max_wait);

	/* JDXCZ    访问LIVELINESS_LOST通信状态*/
	//ReturnCode_t get_liveliness_lost_status(LivelinessLostStatus& status);

	///* JDXCZ    访问OFFERED_DEADLINE_MISSED通信状态 */
	//ReturnCode_t get_offered_deadline_missed_status(_OFFERED_DEADLINE_MISSED_STATUS& status);

	///* JDXCZ    访问OFFERED_INCOMPATIBLE_QOS通信状态 */
	//ReturnCode_t get_offered_incompatible_qos_status(_OFFERED_DEADLINE_MISSED_STATUS& status);

	/* JDXCZ    访问Publication_matched的通信状态 */
	ReturnCode_t get_publication_matched_status(PublicationMatchedStatus& status);

	/* JDXCZ    返回DataWriter关联的主题 */
	TopicImpl* get_topic();

	/* JDXCZ    获取DataWriter所属的Publisher */
	PublisherImpl* get_publisher();

	/* JDXCZ    断言DataWriter的活跃性 */
	ReturnCode_t assert_liveliness();

	/* JDXCZ    获取当前与DataWriter “关联”的订阅列表信息 */
	ReturnCode_t get_matched_subscription_data(SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* JDXCZ    获取当前与DataWriter “关联”的订阅列表 */
	ReturnCode_t get_matched_subscriptions(InstanceHandleSeq& subscription_handles);

	//	/* JDXCZ 设置PubliserQos的值，不兼容则设置失败 */
	//ReturnCode_t set_qos(const DataWriterQos& QoS);

	/* JDXCZ 获取PublisherQos的值 */
	ReturnCode_t get_qos(DataWriterQos& QoS);

	/* JDXCZ 设置PublisherListener的值 */
	ReturnCode_t set_listener(DataWriterListener* pListener, StatusMask mask);

	/* JDXCZ 获取PublisherListener的值 */
	DataWriterListener* get_listener();

public:
	/* Nephalem 自定义接口 */

	/* Nephalem 发送该节点的状态信息，创建、修改、删除、已存在 */
	virtual ReturnCode_t SendInfo(_ENTITY_STATUS_T Status);

	/* Nepalem 设置对用户展示的TopicDescription */
	void setUserDataWriter(DataWriter* pDataWriter);

	/* Nepalem 获取对用户展示的TopicDescription */
	DataWriter* getUserDataWriter();

	/* Nephalem 设置相关的RTPS层Writer 并设置HistoyrCache */
	void setRelatedWriter(Writer* pWriter);

	/* Nephalem 获取相关的RTPS层Writer */
	Writer* getRelatedWriter();

	/* Nephalem DeadLine相关 */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static void deadlineCheck(void* pDataWriter, unsigned char TimerOrWaitFired);
#elif defined ULINX_LINUX
    static void deadlineCheck(union sigval pDataWriter);
#elif defined ULINX_VXWORKS
    static void deadlineCheck(timer_t timerid,int pDataWriter);
#endif

	bool isDeadlineMissed();

	void setDeadlineMissed(bool flag);

	OfferedDeadlineMissedStatus& getDeadlineStatus();

	PublicationMatchedStatus& getPublicationMatchedStatus();

	/* Nephalem 更新现有状态 */
	ReturnCode_t updataLiveLinessChangedStatus();

	/* 调用on_publication_matched listener */
	void on_publication_matched();

	/* Nephalem rti独有的接口，兼容rti */
	ReturnCode_t get_matched_subscription_participant_data(ParticipantBuiltinTopicData& participant_data, const InstanceHandle_t& subscription_handle);

private:
	/* Nephalem 对用户展示的DataWriter */
	DataWriter* m_pUserDataWriter;

	PublisherImpl* m_pPublisherImpl;

	TopicImpl* m_pTopicImpl;

	DataWriterQos m_DataWriterQos;

	DataWriterListener* m_pDataWriterListener;

	StatusMask m_StatusMask;

	Writer* m_pRelatedWriter;

	HistoryCache* m_pWriterCache;

	uLinxTimer* m_pDeadlineTimer;

	bool m_bDeadlineMiss;

	OfferedDeadlineMissedStatus m_DeadLineStatus;

	PublicationMatchedStatus m_PublicationMatchedStatus;

	LivelinessLostStatus m_stLivelinessLostStatus;

	/* JDXCZ 20211014 记录当前 主题发送过的数据的个数 */
	SequenceNumber_t m_CurrentSeqNum;
};
