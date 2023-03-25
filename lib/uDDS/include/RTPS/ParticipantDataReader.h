/************************************************************
** �ļ�����ParticipantDataReader.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ParticipantDataReaderͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_PARTICIPANTDATAREADER_H_INCLUDED_
#define _DDS_PARTICIPANTDATAREADER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "DDS/DataReader.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */


class ParticipantDataReader : public DataReader 
{
public:
	/* Nephalem ���캯�� */
	ParticipantDataReader(DataReaderImpl* pDataReaderImpl);

	/* Nephalem �������� */
	virtual ~ParticipantDataReader();

	/* Nephalem ����ת�� */
	static ParticipantDataReader* narrow(DataReader* pDataReader);

	/* Nephalem  ��DataReader������һ��֮ǰδ���ʹ���Dataֵ������DataReader�С�ɾ��������ʹ�䲻�ٿɷ��� */
	ReturnCode_t take_next_sample(SPDPdiscoveredParticipantData& data, SampleInfo& sampleInfo);

	/* Nephalem ����SerializedData���� */
	ReturnCode_t InterpretSPDPdiscoveredParticipantData(char* pSerializedData, SPDPdiscoveredParticipantData& data);
	
};

#endif
