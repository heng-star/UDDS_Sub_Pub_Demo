#pragma once
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"

#include "DDS/DomainParticipant.h"
#include "DDS/Listener/DomainParticipantListener.h"
#include "ULINXAPI/uLinXSemMutex.h"

class DomainParticipantFactoryImpl
{
public:
	/* Nephalem 构造函数 */
	DomainParticipantFactoryImpl();
	/* Nephale 析构函数 */
	~DomainParticipantFactoryImpl();

	/* Nephalem 以下为规范中定义的接口 */
	/* Nephalem 创建DomainParticipant对象 */
	DomainParticipantImpl* create_participant(_DOMAINID_T DomainId,
		const DomainParticipantQos& QoS,
		DomainParticipantListener* pDomainParticipantListener,
		StatusMask mask);

	/* Nephalem 删除域参与者 */
	ReturnCode_t delete_participant(DomainParticipantImpl* &pDomainParticipant);

	/* Nephalem 规范中定义为随机返回一个DomainParticipant，此处存在线程安全问题 */
	DomainParticipantImpl* lookup_participant(_DOMAINID_T DomainId);

	/* Nephalem 设置默认的DomainParticipantQoS，不兼容则设置失败 */
	/* Nephalem 由于create_participant接口要求传入DomainParticipantQos，此接口目前无用*/
	ReturnCode_t set_default_participant_qos(const DomainParticipantQos& QoS);

	/* Nephalem 获取DomainParticipantQoS默认值,此接口目前无用 */
	ReturnCode_t get_default_participant_qos(DomainParticipantQos& QoS);

	/* Nephalem 设置默认的DomainParticipantFactoryQos，不兼容则设置失败,此接口目前无用 */
	ReturnCode_t set_qos(const DomainParticipantFactoryQos& QoS);

	/* Nephalem 获取DomainParticipantFactoryQos默认值，此接口目前无用 */
	ReturnCode_t get_qos(DomainParticipantFactoryQos& QoS);

private:
	/* Nephalem 存放DomainParticipant的map，一个域Id对应一个list，list存放多个DomainParticipant */
	_DOMAIN_PARTICIPANT_IMPL_MAP m_DomainParticipantImplMap;

	/* Nephalem 此成员变量目前未使用 */
	DomainParticipantFactoryQos m_DomainParticipantFactoryQos;
	/* Nephalem 此成员变量目前未使用 */
	DomainParticipantQos m_DomainParticipantQos;

	/* JD 用于保护 m_DomainParticipantImplMap 和 Map中保存的 List<DomainparticipantImpl> */
	uLinX_SemMutex	m_DomainParticipantImplMapMutex;
};