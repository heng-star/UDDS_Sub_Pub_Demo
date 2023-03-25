/************************************************************
** 文件名：HeartbeatMessageRequest.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-13
** 修改人：无
** 日  期：无
** 描  述：HeartbeatMessageRequest头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_HEARTBEATMESSAGE_REQUEST_H_INCLUDED_
#define _RTPS_HEARTBEATMESSAGE_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPSBasicTypes.h"

class ReaderProxy;
class HeartbeatMessageRequest : public Request
{
public:
	HeartbeatMessageRequest(
		const EntityId_t entityId,
		_READER_PROXY_LIST ReaderProxyList,
		MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter,
		Time_t StartTime,
		Time_t EndTime) :
	Request (entityId,pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "HeartBeat")
		, m_bForcedSend(false)
	{
	};

	ReturnCode_t Execute();

	/* JD 设置强制发送HB报文 */
	ReturnCode_t SetForcedSendFlag(bool bFlag);
	/* JD 获取强制回复的标志位 */
	bool GetForcedSendFlag();
private:
	/* Nephalem 使用复制的数据，不与其他线程使用共享资源 */
	_READER_PROXY_LIST m_ReaderProxyList;

	/* JDXCZ 强制回复HB报文 */
	bool m_bForcedSend;
};

#endif
