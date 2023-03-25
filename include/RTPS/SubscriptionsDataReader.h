/************************************************************
** �ļ�����SubscriptionsDataReader.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����SubscriptionsDataReaderͷ�ļ�
** ��  ����Version 0.1
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
	/* Nephalem ���캯�� */
	SubscriptionsDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem �������� */
	virtual ~SubscriptionsDataReader();

	/* Nephalem ����ת�� */
	static SubscriptionsDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  ��DataReader������һ��֮ǰδ���ʹ���Dataֵ������DataReader�С�ɾ��������ʹ�䲻�ٿɷ��� */
	ReturnCode_t take_next_sample(DiscoveredReaderData& data, SampleInfo& sampleInfo);

	/* Nephalem ����SerializedData���� */
	ReturnCode_t InterpretSPDPdiscoveredReaderData(char* pSerializedData, DiscoveredReaderData& data);
};

#endif
