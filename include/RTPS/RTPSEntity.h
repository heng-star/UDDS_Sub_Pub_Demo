/************************************************************
** �ļ�����RTPSEntity.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-10
** �޸��ˣ���
** ��  �ڣ���
** ��  ����RTPSEntityͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_RTPSENTITY_H_INCLUDED_
#define _RTPS_RTPSENTITY_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"

class RTPSEntity 
{
public:
    RTPSEntity ( GUID_t AGuid ) 
    {
        m_Guid = AGuid;
    }

    virtual ~RTPSEntity () 
    {
    };

    //����GUID
    GUID_t Guid () 
    {
        return m_Guid;
    }
    //����EntityId_t
    EntityId_t entityId () 
    {
        return m_Guid.entityId;
    }

protected:
    //GUID
    GUID_t m_Guid;
};

#endif
