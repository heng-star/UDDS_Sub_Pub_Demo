/************************************************************
** �ļ�����MessageProcessor.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����MessageProcessorͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_MESSAGEPROCESSOR_H_INCLUDED_
#define _RTPS_MESSAGEPROCESSOR_H_INCLUDED_

#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

//����
class Participant;
class MessageTransmitter;
class ReceiveBuffer;
class Endpoint;

class MessageProcessor 
{
public:
    //���캯��
    MessageProcessor(
        Participant *pParticipant,
        ReceiveBuffer *pBuffer);

    //��������
    virtual ~MessageProcessor();

	/* Nephalem ���ݷ�װ�Ƕ��̵߳ĵ� ���Է�װǰ����Ҫʹ�û��������б��� */
	void startEncapsulateMessage();

	void endEncapsulateMessage();

    char *EncapsulateMessage(char *pMessage, unsigned long *ulLength,GUID_t DstGuid);

	/* Nephalem ��װRTPS����ͷ */
	char* EncapsulateMessageHeader(unsigned int& uiShift);

	/* Nephalem ��װINFO_TS�ӱ��� */
	char* EncapsulateINFOTSMessage(unsigned int& uiShift,const _TIME_STAMP & TimeStamp);

	/* Nephalem ��װINFO_DST�ӱ��� */
	char* EncapsulateINFODSTMessage(unsigned int& uiShift, GUID_t DstGuid);

	/* Nephalem ��װDATA�ӱ��� */
	char* EncapsulateDATAMessage(unsigned int& uiShift,char* pUserData,unsigned int uiUserDataLen, const SequenceNumber_t& SeqNum,_PARAMETER_LIST& InlineQos, Endpoint *m_pEndpoint);

	/* Nephalem ��װDATA_FRAG�ӱ��� */
	char* EncapsulateDATAFragMessage(unsigned int& uiShift, char* pUserDataFrag, unsigned int uiUserDataFragLen, unsigned int uiDataFragNum,unsigned int uiUserDataLen, const SequenceNumber_t& SeqNum, _PARAMETER_LIST& InlineQos, Endpoint *m_pEndpoint);

	/* Nephalem �޸�DATA�е�ReaderID */
	char* modifyDataReaderId(EntityId_t readerEntityId);

	/* Nephalem �޸ı�����InfoDst�е�guidprefix�ֶ� */
	char* modifyInFoDstGuidPrefix(guidPrefix_t guidPrefix);

	/* Nephalem ��װHeartBeat�ӱ��� */
	char* EncapsulateHeartBeatMessage(unsigned int& uiShift, EntityId_t writerEntityId,SequenceNumber_t& firstSeq, SequenceNumber_t& lastSeq, unsigned int Count = 1);

	/* Nephalem �޸�HeartBeat�е�ReaderID */
	char* modifyHeartBeatReaderId(EntityId_t readerEntityId);

	/* Nephalem ��װAckNack�ӱ��� */
	char* EncapsulateAckNackMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, _SEQUENCE_NUMBER_SET& seqNumSet);

	/* Nephalem ��װNackFrag�ӱ��� */
	char* EncapsulateNackFragMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, SequenceNumber_t& writerSN, _FRAGMENT_NUMBER_SET& FragmentNumSet);

	/* Nephalem ��װGap�ӱ��� */
	char* EncapsulateGapMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, SequenceNumber_t& stGapStar, _SEQUENCE_NUMBER_SET& stGapList);

	char* getEncapsulateMessage();
	/* Nephalem �����߳� */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static DWORD WINAPI ProcessRun(void* pMessageProcessor);
#elif defined ULINX_LINUX || defined ULINX_VXWORKS
    static long ProcessRun(MessageProcessor* pMessageProcessor);
#endif
	/* Nephalem ��ʼ����RTPS���� */
    ReturnCode_t InterpretMessage(char* pMessage);


    Participant *GetParticipant() 
    {
        return m_pRelatedParticipant;
    }

	bool  isRun();

	void setRunFlag(bool flag);

	bool isStop();

	void setStopFlag();

private:
	bool m_bRunFlag;

	bool m_bStopFlag;

private:
    //��������ͷ
    ReturnCode_t InterpretMessageHeader(char*& pMessage,_RECEIVER& MessageReceiver);

    //�����ӱ���
    ReturnCode_t InterpretSubmessage(char*& pMessage, _RECEIVER& MessageReceiver);

    //����Data�ӱ���
    ReturnCode_t InterpretDataMessage(char* pMessage,_SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//����Heartbeat�ӱ���
   ReturnCode_t InterpretHeartbeatMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

    //����AckNack�ӱ���
   ReturnCode_t InterpretAckNackMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//����DataFrag�ӱ���
	ReturnCode_t InterpretDataFragMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//����INFO_TS�ӱ���
	ReturnCode_t InterpretINFOTSMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//����INFO_DST�ӱ���
	ReturnCode_t InterpretINFODSTMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	/* ����InlineQos �˴�����ָ��Ϊ������ */
	ReturnCode_t InterpretInlineQosMessage(char* &pMessage, _PARAMETER_LIST& inlineQos);

	//����NackFrag�ӱ���
    ReturnCode_t InterpretNackFragMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//����GAP�ӱ���
	ReturnCode_t InterpretGapMessage(char* pMessage, _SUBMESSAGE_HEADER& pSubmessageHeader, _RECEIVER& MessageReceiver);


	/* Nephalem ����������Ϊ2�� */
	ReturnCode_t DoubleEncapsulateMessageSize();
private:
    //��Ӧ��Participant
    Participant *m_pRelatedParticipant;

    //���Ĵ����
    MessageTransmitter *m_pMessageTransmitter;

    //���ջ�����
    ReceiveBuffer *m_pReceiveBuffer;

	uLinX_SemMutex* m_pEncapsulateMessageMutex;

	/* Nephalem  ������װRTPS���ĵĻ����� */
	char* m_pEncapsulateMessage;

	/* Nephalem ��װ�������Ĵ�С */
	unsigned int m_uiEncapsulateMessageSize;

	/* Nephalem ���ش�С�����ã�0Ϊ��ˣ�1ΪС��*/
	unsigned int m_uiEndianness;

	/* Nephalem ��¼������InfoDest��guidPrefix��λ�� */
	unsigned int m_uiInfoDestRecord;

	/* Nephalem ��¼Data�����е�ReaderIdλ�� */
	unsigned int m_uiDataReaderIdRecord;

	/* Nephalem ��¼���������е�ReaderIdλ�� */
	unsigned int m_uiHeartBeatReaderIdRecord;
};

#endif
