/************************************************************
** �ļ�����Message.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-15
** �޸��ˣ���
** ��  �ڣ���
** ��  ����Messageͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _RTPS_MESSAGE_H_INCLUDED_
#define _RTPS_MESSAGE_H_INCLUDED_

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include <bitset>

using std::bitset;

const unsigned int DATAMESSAGE_LIMIT = 63 * 1024;

/**
* @ brief �����ӱ���Ԫ�� SubmessageElement
*/

struct _RECEIVER
{
	ProtocolVersion_t SourceVersion;
	VendorId_t SourceVendorId;
	guidPrefix_t SourceGuidPrefix;
	guidPrefix_t DestGuidPrefix;
	_LOCATOR_LIST_T UnicastReplyLocatorList;
	_LOCATOR_LIST_T MulticastReplyLocatorList;
	bool bHaveTimestame;
	Time_t Timestamp;
};


struct _SEQUENCE_NUMBER_SET 
{
    SequenceNumber_t BitmapBase;
	//*Nephalem 
	//numBit��ʾ��BitmapBase-1�����Чλ
	unsigned int numBit;
    unsigned int bitmap[8];

	_SEQUENCE_NUMBER_SET(): numBit(0)
	{
		memset(bitmap, 0, 32);
	}
};

struct _FRAGMENT_NUMBER_SET 
{
	unsigned int uiBitmapBase;
	unsigned int uiNumBit;
	unsigned int bitmap[8];

	_FRAGMENT_NUMBER_SET() : uiBitmapBase(0), uiNumBit(0)
	{
		memset(bitmap, 0, 32);
	}
};

typedef Time_t _TIME_STAMP;

typedef _COUNT_T _COUNT;
typedef char* SerializedPayload;

/**
* @ brief ���屨������
*/
typedef Octet _SUBMESSAGE_KIND;
const _SUBMESSAGE_KIND PAD             = 0x01;
const _SUBMESSAGE_KIND ACKNACK         = 0x06;
const _SUBMESSAGE_KIND HEARTBEAT       = 0x07;
const _SUBMESSAGE_KIND GAP             = 0x08;
const _SUBMESSAGE_KIND INFO_TS         = 0x09;
const _SUBMESSAGE_KIND INFO_SRC        = 0x0c;
const _SUBMESSAGE_KIND INFO_REPLY_IP4  = 0x0d;
const _SUBMESSAGE_KIND INFO_DST        = 0x0e;
const _SUBMESSAGE_KIND INFO_REPLY      = 0x0f;
const _SUBMESSAGE_KIND NACK_FRAG       = 0x12;
const _SUBMESSAGE_KIND HEARTBEAT_FRAG  = 0x13;
const _SUBMESSAGE_KIND DATA            = 0x15;
const _SUBMESSAGE_KIND DATA_FRAG       = 0x16;

/**
* @ brief ����Э��
*/
typedef char _PROTOCOLID_T[4];
#define PROTOCOL_RTPS "RTPS"


/**
* @ brief ���屨��ͷ_MESSAGE_HEADER
*/ 
struct _MESSAGE_HEADER 
{
    _PROTOCOLID_T Protocol;
    ProtocolVersion_t Version;
    VendorId_t VendorId;
    guidPrefix_t GuidPrefix;
};

/**
* @ brief �����ӱ���ͷ _SUBMESSAGE_HEADER
*/ 
typedef Octet _SUBMESSAGE_FLAG;
struct _SUBMESSAGE_HEADER 
{
    _SUBMESSAGE_KIND SubmessageId;
    //Flag ��һλʼ��Ϊ EndiannessFlag ������λ���ݱ������Ͷ���
    _SUBMESSAGE_FLAG Flag;
    unsigned short usSubmessageLength;

	_SUBMESSAGE_HEADER()
	{
		SubmessageId = 0;
		Flag = 0;
		usSubmessageLength = 0;
	}
};

/**
* @ brief ����AckNack�ӱ���
* @       Header��Flag�ڶ�λΪ FinalFlag
*/
#pragma pack(4)
struct _ACKNACK_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    _SEQUENCE_NUMBER_SET ReaderSNState;
    _COUNT Count;
};
#pragma pack()

//#define PID_PAD         0
//#define PID_SENTINEL    1
//#define PID_STATUS_INFO 0x0071
//#define PID_KEY_HASH    0x0070
//DISPOSED
//const Parameter D = {PID_STATUS_INFO, 4, {0x00, 0x00, 0x00, 0x01}};
//UNREGISTERED
//const Parameter U = {PID_STATUS_INFO, 4, {0x00, 0x00, 0x00, 0x02}};


