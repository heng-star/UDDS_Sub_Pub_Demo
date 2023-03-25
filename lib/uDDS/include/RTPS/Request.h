/************************************************************
** 文件名：Request.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-13
** 修改人：无
** 日  期：无
** 描  述：Request头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_REQUEST_H_INCLUDED_
#define _RTPS_REQUEST_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"

class Endpoint;
class MessageProcessor;
class MessageTransmitter;

class Request 
{
public:
    Request(
		const EntityId_t entityId,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime,
		string strTypeName)
    {
		m_EntityId = entityId;
        m_pMessageProcessor = pMessageProcessor;
        m_pMessageTransmitter = pMessageTransmitter;
        m_StartTime = StartTime;
        m_EndTime = EndTime;
		m_strTypeName = strTypeName;

		/* Request的Transport Priority */
		m_uiPriority = 0;

		m_strTopicName = "";
		m_iDomainCount = 0;
    }

    virtual ~Request() {};

    virtual ReturnCode_t Execute() = 0;

    Time_t GetStartTime()
    {
        return m_StartTime;
    }

    Time_t GetEndTime()
    {
        return m_EndTime;
    }

	const EntityId_t& GetEntityId()
    {
        return m_EntityId;
    }
	ReturnCode_t SetDDSInfo(const int iDomainCount, string TopicName) {
		m_iDomainCount = iDomainCount;
		m_strTopicName = TopicName;

		return RETCODE_OK;
	}
public:
    Time_t m_StartTime;
    Time_t m_EndTime;
	string m_strTypeName;
	ULINX_UINT32 m_uiPriority;
	/* JD 日志记录的相关信息  */
	int m_iDomainCount;
	string m_strTopicName;
protected:
	EntityId_t m_EntityId;
    MessageProcessor *m_pMessageProcessor;
    MessageTransmitter *m_pMessageTransmitter;

};

#endif
