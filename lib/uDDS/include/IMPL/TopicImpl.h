#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "IMPL/TopicDescriptionImpl.h"
#include "IMPL/DomainEntity.h"
#include "QoSPolicy.h"

/* Nephalem 系统头文件 */
#include <string>
using std::string;

/* Nephalem 前置声明 */
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

	/* Nephalem 设置监听器 */
	ReturnCode_t set_listener(TopicListener* pTopicListener, StatusMask mask);

	/* Nephalem 获取设置的监听器 */
	TopicListener* get_listener();

	/* Nephalem 设置默认的TopicQos，不兼容则设置失败 */
	ReturnCode_t set_qos(const TopicQos& QoS);

	/* Nephalem 获取TopicQos默认值 */
	ReturnCode_t get_qos(TopicQos& QoS);

private:
	/* Nephalem 主题QoS */
	TopicQos m_QoS;

	/* Nephalem 主题监听器 */
	TopicListener* m_pTopicListener;
	
};

