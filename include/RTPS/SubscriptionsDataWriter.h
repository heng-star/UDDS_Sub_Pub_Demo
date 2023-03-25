/************************************************************
** �ļ�����SubscriptionsDataWriter.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-04-21
** �޸��ˣ���
** ��  �ڣ���
** ��  ����SubscriptionsDataWriterͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_SUBSCRIPTIONSDATAWRITER_H_INCLUDED_
#define _DDS_SUBSCRIPTIONSDATAWRITER_H_INCLUDED_

/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "DDS/DataWriter.h"
/* Nephalem ϵͳͷ�ļ� */

/* Nephalem ǰ������ */
class DataWriterImpl;

class SubscriptionsDataWriter : public DataWriter
{
public:
	/* Nephalem ���캯�� */
	SubscriptionsDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem �������� */
	virtual ~SubscriptionsDataWriter();

	/* Nephalem ����ת�� */
	static SubscriptionsDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(DiscoveredReaderData& discoverReaderData);
private:
	char pData[2048];

};

#endif
