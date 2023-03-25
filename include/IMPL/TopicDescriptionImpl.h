#pragma once

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"

/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class TopicDescription;
struct TopicQos;

class TopicDescriptionImpl
{
public:
	TopicDescriptionImpl(DomainParticipantImpl* pDomainParticipantImpl,string strTopicName, string strTypeName);

	virtual ~TopicDescriptionImpl();

public:
	/* Nephalem ����Ϊ�淶�ж���Ľӿ� */

	/* Nephale ��ȡ��ص�DomainParticipant*/
	DomainParticipantImpl* get_participant();

	/* Nephalem ��ȡ������ */
	virtual string& get_type_name();

	/* Nephalem ��ȡ������ */
	virtual string& get_name();

public:
	/* Nephalem �Զ���ӿ�*/

	/* Nepalem ���ö��û�չʾ��TopicDescription */
	void setUserTopicDescription(TopicDescription* pTopicDescription);

	/* Nepalem ��ȡ���û�չʾ��TopicDescription */
	TopicDescription* getUserTopicDescription();

	DataReaderImpl* getRelateDataReaderImpl();

	void setRelateDataReaderImpl(DataReaderImpl* pDataReaderImpl);

	/* Nephalem ��ȡTopicQos */
	virtual ReturnCode_t get_qos(TopicQos& QoS) = 0;

protected:
	//������
	string m_strName;
	//����������
	string m_strTypeName;
	//ָ������������������ߵ�ָ��
	DomainParticipantImpl* m_pDomainParticipantImpl;

	/* Nephalem ���û�չʾ��TopicDescription */
	TopicDescription* m_pUserTopicDescription;
	
	DataReaderImpl* pRelateDataReaderImpl;
};