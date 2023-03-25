/************************************************************
** �ļ�����ParticipantDataTypeSupport.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ParticipantDataTypeSupportͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_ParticipantDataTypeSupport_H_INCLUDED_ 
#define _DDS_ParticipantDataTypeSupport_H_INCLUDED_

#include <string>
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
#include "DDS/DomainParticipant.h"
class DomainParticipant;

class ParticipantDataTypeSupport : public TypeSupport 
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
        return "SPDPdiscoveredParticipantData";
    }
};

#endif
