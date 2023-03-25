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
#ifndef _RTPS_DATAMESSAGEMULTI_REQUEST_H_INCLUDED_
#define _RTPS_DATAMESSAGEMULTI_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"

class ReaderProxy;

/* Nephalem 检测指定ReaderProx中是否存在被请求发送的数据，一般用于接收到Ack报文后，进行数据重传 */
class DataMessageWithReaderProxy : public Request
{
public:
    DataMessageWithReaderProxy (const EntityId_t entityId,
		ReaderProxy *m_pReaderProxy,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "DataMessageWithReaderProxy")
		, m_pReaderProxy(m_pReaderProxy)
    {
    };

    ReturnCode_t Execute();

	ReturnCode_t sendDataMessage(unsigned int & uiShift, _CACHE_CHANGE*  pCacheChange, Endpoint* pEndpoint);

	ReturnCode_t sendDataFragMessage(unsigned int & uiShift, _CACHE_CHANGE*  pCacheChange, Endpoint* pEndpoint);

private:
    ReaderProxy *m_pReaderProxy;
};

#endif
