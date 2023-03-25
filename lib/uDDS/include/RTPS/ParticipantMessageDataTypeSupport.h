/************************************************************
** �ļ�����ParticipantDataTypeSupport.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2022-04-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ParticipantMessageDataTypeSupportͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_ParticipantMessageDataTypeSupport_H_INCLUDED_ 
#define _DDS_ParticipantMessageDataTypeSupport_H_INCLUDED_

#include <string>
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
#include "DDS/DomainParticipant.h"
class DomainParticipant;

class ParticipantMessageDataTypeSupport : public TypeSupport 
{
public:
    static ReturnCode_t register_type(DomainParticipant* pDomainParticipant, string strTypeName) 
    {
		if (strTypeName.empty())
			strTypeName = get_type_name();

		return pDomainParticipant->register_type(strTypeName);
    }

    static string get_type_name() 
    { 
        return "ParticipantMessageData";
    }
};

#endif
