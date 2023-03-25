#pragma once
/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"
#include "QoSPolicy.h"
#include "IMPL/DomainEntity.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinxTimer.h"
#include "DDS/Listener/DataWriterListener.h"
/* Nephalem ϵͳͷ�ļ� */


/* Nephalem ǰ������ */
class DataWriter;
class PublisherImpl;
class DataWriterListener;
class Writer;
class HistoryCache;

typedef  void Data;
class DataWriterImpl : public DomainEntity
{
public:
	/* Nephalem ���캯�� */
	DataWriterImpl(PublisherImpl* pPublisherImpl,
		TopicImpl* pTopic,
		const DataWriterQos& Qos,
		StatusMask mask,
		DataWriterListener* pDataWriterListener = NULL);

	/* Nephalem �������� */
	virtual ~DataWriterImpl();

public:
	/* JDXCZ �˴�Ϊ�淶�ж���Ľӿ� */

	///* JDXCZ    ֪ͨ����Ӧ�ó����޸��ض�����ʵ�� */
	//InstanceHandle_t register_instance(const Data* instance);

	///* JDXCZ    ֪ͨ����Ӧ�ó����޸��ض�����ʵ�������޸�source_timestamp��ֵ */
	//InstanceHandle_t register_instance_w_timestamp(const Data* instance, const Time_t& timestamp);

	///* JDXCZ    ����OFFERED_DEADLINE_MISSEDͨ��״̬ */
	//ReturnCode_t unregister_instance(const Data* instance, const InstanceHandle_t& handle);

	///* JDXCZ    ����OFFERED_DEADLINE_MISSEDͨ��״̬ */
	//ReturnCode_t  unregister_instance_w_timestamp(const Data* instance, const InstanceHandle_t& handle, const Time_t& timestamp);

	///* JDXCZ    ȡ��instance_handle��Ӧ��ʵ���ؼ���ֵ */
	//ReturnCode_t get_key_value(const Data* key_holder, const InstanceHandle_t& handle);

	///* JDXCZ    ����DataWriterʵ�� */
	//InstanceHandle_t lookup_instance(const Data* instance);

	/* JDXCZ    �޸�����ʵ����ֵ ������������Dataδȷ����Data ���͸�Ϊchar* */
	//ReturnCode_t write(const Data* data, const InstanceHandle_t& handle);

	/* Nephalem ����Ϸ�write�ӿڣ����ཫ����ת��Ϊchar*�� ���� */
	ReturnCode_t write(const char* pData, unsigned int length, const InstanceHandle_t& handle, _PARAMETER_LIST & InlineQos, GUID_t stReaderGuid = GUID_UNKNOWN);

	/* JDXCZ    �޸�����ʵ����ֵ��ͨ��SampleInfo��source_timestamp�����ṩ�ɹ�DataReader����ʹ�õ�source_timestamp��ֵ */
	ReturnCode_t write_w_timestamp(const char* pData, unsigned int length, const InstanceHandle_t& handle, _PARAMETER_LIST & InlineQos, const Time_t& timestamp, GUID_t stReaderGuid = GUID_UNKNOWN);

	///* JDXCZ    �����м��ɾ�����ݣ�ͨ��SampleInfo��source_timestamp�����ṩ�ɹ�DataReader����ʹ�õ�source_timestamp��ֵ��*/
	//ReturnCode_t dispose(const Data* data, const InstanceHandle_t& handle);

	///* JDXCZ    �����м��ɾ������ ������*/
	//ReturnCode_t dispose_w_timestamp(const Data* data, const InstanceHandle_t& handle, const Time_t& timestamp);

	///* JDXCZ    ���������̣߳�֪��DataWriter���͵����ݱ�����RELIABLE��DataReaderʵ��ȷ�� */
	//ReturnCode_t wait_for_acknowledgments(const Duration_t& max_wait);

	/* JDXCZ    ����LIVELINESS_LOSTͨ��״̬*/
	//ReturnCode_t get_liveliness_lost_status(LivelinessLostStatus& status);

	///* JDXCZ    ����OFFERED_DEADLINE_MISSEDͨ��״̬ */
	//ReturnCode_t get_offered_deadline_missed_status(_OFFERED_DEADLINE_MISSED_STATUS& status);

	///* JDXCZ    ����OFFERED_INCOMPATIBLE_QOSͨ��״̬ */
	//ReturnCode_t get_offered_incompatible_qos_status(_OFFERED_DEADLINE_MISSED_STATUS& status);

	/* JDXCZ    ����Publication_matched��ͨ��״̬ */
	ReturnCode_t get_publication_matched_status(PublicationMatchedStatus& status);

	/* JDXCZ    ����DataWriter���������� */
	TopicImpl* get_topic();

	/* JDXCZ    ��ȡDataWriter������Publisher */
	PublisherImpl* get_publisher();

	/* JDXCZ    ����DataWriter�Ļ�Ծ�� */
	ReturnCode_t assert_liveliness();

	/* JDXCZ    ��ȡ��ǰ��DataWriter ���������Ķ����б���Ϣ */
	ReturnCode_t get_matched_subscription_data(SubscriptionBuiltinTopicData& subscription_data, const InstanceHandle_t& subscription_handle);

	/* JDXCZ    ��ȡ��ǰ��DataWriter ���������Ķ����б� */
	ReturnCode_t get_matched_subscriptions(InstanceHandleSeq& subscription_handles);

	//	/* JDXCZ ����PubliserQos��ֵ��������������ʧ�� */
	//ReturnCode_t set_qos(const DataWriterQos& QoS);

	/* JDXCZ ��ȡPublisherQos��ֵ */
	ReturnCode_t get_qos(DataWriterQos& QoS);

	/* JDXCZ ����PublisherListener��ֵ */
	ReturnCode_t set_listener(DataWriterListener* pListener, StatusMask mask);

	/* JDXCZ ��ȡPublisherListener��ֵ */
	DataWriterListener* get_listener();

public:
	/* Nephalem �Զ���ӿ� */

	/* Nephalem ���͸ýڵ��״̬��Ϣ���������޸ġ�ɾ�����Ѵ��� */
	virtual ReturnCode_t SendInfo(_ENTITY_STATUS_T Status);

	/* Nepalem ���ö��û�չʾ��TopicDescription */
	void setUserDataWriter(DataWriter* pDataWriter);

	/* Nepalem ��ȡ���û�չʾ��TopicDescription */
	DataWriter* getUserDataWriter();

	/* Nephalem ������ص�RTPS��Writer ������HistoyrCache */
	void setRelatedWriter(Writer* pWriter);

	/* Nephalem ��ȡ��ص�RTPS��Writer */
	Writer* getRelatedWriter();

	/* Nephalem DeadLine��� */
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

	/* Nephalem ��������״̬ */
	ReturnCode_t updataLiveLinessChangedStatus();

	/* ����on_publication_matched listener */
	void on_publication_matched();

	/* Nephalem rti���еĽӿڣ�����rti */
	ReturnCode_t get_matched_subscription_participant_data(ParticipantBuiltinTopicData& participant_data, const InstanceHandle_t& subscription_handle);

private:
	/* Nephalem ���û�չʾ��DataWriter */
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

	/* JDXCZ 20211014 ��¼��ǰ ���ⷢ�͹������ݵĸ��� */
	SequenceNumber_t m_CurrentSeqNum;
};
