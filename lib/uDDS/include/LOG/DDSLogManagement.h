#ifndef _DDS_LOG_H
#define _DDS_LOG_H
#include <set>
using namespace std;

#include "BasicTypes.h"
#include "uLinxDataType.h"
#include "ULINXAPI/uLinXSemMutex.h"
#include "ULINXAPI/uLinXThread.h"
#define WM_MATCH_LOG			0x1040
#define WM_DOMAINRELEASE_LOG	0x1050
#define WM_RECV_LOG				0x1060
#define WM_WRITE_LOG			0x1070
#define WM_ERROR_LOG			0x1080
#define WM_INFO_LOG				0x1090
#define WM_NEWLINE				0x0002		/* JD ���� */
#define WM_BINARY				0x0001		/* JD ������ */
typedef GUID_t _GUID_T;
typedef struct  DDSLog_DATA_INFO
{
	char* m_pData;
	string m_strTime;
	int m_iLen;
	unsigned int m_iMode;
	_GUID_T m_Guid;
	DDSLog_DATA_INFO()
	{
		m_pData = NULL;
		m_strTime = "";
	}
	~DDSLog_DATA_INFO()
	{
		m_strTime = "";
		if (NULL != m_pData)
		{
			delete m_pData;
			m_pData = NULL;
		}
	}
}_DDSLOG_DATA_INFO_T;

typedef set<string> STRING_VEC;

class  DDSLogManagement
{
public:
	/* ���캯�� */
	DDSLogManagement();

	//DDSLogManagement(const char* pFilePath,const char* pCompName);

	DDSLogManagement(const _DOMAINID_T& uiDomainId, const unsigned int& uiFileSize, const unsigned int& uiTotalSize,
		const char* pCompName, const char* pFilePath);

	/* ����DDSLogManagement�ĸ��ֲ��� */
	int SetDDSLogManagement(const _DOMAINID_T uiDomainId, const unsigned int uiFileSize, const unsigned int uiTotalSize,
		const char* pCompName, const char* pFilePath);
	int SetUseDDSLogFlag(bool bUseDDSLog);
	//DDSLogManagement(){};
	~DDSLogManagement();

	/* ������־�ļ��ӿڣ���־�ļ�*/
	int WriteDDSLog(char* pData, const int len, const int Mod, _GUID_T Guid = GUID_UNKNOWN, int iDomainCount = 0);

	int GetDDSLogDataVec(vector<_DDSLOG_DATA_INFO_T*>& DDSLogDataVec);

protected:
private:
	/* ������Ϣ���� */
#ifdef ULINX_WIN
	static DWORD WINAPI DDSLogProcessRun(LPVOID pDDSLogManagement);
	/* �߳̾�� */
	HANDLE m_HTask;

	/* �߳�ID */
	DWORD	m_HTaskID;
#elif defined ULINX_LINUX
	static void* DDSLogProcessRun(void* pDDSLogManagement);
	pthread_t m_HTaskID;
#elif defined ULINX_VX
#endif
	/* д����־�ļ� */
	int WriteToLogFile(const string& strLogInfo, int len, unsigned int Mod);

	/* �������� ����Vec�����ݷ��� string�� */
	int ProcessData();

	/* ������־��¼�߳� */
	void	StartDDSLogTask();

	/* �ر���־�߳� */
	void	StopDDSLogTask();

	/*  ��ȡϵͳʱ�� */
	int GetSysTime(string& strTime);

	/* �@ȡ�ļ���С��*/
	long getFileSize(FILE* log);

	int WriteFile(int Mod);
private:
	/* ��Ҫ��¼��־���ݵ��ܴ�С */
	unsigned int m_uiStrTotalLen;

	/* ��־�ļ��ܴ�С */
	unsigned int m_uiTotalSize;

	/* ������־�ļ���С */
	unsigned int m_uiFileSize;

	/* �����ļ��Ĵ�С */
	unsigned int m_uiLogFileNum;

	/* ��¼�ĸ��� */
	unsigned int m_uiMsgCount;

	/* ��־�ļ�·�� */
	string m_strFilePath;

	/* Ӧ�õ����� / ����� */
	string m_strCompName;

	/* ��־�ļ�����¼�������� */
	unsigned int m_uiDomainID;

	/* �Ƿ�ֵ¼��־�ı�־λ Ĭ��λfalse */
	bool	m_bUseDDSLog;

	/* �߳̿�ʼ�˳���ʶ */
	bool	m_bBeginQuit;

