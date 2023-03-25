/************************************************************
** 文件名：Writer.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-12
** 修改人：无
** 日  期：无
** 描  述：DataWriter头文件
** 版  本：Writer 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_WRITER_INCLUDED_H
#define _RTPS_WRITER_INCLUDED_H

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Endpoint.h"


class HistoryCache;
class RequestScheduler;
class DataWriter;

class Writer : public Endpoint
{
public:
    //构造函数
    Writer( GUID_t            Guid,
		const DataWriterQos&	dataWriterQoS,
        RequestScheduler  **pScheduleList );

    //析构函数
    virtual ~Writer();

	//生成一个_CACHE_CHANGE
	_CACHE_CHANGE* new_change(const char *pData, int iLength, _CHANGE_KIND_T Kind, InstanceHandle_t Handle);

public:
	/* Nephalem 自定义接口 */
	/* Nephalem 设置writer的HistoryCache */
	void setWriterHistoryCache(HistoryCache* pHistoryCache);

	/* Nephalem LastChangeSequence数据编号 + 1*/
	void addLastChangeSequence();

	/* Nephalem 获取匹配上的DataReader的数量 */
	virtual unsigned int GetMatchDataReaderNum() = 0;

	//将数据发送请求插入请求队列 虚函数 提供接口
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange) = 0;

	/* Nephalem 移除指定Change statelesswriter暂时无用  */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq) = 0;

	/* Nephalem 数据发送完的处理函数 */
	//virtual ReturnCode_t DataSendFindish(SequenceNumber_t Seq) = 0;





    //获取Writer的信息
    //_WRITER_PROXY_DATA* getWriterInfo();
    //virtual HistoryCache* GetWriterCache();
    //virtual Duration_t* GetNackResponseDelay();
    //virtual RequestScheduler* GetScheduleList();

    //返回对应的缓冲区指针
    HistoryCache* GetWriterCache() 
    {
        return m_pWriterCache;
    }

    //获取发送新报文的截止期
    Time_t Deadline() 
    {
        return m_Deadline;
    }

    //获取Heartbeat报文发送周期
    Duration_t HeartbeatPeriod() 
    {
        return m_HeartbeatPeriod;
    }

    Duration_t GetNackResponseDelay() 
    {
        return m_NackResponseDelay;
    };

    Duration_t GetNackSuppressionDuration() 
    {
        return m_NackSuppressionDuration;
    };


	RequestScheduler** Request_Scheduler() 
    {
		return m_pScheduleList;
	}

	void setRelatedDataWriter(DataWriterImpl* pDataWriter);

	DataWriterImpl* GetRelatedDataWriter()
    {
		return m_pRelatedDataWriterImpl;
	}

	/* Nephalem 更新存活性状态时间 */
	ReturnCode_t updataLiveLinessTime(LivelinessQosPolicyKind kind);

	/* Nephalem 设置存活性状态 */
	int checkLiveLiness(const Time_t& curTime);


protected:
    /* Nephalem 规范中定义的的变量 */
	/* Nephalem true：直接发送 false：通过HB-ACK驱动 */
    bool             m_bPushMode;
    //Heartbeat发送周期
    Duration_t       m_HeartbeatPeriod;
    //回复Nack报文的延时
    Duration_t       m_NackResponseDelay;
    //忽略一段时间内的重复Nack报文
    Duration_t       m_NackSuppressionDuration;
	/* 上一次生成的Change的序列号 */
	SequenceNumber_t m_LastChangeSequence;

	//对应的缓冲区
	HistoryCache     *m_pWriterCache;

    //上一次发送报文的时间
    Time_t           m_DataSendTime;
    //发送新报文的截止期
    Duration_t       m_Deadline;
    //已经成功发送的Change的序列号
    SequenceNumber_t m_HighestSeqNumFinished;
    //对应的DDS DataWriter
    DataWriterImpl     *m_pRelatedDataWriterImpl;
    //调度队列，0为ImmeditRequestScheduler，1为PeriodRequestScheduler
    RequestScheduler **m_pScheduleList;

	DataWriterQos   m_dataWriterQoS;

	/* Nephalem 上次记录的存活时间 */
	Time_t			m_stLiveLinessTime;

	/* Nephalem liveliness状态 */
	bool m_bAlive;
};

#endif
