/************************************************************
** 文件名：SubscriptionsDataReader.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：SubscriptionsDataReader头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_SUBSCRIPTIONSDATAREADER_H_INCLUDED_
#define _DDS_SUBSCRIPTIONSDATAREADER_H_INCLUDED_

#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DataReader.h"
#include "RTPS/ParticipantDataReader.h"

class Topic;
class DomainParticipant;
class DataReader;
class DataWriter;
class Subscriber;
class DataReaderListener;
class SubscriptionsDataManager;
class ParticipantDataReader;
class ParticipantDataManager;

class SubscriptionsDataReader : public DataReader
{
public:
	/* Nephalem 构造函数 */
	SubscriptionsDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem 析构函数 */
	virtual ~SubscriptionsDataReader();

	/* Nephalem 类型转换 */
	static SubscriptionsDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  从DataReader复制下一个之前未访问过的Data值，并从DataReader中“删除”它，使其不再可访问 */
	ReturnCode_t take_next_sample(DiscoveredReaderData& data, SampleInfo& sampleInfo);

	/* Nephalem 解析SerializedData数据 */
	ReturnCode_t InterpretSPDPdiscoveredReaderData(char* pSerializedData, DiscoveredReaderData& data);
};

#endif
