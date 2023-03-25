#pragma once

#include "RTPS/Request.h"
#include "RTPS/Message.h"

class WriterProxy;
class MessageProcessor;
class MessageTransmitter;

class NackFragMessageRequest : public Request
{
public:
	NackFragMessageRequest(const EntityId_t entityId,
		WriterProxy *pWriterProxy,
		SequenceNumber_t& writerSN,
		_FRAGMENT_NUMBER_SET& seqNumSet,
		MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter,
		Time_t StartTime,
		Time_t EndTime) :
		Request(entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "Acknack")
		, m_pWriterProxy(pWriterProxy), m_writerSN(writerSN),m_FragmentNumSet(seqNumSet)
	{
	};

	ReturnCode_t Execute();


private:

	WriterProxy *m_pWriterProxy;

	SequenceNumber_t m_writerSN;

	_FRAGMENT_NUMBER_SET m_FragmentNumSet;

};
