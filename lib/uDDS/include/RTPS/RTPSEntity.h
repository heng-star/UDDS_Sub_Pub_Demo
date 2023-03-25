/************************************************************
** 文件名：RTPSEntity.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-10
** 修改人：无
** 日  期：无
** 描  述：RTPSEntity头文件
** 版  本：Version 0.1
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

    //返回GUID
    GUID_t Guid () 
    {
        return m_Guid;
    }
    //返回EntityId_t
    EntityId_t entityId () 
    {
        return m_Guid.entityId;
    }

protected:
    //GUID
    GUID_t m_Guid;
};

#endif
