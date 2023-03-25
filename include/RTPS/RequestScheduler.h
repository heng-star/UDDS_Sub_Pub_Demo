/************************************************************
** �ļ�����RequestScheduler.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����RequestSchedulerͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_REQUESTEDSCHEDULER_H_INCLUDED_
#define _RTPS_REQUESTEDSCHEDULER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"



#define SCHEDULER_LENGTH 10000
#include "ULINXAPI/uLinXSemMutex.h"
//����
class MessageProcessor;
class MessageTransmitter;
class Request;
class WriterProxy;
class ReaderProxy;
typedef list<Request *> _REQUEST_LIST_T;

class RequestScheduler
{
public:
    RequestScheduler(MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter);
	virtual ~RequestScheduler();

    //��ӵ�������
    virtual ReturnCode_t RequestAdd(Request *pRequest) = 0;

    //ɾ��һ����������
    virtual ReturnCode_t RequestRemove(Request *pRequest) = 0;

 //   //�����ĳEndpoint������ĵ�������
 //   virtual ReturnCode_t RequestClean(Endpoint *pEndpoint) = 0;

	////ɾ�����ȶ���������readerProxy��ص�Request
	//virtual ReturnCode_t RequestClean(ReaderProxy *pReaderProxy) = 0;

	////ɾ�����ȶ���������wtiterProxy��ص�Request
	//virtual ReturnCode_t RequestClean(WriterProxy *pWriterProxy) = 0;

    //���е���
    //ReturnCode_t RequestScheduling();

    MessageProcessor *GetMessageProcessor()
    {
        return m_pMessageProcessor;
    }

    MessageTransmitter *GetMessageTransmitter ()
    {
        return m_pMessageTransmitter;
    }

//private:
//    virtual ReturnCode_t RequestExecute(Request *pRequest) = 0;
	bool  isRun();

	void setRunFlag(bool flag);

	bool isStop();

	void setStopFlag();

protected:
    //���Ĵ����
    MessageProcessor *m_pMessageProcessor;

    MessageTransmitter *m_pMessageTransmitter;
    //���ȶ���
    _REQUEST_LIST_T m_RequestList;

    //wangyi 2021/8/25 HeartBeat���ȶ���
    _REQUEST_LIST_T m_RequestHeartBeatList;
	uLinX_SemMutex* m_pRequestListMutex;

	uLinX_SemAphore* m_pRequestListAphore;

private:
	bool m_bRunFlag;

	bool m_bStopFlag;
};

#endif
