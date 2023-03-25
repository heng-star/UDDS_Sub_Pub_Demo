/************************************************************
** 文件名：Endpoint.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-10
** 修改人：无
** 日  期：无
** 描  述：Endpoint头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_ENDPOINT_H_INCLUDED_
#define _RTPS_ENDPOINT_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/RTPSEntity.h"
#include "QoSPolicy.h"


class Endpoint : public RTPSEntity 
{
public:
    //构造函数
    Endpoint ( GUID_t Guid) :
    RTPSEntity (Guid) 
    {
    }

    //析构函数
    virtual ~Endpoint () 
    {
        m_UnicastLocatorList.clear();
        m_MulticastLocatorList.clear();
    };


    virtual Time_t Deadline() 
    {
        return TIME_INFINITE;
    }

    //虚函数 检查Deadline QoS的接口
    virtual ReturnCode_t DeadlineCheck() 
    {
        return RETCODE_OK;
    };

    /* Nephalem 获取单播地址列表 */
	_LOCATOR_LIST_T getUnicastLocatorList();


	/* Nephalem 设置本地使用的Ip */
	void setUnicastLocatorList(_LOCATOR_LIST_T& unicastLocator);

    //获取多播地址列表
    _LOCATOR_LIST_T MulticastLocatorListGet()
    {
        return m_MulticastLocatorList;
    }


    //获取端点的可靠程度
    _RELIABILITY_KIND_T ReliabilityKind() 
    {
        return m_ReliabilityLevel;
    }

protected:
	/* Nephalem 规范中定义的变量 */
	//主题类型，是否有键
	_TOPIC_KIND_T m_TopicKind;

    //可靠程度
    _RELIABILITY_KIND_T m_ReliabilityLevel;

    /* 单播地址列表 */
    _LOCATOR_LIST_T m_UnicastLocatorList;

    //多播地址列表
    _LOCATOR_LIST_T m_MulticastLocatorList;

};

#endif
