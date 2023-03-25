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
	ULINX_INT32	   m_uiNum;	/* ��ǰSubscriber�еڼ���Endpoint*/
	DataReaderQos  m_DataReaderQoS;
	string m_strTopicName;
	string m_strTopicType;
};
struct _StaticDataWriter_T {
	ULINX_INT32	   m_uiNum;	/* ��ǰSubscriber�еڼ���Endpoint*/
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

/* JDXCZ ���ڱ���͹���̬�ڵ���Ϣ  */
class DDS_DLL StaticDomainParticipant
{
public:
	StaticDomainParticipant(DomainParticipantImpl* pDomainParticipantImpl, _StaticParticipantInfo_T* pStaticParticipant) ;
	~StaticDomainParticipant();


	/*  ��̬��Ϣ���г�ʼ�� ������Ӧ�ķ����ߺͶ����ߣ����ݶ��ߣ�����д�� */
	int Init();

	/* ����Topic�ҵ���Ӧ��DataReader */
	DataReader* find_datareader(TopicDescription* pTopic);

	/* ����Topic�ҵ���Ӧ��DataWriter  */
	DataWriter* find_datawriter(TopicDescription* pTopic);

	/* �ҵ����صľ�̬�ڵ���Ϣ */
	_StaticParticipantInfo_T* GetLocalStaticparticipant();

	/* �ж�pTopic�Ƿ��Ǿ�̬�����ļ��е����� */
	bool IsStaticTopic(TopicDescription* pTopic);

	/* �ж�participant���������MD5ֵ�Ƿ񱻱��������ļ���ͬ ,true-����MD5ֵ��ͬ*/
	bool IsSameStaticParticipant(string strName,string strMD5);

	/* ���о�̬�ڵ���Ϣ��ƥ�� */
	int StaticMatch(Discovery* pDiscovery, _StaticParticipantInfo_T* pStaticParticipant, guidPrefix_t guidprefix);

	/* ����̬�����ļ���DataReaderתΪDiscoveredReaderData */
	int StaticDataReaderToDiscoverReaderData(_StaticDataReader_T* pDR, DiscoveredReaderData& discoveredReaderData);

	/* ����̬�����ļ���DataWriterתΪDiscoveredWriterData */
	int StaticDataWriterToDiscoverWriterData(_StaticDataWriter_T* pDW, DiscoveredWriterData& discoveredWriterData);

	/* ����̬�����ļ���DataReaderQosתΪDiscoveredReaderData */
	int DataReaderQosToDiscoverReaderData(DataReaderQos& pDRQos, DiscoveredReaderData& discoveredReaderData);

	/* ����̬�����ļ���DataWriterQosתΪDiscoveredWriterData */
	int DataWriterQosToDiscoverReaderData(DataWriterQos& pDRQos, DiscoveredWriterData& discoveredWriterData);

	/* ��ȡ�����ļ���DataWriteQoS */
	int ReadDataWriterQos(TiXmlElement* TiXmlElement, DataWriterQos& DWQos);

	/* ��ȡ�����ļ���DataReaderQoS*/
	int ReadDataReaderQos(TiXmlElement* TiXmlElement, DataReaderQos& DRQos);

	/* ��ȡparticipant��MD5ֵ�������Ϣ */
	int GetMD5Map(map<string, string>& MD5Map);
private:
	/* ���ؾ�̬�ڵ���Ϣ */
	_StaticParticipantInfo_T* m_pLocalStaticParticipant;

	/* ���ؾ�̬�ڵ������ */
	string m_strName;

	int  m_iDomainId;

	/* ��̬�ļ���Ӧ��DomainParticipant */
	DomainParticipantImpl* m_pDomainParticipantImpl;

	/* Ŀǰ�涨ֻ��һ��Publisher���û��ھ�̬ģʽ�£���Publisher��ָ�뷵�� */
	/* ��̬�ڵ㴴����Publisher  */
	Publisher* m_pPublisher;

	/*  ��̬�ڵ㴴����Subscriber */
	Subscriber* m_pSubscriber;

/* JD ��Ҫ�ͷŵ���Դ */
	/* �����ļ��Ĵ洢  */
	map<string, _StaticParticipantInfo_T*> m_StaticParitcipantInfoMap;

	/* �����ľ�̬DataReader */
	map<Topic*, DataReader*> m_DataReaderMap;

	/* �����ľ�̬DataWriter*/
	map<Topic*, DataWriter*> m_DataWriterMap;

	/* �洢����Topicָ�룬�����жϴ����������Ƿ��������ļ��� */
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
	/* ���ؽڵ������ */
	string m_strName;

	map<int, _StaticParticipantInfo_T*> m_StaticParticipantInfoMap;

};


/* JDXCZ �����ȡ�������ļ��е������Ϣ */
class StaticMatchManager 
{
private:
	map<string, StaticDomainParticipantFactory*> m_StataicDomainParticipantFactoryMap;
	
	/* �ж��Ƿ�ʹ�þ�̬ƥ�� */
	bool m_bUseStaticMatch;
	/* ��ǰ��̬ƥ��������ļ��汾 */
	string m_strVersion;
	/* ���ؽڵ������ */
	string m_strName;
	/* ��ž�̬�����ļ���ÿ��participant��MD5ֵ */
	map<string, string> m_MD5Map;

	StaticDomainParticipantFactory* m_pLocalStaticDomainParticipantFactory;

	/* ��ȡ��̬��Ϣ�Ĺ����� */
	static StaticMatchManager* m_pInstance;
public:
	StaticMatchManager();

	~StaticMatchManager();

	/* ��ȡ�����ļ���ÿ�� */
	int CalculateMD5(string strXmlPath);

	/* ���������ļ����������ļ���*/
	int Config(string strXmlPath);

	static StaticMatchManager* GetInstance();

	/* ����ָ�������ƣ��ҵ�ָ����̬�ڵ����Ϣ */
	_StaticParticipantInfo_T* GetStaticparticipantInfo(int Domainid,string name);

	/* ����ָ�������ƣ��ҵ�ָ����̬�ڵ����Ϣ */
	_StaticParticipantInfo_T* GetLocalStaticparticipantInfo(int Domainid);
};




#endif