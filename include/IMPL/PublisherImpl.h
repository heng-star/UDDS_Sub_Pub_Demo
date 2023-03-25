#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/DomainEntity.h"

/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DomainParticipantImpl;
class PublisherListener;
class DataWriterImpl;
class DataWriterListener;

class PublisherImpl : public DomainEntity
{
public:
	//���캯��
	PublisherImpl(DomainParticipantImpl* pRelatedDomainParticipant,
		const PublisherQos& QoS,
		StatusMask mask,
		PublisherListener* pPublisherListener = NULL);
	//��������
	virtual ~PublisherImpl(void);
public:
	/* JDXCZ �˴�Ϊ�淶�ж���Ľӿ� */

	/* JDXCZ ��������д�� */
	DataWriterImpl* create_datawriter(TopicImpl* pTopicImpl, const DataWriterQos& Qos, StatusMask mask, DataWriterListener* pDataWriterListener = NULL);

	/* JDXCZ ɾ������д�� */
	ReturnCode_t delete_datawriter(DataWriterImpl*& pDataWriter);

	/* JDXCZ ��������д�� */
	_DATA_WRITER_IMPL_LIST_T  lookup_datawriter(const string& topic_name);

	///* JDXCZ ����DDS����Ӧ�ý������ڱ�Publisher��DataWriter������ж���޸� */
	//ReturnCode_t suspend_publications();

	///* JDXCZ	��֪����Ӧ�ó��������֮ǰsuspend_publications���������Ķ���޸ģ�
	//			����ʵ���߿���ʹ��������ʾ����������suspend_publications���������������޸�*/
	//ReturnCode_t resume_pulications();

	///* JDXCZ Ҫ��Ӧ�ó���ʹ������Publisher��DataWriter����ʼ��һ�¼������޸� */
	//ReturnCode_t begin_coherent_changes();

	///* JDXCZ �ս���begin_coherent_changes�����������ġ�һ�¼��� */
	//ReturnCode_t end_coherent_changes();

	///* JDXCZ	���������̣߳�ֱ������ƥ��Ŀɿ���DataReaderʵ�嶼ȷ���յ��ɿ���DataWriterʵ��д�����������
	//			����max_wait�����趨�ĳ���ʱ���Ѿ����� */
	//ReturnCode_t wait_for_acknowledgments(Duration_t max_wait);

	/* JDXCZ    ����Publisher������Domainparticipant */
	DomainParticipantImpl* get_participant();

	///* JDXCZ    ɾ��Publisher���󴴽�������ʵ�壬ɾ�����а�����DataWriter */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ    ����DataWriterQos��Ĭ��ֵ */
	//ReturnCode_t set_default_datawriter_qos(const DataWriterQos& Qos);

	///* JDXCZ    ��ȡDataWriterQos��Ĭ��ֵ */
	//ReturnCode_t get_default_datawriter_qos(DataWriterQos& Qos);

	///* JDXCZ ��TopicQos��ֵ���Ƶ�DataWriterQos */
	//ReturnCode_t copy_from_topic_qos(DataWriterQos& datawriter_qos, const TopicQos& topic_qos);

	///* JDXCZ ����PubliserQos��ֵ��������������ʧ�� */
	//ReturnCode_t set_qos(const PublisherQos& QoS);

	/* JDXCZ ��ȡPublisherQos��ֵ */
	ReturnCode_t get_qos(PublisherQos& QoS);

	///* JDXCZ ����PublisherListener��ֵ */
	//ReturnCode_t set_listener(PublisherListener* pListener, StatusMask mask);

	///* JDXCZ ��ȡPublisherListener��ֵ */
	//PublisherListener* get_listener();

public:
	/* Nephalem �Զ���ӿ� */

	/* Nepalem ���ö��û�չʾ��pPublisher */
	void setUserPublisher(Publisher* pPublisher);

	/* Nepalem ��ȡ���û�չʾ��pPublisher */
	Publisher* getUserPublisher();

private:
	Publisher* m_pUserPublisher;

	DomainParticipantImpl* m_pRelatedDomainParticipant;

	PublisherQos m_PublisherQos;

	PublisherListener* m_pPublisherListener;

	_DATA_WRITER_IMPL_LIST_T  m_DatawriterImplList;
};