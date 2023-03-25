/************************************************************
** �ļ��� uLinxThread.h
** �����ˣ�Nephalem<zg250610346@163.com>
** ��  �ڣ�2018-06-19
** �޸��ˣ���
** ��  �ڣ���
** ��  ����uLinxThreadͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _APP_ULINX_THREAD_H_INCLUDED_
#define _APP_ULINX_THREAD_H_INCLUDED_

#include "uLinxDataType.h"

using namespace std;

class uLinXThread
{
public:
	//���캯��
	uLinXThread();
	//���캯��
	uLinXThread(string ThreadName);
	//��������
	~uLinXThread();
	//����ջ��С ���ڴ����߳�ǰ
	void SetStackSize(ULINX_INT32 StackSize);
	//�����߳�
	void CreateThread(void* Thread, void * arglist, ULINX_INT32 Priority, string ThreadName = "");
	//��ȡ���̲߳����Ķ���
	ULINX_THREAD GetThreadID();
	//ɾ���߳�
    void DeleteThread(ULINX_THREAD Thread);

private:

	ULINX_THREAD m_ThreadID;            //�������������ϵ��߳�ID����ָ���߳̽��в����Ķ���

	string m_ThreadName;                //�߳���

	ULINX_INT32 m_StackSize;            //�߳�ջ��С

	ULINX_UINT32 m_ThrdAddr;            //windows���߳�ID��ַ	

	ULINX_INT32 m_ThreadPriority;       //�߳����ȼ�
};
#endif
