#pragma once
/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"
#include "ULINXAPI/uLinxTimer.h"
#include "DDS/DataReader.h"
#include "DDS/Listener/DataReaderListener.h"
/* Nephalem ϵͳͷ�ļ� */


/* Nephalem ǰ������ */
class DataReaderListener;
class TopicDescriptionImpl;
class Reader;
class HistoryCache;
class DDSContentFilter;

class DataReaderImpl : public DomainEntity
{
public:
	//���캯��
	DataReaderImpl(SubscriberImpl* pSubscriberImpl,
		TopicDescriptionImpl* pTopic,
		const DataReaderQos& QoS,
		StatusMask mask,
		DataReaderListener* pDataReaderListener = NULL);
	//��������
	virtual ~DataReaderImpl();
public:
	/* JDXCZ �˴�Ϊ�淶�ж���Ľӿ� */

	/* JDXCZ ����DataReader��ֵ��������������ʧ�� */
	//ReturnCode_t set_qos(const DataReaderQos& QoS);

	/* JDXCZ ��ȡDataReader��ֵ */
	ReturnCode_t get_qos(DataReaderQos& QoS);

	///* JDXCZ ����DataReaderListener��ֵ */
	ReturnCode_t set_listener(DataReaderListener* pListener, StatusMask mask);

	/* JDXCZ ����DataReaderListener��ֵ */
	DataReaderListener* get_listener();

	///* JDXCZ    ����һ��ReadCondition���󶨵�������DataReader*/
	//ReaderCondition* create_readcondition(SampleStateKind smaple_states[], ViewStateKind  view_states[], InstanceStateKind  instance_states[]);

	///* JDXCZ    ����һ��QueryCondition,�󶨵�������DataReader��*/
	//QueryCondition create_querycondition(SampleStateKind smaple_states[], ViewStateKind  view_states[], InstanceStateKind  instance_states[], const string& query_expression, string query_parameters);

	///* JDXCZ    ɾ�����ӵ�DataReader��ReadCondition*/
	//ReturnCode_t delete_readcondition(ReaderCondition* condition);

