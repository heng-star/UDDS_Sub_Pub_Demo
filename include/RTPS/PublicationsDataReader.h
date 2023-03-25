/************************************************************
** 文件名：PublicationsDataReader.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：PublicationsDataReader头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_PUBLICATIONSDATAREADER_H_INCLUDED_
#define _DDS_PUBLICATIONSDATAREADER_H_INCLUDED_

#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DataReader.h"
#include "RTPS/ParticipantDataReader.h"

class PublicationsDataManager;
class Subscriber;
class DomainParticipant;
class ParticipantDataReader;
class ParticipantDataManager;

//typedef list<Publications> PublicationsSeq;

class PublicationsDataReader : public DataReader
{
public:
	/* Nephalem 构造函数 */
	PublicationsDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem 析构函数 */
	virtual ~PublicationsDataReader();

	/* Nephalem 类型转换 */
	static PublicationsDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  从DataReader复制下一个之前未访问过的Data值，并从DataReader中“删除”它，使其不再可访问 */
	ReturnCode_t take_next_sample(DiscoveredWriterData& data, SampleInfo& sampleInfo);

	/* Nephalem 解析SerializedData数据 */
	ReturnCode_t InterpretSPDPdiscoveredWriterData(char* pSerializedData, DiscoveredWriterData& data);
};

#endif
