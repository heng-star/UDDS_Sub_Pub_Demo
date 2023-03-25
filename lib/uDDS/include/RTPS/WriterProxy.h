/************************************************************
** 文件名：WriterProxy.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-11
** 修改人：无
** 日  期：无
** 描  述：WriterProxy头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_WRITERPROXY_H_INCLUDED_
#define _RTPS_WRITERPROXY_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "RTPS/Message.h"

class RequestScheduler;
class StatefulReader;
class Endpoint;

class WriterProxy 
{
public:
    //构造函数
    WriterProxy(GUID_t WriterGuid,
        _LOCATOR_LIST_T UnicastLocatorList,
        _LOCATOR_LIST_T MulticastLocatorList);

    //析构函数
    //virtual ~WriterProxy();

public:
	/* Nephalem 规范中定义的接口 */
	/* Nephalem 代理中最大数据的编号 */
	SequenceNumber_t available_changes_max();

	ReturnCode_t irrelevant_change_set(SequenceNumber_t seqNum);

	/* Nephalem 将小于该编号且状态为MISSING或UNKNOWN的数据状态修改为LOST */
	ReturnCode_t lost_changes_update(SequenceNumber_t& fistAvailableSeqNum);

	///* Nephalem 返回所有状态为MISSING的数据的编号 */
	//vector<SequenceNumber_t> missing_changes();

	/* Nephalem 将小于该编号且状态为UNKNOWN的数据状态修改为MISSING */
	ReturnCode_t missing_changes_update(SequenceNumber_t& lastAvailableSeqNum);

	/* Nephalem 将指定数据的状态设置为RECEIVED */
	ReturnCode_t received_change_set(SequenceNumber_t seqNum);

public:
	/* Nephalem 自定义接口 */
	/* Nephalem 添加CacheChang到代理中 */
	ReturnCode_t addCacheChange(_CACHE_CHANGE* pCacheChange);

	/* Nephalem 处理HB报文 检查从First到Last的数据是否存在，不存在的则创建UNKNOWN状态的数据 */
	ReturnCode_t checkCacheChange(SequenceNumber_t& fistAvailableSeqNum, SequenceNumber_t& lastAvailableSeqNum);

	/* Nephalem 处理HB报文 根据缓冲区中的MISS状态设置ReaderSNState */
	ReturnCode_t getReaderSNState(_SEQUENCE_NUMBER_SET& SeqNumSet);

	/* Nephalem 处理HB报文 判断是否是重复的HB报文，重复的话可忽略，非重复则更新本地记录的值 */
	bool ignoreHeartBeat(unsigned int heartBeatCount);

	/* Nephalem 获取可用的数据 */
	_CACHE_CHANGE* getAvailableChanges(SequenceNumber_t maxAvailableNum);

	/* Nephalem 获取指定编号的ChangeFromWriter */
	ChangeFromWriter& getChangeFromWriter(SequenceNumber_t& SeqNumber);

	/* Nephalem 重新设置大小，尽力传输下分片数据的过期缓存需要手动释放 */
	ReturnCode_t resize(int size);

	/* Nephalem 根据分片接收情况 发送NackFarg */
	ReturnCode_t CreateNackFragRequest(Endpoint *pEndpoint, RequestScheduler *pRequestScheduler);

	/* Nephalem 可用数据编号+1 */
	void addAvailableNum();

	/* Nephalem 获取writer的guid */
	GUID_t getGuid();

	/* Nephalem 获取远端发布者的单播接收地址 */
	_LOCATOR_LIST_T getUnicastLocatorList();

	ReturnCode_t SetDDSInfo(int iDomainCount,string TopicNames);

	/* Nephalem 转化设置Qos */
	ReturnCode_t setQos(DiscoveredWriterData & writerData);

	/* Nephalem 更新存活性状态时间 */
	ReturnCode_t updataLiveLinessTime(const Time_t& curTime);

	/* Nephalem 设置存活性状态 */
	ReturnCode_t setLiveLinessStatus(bool bAlive);

	/* Nephalem 设置LifeSpan */
	ReturnCode_t setLifeSpan(Time_t& curTime);

	int checkLiveLiness(const Time_t& curTime, const Time_t& lease_duration);
	
	/* JD 20220720 设置接收到HB报文的序号  */
	void SetHeartbeatCount(unsigned int uiHeartBeatCount);
	
	/* JD 20220720 获取接收到HB报文的序号 */
	unsigned int GetHeartbeatCount();

private:
	/* Nephalem 规范中定义的变量 */
	//远端发布端的GUID
	GUID_t m_RemoteWriterGuid;

	//单播地址列表
	_LOCATOR_LIST_T m_UnicastLocatorList;

	//多播地址列表
	_LOCATOR_LIST_T m_MulticastLocatorList;

	/* Nephalem 存储writer发送的数据，考虑到可靠传输需要排序，使用Map*/
	ChangeFromWriterMap m_ChangesFromWriter;

private:

	/* Nephalem */
	/* Nephalem 可提交数据的最大编号，该编号的数据可能已经被提交过  该数据会被HB更新 */
	SequenceNumber_t m_AvailableSeqNum;

	/* Nephalem 上次接收的心态序号，重复序号的HB报文不再接收 */
	unsigned int m_uiHeartBeatCount;

	/* Nephalem DataWriterQos*/
	DataWriterQos m_stQos;

	/* Nephalem liveliness状态 */
	bool m_bAlive;

	/* Nephalem 上次记录的存活信息时间 */
	Time_t m_stLiveLinessTime;

	/* 日志记录的相关信息 */
	int m_iDomainCount;

	string m_strTopicName;

};

#endif
