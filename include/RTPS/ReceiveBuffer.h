/************************************************************
** �ļ�����ReceiveBuffer.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-16
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ReceiveBufferͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_RECEIVEBUFFER_H_INCLUDED_
#define _RTPS_RECEIVEBUFFER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "ULINXAPI/uLinXSemMutex.h"

class ReceiveBuffer 
{
public:
    //���캯��
    ReceiveBuffer(unsigned int ulLength);

    //��������
    virtual ~ReceiveBuffer();

    //��
    ReturnCode_t Read(char *pMessage, unsigned int& uiLength);

    //д
    ReturnCode_t Write(char *pMessage, unsigned int uiLength);

	//����ָ��ָ������ֶ�֮��
    ReturnCode_t FindPad();

	ReturnCode_t SetDDSInfo(int iDomainCount);

	int	GetDDSInfo();

private:
    //��������С
    unsigned int m_uiLength;

    //��ָ��λ��
    unsigned int m_uiReadPosition;

    //дָ��λ��
    unsigned int m_uiWritePosition;

    //������ һ��ѭ���Ŀռ�
    char *m_pBuffer;

	//���п�д�ռ�
	unsigned int m_uiAvailableLength;

	/* Nephalem ������������ */
	uLinX_SemMutex*  m_bufferMutex;

	/* Nephalem �ź������ж��Ƿ��л��������� */
	uLinX_SemAphore* m_bufferAphore;

	int m_iDomainCount;

};

#endif