/**
* @ brief ����Data�ӱ���
* @       Header��Flag�ڶ�λΪ InlineQosFlag //�ݲ�ʵ��
* @       ����λΪ DataFlag
* @       ����λΪ KeyFlag
*/
struct _DATA_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    _SUBMESSAGE_FLAG ExtraFlags[2];
    unsigned short usOctetsToInlineQos;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    SequenceNumber_t WriterSN;

	/* Nephalem Ϊ�˷������Data�ӱ������ݳ��� */
	/* Nephalem Data�����в���һ���� InlineQos��SerializedPayload 
				����������������������� */
	//_PARAMETER_LIST InlineQos; 
	//SerializedPayload SerializedPayload;
};

/**
* @ brief ����Heartbeat�ӱ���
* @       Header��Flag�ڶ�λΪ FinalFlag
* @       ����λΪ LivenessFlag
*/
struct _HEARTBEAT_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    SequenceNumber_t FirstSN;
    SequenceNumber_t LastSN;
    _COUNT Count;		/* JDXCZ 2022-0720 ��˴����͵�Countֵ*/
};

/**
* @ brief ����InfoDestination�ӱ���
*/
struct _INFO_DESTINATION_SUBMESSAGE {
    _SUBMESSAGE_HEADER Header;
    guidPrefix_t GuidPrefix;
};

/**
* @ brief ����InfoReply�ӱ���
* @       Header��Flag�ڶ�λΪ MulticastFlag
*/
struct _INFO_REPLY_SUBMESSAGE 
{
    //_SUBMESSAGE_HEADER Header;
    //_LOCATORLIST UnicastLocatorList;
    //_LOCATORLIST MulticastLocatorList;
};

/**
* @ brief ����InfoReplyIp4�ӱ���
* @       Header��Flag�ڶ�λΪ MulticastFlag
*/
/*
struct InfoReplySubmessage {
_SUBMESSAGE_HEADER Header;
LocatorUDPv4_t UnicastLocatorList;
LocatorUDPv4_t MulticastLocatorList;
};
*/

/**
* @ brief ����InfoSource�ӱ���
*/
struct _INFO_SOURCE 
{
    _SUBMESSAGE_HEADER Header;
    long lUnused;
    ProtocolVersion_t Version;
    VendorId_t VendorId;
	guidPrefix_t GuidPrefix;
};

/**
* @ brief ����InfoTimestamp�ӱ���
* @       Header��Flag�ڶ�λΪ InvalidateFlag
*/
struct _INFO_TIME_STAMP 
{
    _SUBMESSAGE_HEADER Header;
    _TIME_STAMP Timestamp;
};

struct _DATA_FRAG
{
	unsigned int uiFragmentStartingNum; //��Ƭ����ʼfrag�ķ�Ƭ��
	unsigned short usFragmentsInSubmessage; //��Ƭ�а�����frag����
	unsigned short usFragmentSize; //ÿ����Ƭ�Ĵ�С
	unsigned int uiSampleSize; //����ԭʼ��С
};
/**
* @ brief ����DataFrag�ӱ���
* @       Header��Flag�ڶ�λΪ InlineQosFlag //�ݲ�ʵ��
* @       ����λΪ DataFlag
* @       ����λΪ KeyFlag
*/
struct _DATA_FRAG_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    _SUBMESSAGE_FLAG ExtraFlags[2];
    unsigned short usOctetsToInlineQos;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    SequenceNumber_t WriterSN;

 //   _PARAMETER_LIST InlineQos; //
 //   SerializedPayload SerializedPayload;
};

/**
* @ brief ����NackFrag�ӱ���
* @       Header��Flag��һλΪ EndiannessFlag
* @       Header��Flag�ڶ�λΪ InvalidateFlag
*/
struct _NACK_FRAG_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    EntityId_t ReaderId;
    EntityId_t WriterId;
	SequenceNumber_t WriterSN;
    _FRAGMENT_NUMBER_SET FragmentNState;
    _COUNT Count;
};

/**
* @ brief ����GAP�ӱ���
* @       Header��Flag��һλΪ EndiannessFlag
* @       Header��Flag�ڶ�λΪ InvalidateFlag
*/
struct _GAP_SUBMESSAGE
{
	_SUBMESSAGE_HEADER Header;
	EntityId_t ReaderId;
	EntityId_t WriterId;
	SequenceNumber_t GapStart;
	_SEQUENCE_NUMBER_SET GapList;
};

#endif

