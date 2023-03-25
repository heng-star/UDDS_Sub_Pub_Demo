#ifndef  _XML_CONFIG_H
#define  _XML_CONFIG_H
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "QoSPolicy.h"
#include "TINYXML/tinyxml.h"
class DomainParticipantImpl;

/* 
	JDXCZ-为测试静态匹配读取Qos功能准备，具体的实现以jmj的实现为准 
读取配置文件 ，将配置文件信息保存下来 

*/

class DDSXmlConfig
{
public:
	DDSXmlConfig(DomainParticipantImpl* pDomainParticipant);

	~DDSXmlConfig();

public:
	/*jmj 加载配置文件*/
	bool LoadXml();

	/*jmj 释放配置文件指针*/
	ReturnCode_t freeXmlDocument();

	/*jmj 根据配置文件更新本地datawriter的qos*/
	ReturnCode_t updateDataWriterQos();

	/*jmj 根据配置文件更新本地datareader的qos*/
	ReturnCode_t updateDataReaderQos();

	/*jmj 根据配置文件更新本地publisher的qos*/
	ReturnCode_t updatePublisherQos();

	/*jmj 根据配置文件更新本地subscriber的qos*/
	ReturnCode_t updateSubscriberQos();

	/*jmj 根据配置文件更新本地participant的qos*/
	ReturnCode_t updateParticipantQos();

	/*jmj 根据配置文件更新本地topic的qos*/
	ReturnCode_t updateTopicQos();

	/*jmj durability的kindstring转enum*/
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
	/*jmj 配置文件获取*/
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
