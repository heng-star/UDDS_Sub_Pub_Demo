/************************************************************
** 文件名：MessageTransmitter.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-16
** 修改人：无
** 日  期：无
** 描  述：MessageTransmitter头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_MESSAGETRANSMITTER_H_INCLUDED_
#define _RTPS_MESSAGETRANSMITTER_H_INCLUDED_

#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPSBasicTypes.h"

/**
* @ brief 定义接收缓冲区大小 字节
*/
#define RECEIVE_BUFFER_SIZE 1024 * 1024 * 50

//声明
class ReceiveBuffer;

class MessageTransmitter 
{
public:
    //构造函数
    MessageTransmitter(ReceiveBuffer *pReceiveBuffer) 
    {
        m_pReceiveBuffer = pReceiveBuffer;

		m_bRunFlag = true;

		m_bStopFlag = false;
    }

    //析构函数
    virtual ~MessageTransmitter() 
    {
        m_Locator.clear();
    };

	virtual ReturnCode_t SendAddrAdd(Locator_t SendAddr) = 0;

    //发送 虚函数提供接口
    virtual ReturnCode_t MessageSend(
        Locator_t Source,
        Locator_t Destination,
        char *pMessage,
        unsigned int uiLength) = 0;

	virtual ReturnCode_t MessageSend(
		_LOCATOR_LIST_T& SourceList,
		_LOCATOR_LIST_T& DestinationList,
		char* pMessage,
		unsigned int uiLength
	) = 0;

    //多播发送 虚函数提供接口
    virtual ReturnCode_t SendMultiMessage(
        Locator_t Source,
        Locator_t Destination,
        char *pMessage,
        unsigned int uiLength) = 0;

    //接收 虚函数提供接口
    virtual ReturnCode_t ReceiveMessage() = 0;

    //添加监听地址
    virtual ReturnCode_t ReceiveAddrAdd(Locator_t ReceiveAddr) = 0;

    //添加监听多播地址
    //virtual ReturnCode_t ReceiveMultiAddrAdd(Locator_t sourceAddr, Locator_t ReceiveAddr) = 0;

    //删除监听地址
    virtual ReturnCode_t ReceiveAddrRemove(Locator_t ReceiveAddr) = 0;

    //开始传输线程/任务
    static DWORD WINAPI TransmitRun(void* lpMessageTransmitter);

	bool  isRun();

	void setRunFlag(bool flag);

	bool isStop();

	void setStopFlag();

private:
	bool m_bRunFlag;

	bool m_bStopFlag;
protected:
    //接收缓冲区
    ReceiveBuffer *m_pReceiveBuffer;

    //监听地址列表
    _LOCATOR_LIST_T m_Locator;

};

#endif
