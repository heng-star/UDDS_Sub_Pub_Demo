#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
class DomainParticipantImpl;
class SubscriberListener;
class TopicDescriptionImpl;
class DataReaderListener;

class SubscriberImpl : public DomainEntity
{
public:
	//构造函数
	SubscriberImpl(DomainParticipantImpl* pRelatedDomainParticipant,
		const SubscriberQos& QoS,
		StatusMask mask,
		SubscriberListener* pSublisherListener = NULL);
	//析构函数
	virtual ~SubscriberImpl();
public:
	/* JDXCZ 此处为规范中定义的接口 */

	/* JDXCZ 设置SubscriberQos的值，不兼容则设置失败 */
	//ReturnCode_t set_qos(const SubscriberQos& QoS);

	/* JDXCZ 获取SubscriberQos的值 */
	ReturnCode_t get_qos(SubscriberQos& QoS);

	/* JDXCZ 设置SubscriberListener的值 */
	ReturnCode_t set_listener(SubscriberListener* pListener, StatusMask mask);

	///* JDXCZ 获取SubscriberListener的值 */
	//SubscriberListener* get_listener();

	/* JDXCZ    创建数据读者 */
	DataReaderImpl* create_datareader(TopicDescriptionImpl* pTopic, const DataReaderQos& Qos, DataReaderListener* pDataReaderListener, StatusMask mask);

	/* JDXCZ    删除数据读者 */
	ReturnCode_t delete_datareader(DataReaderImpl* pDataReader);

	/* JDXCZ   查找数据读者 如果有多个数据读者则查找到的第一个 */
	DataReaderImpl* lookup_datareader(const string& topic_name);

	///* JDXCZ   表示应用程序即将访问附加到订阅者（Subscriber）上的任何DataReader对象中的数据样本 */
	//ReturnCode_t begin_access();

	///* JDXCZ   此方法表示应用程序已完成访问Subscriber管理的DataReader对象中的数据样本 */
	//ReturnCode_t end_access();

	///* JDXCZ   此方法允许应用程序访问包含具有指定sample_states，view_states和instance_states的样本的DataReader对象 */
	//ReturnCode_t get_datareaders(DataReader* pDataReaders[], const SampleStateKind& sample_states[], const ViewStateKind& view_states[], const InstanceStateKind& instanceStateKind[]);

	///* JDXCZ 此方法调用绑定到DataReader实体的DataReaderListener对象的on_data_available方法，该实体的DATA_AVAILABLE状态被视为已更改。
	//	通常在SubscriberListener的on_data_on_readers方法中调用此方法。这样一来SubscriberListener可以委托DataReaderListener对象处理数据 */
	//ReturnCode_t notify_datareaders();

	///* JDXCZ 允许访问SAMPLE_LOST通信状态   */
	///* ReturnCode_t  get_sample_lost_status( SampleLostStatus& status); */


	/* JDXCZ 获取Subscriber所属的DomainParticipant */
	DomainParticipantImpl* get_participant();

	///* JDXCZ 删除Subscriber中所有实体，删除所有DataReader */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ 设置DataReader的默认Qos */
	//ReturnCode_t set_default_datareader_qos(const DataReaderQos& Qos);

	///* JDXCZ 获取DataReader的默认Qos */
	//ReturnCode_t get_default_datareader_qos(DataReaderQos& Qos);

	///* JDXCZ 将TopicQos的值复制到DataReaderQos */
	//ReturnCode_t copy_from_topic_qos(DataReaderQos& datareader_qos, const TopicQos& topic_qos);

public:
	/* Nephalem 自定义接口 */

	/* Nepalem 设置对用户展示的Subscriber */
	void setUserSubscriber(Subscriber* pSubscriber);

	/* Nepalem 获取对用户展示的Subscriber */
	Subscriber* getUserSubscriber();

private:
	/* Nepalem 对用户展示的Subscriber */
	Subscriber* m_pUserSubscriber;

	DomainParticipantImpl* m_pRelatedDomainParticipant;

	SubscriberQos m_SubscriberQos;

	SubscriberListener* m_pSubscriberListener;

	/* Nephalem 当前发布者创建的数据写者列表 */
	_DATA_READER_IMPL_LIST_T m_DataReaderImplList;

};