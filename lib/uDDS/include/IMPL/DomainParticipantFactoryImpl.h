#pragma once
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"

#include "DDS/DomainParticipant.h"
#include "DDS/Listener/DomainParticipantListener.h"
#include "ULINXAPI/uLinXSemMutex.h"

class DomainParticipantFactoryImpl
{
public:
	/* Nephalem ���캯�� */
	DomainParticipantFactoryImpl();
	/* Nephale �������� */
	~DomainParticipantFactoryImpl();

	/* Nephalem ����Ϊ�淶�ж���Ľӿ� */
	/* Nephalem ����DomainParticipant���� */
	DomainParticipantImpl* create_participant(_DOMAINID_T DomainId,
		const DomainParticipantQos& QoS,
		DomainParticipantListener* pDomainParticipantListener,
		StatusMask mask);

	/* Nephalem ɾ��������� */
	ReturnCode_t delete_participant(DomainParticipantImpl* &pDomainParticipant);

	/* Nephalem �淶�ж���Ϊ�������һ��DomainParticipant���˴������̰߳�ȫ���� */
	DomainParticipantImpl* lookup_participant(_DOMAINID_T DomainId);

	/* Nephalem ����Ĭ�ϵ�DomainParticipantQoS��������������ʧ�� */
	/* Nephalem ����create_participant�ӿ�Ҫ����DomainParticipantQos���˽ӿ�Ŀǰ����*/
	ReturnCode_t set_default_participant_qos(const DomainParticipantQos& QoS);

	/* Nephalem ��ȡDomainParticipantQoSĬ��ֵ,�˽ӿ�Ŀǰ���� */
	ReturnCode_t get_default_participant_qos(DomainParticipantQos& QoS);

	/* Nephalem ����Ĭ�ϵ�DomainParticipantFactoryQos��������������ʧ��,�˽ӿ�Ŀǰ���� */
	ReturnCode_t set_qos(const DomainParticipantFactoryQos& QoS);

	/* Nephalem ��ȡDomainParticipantFactoryQosĬ��ֵ���˽ӿ�Ŀǰ���� */
	ReturnCode_t get_qos(DomainParticipantFactoryQos& QoS);

private:
	/* Nephalem ���DomainParticipant��map��һ����Id��Ӧһ��list��list��Ŷ��DomainParticipant */
	_DOMAIN_PARTICIPANT_IMPL_MAP m_DomainParticipantImplMap;

	/* Nephalem �˳�Ա����Ŀǰδʹ�� */
	DomainParticipantFactoryQos m_DomainParticipantFactoryQos;
	/* Nephalem �˳�Ա����Ŀǰδʹ�� */
	DomainParticipantQos m_DomainParticipantQos;

	/* JD ���ڱ��� m_DomainParticipantImplMap �� Map�б���� List<DomainparticipantImpl> */
	uLinX_SemMutex	m_DomainParticipantImplMapMutex;
};