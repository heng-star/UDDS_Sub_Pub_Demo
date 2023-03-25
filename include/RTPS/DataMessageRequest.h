/************************************************************
** 文件名：DataMessageRequest.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-13
** 修改人：无
** 日  期：无
** 描  述：DataMessageRequest头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_DATAMESSAGE_REQUEST_H_INCLUDED_
#define _RTPS_DATAMESSAGE_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPSBasicTypes.h"

class ReaderProxy;

/* Nephalem 向读者代理列表中的所有代理发送指定数据 一般在用户调用发送接口后使用 */
/* ReaderProxyList 为需要发送到的代理列表 */
/* _CACHE_CHANGE   为需要发送的数据       */
/* 可靠传输						          */

class DataMessageRequest : public Request
{
public:
	DataMessageRequest(const EntityId_t entityId,
		_READER_PROXY_LIST ReaderProxyList,
		_CACHE_CHANGE*  pCacheChange ,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "Data")
		, m_ReaderProxyList(ReaderProxyList),m_pCacheChange(pCacheChange)
    {
    };

    ReturnCode_t Execute();

	ReturnCode_t sendDataMessage(unsigned int & uiShift);

	ReturnCode_t sendDataFragMessage(unsigned int & uiShift);

private:
	_READER_PROXY_LIST m_ReaderProxyList;

	_CACHE_CHANGE*  m_pCacheChange;

};

#endif
