/************************************************************
** �ļ�����PeriodRequestScheduler.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-11-14
** �޸��ˣ���
** ��  �ڣ���
** ��  ����PeriodRequestSchedulerͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_PERIODREQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_PERIODREQUESTEDSCHEDULER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/RequestScheduler.h"
#include "ULINXAPI/uLinxTimer.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */


//����
class MessageProcessor;
class MessageTransmitter;
class Request;
class TimerManager;

class PeriodRequestScheduler : public RequestScheduler
{
public:
	PeriodRequestScheduler(MessageProcessor *pMessageProcessor,
		MessageTransmitter *pMessageTransmitter);
	//virtual ~PeriodRequestScheduler();

	//��ӵ�������
	ReturnCode_t RequestAdd(Request *pRequest);

	//ɾ��һ����������
	ReturnCode_t RequestRemove(Request *pRequest);

	////�����ĳEndpoint������ĵ�������
	//ReturnCode_t RequestClean(Endpoint *pEndpoint);

	////ɾ�����ȶ���������readerProxy��ص�Request
	//ReturnCode_t RequestClean(ReaderProxy *pReaderProxy);

	////ɾ�����ȶ���������wtiterProxy��ص�Request
	//ReturnCode_t RequestClean(WriterProxy *pWriterProxy);


//	//���m_RequestList�Ƿ������Ӧrequest
//	bool RequestExist(Request *pRequest);
//
#if (defined( ULINX_WIN) ||  defined(_WIN32))
	static VOID CALLBACK TimeRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired = false);
#elif defined ULINX_LINUX
    static void  TimeRoutine(union sigval lpParam);
#elif defined ULINX_VXWORKS
    static void  TimeRoutine(timer_t timerid,int lpParam);
#endif

private:
	//ReturnCode_t RequestExecute(Request *pRequest);
	map<Request*,uLinxTimer*> m_pTimerMap;
};
#endif