	/* �߳�����˳���ʶ */
	bool    m_bEndQuit;

	/* �ж��Ƿ񵽼�¼ʱ��*/
	bool	m_bWriteFile;

	/* �ϴμ�¼��־��ʱ�� */
	DWORD m_CurrentTick;

	/* ���MatchLog����Ϣ */
	string m_strMatchLog;

	/* ���RecvLog����Ϣ */
	string m_strRecvLog;

	/* ���WriteLog����Ϣ */
	string m_strWriteLog;

	/* ���InfoLog����Ϣ */
	string m_strInfoLog;

	/* ���ErrorLog����Ϣ */
	string m_strErrorLog;

	/* ���DomainRelease ����Ϣ */
	string m_strDomainReleaseLog;
	
	///* Topic ��Ϣ��¼��־λ */
	/* ������־��¼����� */
	uLinX_SemMutex m_SeqMutex;
	/* ����д��־������ */
	uLinX_SemMutex m_MsgMutex;
	/* �߳� */
	uLinXThread m_Thread;

	vector<_DDSLOG_DATA_INFO_T*>  m_DDSLogDataVec;


}; // class DDSLogManagement

class DDS_DLL DDSLogManagementFactory {
public:
	DDSLogManagementFactory();
	~DDSLogManagementFactory();
	static DDSLogManagementFactory* GetInstance();
	static int EntityToString(EntityId_t EntityId, string& strEntity);
	static int GuidPrefixToString(guidPrefix_t,string& strGuidPrefix);
	/* ������������ص���־������� */
	DDSLogManagement* CreateDDSManagement(int iDomainCount);

	/* ɾ����������ص���־������� */
	int RemoveDDSManagement(int iDomainCount);

	bool GetUseDDSLogFlag(int iDomainCount);
	/* �ж��Ƿ��¼Topic true��ʾ��¼*/
	bool IsWriteTopic(int iDomainCount, const string& TopicName);
	/* */
	bool IsReadTopic(int iDomainCount, const string& TopicName);
	/* */
	bool IsWriteALLTopic(int iDomainCount, const string& TopicName);
	/* */
	bool IsReadALLTopic(int iDomainCount, const string& TopicName);
	/* */
	bool IsQueryTopic(int iDomainCount, const string& TopicName);

	static int WriteDDSLog(int iDomainCount, char* pData, const size_t len, const int Mod, _GUID_T Guid = GUID_UNKNOWN);
private:
	/* ��ȡ��������ص���־������� */
	/* JD ��ֹ�����ط����� DDSLogManagement����ĳ�Ա û�н����пյĲ�������߸�Ϊ˽�� */
	DDSLogManagement* GetDDSManagement(int iDomainCount);

	static DDSLogManagementFactory* m_pInstance;

	map<_DOMAINID_T, DDSLogManagement*> m_DDSLogManagementMap;

	DDSLogManagement* m_pDDSLogManagement;

	/* ��Ҫ����־��¼������ */
	set<int> m_DomainIdVec;
	/* ��־�ļ���Ŀ¼ */
	string	m_strFilePath;
	string  m_strCompName;

	bool	m_bUseDDSLog;
	/* Topic ��Ϣ��¼��־λ */
	bool	m_bWriteFlag;
	bool	m_bWriteALLFlag;
	bool	m_bReadFlag;
	bool	m_bReadALLFlag;
	bool	m_bQueryALLFlag;
	/* �ж��Ƿ��¼���͵������ϵ����� */
	bool	m_bSocketFlag;

	int		m_iFileSize;
	int		m_iTotalSize;

	/* ���WriteTopic��Vec */
	STRING_VEC m_WriteTopicVec;

	/* ���WriteTopic��Vec */
	STRING_VEC m_ReadTopicVec;

	/* ���WriteTopic��Vec */
	STRING_VEC m_WriteALLTopicVec;

	/* ���WriteTopic��Vec */
	STRING_VEC m_ReadTALLopicVec;

	/* ���QueryTopic��Vec */
	STRING_VEC m_QueryTopicVec;
private:
	/* ��ȡ��־�������ļ������ļ� */
	int LogConfig();
	/* ��ȡ������ */
	int GetProcessName(string& ProcessName);
	/* ��ȡ����Id */
	unsigned long DDSGetProcessId();

	uLinX_SemMutex m_DDSLogManagementMutex;
};


#endif //_DDS_LOG_H
