/************************************************************
** �ļ�����ParticipantDataWriter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ParticipantDataWriterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/

#ifndef _DDS_PARTICIPANTDATAWRITER_H_INCLUDED_
#define _DDS_PARTICIPANTDATAWRITER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DataWriter.h"
#include "RTPSBasicTypes.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DataWriterImpl;
class ParticipantDataWriter : public DataWriter
{
public:
	/* Nephalem ���캯�� */
	ParticipantDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem �������� */
	virtual ~ParticipantDataWriter();

	/* Nephalem ����ת�� */
	static ParticipantDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(SPDPdiscoveredParticipantData& participantData);
private:
	char pData[2048];
};

#endif
