/************************************************************
** �ļ�����Endpoint.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-10
** �޸��ˣ���
** ��  �ڣ���
** ��  ����Endpointͷ�ļ�
** ��  ����Version 0.1
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
    //���캯��
    Endpoint ( GUID_t Guid) :
    RTPSEntity (Guid) 
    {
    }

    //��������
    virtual ~Endpoint () 
    {
        m_UnicastLocatorList.clear();
        m_MulticastLocatorList.clear();
    };


    virtual Time_t Deadline() 
    {
        return TIME_INFINITE;
    }

    //�麯�� ���Deadline QoS�Ľӿ�
    virtual ReturnCode_t DeadlineCheck() 
    {
        return RETCODE_OK;
    };

    /* Nephalem ��ȡ������ַ�б� */
	_LOCATOR_LIST_T getUnicastLocatorList();


	/* Nephalem ���ñ���ʹ�õ�Ip */
	void setUnicastLocatorList(_LOCATOR_LIST_T& unicastLocator);

    //��ȡ�ಥ��ַ�б�
    _LOCATOR_LIST_T MulticastLocatorListGet()
    {
        return m_MulticastLocatorList;
    }


    //��ȡ�˵�Ŀɿ��̶�
    _RELIABILITY_KIND_T ReliabilityKind() 
    {
        return m_ReliabilityLevel;
    }

protected:
	/* Nephalem �淶�ж���ı��� */
	//�������ͣ��Ƿ��м�
	_TOPIC_KIND_T m_TopicKind;

    //�ɿ��̶�
    _RELIABILITY_KIND_T m_ReliabilityLevel;

    /* ������ַ�б� */
    _LOCATOR_LIST_T m_UnicastLocatorList;

    //�ಥ��ַ�б�
    _LOCATOR_LIST_T m_MulticastLocatorList;

};

#endif
