/************************************************************
** �ļ�����PublicationsDataWriter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����PublicationsDataWriterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_PUBLICATIONSDATAWRITER_H_INCLUDED_
#define _DDS_PUBLICATIONSDATAWRITER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "DDS/DataWriter.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DataWriterImpl;

class PublicationsDataWriter : public DataWriter
{
public:
	/* Nephalem ���캯�� */
	PublicationsDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem �������� */
	virtual ~PublicationsDataWriter();

	/* Nephalem ����ת�� */
	static PublicationsDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(DiscoveredWriterData& discoverWriterData);
private:
	char pData[2048];
};

#endif
