/************************************************************
** 文件名：ReaderProxy.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-12
** 修改人：无
** 日  期：无
** 描  述：ReaderProxy头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef RTPS_READERPROXY_INCLUDED_H
#define RTPS_READERPROXY_INCLUDED_H

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Message.h"
#include "ULINXAPI/uLinXSemMutex.h"

class Writer;
class HistoryCache;
class StatefulWriter;

typedef list<ChangeForReader> ChangeForReaderList;

/* Nephalem 远端Reader代理，在主线程发送数据、发送HB报文线程、解析线程ack报文处理 */
/* 中都有涉及，故必须使用互斥锁进行保护 */
class ReaderProxy
{
public:
    //构造函数
    ReaderProxy( GUID_t ReaderGuid,
		_LOCATOR_LIST_T UnicastLocatorList,
		_LOCATOR_LIST_T MulticastLocatorList,
		bool bIsActive);

    //析构函数
    //virtual ~ReaderProxy();

	/* Nephalem 规范中定义的方法 */
	/* Nephalem 序号值小于等于committed_seq_num的状态改为ACKNOWLEDGED */
	ReturnCode_t acked_changes_set(SequenceNumber_t& committed_seq_num);

	/* Nephalem 返回状态为REQUESTED的最小序列的ChangeForReader */
	ChangeForReader next_requested_change();

	///* Nephalem 返回状态为UNSENT的最小序列的ChangeForReader */
	//ChangeForReader& next_unsent_change();

	///* Nephalem 返回状态为UNSENT的所有ChangeForReader */
	//_CHANGE_FOR_READER_LIST unsent_changes();

	///* Nephalem 返回状态为REQUESTED的所有ChangeForReader */
	//_CHANGE_FOR_READER_LIST requested_changes();

	/* Nephalem 将指定的序号的状态全部改为请求 */
	ReturnCode_t requested_changes_set(_SEQUENCE_NUMBER_SET& req_seq_num_set);

	/* Nephalem 返回状态为UNACKNOWLEDGED的所有ChangeForReader */
	ChangeForReaderList unacked_changes();

public:
	/* Nephalem 自定义方法 */
	/* Nephalem 根据HistoryCache初始化ChangesForReaderList 创建新的代理时，执行此操作 */
	ReturnCode_t initChangesForReaderList(HistoryCache* pWriterCache);

	/* Nephalem 设置不相关的数据 */
	ReturnCode_t setIrrelevantChange(SequenceNumber_t& unacked_seq_num);

	/* Nephalem 获取远端reader的GUID */
	GUID_t getGuid();

	/* Nephalem 获取最小的未被确认的数据的序号 用于发送HeartBeat报文 */
	SequenceNumber_t getUnacknowledgedMinSeq();

	/* Nephalem 获取最大的数据序号 用于发送HeartBeat报文  */
	SequenceNumber_t getMaxSeq();

	/* Nephalem 发送请求执行后 将对应的数据数据状态改为未确认 */
	ReturnCode_t unacked_changes_set(SequenceNumber_t& unacked_seq_num);

	/* Nephalem 是否被代理确认已接收到 */
	bool isAckedByReader(SequenceNumber_t & seq);

	/* Nephalem 获取远端reader的接收单播地址 */
	_LOCATOR_LIST_T getUnicastLocatorList();

    //添加ChangeForReader对象
    ChangeForReader* ChangeForReaderAdd(const _CACHE_CHANGE* pCacheChange );

    /* Nephalem 代理中删除指定序号的ChangeForReader */
    ReturnCode_t ChangeForReaderRemove(SequenceNumber_t& Seq);

	/* Nephalem 将指定的序号的状态全部改为请求undeway */
	ReturnCode_t undeway_changes_set(SequenceNumber_t& undeway_seq_num);

	ReturnCode_t setQos(DiscoveredReaderData & readerData);

    //设置接收的AckNack报文编号
    ReturnCode_t SetAckNackLastCount (_COUNT_T Count) 
    {
        m_AckNackLastCount = Count;

        return RETCODE_OK;
    }

    SequenceNumber_t HighestSeqNumAcked() 
    {
        return m_HighestSeqNumAcked;
    }

    //是否存在多播地址
    bool MulticastExist() 
    {
        if (m_MulticastLocatorList.size() == 0)
            return false;
        return true;
    }

	//获取针对该订阅端代理发送的心跳报文个数
	unsigned long GetHBSendTimes()
	{
		return m_ulHBSendTimes;
	}

	//增加订阅端代理发送的心跳报文个数
	void IncreaseHBSendTimes()
	{
		m_ulHBSendTimes++;
	}

	/* Nephalem 远端reader是否对writer做出响应 */
	bool isActive();

	/* JD 设置日志记录需要的信息*/
	int SetDDSInfo(const int iDomainCount,const string TopicName);

	/* 判断是否需要回复单播的HB报文 */
	bool GetSendUnicastHeartbeatFlag();
	
	int SetSendUnicastHeartbeatFlag(bool bFlag);

private:
	/* Nephalem 规范中定义的变量 */
    /* 远端订阅端点的GUID */
    GUID_t					m_RemoteReaderGuid;
    /* 远端订阅端单播地址列表 */
	_LOCATOR_LIST_T         m_UnicastLocatorList;
    /*  远端订阅端多播地址列表 */
    _LOCATOR_LIST_T         m_MulticastLocatorList;
    /* ReaderProxy的ChangeForReader列表 */
	ChangeForReaderMap		m_ChangesForReader;//修改
	/* Nephalem 是否发送inlineQos */
	bool					m_bExpectsInlinesQos;
	/* Nephalem 远端reader是否对writer做出响应 */
    bool					m_bIsActive;
private:

	/* Nephalem 互斥锁，对ChangesForReader进行读写保护 */
	uLinX_SemMutex		ChangesForReaderMutex;
    //最近接收到的AckNack报文的序列号
    _COUNT_T             m_AckNackLastCount;

    //已发送_CACHE_CHANGE的最大序列号
    SequenceNumber_t    m_HighestSeqNumSent;

    //已被确认的_CACHE_CHANGE的最大序列号
    SequenceNumber_t    m_HighestSeqNumAcked;

    //下一次可以接收Nack的时间
    Time_t              m_NextNackAllowedTime;

    //下次重发Data报文的时间
    Time_t              m_NextRepairTime;

	//针对该订阅段代理发送的心跳报文个数
	unsigned long m_ulHBSendTimes;

	/* JD 2021 添加日志时，需要获取的信息*/
	int m_iDomainCount;

	string m_strTopicName;

	DataReaderQos m_stQos;
	/* JDXCZ 2022-07-14 静态匹配需要判断是否需要回复单播的心跳报文 true-回复，false-不回复 */
	bool m_bUnicastHeartbeatFlag;

};

#endif
