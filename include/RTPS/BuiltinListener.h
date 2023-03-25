/************************************************************
** �ļ�����BuiltinListener.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-18
** �޸��ˣ���
** ��  �ڣ���
** ��  ����BuiltinListenerͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_BUILTIN_LISTENER_H_INCLUDED_
#define _RTPS_BUILTIN_LISTENER_H_INCLUDED_

#include "BasicTypes.h"
#include "ReturnCode.h"
#include "DDS/Listener/DataWriterListener.h"
#include "DDS/Listener/DataReaderListener.h"

class DataWriter;
class DataReader;

//class BuiltinPariticipantWriterListener : public DataWriterListener
//{
//public:
//    BuiltinPariticipantWriterListener() {};
//    virtual ~BuiltinPariticipantWriterListener() {};
//    ReturnCode_t On_Offered_Deadline_Missed( DataWriter* pBuiltinParticipantWriter, const _OFFERED_DEADLINE_MISSED_STATUS& Status);
//};
//
////2013-10-14 hjy modify
//class BuiltinPublicationsWriterListener : public DataWriterListener
//{
//public:
//	BuiltinPublicationsWriterListener() {};
//	virtual ~BuiltinPublicationsWriterListener() {};
//	ReturnCode_t On_Offered_Deadline_Missed( DataWriter* pBuiltinPublicationsWriter, const _OFFERED_DEADLINE_MISSED_STATUS& Status);
//};
//
////2013-10-14 hjy modify
//class BuiltinSubscriptionsWriterListener : public DataWriterListener
//{
//public:
//	BuiltinSubscriptionsWriterListener() {};
//	virtual ~BuiltinSubscriptionsWriterListener() {};
//	ReturnCode_t On_Offered_Deadline_Missed( DataWriter* pBuiltinPSubscriptionsWriter, const _OFFERED_DEADLINE_MISSED_STATUS& Status);
//};
//
//class BuiltinPariticipantReaderListener : public DataReaderListener
//{
//public:
//    BuiltinPariticipantReaderListener() {};
//    virtual ~BuiltinPariticipantReaderListener() {};
//    ReturnCode_t  on_data_available( DataReader* pBuiltinParticipantReader);
//};
//
//class BuiltinPublicationsReaderListener : public DataReaderListener
//{
//public:
//    BuiltinPublicationsReaderListener() {};
//    virtual ~BuiltinPublicationsReaderListener() {};
//    ReturnCode_t  on_data_available( DataReader* pBuiltinPublicationsReader);
//};
//
//class BuiltinSubscriptionsReaderListener : public DataReaderListener
//{
//public:
//    BuiltinSubscriptionsReaderListener() {};
//    virtual ~BuiltinSubscriptionsReaderListener() {};
//    ReturnCode_t  on_data_available( DataReader* pBuiltinSubscriptionsReader);
//};

#endif
