#pragma once

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"

/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
class TopicDescription;
struct TopicQos;

class TopicDescriptionImpl
{
public:
	TopicDescriptionImpl(DomainParticipantImpl* pDomainParticipantImpl,string strTopicName, string strTypeName);

	virtual ~TopicDescriptionImpl();

public:
	/* Nephalem 以下为规范中定义的接口 */

	/* Nephale 获取相关的DomainParticipant*/
	DomainParticipantImpl* get_participant();

	/* Nephalem 获取类型名 */
	virtual string& get_type_name();

	/* Nephalem 获取主题名 */
	virtual string& get_name();

public:
	/* Nephalem 自定义接口*/

	/* Nepalem 设置对用户展示的TopicDescription */
	void setUserTopicDescription(TopicDescription* pTopicDescription);

	/* Nepalem 获取对用户展示的TopicDescription */
	TopicDescription* getUserTopicDescription();

	DataReaderImpl* getRelateDataReaderImpl();

	void setRelateDataReaderImpl(DataReaderImpl* pDataReaderImpl);

	/* Nephalem 获取TopicQos */
	virtual ReturnCode_t get_qos(TopicQos& QoS) = 0;

protected:
	//主题名
	string m_strName;
	//主题类型名
	string m_strTypeName;
	//指向主题所属的域参与者的指针
	DomainParticipantImpl* m_pDomainParticipantImpl;

	/* Nephalem 对用户展示的TopicDescription */
	TopicDescription* m_pUserTopicDescription;
	
	DataReaderImpl* pRelateDataReaderImpl;
};