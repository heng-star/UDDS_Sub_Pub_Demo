/************************************************************
** 文件名：ParticipantDataWriter.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：ParticipantDataWriter头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/

#ifndef _DDS_PARTICIPANTDATAWRITER_H_INCLUDED_
#define _DDS_PARTICIPANTDATAWRITER_H_INCLUDED_

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DataWriter.h"
#include "RTPSBasicTypes.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
class DataWriterImpl;
class ParticipantDataWriter : public DataWriter
{
public:
	/* Nephalem 构造函数 */
	ParticipantDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem 析构函数 */
	virtual ~ParticipantDataWriter();

	/* Nephalem 类型转换 */
	static ParticipantDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(SPDPdiscoveredParticipantData& participantData);
private:
	char pData[2048];
};

#endif
