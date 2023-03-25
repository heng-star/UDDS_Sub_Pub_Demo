/************************************************************
** �ļ�����FragRepairRequest.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-10-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����FragRepairRequestͷ�ļ�
** ��  ����Version 0.1
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

	//�������FragRepairRequest��endpoint��readerproxy����ͬ������������ǿɱȽϵ�
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
