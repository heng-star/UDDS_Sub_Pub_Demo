#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/DomainEntity.h"

/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
class DomainParticipantImpl;
class PublisherListener;
class DataWriterImpl;
class DataWriterListener;

class PublisherImpl : public DomainEntity
{
public:
	//构造函数
	PublisherImpl(DomainParticipantImpl* pRelatedDomainParticipant,
		const PublisherQos& QoS,
		StatusMask mask,
		PublisherListener* pPublisherListener = NULL);
	//析构函数
	virtual ~PublisherImpl(void);
public:
	/* JDXCZ 此处为规范中定义的接口 */

	/* JDXCZ 创建数据写者 */
	DataWriterImpl* create_datawriter(TopicImpl* pTopicImpl, const DataWriterQos& Qos, StatusMask mask, DataWriterListener* pDataWriterListener = NULL);

	/* JDXCZ 删除数据写者 */
	ReturnCode_t delete_datawriter(DataWriterImpl*& pDataWriter);

	/* JDXCZ 查找数据写者 */
	_DATA_WRITER_IMPL_LIST_T  lookup_datawriter(const string& topic_name);

	///* JDXCZ 告诉DDS服务，应用将对属于本Publisher的DataWriter对象进行多次修改 */
	//ReturnCode_t suspend_publications();

	///* JDXCZ	告知服务，应用程序已完成之前suspend_publications方法启动的多个修改，
	//			服务实现者可以使用这种提示批量处理自suspend_publications以来所做的所有修改*/
	//ReturnCode_t resume_pulications();

	///* JDXCZ 要求应用程序使用属于Publisher的DataWriter对象开始“一致集”的修改 */
	//ReturnCode_t begin_coherent_changes();

	///* JDXCZ 终结由begin_coherent_changes方法的启动的“一致集” */
	//ReturnCode_t end_coherent_changes();

	///* JDXCZ	阻塞调用线程，直到所有匹配的可靠的DataReader实体都确认收到可靠的DataWriter实体写入的所有数据
	//			或者max_wait参数设定的持续时间已经到期 */
	//ReturnCode_t wait_for_acknowledgments(Duration_t max_wait);

	/* JDXCZ    返回Publisher所属的Domainparticipant */
	DomainParticipantImpl* get_participant();

	///* JDXCZ    删除Publisher对象创建的所有实体，删除所有包含的DataWriter */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ    设置DataWriterQos的默认值 */
	//ReturnCode_t set_default_datawriter_qos(const DataWriterQos& Qos);

	///* JDXCZ    获取DataWriterQos的默认值 */
	//ReturnCode_t get_default_datawriter_qos(DataWriterQos& Qos);

	///* JDXCZ 将TopicQos的值复制到DataWriterQos */
	//ReturnCode_t copy_from_topic_qos(DataWriterQos& datawriter_qos, const TopicQos& topic_qos);

	///* JDXCZ 设置PubliserQos的值，不兼容则设置失败 */
	//ReturnCode_t set_qos(const PublisherQos& QoS);

	/* JDXCZ 获取PublisherQos的值 */
	ReturnCode_t get_qos(PublisherQos& QoS);

	///* JDXCZ 设置PublisherListener的值 */
	//ReturnCode_t set_listener(PublisherListener* pListener, StatusMask mask);

	///* JDXCZ 获取PublisherListener的值 */
	//PublisherListener* get_listener();

public:
	/* Nephalem 自定义接口 */

	/* Nepalem 设置对用户展示的pPublisher */
	void setUserPublisher(Publisher* pPublisher);

	/* Nepalem 获取对用户展示的pPublisher */
	Publisher* getUserPublisher();

private:
	Publisher* m_pUserPublisher;

	DomainParticipantImpl* m_pRelatedDomainParticipant;

	PublisherQos m_PublisherQos;

	PublisherListener* m_pPublisherListener;

	_DATA_WRITER_IMPL_LIST_T  m_DatawriterImplList;
};