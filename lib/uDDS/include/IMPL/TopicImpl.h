#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/TopicDescriptionImpl.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"

/* Nephalem ϵͳͷ�ļ� */
#include <string>
using std::string;

/* Nephalem ǰ������ */
class DomainParticipantImpl;
class TopicListener;

class TopicImpl : public TopicDescriptionImpl, public DomainEntity
{
public:
	TopicImpl(string strTopicName, 
		string strTypeName, 
		DomainParticipantImpl* pRelatedParticipant,
		const TopicQos& QoS,
		TopicListener* pTopicListener = NULL);

	virtual ~TopicImpl();

	/* Nephalem ���ü����� */
	ReturnCode_t set_listener(TopicListener* pTopicListener, StatusMask mask);

	/* Nephalem ��ȡ���õļ����� */
	TopicListener* get_listener();

	/* Nephalem ����Ĭ�ϵ�TopicQos��������������ʧ�� */
	ReturnCode_t set_qos(const TopicQos& QoS);

	/* Nephalem ��ȡTopicQosĬ��ֵ */
	ReturnCode_t get_qos(TopicQos& QoS);

private:
	/* Nephalem ����QoS */
	TopicQos m_QoS;

	/* Nephalem ��������� */
	TopicListener* m_pTopicListener;
	
};

