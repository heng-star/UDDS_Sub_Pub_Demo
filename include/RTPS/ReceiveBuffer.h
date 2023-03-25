/************************************************************
** 文件名：ReceiveBuffer.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-16
** 修改人：无
** 日  期：无
** 描  述：ReceiveBuffer头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_RECEIVEBUFFER_H_INCLUDED_
#define _RTPS_RECEIVEBUFFER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "ULINXAPI/uLinXSemMutex.h"

class ReceiveBuffer 
{
public:
    //构造函数
    ReceiveBuffer(unsigned int ulLength);

    //析构函数
    virtual ~ReceiveBuffer();

    //读
    ReturnCode_t Read(char *pMessage, unsigned int& uiLength);

    //写
    ReturnCode_t Write(char *pMessage, unsigned int uiLength);

	//将读指针指到填充字段之后
    ReturnCode_t FindPad();

	ReturnCode_t SetDDSInfo(int iDomainCount);

	int	GetDDSInfo();

private:
    //缓冲区大小
    unsigned int m_uiLength;

    //读指针位置
    unsigned int m_uiReadPosition;

    //写指针位置
    unsigned int m_uiWritePosition;

    //缓冲区 一个循环的空间
    char *m_pBuffer;

	//现有可写空间
	unsigned int m_uiAvailableLength;

	/* Nephalem 缓冲区互斥锁 */
	uLinX_SemMutex*  m_bufferMutex;

	/* Nephalem 信号量，判断是否有缓冲区可用 */
	uLinX_SemAphore* m_bufferAphore;

	int m_iDomainCount;

};

#endif
