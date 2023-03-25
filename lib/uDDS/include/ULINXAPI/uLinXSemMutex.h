/************************************************************
** 文件名：SemMutex.h
** 创建人：Nephalem<635584332@qq.com>
** 日  期：2018-06-13
** 修改人：无
** 日  期：无
** 描  述：SemMutex头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _APP_SEMMUTEX_H_INCLUDED_
#define _APP_SEMMUTEX_H_INCLUDED_

#include "uLinxDataType.h"

class uLinX_SemMutex
{
private:

    string MutexName;            //	互斥锁名，如果添加了互斥锁名，则为进程间互斥锁
//xiugai
    ULINX_MUTEX m_hSemMutex;     //	互斥锁对象

public:

    //互斥锁构造函数
    uLinX_SemMutex();

    //进程间互斥锁构造函数
    uLinX_SemMutex(const ULINX_INT8* Name);

    //互斥锁析构函数
    ~uLinX_SemMutex();

    //加锁
    ULINX_INT32 SemMutex_Lock();
    //加锁最长等待时间
    ULINX_INT32 SemMutex_Lock(ULINX_UINT32 MilliSeconds);
    //解锁
    ULINX_INT32 SemMutex_Unlock();
};


class uLinX_SemAphore
{
private:

    string SemAphoreName;            //	互斥锁名，如果添加了互斥锁名，则为进程间互斥锁

    ULINX_APHORE m_SemAphore;

public:
    //信号量构造函数
    uLinX_SemAphore();

    //信号量构造函数
    uLinX_SemAphore(ULINX_UINT32 InitCout, ULINX_UINT32 MaxCout);

    //进程间信号量构造函数
    uLinX_SemAphore(ULINX_UINT32 InitCout, ULINX_UINT32 MaxCout,const ULINX_INT8 *Name);

    //信号量析构函数
    ~uLinX_SemAphore();

    //获取信号量
    ULINX_INT32 SemAphore_Wait();

    //获取信号量
    ULINX_INT32 SemAphore_Wait(ULINX_UINT32 MilliSeconds);

    //释放信号量
    ULINX_INT32 SemAphore_Release();

    ULINX_INT32 SemAphore_Release(ULINX_INT32 ReleaseCount);
};
#endif
