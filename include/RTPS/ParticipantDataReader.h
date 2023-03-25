/************************************************************
** 文件名：ParticipantDataReader.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：ParticipantDataReader头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_PARTICIPANTDATAREADER_H_INCLUDED_
#define _DDS_PARTICIPANTDATAREADER_H_INCLUDED_

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "DDS/DataReader.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */


class ParticipantDataReader : public DataReader 
{
public:
	/* Nephalem 构造函数 */
	ParticipantDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem 析构函数 */
	virtual ~ParticipantDataReader();

	/* Nephalem 类型转换 */
	static ParticipantDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  从DataReader复制下一个之前未访问过的Data值，并从DataReader中“删除”它，使其不再可访问 */
	ReturnCode_t take_next_sample(SPDPdiscoveredParticipantData& data, SampleInfo& sampleInfo);

	/* Nephalem 解析SerializedData数据 */
	ReturnCode_t InterpretSPDPdiscoveredParticipantData(char* pSerializedData, SPDPdiscoveredParticipantData& data);
	
};

#endif
