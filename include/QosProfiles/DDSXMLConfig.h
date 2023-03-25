#ifndef  _XML_CONFIG_H
#define  _XML_CONFIG_H
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "QoSPolicy.h"
#include "TINYXML/tinyxml.h"
class DomainParticipantImpl;

/* 
	JDXCZ-Ϊ���Ծ�̬ƥ���ȡQos����׼���������ʵ����jmj��ʵ��Ϊ׼ 
��ȡ�����ļ� ���������ļ���Ϣ�������� 

*/

class DDSXmlConfig
{
public:
	DDSXmlConfig(DomainParticipantImpl* pDomainParticipant);

	~DDSXmlConfig();

public:
	/*jmj ���������ļ�*/
	bool LoadXml();

	/*jmj �ͷ������ļ�ָ��*/
	ReturnCode_t freeXmlDocument();

	/*jmj ���������ļ����±���datawriter��qos*/
	ReturnCode_t updateDataWriterQos();

	/*jmj ���������ļ����±���datareader��qos*/
	ReturnCode_t updateDataReaderQos();

	/*jmj ���������ļ����±���publisher��qos*/
	ReturnCode_t updatePublisherQos();

	/*jmj ���������ļ����±���subscriber��qos*/
	ReturnCode_t updateSubscriberQos();

	/*jmj ���������ļ����±���participant��qos*/
	ReturnCode_t updateParticipantQos();

	/*jmj ���������ļ����±���topic��qos*/
	ReturnCode_t updateTopicQos();

	/*jmj durability��kindstringתenum*/
	static DurabilityQosPolicyKind durabilityKindStringToEnum(string sKind);

	/*jmj */
	static int QosStringToInt(string sKind);

	/*jmj */
	static unsigned int QosStringToUint(string sKind);

	/*jmj*/
	static HistoryQosPolicyKind durabilityservice_historyKindStringToEnum(string sKind);

	/*jmj*/
	static LivelinessQosPolicyKind livelinessKindStringToEnum(string sKind);

	/*jmj reliability.kind*/
	static ReliabilityQosPolicyKind reliabilityKindStringToEnum(string sKind);

	/*jmj destination.kind*/
	static DestinationOrderQosPolicyKind destinationKindStringToEnum(string sKind);

	/*jmj history.kind*/
	static HistoryQosPolicyKind historyKindStringToEnum(string sKind);

	/*jmj ownership.kind*/
	static OwnershipQosPolicyKind ownershipKindStringToEnum(string sKind);

	/*jmj QosStringToBool*/
	static bool QosStringToBool(string sKind);

	/*jmj PresentationQos*/
	static PresentationQosPolicyAccessScopeKind presentationAccessStringToEnum(string sKind);

	/*jmj*/
	static ReturnCode_t GetDataWriterQosFromXml(TiXmlElement *datawriterqosElement, DataWriterQos &m_dwQosXml);

	static ReturnCode_t GetDataReaderQosFromXml(TiXmlElement *datareaderqosElement, DataReaderQos &m_drQosXml);

private:
	DomainParticipantImpl* m_pDomainParticipant;
	/*jmj �����ļ���ȡ*/
	TiXmlDocument *uDDSDocument;

	DataWriterQos m_dwQosXml;
	DataReaderQos m_drQosXml;
	SubscriberQos m_subQosXml;
	PublisherQos m_pubQosXml;
	TopicQos m_topicQosXml;
	DomainParticipantQos m_parQosXml;

	DataWriterQos m_dwQosXmldefault;
	DataReaderQos m_drQosXmldefault;
	SubscriberQos m_subQosXmldefault;
	PublisherQos m_pubQosXmldefault;
	TopicQos m_topicQosXmldefault;
	DomainParticipantQos m_parQosXmldefault;


	map<string, DataWriterQos> topic_dwqosMap;
	map<string, DataReaderQos> topic_drqosMap;
	map<string, SubscriberQos> topic_subqosMap;
	map<string, PublisherQos> topic_pubqosMap;
	map<string, TopicQos> topic_topicqosMap;
	map<string, DomainParticipantQos> topic_partqosMap;

	map<string, DataWriterQos> base_dwqosMap;
	map<string, DataReaderQos> base_drqosMap;
	map<string, SubscriberQos> base_subqosMap;
	map<string, PublisherQos> base_pubqosMap;
	map<string, TopicQos> base_topicqosMap;
	map<string, DomainParticipantQos> base_partqosMap;

};



#endif // ! _XML_CONFIG_H
