/************************************************************
** �ļ�����PublicationsDataReader.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����PublicationsDataReaderͷ�ļ�
** ��  ����Version 0.1
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
	/* Nephalem ���캯�� */
	PublicationsDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem �������� */
	virtual ~PublicationsDataReader();

	/* Nephalem ����ת�� */
	static PublicationsDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  ��DataReader������һ��֮ǰδ���ʹ���Dataֵ������DataReader�С�ɾ��������ʹ�䲻�ٿɷ��� */
	ReturnCode_t take_next_sample(DiscoveredWriterData& data, SampleInfo& sampleInfo);

	/* Nephalem ����SerializedData���� */
	ReturnCode_t InterpretSPDPdiscoveredWriterData(char* pSerializedData, DiscoveredWriterData& data);
};

#endif