	///* JDXCZ    ͨ��DataReader����Dataֵ�ĺϼ�*/
	//ReturnCode_t read(Data data_values[], SampleInfo sample_infos[], long max_samples, SampleStateKind sample_states[], ViewStateKind view_states[], InstanceStateKind instance_states);
	ReturnCode_t read(UserDataVector& data_values, SampleInfoSeq& sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	/* JDXCZ    ����DataReader�е����������ϼ��Լ���Ӧ��SampleInfo�ṹ�ϼ�*/
	/* Nephalem data_values max_len = 0 ʹ���㿽�� ʹ�������ͨ��return_loan�黹 */
	/* Nephalem data_values max_len > 0 ʹ����� */
	/* Nephalem data_values sample_infos����������������ͬ */
	/* Nephalem take������ȡ�����ݲ����ٱ�take */
	//ReturnCode_t take(Data data_values[], SampleInfoSeq sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);
	ReturnCode_t take(UserDataVector& data_values, SampleInfoSeq& sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	///* JDXCZ    ������ReadCondition��ָ��������ƥ�������*/
	//ReturnCode_t read_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, const ReaderCondition& readcondition);

	///* JDXCZ    ������ReadCondition��ָ��������ƥ�������*/
	//ReturnCode_t take_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, const ReaderCondition& readcondition);

	///* JDXCZ    ��DataReader������һ��֮ǰδ���ʹ���Dataֵ*/
	//ReturnCode_t read_next_sample(Data data_values[], SampleInfo sample_infos[]);
	ReturnCode_t read_next_sample(UserData& data_value, SampleInfo& sample_info);

	/* JDXCZ    ��DataReader������һ��֮ǰδ���ʹ���Dataֵ������DataReader�С�ɾ��������ʹ�䲻�ٿɷ���*/
	//ReturnCode_t take_next_sample(Data& data_values, SampleInfo& sample_info);
	ReturnCode_t take_next_sample(UserData& data_value, SampleInfo& sample_info);

	///* JDXCZ    ��DataReader����Dataֵ�ĺϼ� */
	//ReturnCode_t read_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    ��DataReader����Dataֵ�ĺϼ�*/
	//ReturnCode_t take_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    ��DataReader������һ��֮ǰδ���ʹ���Dataֵ */
	//ReturnCode_t reaad_next_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t previous_handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    ��DataReader������һ��֮ǰδ���ʹ���Dataֵ������DataReader�С�ɾ��������ʹ�䲻�ٿɷ���*/
	//ReturnCode_t take_next_instance(Data data_values[], SampleInfo sample_info[], long max_samples, InstanceHandle_t previous_handle, SampleStateKind sample_states, ViewStateKind samole_states[], InstanceStateKind instance_states);

	///* JDXCZ    ��DataReader����Dataֵ�ļ��ϣ���Ϊ��read_next_instance��ͬ��ֻ�Ƿ��ص�������������������ָ��������*/
	//ReturnCode_t read_next_instance_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, InstanceHandle_t previous_handle, ReadCondition* pReadCondition);

	///* JDXCZ    DataReader����Dataֵ�ϼ�������DataReader�С�ɾ�������� */
	//ReturnCode_t take_next_instance_w_condition(Data data_values[], SampleInfo sample_infos[], long max_samples, InstanceHandle_t previous_handle, ReadCondition* pReadCondition);

	///* JDXCZ    ��DataReader֪ͨӦ�ó�������ɷ���data_values��sample_infos�ĺϼ�����Щ�ϼ��ǽ���ǰͨ��DataReader��read��take������õ� */
	//ReturnCode_t return_loan(Data data_values[], SampleInfo sample_infos[]);

	///* JDXCZ    �������LIVELINESS_CHANGEDͨ��״̬ */
	//ReturnCode_t get_liveliness_changed_status(LivelinessChangedStatus& status);

	///* JDXCZ    �������REQUESTED_DEADLINE_MISSEDͨ��״̬ */
	//ReturnCode_t get_requested_deadline_missed_status(_REQUESTED_DEADLINE_MISSED_STATUS& status);

	///* JDXCZ    �������REQUESTED_INCOMPATIBLE_QOSͨ��״̬ */
	//ReturnCode_t get_requested_incompatible_qos_status(RequestedIncompatibleQosStatus& status);

	///* JDXCZ    �������SAMPLE_LOSTͨ��״̬ */
	//ReturnCode_t get_sample_lost_status(SampleLostStatus& status);

	///* JDXCZ    �������SAMPLE_REJECTEDͨ��״̬ */
	//ReturnCode_t get_sample_rejected_statu(SampleRejectedStatus& status);

	/* JDXCZ    �������SUBSCRIPTION_MATCHEDͨ��״̬ */
	ReturnCode_t get_subscription_matched_status(SubscriptionMatchedStatus& status);

	/* JDXCZ    ������DataReader������TopicDescription */
	TopicDescriptionImpl* get_topicdescription();

	/* JDXCZ    ������DataReader������Subscriber */
	SubscriberImpl* get_subscriber();

	///* JDXCZ    ��ȡ��instance_handle��Ӧ��ʵ���ؼ���ke�������key_holderʵ������ɹؼ���key���ֶ� */
	//ReturnCode_t get_key_value(Data key_holder, InstanceHandle_t handle);

	///* JDXCZ    ʵ��instance��Ϊ������������һ����� */
	//InstanceHandle_t lookup_instance(Data instance);

	///* JDXCZ    ɾ��ͨ��DataReader����ġ���������������������ʵ��,ɾ��QueryCondition ��ReadCondition���� */
	//ReturnCode_t delete_contained_entities();

	///* JDXCZ    ���������̣߳�ֱ�����յ����С���ʷ�����ݣ�����max_wait����ָ����ʱ���ѵ��� */
	//ReturnCode_t wait_for_historical_data(const Duration_t max_wait);

	/* JDXCZ    ��ȡ��ǰ��DataReader ���������ķ�����Ϣ */
	ReturnCode_t get_matched_publication_data(PublicationBuiltinTopicData& publication_data, const InstanceHandle_t& publication_handle);

	/* JDXCZ    ��ȡ��ǰ��DataReader ���������ķ����б� */
	InstanceHandle_t get_matched_publications(InstanceHandleSeq& publication_handles);

public:
	/* Nephalem �Զ���ӿ� */

	/* Nephalem ���͸ýڵ��״̬��Ϣ���������޸ġ�ɾ�����Ѵ��� */
	virtual ReturnCode_t SendInfo(_ENTITY_STATUS_T Status);

	/* Nepalem ���ö��û�չʾ��DataReader */
	void setUserDataReader(DataReader* pDataReader);

	/* Nepalem ��ȡ���û�չʾ��pPublisher */
	DataReader* getUserDataReader();

	/* Nephalem ������ص�RTPS��Reader ������HistoyrCache */
	void setRelatedReader(Reader* pReader);

	/* Nephalem ��ȡ��ص�RTPS��Reader */
	Reader* getRelatedReader();

	/* Nephalem ���ݵ���֪ͨ */
	ReturnCode_t DataReceive(_CACHE_CHANGE * pCacheChange);

	/* Nephalem ��Cache�ж�ȡ���� */
	ReturnCode_t ReadFromCache(char*& pMyDataValue, unsigned int& uiLeng, InstanceHandle_t& Handle, _CHANGE_KIND_T& Kind);

	/* Nephalem DeadLine��� */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static void deadlineCheck(void* pDataReader, unsigned char TimerOrWaitFired);
#elif defined ULINX_LINUX
    static void deadlineCheck(union sigval pDataReader);
#elif defined ULINX_VXWORKS
    static void deadlineCheck(timer_t timerid,int pDataReader);
#endif

	bool isDeadlineMissed();

	void setDeadlineMissed(bool flag);

	/* Nephalem �������Ȩ��¼ */
	void clearOwnerShipWriter();

	void setOwnerShipWriter(DiscoveredWriterData& remoteWriter);

	/* Nephalem ���lifespan���ʱ�� */
	void checkLifeSpan();

	GUID_t getOwnerShipWriter();

	RequestedDeadlineMissedStatus& getDeadlineStatus();

	SubscriptionMatchedStatus& getSubscriptionMatchedStatus();

	LivelinessChangedStatus& getLivelinessChangedStatus();

	/* Nephalem ����������� */
	ReturnCode_t updataLiveLinessChangedStatus();
	/* Nephalem ��������״̬ */
	ReturnCode_t updataLiveLinessChangedStatus(bool bAlive);

	/* ����on_subscription_matched listener */
	void on_subscription_matched();

	/* Nephalem rti���еĽӿڣ�����rti */
	ReturnCode_t get_matched_publication_participant_data(ParticipantBuiltinTopicData& participant_data, const InstanceHandle_t& publication_handle);

	ReturnCode_t SetDataFilter(DDSContentFilter* pDataFilter);
private:
	/* Nephalem ���û�չʾ��DataReader */
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

	/* wangyi 2022/2/21 ǰһ���ύ����ʱ�� */
	ULINX_INT64 m_LastTime;

	RequestedDeadlineMissedStatus m_DeadlineStatus;

	/* Nephalem ƥ��״̬ */
	SubscriptionMatchedStatus	m_SubscriptionMatchedStatus;

	LivelinessChangedStatus		m_LiveLinessChangeStatus;

	/* JDXCZ ���ݹ�����������������������  void*  **/
	DDSContentFilter* m_pDataFilter;
public:
	/* JD ��ǰ���ձ��ĵ����к� */
	SequenceNumber_t	m_CurrentSeqNum;
};
