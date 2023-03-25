/************************************************************
** �ļ�����ImmeditRequestScheduler.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-11-14
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ImmeditRequestSchedulerͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_IMMEDITREQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_IMMEDITREQUESTEDSCHEDULER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/RequestScheduler.h"
#include "uLinxDataType.h"


//����
class MessageProcessor;
class MessageTransmitter;
class Request;

class ImmeditRequestScheduler : public RequestScheduler
{
public:
	ImmeditRequestScheduler(MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter);
	virtual ~ImmeditRequestScheduler();

	//��ӵ�������
	ReturnCode_t RequestAdd(Request *pRequest);

	//ɾ��һ����������
	ReturnCode_t RequestRemove(Request *pRequest);

	////�����ĳEndpoint������ĵ�������
	//ReturnCode_t RequestClean(Endpoint *pEndpoint);

	////ɾ�����ȶ���������pReaderProxy��ص�Request
	//ReturnCode_t RequestClean(ReaderProxy *pReaderProxy);

	////ɾ�����ȶ���������pWtiterProxy��ص�Request
	//ReturnCode_t RequestClean(WriterProxy *pWriterProxy);

	//���е���
	ReturnCode_t RequestScheduling();

//	ReturnCode_t RequestLastScheduling();

    static DWORD WINAPI ScheduleRun(void* lpRequestScheduler);
};
#endif
