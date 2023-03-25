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
#ifndef _DDS_PublicationsTYPESUPPORT_H_INCLUDED_ 
#define _DDS_PublicationsTYPESUPPORT_H_INCLUDED_

#include <string>
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
#include "DDS/DomainParticipant.h"
class DomainParticipant;

class PublicationsTypeSupport : public TypeSupport 
{
public:
    static ReturnCode_t register_type(DomainParticipant* pDomainParticipant, string strTypeName) 
    {
		if (strTypeName.empty())
			strTypeName = get_type_name();

		pDomainParticipant->register_type(strTypeName);

        return RETCODE_OK;
    }

    static string get_type_name()
    { 
        return "PublicationBuiltinTopicData";
    }
};

#endif
