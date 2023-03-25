/************************************************************
** 文件名：Entity.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-17
** 修改人：无
** 日  期：无
** 描  述：Entity头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_ENTITY_H_INCLUDED_
#define _DDS_ENTITY_H_INCLUDED_

#include "ReturnCode.h"
#include "BasicTypes.h"

class DDSListener;

class DDS_DLL Entity 
{
protected:
    ////QoS设置
    //_ENTITY_QOS* m_pQos;
    ////监听器指针
    //DDSListener* m_pListener;

public:
    Entity() {};

    virtual ~Entity() {};

public:
	/* Nephalem 规范中定义的接口 这些接口可能对外提供，故与规范保持一致 */

	//virtual ReturnCode_t set_qos(const _ENTITY_QOS& pQos) = 0;

	//virtual ReturnCode_t get_qos(_ENTITY_QOS& pQos) = 0;

	//virtual ReturnCode_t set_listener(const DDSListener* a, StatusMask Mask) = 0;

	//virtual DDSListener* get_listener() = 0;

	//virtual StatusCondition get_statuscondition() = 0;

	//virtual StatusKind get_status_change() = 0;

	//virtual ReturnCode_t enable() = 0;

	//virtual InstanceHandle_t get_instance_handle() = 0;

    //设置QoS策略
	/* Nephalem 此处需要规范化改造 改动较多，先不改 */
	//virtual ReturnCode_t SetQos(_ENTITY_QOS* pQos) { return 0; };

	//virtual _ENTITY_QOS* GetQos() { return 0; };
 //   //设置监听器
 //   virtual ReturnCode_t SetListener(DDSListener *pListener, StatusMask Mask) =0;
 //   //获取监听器
 //   virtual DDSListener* GetListener() = 0;

};

#endif
