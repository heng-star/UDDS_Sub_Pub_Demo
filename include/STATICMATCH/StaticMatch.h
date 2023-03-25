#ifndef _STATIC_MATCH_H
#define _STATIC_MATCH_H

#include "BasicTypes.h"
#include "QoSPolicy.h"
#include "RTPSBasicTypes.h"

//class DomainParticipant;

class Discovery;
class TiXmlElement;

void DataReaderQosShow(const DataReaderQos& pQos);
void DataWriterQosShow(const DataWriterQos& pQos);
struct _StaticDataReader_T {
	ULINX_INT32	   m_uiNum;	/* 当前Subscriber中第几个Endpoint*/
	DataReaderQos  m_DataReaderQoS;
	string m_strTopicName;
	string m_strTopicType;
};
struct _StaticDataWriter_T {
	ULINX_INT32	   m_uiNum;	/* 当前Subscriber中第几个Endpoint*/
	DataWriterQos  m_DataWriterQoS;
	string m_strTopicName;
	string m_strTopicType;
};
struct _StaticParticipantInfo_T
{
	int		m_iDomainId;
	unsigned int m_uiReaderEntityKey;
	unsigned int m_uiWriterEntityKey;
	string	m_strName;
	string	m_MD5;
	vector<_StaticDataReader_T*> m_pStaticDataReaderVec;
	vector<_StaticDataWriter_T*> m_pStaticDataWriterVec;
	_StaticParticipantInfo_T(int DomainId)
	{
		m_iDomainId = DomainId;
		m_uiWriterEntityKey = (m_iDomainId << 3 * 8) + (0x04 << 2 * 8);
		m_uiReaderEntityKey = (m_iDomainId << 3 * 8) + (0x09 << 2 * 8);

		m_strName = "";
	}
	~_StaticParticipantInfo_T()
	{
		for (int i = 0; i < m_pStaticDataReaderVec.size(); i++)
		{
			delete m_pStaticDataReaderVec[i];
			m_pStaticDataReaderVec[i] = NULL;
		}
		for (int i = 0; i < m_pStaticDataWriterVec.size(); i++)
		{
			delete m_pStaticDataWriterVec[i];
			m_pStaticDataWriterVec[i] = NULL;
		}
		m_pStaticDataReaderVec.clear();
		m_pStaticDataWriterVec.clear();

	}

};

/* JDXCZ 用于保存和管理静态节点信息  */
class DDS_DLL StaticDomainParticipant
{
public:
	StaticDomainParticipant(DomainParticipantImpl* pDomainParticipantImpl, _StaticParticipantInfo_T* pStaticParticipant) ;
	~StaticDomainParticipant();


	/*  静态信息进行初始化 创建对应的发布者和订阅者，数据读者，数据写着 */
	int Init();

	/* 根据Topic找到对应的DataReader */
	DataReader* find_datareader(TopicDescription* pTopic);

	/* 根据Topic找到对应的DataWriter  */
	DataWriter* find_datawriter(TopicDescription* pTopic);

	/* 找到本地的静态节点信息 */
	_StaticParticipantInfo_T* GetLocalStaticparticipant();

	/* 判断pTopic是否是静态配置文件中的主题 */
	bool IsStaticTopic(TopicDescription* pTopic);

	/* 判断participant的组件名和MD5值是否被本地配置文件相同 ,true-在且MD5值相同*/
	bool IsSameStaticParticipant(string strName,string strMD5);

	/* 进行静态节点信息的匹配 */
	int StaticMatch(Discovery* pDiscovery, _StaticParticipantInfo_T* pStaticParticipant, guidPrefix_t guidprefix);

	/* 将静态配置文件中DataReader转为DiscoveredReaderData */
	int StaticDataReaderToDiscoverReaderData(_StaticDataReader_T* pDR, DiscoveredReaderData& discoveredReaderData);

	/* 将静态配置文件中DataWriter转为DiscoveredWriterData */
	int StaticDataWriterToDiscoverWriterData(_StaticDataWriter_T* pDW, DiscoveredWriterData& discoveredWriterData);

