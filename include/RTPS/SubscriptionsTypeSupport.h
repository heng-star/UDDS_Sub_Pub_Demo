/************************************************************
** 文件名：ParticipantDataTypeSupport.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：ParticipantDataTypeSupport头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_SubscriptionsTYPESUPPORT_H_INCLUDED_ 
#define _DDS_SubscriptionsTYPESUPPORT_H_INCLUDED_

#include <string>
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
#include "DDS/DomainParticipant.h"
class DomainParticipant;

class SubscriptionsTypeSupport : public TypeSupport 
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
        return "SubscriptionBuiltinTopicData";
    }
};

#endif
