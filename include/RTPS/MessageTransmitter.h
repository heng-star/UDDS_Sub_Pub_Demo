/************************************************************
** �ļ�����MessageTransmitter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-16
** �޸��ˣ���
** ��  �ڣ���
** ��  ����MessageTransmitterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_MESSAGETRANSMITTER_H_INCLUDED_
#define _RTPS_MESSAGETRANSMITTER_H_INCLUDED_

#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"

/**
* @ brief ������ջ�������С �ֽ�
*/
#define RECEIVE_BUFFER_SIZE 1024 * 1024 * 50

//����
class ReceiveBuffer;

class MessageTransmitter 
{
public:
    //���캯��
    MessageTransmitter(ReceiveBuffer *pReceiveBuffer) 
    {
        m_pReceiveBuffer = pReceiveBuffer;

		m_bRunFlag = true;

		m_bStopFlag = false;
    }

    //��������
    virtual ~MessageTransmitter() 
    {
        m_Locator.clear();
    };

	virtual ReturnCode_t SendAddrAdd(Locator_t SendAddr) = 0;

    //���� �麯���ṩ�ӿ�
    virtual ReturnCode_t MessageSend(
        Locator_t Source,
        Locator_t Destination,
        char *pMessage,
        unsigned int uiLength) = 0;

	virtual ReturnCode_t MessageSend(
		_LOCATOR_LIST_T& SourceList,
		_LOCATOR_LIST_T& DestinationList,
		char* pMessage,
		unsigned int uiLength
	) = 0;

    //�ಥ���� �麯���ṩ�ӿ�
    virtual ReturnCode_t SendMultiMessage(
        Locator_t Source,
        Locator_t Destination,
        char *pMessage,
        unsigned int uiLength) = 0;

    //���� �麯���ṩ�ӿ�
    virtual ReturnCode_t ReceiveMessage() = 0;

    //��Ӽ�����ַ
    virtual ReturnCode_t ReceiveAddrAdd(Locator_t ReceiveAddr) = 0;

    //��Ӽ����ಥ��ַ
    //virtual ReturnCode_t ReceiveMultiAddrAdd(Locator_t sourceAddr, Locator_t ReceiveAddr) = 0;

    //ɾ��������ַ
    virtual ReturnCode_t ReceiveAddrRemove(Locator_t ReceiveAddr) = 0;

    //��ʼ�����߳�/����
    static DWORD WINAPI TransmitRun(void* lpMessageTransmitter);

	bool  isRun();

	void setRunFlag(bool flag);

	bool isStop();

	void setStopFlag();

private:
	bool m_bRunFlag;

	bool m_bStopFlag;
protected:
    //���ջ�����
    ReceiveBuffer *m_pReceiveBuffer;

    //������ַ�б�
    _LOCATOR_LIST_T m_Locator;

};

#endif
