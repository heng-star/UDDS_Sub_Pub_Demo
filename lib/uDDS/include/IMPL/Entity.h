/************************************************************
** �ļ�����Entity.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-17
** �޸��ˣ���
** ��  �ڣ���
** ��  ����Entityͷ�ļ�
** ��  ����Version 0.1
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
    ////QoS����
    //_ENTITY_QOS* m_pQos;
    ////������ָ��
    //DDSListener* m_pListener;

public:
    Entity() {};

    virtual ~Entity() {};

public:
	/* Nephalem �淶�ж���Ľӿ� ��Щ�ӿڿ��ܶ����ṩ������淶����һ�� */

	//virtual ReturnCode_t set_qos(const _ENTITY_QOS& pQos) = 0;

	//virtual ReturnCode_t get_qos(_ENTITY_QOS& pQos) = 0;

	//virtual ReturnCode_t set_listener(const DDSListener* a, StatusMask Mask) = 0;

	//virtual DDSListener* get_listener() = 0;

	//virtual StatusCondition get_statuscondition() = 0;

	//virtual StatusKind get_status_change() = 0;

	//virtual ReturnCode_t enable() = 0;

	//virtual InstanceHandle_t get_instance_handle() = 0;

    //����QoS����
	/* Nephalem �˴���Ҫ�淶������ �Ķ��϶࣬�Ȳ��� */
	//virtual ReturnCode_t SetQos(_ENTITY_QOS* pQos) { return 0; };

	//virtual _ENTITY_QOS* GetQos() { return 0; };
 //   //���ü�����
 //   virtual ReturnCode_t SetListener(DDSListener *pListener, StatusMask Mask) =0;
 //   //��ȡ������
 //   virtual DDSListener* GetListener() = 0;

};

#endif
