/************************************************************
** �ļ�����SemMutex.h
** �����ˣ�Nephalem<635584332@qq.com>
** ��  �ڣ�2018-06-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����SemMutexͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _APP_SEMMUTEX_H_INCLUDED_
#define _APP_SEMMUTEX_H_INCLUDED_

#include "uLinxDataType.h"

class uLinX_SemMutex
{
private:

    string MutexName;            //	�����������������˻�����������Ϊ���̼以����
//xiugai
    ULINX_MUTEX m_hSemMutex;     //	����������

public:

    //���������캯��
    uLinX_SemMutex();

    //���̼以�������캯��
    uLinX_SemMutex(const ULINX_INT8* Name);

    //��������������
    ~uLinX_SemMutex();

    //����
    ULINX_INT32 SemMutex_Lock();
    //������ȴ�ʱ��
    ULINX_INT32 SemMutex_Lock(ULINX_UINT32 MilliSeconds);
    //����
    ULINX_INT32 SemMutex_Unlock();
};


class uLinX_SemAphore
{
private:

    string SemAphoreName;            //	�����������������˻�����������Ϊ���̼以����

    ULINX_APHORE m_SemAphore;

public:
    //�ź������캯��
    uLinX_SemAphore();

    //�ź������캯��
    uLinX_SemAphore(ULINX_UINT32 InitCout, ULINX_UINT32 MaxCout);

    //���̼��ź������캯��
    uLinX_SemAphore(ULINX_UINT32 InitCout, ULINX_UINT32 MaxCout,const ULINX_INT8 *Name);

    //�ź�����������
    ~uLinX_SemAphore();

    //��ȡ�ź���
    ULINX_INT32 SemAphore_Wait();

    //��ȡ�ź���
    ULINX_INT32 SemAphore_Wait(ULINX_UINT32 MilliSeconds);

    //�ͷ��ź���
    ULINX_INT32 SemAphore_Release();

    ULINX_INT32 SemAphore_Release(ULINX_INT32 ReleaseCount);
};
#endif
