/************************************************************
** �ļ�����ParticipantDataWriter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2022-04-13
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ParticipantMessageDataWriterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/

#ifndef _DDS_PARTICIPANTMESSAGEDATAWRITER_H_INCLUDED_
#define _DDS_PARTICIPANTMESSAGEDATAWRITER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "DDS/DataWriter.h"
#include "RTPSBasicTypes.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DataWriterImpl;
class ParticipantMessageDataWriter : public DataWriter
{
public:
	/* Nephalem ���캯�� */
	ParticipantMessageDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem �������� */
	virtual ~ParticipantMessageDataWriter();

	/* Nephalem ����ת�� */
	static ParticipantMessageDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(ParticipantMessageData& participantData);
private:
	char pData[2048];
};

#endif
