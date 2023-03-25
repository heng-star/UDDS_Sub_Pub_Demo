/************************************************************
** 文件名：StatefulReader.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-11
** 修改人：无
** 日  期：无
** 描  述：StatefulReader头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_STATEFULREADER_H_INCLUDED_
#define _RTPS_STATEFULREADER_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPS/Reader.h"
#include "RTPS/Message.h"
#include "RTPS/Request.h"

class WriterProxy;
class RequestScheduler;

class StatefulReader : public Reader 
{
public:
    //构造函数
    StatefulReader (
        GUID_t Guid,
        const DataReaderQos& pQos,
        RequestScheduler** pRequestScheduler);

    //析构函数
    virtual ~StatefulReader ();

	/* Nephalem 规范中定义的接口 */
	//增加匹配的发布端代理
   ReturnCode_t matched_writer_add (WriterProxy *pWriterProxy);

   //删除匹配的发布端代理
   ReturnCode_t matched_writer_remove (WriterProxy *pWriterProxy);

   //查找特定前缀的发布端代理
    WriterProxy* matched_writer_lookup (GUID_t writerGuid);

public:
	/* Nephalem 自定义接口 */
	/* Nephalem 接收用户数据 */
	virtual ReturnCode_t DataMessageReceive(_RECEIVER& MessageReceiver, _DATA_SUBMESSAGE& DataMessage, _PARAMETER_LIST& InlineQos, SerializedPayload serializedPayload,unsigned int uiDataLen);

	/* Nephalem 可靠数据接收处理 */
	ReturnCode_t ReliableDataMessageReceive(_CACHE_CHANGE* pCacheChange);

	/* Nephalem 尽力传输数据接收处理 */
	ReturnCode_t BestEffortDataMessageReceive(_CACHE_CHANGE* pCacheChange);

	/* Nephalem 接收用户HeartBeat报文 */
	virtual ReturnCode_t HeartBeatMessageReceive(_RECEIVER& MessageReceiver,_HEARTBEAT_SUBMESSAGE& HeartBeatMessage) ;

	/* Nephalem 接收用户数据分片报文 */
	virtual ReturnCode_t DataFragMessageReceive(_RECEIVER& MessageReceiver, _DATA_FRAG_SUBMESSAGE& DataFragMessage, _DATA_FRAG& DataFrag, _PARAMETER_LIST& InlineQos, SerializedPayload serializedPayload, unsigned int uiDataLen);

	/* Nephalem 接收用户GAP报文 */
	virtual ReturnCode_t GapMessageReceive(_RECEIVER& MessageReceiver,_GAP_SUBMESSAGE& stGapMessage);

	RequestScheduler** GetRequestScheduler() 
    {
		return m_pScheduleList;
	}

	/* Nephalem 设置远端写者存活性状态 */
	ReturnCode_t setRemoteWriterLiveLiness(const GUID_t& Guid, const Time_t& curTime, LivelinessQosPolicyKind kind);

	/* Nephalem 检查远端写者存活性状态 */
	ReturnCode_t checkRemoteWriterLiveLiness(const Time_t& curTime);

	/* Nephalem 检查是否有可用数据并提交给DataReader */
	ReturnCode_t submitAvailableData(WriterProxy* pWriterProxy);
	
	/* JD 创建一个定时发送的AckRequest的请求  */
	int CreateAckNackRequest(WriterProxy* pWriterProxy, _SEQUENCE_NUMBER_SET seqNumSet);

private:

	_WRITER_PROXY_LIST_T m_MatchedWriter;

	/* Nephalem 已经提交数据数量 */
	SequenceNumber_t m_LastChangeSequence;

	/* Nephalem 周期性进行Deadline检测的请求 */
	Request* m_pDeadlineRequest;

};

#endif
