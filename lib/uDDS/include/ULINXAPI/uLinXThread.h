/************************************************************
** 文件名 uLinxThread.h
** 创建人：Nephalem<zg250610346@163.com>
** 日  期：2018-06-19
** 修改人：无
** 日  期：无
** 描  述：uLinxThread头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _APP_ULINX_THREAD_H_INCLUDED_
#define _APP_ULINX_THREAD_H_INCLUDED_

#include "uLinxDataType.h"

using namespace std;

class uLinXThread
{
public:
	//构造函数
	uLinXThread();
	//构造函数
	uLinXThread(string ThreadName);
	//析构函数
	~uLinXThread();
	//设置栈大小 用在创建线程前
	void SetStackSize(ULINX_INT32 StackSize);
	//创建线程
	void CreateThread(void* Thread, void * arglist, ULINX_INT32 Priority, string ThreadName = "");
	//获取对线程操作的对象
	ULINX_THREAD GetThreadID();
	//删除线程
    void DeleteThread(ULINX_THREAD Thread);

private:

	ULINX_THREAD m_ThreadID;            //不是真正意义上的线程ID，是指对线程进行操作的对象

	string m_ThreadName;                //线程名

	ULINX_INT32 m_StackSize;            //线程栈大小

	ULINX_UINT32 m_ThrdAddr;            //windows的线程ID地址	

	ULINX_INT32 m_ThreadPriority;       //线程优先级
};
#endif
