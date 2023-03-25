/************************************************************
** 文件名：Reader.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-11
** 修改人：无
** 日  期：无
** 描  述：Reader头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_READER_H_INCLUDED_
#define _RTPS_READER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Endpoint.h"
#include "Message.h"

//声明
class DataReaderImpl;
class HistoryCache;
class RequestScheduler;
class DDSContentFilter;

class Reader : public Endpoint 
{
public:
    //构造函数
    Reader (GUID_t Guid,
        const DataReaderQos& pQos,
        RequestScheduler** pRequestScheduler);

    //析构函数
    ~Reader ();

	/* Nephalem 接收用户数据报文 */
	virtual ReturnCode_t DataMessageReceive(
		_RECEIVER& MessageReceiver,
		_DATA_SUBMESSAGE& DataMessage,
		_PARAMETER_LIST& InlineQos,
		SerializedPayload serializedPayload,
		unsigned int uiDataLen
	) = 0;

	/* Nephalem 接收用户数据分片报文 */
	virtual ReturnCode_t DataFragMessageReceive(
		_RECEIVER& MessageReceiver,
		_DATA_FRAG_SUBMESSAGE& DataFragMessage,
		_DATA_FRAG& DataFrag,
		_PARAMETER_LIST& InlineQos,
		SerializedPayload serializedPayload,
		unsigned int uiDataLen
	) = 0;

	/* Nephalem 接收用户HeartBeat报文 */
	virtual ReturnCode_t HeartBeatMessageReceive(
		_RECEIVER& MessageReceiver,
		_HEARTBEAT_SUBMESSAGE& HeartBeatMessage
	) = 0;

	/* Nephalem 接收用户GAP报文 */
	virtual ReturnCode_t GapMessageReceive(
		_RECEIVER& MessageReceiver,
		_GAP_SUBMESSAGE& HeartBeatMessage
	) = 0;

	void setRelatedDataReader(DataReaderImpl* pDataReaderImpl);

	DataReaderImpl* getRelatedDataReader();

	void setReaderHistoryCache(HistoryCache* pHistoryCache);

    //生成_CACHE_CHANGE
    _CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);
    _CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, SequenceNumber_t SeqNum, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);
	
	//JDXCZ 打算在cache中添加一个字段，判断大小端，
	//_CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle,_SUBMESSAGE_FLAG Flag);
	//_CACHE_CHANGE *NewChange(GUID_t WriterGuid, char *pMessage, unsigned long ulLength, SequenceNumber_t SeqNum, _CHANGE_KIND_T Kind, InstanceHandle_t Handle,_SUBMESSAGE_FLAG Flag);

    //通知DDS DataReader数据到达
    //ReturnCode_t DataNotify(SequenceNumber_t LocalSeqNum);

    //获取忽略重复Heartbeat报文的时间
    Duration_t HeartbeatSuppressionDuration() 
    {
        return m_HeartbeatSuppressionDuration;
    }

    //获取Heartbeat报文回复延时
    Duration_t HearbeatResponseDelay() 
    {
        return m_HeartbeatResponseDelay;
    }

    //获取接收报文的截止期Deadline
    Duration_t Deadline() {
        return m_Deadline;
    }

    //初始化调度队列
    virtual ReturnCode_t ScheduleListInit() 
    {
        return RETCODE_OK;
    }

    //检查是否还有相应的Writer在发送该实例
    //bool noWriters(InstanceHandle_t Handle);

 //   //获取实例状态
 //   ReturnCode_t GetInstanceState(InstanceHandle_t Handle, InstanceStateKind& InstanceState);

	////更新实例状态
	//ReturnCode_t InstanceUpdate(GUID_t WriterGuid, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);

    SequenceNumber_t GetNewChangeSeqNum() 
    {
        return ++m_LastChangeSeqNum;
    }

	//void SetSeqNumNotify(SequenceNumber_t SeqNum);

protected:
	/* Nephalem 规范中定义的变量 */

	/* Nephalem 是否使用inlineQoS */
	bool			m_bExpectsInlineQos;
    /* Heartbeat报文回复延时 */
    Duration_t		m_HeartbeatResponseDelay;
    /* 忽略重复的Heartbeat报文的时间 */
    Duration_t		m_HeartbeatSuppressionDuration;

	/* Nephalem 读者缓冲区 */
	HistoryCache *m_pReaderCache;

	/* Nephalem 分片缓冲区 */
	HistoryCache *m_pFragDataCache;

protected:
    //接收新报文的截止期
    Duration_t m_Deadline;

    //最新生成的Change的序列号
    SequenceNumber_t m_LastChangeSeqNum;

    //调度队列，0为ImmeditRequestScheduler，1为PeriodRequestScheduler
    RequestScheduler** m_pScheduleList;

	/* Nephalem 相关数据读者*/
	DataReaderImpl *m_pRelatedDataReaderImpl;

    //上交的SequenceNumber
    SequenceNumber_t m_HighestSeqNumNotify;

	DataReaderQos m_dataReaderQos;
};

#endif
