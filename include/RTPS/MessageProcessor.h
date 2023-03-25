/************************************************************
** 文件名：MessageProcessor.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-13
** 修改人：无
** 日  期：无
** 描  述：MessageProcessor头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_MESSAGEPROCESSOR_H_INCLUDED_
#define _RTPS_MESSAGEPROCESSOR_H_INCLUDED_

#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

//声明
class Participant;
class MessageTransmitter;
class ReceiveBuffer;
class Endpoint;

class MessageProcessor 
{
public:
    //构造函数
    MessageProcessor(
        Participant *pParticipant,
        ReceiveBuffer *pBuffer);

    //析构函数
    virtual ~MessageProcessor();

	/* Nephalem 数据封装是多线程的的 所以封装前后需要使用互斥锁进行保护 */
	void startEncapsulateMessage();

	void endEncapsulateMessage();

    char *EncapsulateMessage(char *pMessage, unsigned long *ulLength,GUID_t DstGuid);

	/* Nephalem 封装RTPS报文头 */
	char* EncapsulateMessageHeader(unsigned int& uiShift);

	/* Nephalem 封装INFO_TS子报文 */
	char* EncapsulateINFOTSMessage(unsigned int& uiShift,const _TIME_STAMP & TimeStamp);

	/* Nephalem 封装INFO_DST子报文 */
	char* EncapsulateINFODSTMessage(unsigned int& uiShift, GUID_t DstGuid);

	/* Nephalem 封装DATA子报文 */
	char* EncapsulateDATAMessage(unsigned int& uiShift,char* pUserData,unsigned int uiUserDataLen, const SequenceNumber_t& SeqNum,_PARAMETER_LIST& InlineQos, Endpoint *m_pEndpoint);

	/* Nephalem 封装DATA_FRAG子报文 */
	char* EncapsulateDATAFragMessage(unsigned int& uiShift, char* pUserDataFrag, unsigned int uiUserDataFragLen, unsigned int uiDataFragNum,unsigned int uiUserDataLen, const SequenceNumber_t& SeqNum, _PARAMETER_LIST& InlineQos, Endpoint *m_pEndpoint);

	/* Nephalem 修改DATA中的ReaderID */
	char* modifyDataReaderId(EntityId_t readerEntityId);

	/* Nephalem 修改报文中InfoDst中的guidprefix字段 */
	char* modifyInFoDstGuidPrefix(guidPrefix_t guidPrefix);

	/* Nephalem 封装HeartBeat子报文 */
	char* EncapsulateHeartBeatMessage(unsigned int& uiShift, EntityId_t writerEntityId,SequenceNumber_t& firstSeq, SequenceNumber_t& lastSeq, unsigned int Count = 1);

	/* Nephalem 修改HeartBeat中的ReaderID */
	char* modifyHeartBeatReaderId(EntityId_t readerEntityId);

	/* Nephalem 封装AckNack子报文 */
	char* EncapsulateAckNackMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, _SEQUENCE_NUMBER_SET& seqNumSet);

	/* Nephalem 封装NackFrag子报文 */
	char* EncapsulateNackFragMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, SequenceNumber_t& writerSN, _FRAGMENT_NUMBER_SET& FragmentNumSet);

	/* Nephalem 封装Gap子报文 */
	char* EncapsulateGapMessage(unsigned int& uiShift, EntityId_t writerEntityId, EntityId_t readerEntityId, SequenceNumber_t& stGapStar, _SEQUENCE_NUMBER_SET& stGapList);

	char* getEncapsulateMessage();
	/* Nephalem 解析线程 */
#if (defined( ULINX_WIN) ||  defined(_WIN32))
    static DWORD WINAPI ProcessRun(void* pMessageProcessor);
#elif defined ULINX_LINUX || defined ULINX_VXWORKS
    static long ProcessRun(MessageProcessor* pMessageProcessor);
#endif
	/* Nephalem 开始解析RTPS报文 */
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
    //解析报文头
    ReturnCode_t InterpretMessageHeader(char*& pMessage,_RECEIVER& MessageReceiver);

    //解析子报文
    ReturnCode_t InterpretSubmessage(char*& pMessage, _RECEIVER& MessageReceiver);

    //解析Data子报文
    ReturnCode_t InterpretDataMessage(char* pMessage,_SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//解析Heartbeat子报文
   ReturnCode_t InterpretHeartbeatMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

    //解析AckNack子报文
   ReturnCode_t InterpretAckNackMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//解析DataFrag子报文
	ReturnCode_t InterpretDataFragMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//解析INFO_TS子报文
	ReturnCode_t InterpretINFOTSMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//解析INFO_DST子报文
	ReturnCode_t InterpretINFODSTMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	/* 解析InlineQos 此处报文指针为传引用 */
	ReturnCode_t InterpretInlineQosMessage(char* &pMessage, _PARAMETER_LIST& inlineQos);

	//解析NackFrag子报文
    ReturnCode_t InterpretNackFragMessage(char* pMessage, _SUBMESSAGE_HEADER& submessageHeader, _RECEIVER& MessageReceiver);

	//解析GAP子报文
	ReturnCode_t InterpretGapMessage(char* pMessage, _SUBMESSAGE_HEADER& pSubmessageHeader, _RECEIVER& MessageReceiver);


	/* Nephalem 缓冲区扩容为2倍 */
	ReturnCode_t DoubleEncapsulateMessageSize();
private:
    //对应的Participant
    Participant *m_pRelatedParticipant;

    //报文传输端
    MessageTransmitter *m_pMessageTransmitter;

    //接收缓冲区
    ReceiveBuffer *m_pReceiveBuffer;

	uLinX_SemMutex* m_pEncapsulateMessageMutex;

	/* Nephalem  用于组装RTPS报文的缓冲区 */
	char* m_pEncapsulateMessage;

	/* Nephalem 组装缓冲区的大小 */
	unsigned int m_uiEncapsulateMessageSize;

	/* Nephalem 本地大小端设置：0为大端，1为小端*/
	unsigned int m_uiEndianness;

	/* Nephalem 记录报文中InfoDest中guidPrefix的位置 */
	unsigned int m_uiInfoDestRecord;

	/* Nephalem 记录Data报文中的ReaderId位置 */
	unsigned int m_uiDataReaderIdRecord;

	/* Nephalem 记录心跳报文中的ReaderId位置 */
	unsigned int m_uiHeartBeatReaderIdRecord;
};

#endif