	/* 将静态配置文件中DataReaderQos转为DiscoveredReaderData */
	int DataReaderQosToDiscoverReaderData(DataReaderQos& pDRQos, DiscoveredReaderData& discoveredReaderData);

	/* 将静态配置文件中DataWriterQos转为DiscoveredWriterData */
	int DataWriterQosToDiscoverReaderData(DataWriterQos& pDRQos, DiscoveredWriterData& discoveredWriterData);

	/* 读取配置文件中DataWriteQoS */
	int ReadDataWriterQos(TiXmlElement* TiXmlElement, DataWriterQos& DWQos);

	/* 读取配置文件中DataReaderQoS*/
	int ReadDataReaderQos(TiXmlElement* TiXmlElement, DataReaderQos& DRQos);

	/* 获取participant的MD5值的相关信息 */
	int GetMD5Map(map<string, string>& MD5Map);
private:
	/* 本地静态节点信息 */
	_StaticParticipantInfo_T* m_pLocalStaticParticipant;

	/* 本地静态节点的名称 */
	string m_strName;

	int  m_iDomainId;

	/* 静态文件对应的DomainParticipant */
	DomainParticipantImpl* m_pDomainParticipantImpl;

	/* 目前规定只有一个Publisher，用户在静态模式下，将Publisher的指针返回 */
	/* 静态节点创建的Publisher  */
	Publisher* m_pPublisher;

	/*  静态节点创建的Subscriber */
	Subscriber* m_pSubscriber;

/* JD 需要释放的资源 */
	/* 配置文件的存储  */
	map<string, _StaticParticipantInfo_T*> m_StaticParitcipantInfoMap;

	/* 创建的静态DataReader */
	map<Topic*, DataReader*> m_DataReaderMap;

	/* 创建的静态DataWriter*/
	map<Topic*, DataWriter*> m_DataWriterMap;

	/* 存储创建Topic指针，用于判断创建的主题是否在配置文件中 */
	set<Topic*> m_TopicSet;
};
class StaticDomainParticipantFactory
{
public:
	StaticDomainParticipantFactory(string strName);
	~StaticDomainParticipantFactory();
	int InsertStaticParticipantInfo(int DomainID,_StaticParticipantInfo_T* pStaticParticipantInfo);
	_StaticParticipantInfo_T* GetStaticParticipantInfo(int DomainID);

	void show();
private:
	/* 本地节点的名称 */
	string m_strName;

	map<int, _StaticParticipantInfo_T*> m_StaticParticipantInfoMap;

};


/* JDXCZ 管理读取到配置文件中的相关信息 */
class StaticMatchManager 
{
private:
	map<string, StaticDomainParticipantFactory*> m_StataicDomainParticipantFactoryMap;
	
	/* 判断是否使用静态匹配 */
	bool m_bUseStaticMatch;
	/* 当前静态匹配的配置文件版本 */
	string m_strVersion;
	/* 本地节点的名称 */
	string m_strName;
	/* 存放静态配置文件中每个participant的MD5值 */
	map<string, string> m_MD5Map;

	StaticDomainParticipantFactory* m_pLocalStaticDomainParticipantFactory;

	/* 读取静态信息的管理类 */
	static StaticMatchManager* m_pInstance;
public:
	StaticMatchManager();

	~StaticMatchManager();

	/* 获取配置文件中每个 */
	int CalculateMD5(string strXmlPath);

	/* 加载配置文件，将配置文件中*/
	int Config(string strXmlPath);

	static StaticMatchManager* GetInstance();

	/* 根据指定的名称，找到指定静态节点的信息 */
	_StaticParticipantInfo_T* GetStaticparticipantInfo(int Domainid,string name);

	/* 根据指定的名称，找到指定静态节点的信息 */
	_StaticParticipantInfo_T* GetLocalStaticparticipantInfo(int Domainid);
};




#endif