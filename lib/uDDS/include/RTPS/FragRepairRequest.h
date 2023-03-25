/************************************************************
** 文件名：FragRepairRequest.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-10-13
** 修改人：无
** 日  期：无
** 描  述：FragRepairRequest头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_FRAGREPAIR_REQUEST_H_INCLUDED_
#define _RTPS_FRAGREPAIR_REQUEST_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPS/Message.h"

class ReaderProxy;

class FragRepairRequest : public Request 
{
public:
	FragRepairRequest (const EntityId_t entityId,
		ReaderProxy *pReaderProxy,
		SequenceNumber_t &WriterSN,
		_FRAGMENT_NUMBER_SET &FragmentNumberSet,
		MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter,
		Time_t StartTime,
		Time_t EndTime) :
	Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "FragRepair")
    {
		m_pReaderProxy = pReaderProxy;
		m_pWriterSN = WriterSN;
		m_pFragmentNumberSet = FragmentNumberSet;
	};

	ReturnCode_t Execute();

	//如果两个FragRepairRequest的endpoint、readerproxy都相同，则表明它们是可比较的
	//bool Comparable(FragRepairRequest *pRequest)
 //   {
	//	//		return (this->GetEndpoint() == request->GetEndpoint() && this->m_readerProxy == request->m_readerProxy);
	//	return (this->GetEndpoint() == pRequest->GetEndpoint());
	//}

	ReaderProxy* GetReaderProxy()
    {
		return m_pReaderProxy;
	}

private:
	ReaderProxy *m_pReaderProxy;
	SequenceNumber_t m_pWriterSN;
	_FRAGMENT_NUMBER_SET m_pFragmentNumberSet;
};

#endif
