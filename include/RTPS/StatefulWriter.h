/************************************************************
** 文件名：StatefulWriter.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-12
** 修改人：无
** 日  期：无
** 描  述：StatefulWriter头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_STATEFULWRITER_INCLUDED_H
#define _RTPS_STATEFULWRITER_INCLUDED_H

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Writer.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

class RequestScheduler;
class ReaderProxy;
class Request;

class StatefulWriter : public Writer
{
public:
    //构造函数
    StatefulWriter(GUID_t Guid,
        const DataWriterQos& dataWriterQoS,
        RequestScheduler  **pScheduleList);

    /* 析构函数 */
    virtual ~StatefulWriter();

	/* Nephalem 规范中定义的接口 */
	 //添加匹配的订阅端代理
    ReturnCode_t matched_reader_add( ReaderProxy* pReaderProxy);

    //删除匹配的订阅端代理
    ReturnCode_t matched_reader_remove( ReaderProxy* pReaderProxy);

    //删除特定前缀的订阅端代理
	ReaderProxy* matched_reader_lookup(GUID_t guid);

	/* Nephalem 收发数据被所有订阅确认接收到,
	处理Ack报文时调用，删除代理时 调用*/
	bool is_acked_by_all(/*_CACHE_CHANGE* a_change*/ SequenceNumber_t & Seq);

public:

	/* Nephalem 自定义接口 */
	_READER_PROXY_LIST getMatchedReaderProxy();

	/* Nephalem 接收AckNack报文 */ 
    ReturnCode_t AckNackMessageReceive(_RECEIVER& MessageReceiver, _ACKNACK_SUBMESSAGE& ackSubMessage);

	/* Nephalem 接收NackFrag报文 */
	ReturnCode_t NackFragMessageReceive(_RECEIVER& MessageReceiver, _NACK_FRAG_SUBMESSAGE& NackFragSubMessage);


	//胡敬羽 2013-09-04 修改
	unsigned int GetMatchDataReaderNum();

	//将数据发送请求插入请求队列 虚函数 提供接口
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange);

	/* Nephalem 移除指定Change 可靠传输下缓冲区已满时，
	或者数据已被所有代理确认接收到时，移除旧数据
	同时移除代理中ChangForReader  */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq);

	/* JD 20211014 设置 heartbeat 所属的数据域和主题的名称 */
	ReturnCode_t SetHeartBeatRequest(const int iDomainCount,string TopicName);

private:

	/* Nephalem 清除已被确认接收到的数据 */
	ReturnCode_t removeAckedChange();

private:
    //匹配的订阅端代理列表
    _READER_PROXY_LIST m_MatchedReaderList; //修改

	/* Nephalem 周期性发送心跳的请求 */
	Request* m_pHeartBeatRequest;

	/* Nephalem 用于保护m_MatchedReaderList */
	uLinX_SemMutex* m_MatchedReaderMutex;
};

#endif
