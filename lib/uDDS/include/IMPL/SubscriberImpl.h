#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DomainParticipantImpl;
class SubscriberListener;
class TopicDescriptionImpl;
class DataReaderListener;

class SubscriberImpl : public DomainEntity
{
public:
	//���캯��
	SubscriberImpl(DomainParticipantImpl* pRelatedDomainParticipant,
		const SubscriberQos& QoS,
		StatusMask mask,
		SubscriberListener* pSublisherListener = NULL);
	//��������
	virtual ~SubscriberImpl();
public:
	/* JDXCZ �˴�Ϊ�淶�ж���Ľӿ� */

	/* JDXCZ ����SubscriberQos��ֵ��������������ʧ�� */
	//ReturnCode_t set_qos(const SubscriberQos& QoS);

	/* JDXCZ ��ȡSubscriberQos��ֵ */
	ReturnCode_t get_qos(SubscriberQos& QoS);

	/* JDXCZ ����SubscriberListener��ֵ */
	ReturnCode_t set_listener(SubscriberListener* pListener, StatusMask mask);

	///* JDXCZ ��ȡSubscriberListener��ֵ */
	//SubscriberListener* get_listener();

	/* JDXCZ    �������ݶ��� */
	DataReaderImpl* create_datareader(TopicDescriptionImpl* pTopic, const DataReaderQos& Qos, DataReaderListener* pDataReaderListener, StatusMask mask);

	/* JDXCZ    ɾ�����ݶ��� */
	ReturnCode_t delete_datareader(DataReaderImpl* pDataReader);

	/* JDXCZ   �������ݶ��� ����ж�����ݶ�������ҵ��ĵ�һ�� */
	DataReaderImpl* lookup_datareader(const string& topic_name);

	///* JDXCZ   ��ʾӦ�ó��򼴽����ʸ��ӵ������ߣ�Subscriber���ϵ��κ�DataReader�����е��������� */
	//ReturnCode_t begin_access();

	///* JDXCZ   �˷�����ʾӦ�ó�������ɷ���Subscriber�����DataReader�����е��������� */
	//ReturnCode_t end_access();

	///* JDXCZ   �˷�������Ӧ�ó�����ʰ�������ָ��sample_states��view_states��instance_states��������DataReader���� */
	//ReturnCode_t get_datareaders(DataReader* pDataReaders[], const SampleStateKind& sample_states[], const ViewStateKind& view_states[], const InstanceStateKind& instanceStateKind[]);

	///* JDXCZ �˷������ð󶨵�DataReaderʵ���DataReaderListener�����on_data_available��������ʵ���DATA_AVAILABLE״̬����Ϊ�Ѹ��ġ�
	//	ͨ����SubscriberListener��on_data_on_readers�����е��ô˷���������һ��SubscriberListener����ί��DataReaderListener���������� */
	//ReturnCode_t notify_datareaders();

	///* JDXCZ �������SAMPLE_LOSTͨ��״̬   */
	///* ReturnCode_t  get_sample_lost_status( SampleLostStatus& status); */


	/* JDXCZ ��ȡSubscriber������DomainParticipant */
	DomainParticipantImpl* get_participant();

	///* JDXCZ ɾ��Subscriber������ʵ�壬ɾ������DataReader */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ ����DataReader��Ĭ��Qos */
	//ReturnCode_t set_default_datareader_qos(const DataReaderQos& Qos);

	///* JDXCZ ��ȡDataReader��Ĭ��Qos */
	//ReturnCode_t get_default_datareader_qos(DataReaderQos& Qos);

	///* JDXCZ ��TopicQos��ֵ���Ƶ�DataReaderQos */
	//ReturnCode_t copy_from_topic_qos(DataReaderQos& datareader_qos, const TopicQos& topic_qos);

public:
	/* Nephalem �Զ���ӿ� */

	/* Nepalem ���ö��û�չʾ��Subscriber */
	void setUserSubscriber(Subscriber* pSubscriber);

	/* Nepalem ��ȡ���û�չʾ��Subscriber */
	Subscriber* getUserSubscriber();

private:
	/* Nepalem ���û�չʾ��Subscriber */
	Subscriber* m_pUserSubscriber;

	DomainParticipantImpl* m_pRelatedDomainParticipant;

	SubscriberQos m_SubscriberQos;

	SubscriberListener* m_pSubscriberListener;

	/* Nephalem ��ǰ�����ߴ���������д���б� */
	_DATA_READER_IMPL_LIST_T m_DataReaderImplList;

};