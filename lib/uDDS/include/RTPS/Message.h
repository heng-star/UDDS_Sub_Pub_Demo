/************************************************************
** 文件名：Message.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-15
** 修改人：无
** 日  期：无
** 描  述：Message头文件
** 版  本：Version 0.1
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
* @ brief 定义子报文元素 SubmessageElement
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
	//numBit表示从BitmapBase-1起的有效位
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
* @ brief 定义报文类型
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
* @ brief 定义协议
*/
typedef char _PROTOCOLID_T[4];
#define PROTOCOL_RTPS "RTPS"


/**
* @ brief 定义报文头_MESSAGE_HEADER
*/ 
struct _MESSAGE_HEADER 
{
    _PROTOCOLID_T Protocol;
    ProtocolVersion_t Version;
    VendorId_t VendorId;
    guidPrefix_t GuidPrefix;
};

/**
* @ brief 定义子报文头 _SUBMESSAGE_HEADER
*/ 
typedef Octet _SUBMESSAGE_FLAG;
struct _SUBMESSAGE_HEADER 
{
    _SUBMESSAGE_KIND SubmessageId;
    //Flag 第一位始终为 EndiannessFlag 其他各位根据报文类型而定
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
* @ brief 定义AckNack子报文
* @       Header中Flag第二位为 FinalFlag
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
* @ brief 定义Data子报文
* @       Header中Flag第二位为 InlineQosFlag //暂不实现
* @       第三位为 DataFlag
* @       第四位为 KeyFlag
*/
struct _DATA_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    _SUBMESSAGE_FLAG ExtraFlags[2];
    unsigned short usOctetsToInlineQos;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    SequenceNumber_t WriterSN;

	/* Nephalem 为了方便计算Data子报文数据长度 */
	/* Nephalem Data报文中并不一定有 InlineQos和SerializedPayload 
				将这两部剥离出来单独处理 */
	//_PARAMETER_LIST InlineQos; 
	//SerializedPayload SerializedPayload;
};

/**
* @ brief 定义Heartbeat子报文
* @       Header中Flag第二位为 FinalFlag
* @       第三位为 LivenessFlag
*/
struct _HEARTBEAT_SUBMESSAGE 
{
    _SUBMESSAGE_HEADER Header;
    EntityId_t ReaderId;
    EntityId_t WriterId;
    SequenceNumber_t FirstSN;
    SequenceNumber_t LastSN;
    _COUNT Count;		/* JDXCZ 2022-0720 向此代理发送的Count值*/
};

/**
* @ brief 定义InfoDestination子报文
*/
struct _INFO_DESTINATION_SUBMESSAGE {
    _SUBMESSAGE_HEADER Header;
    guidPrefix_t GuidPrefix;
};

/**
* @ brief 定义InfoReply子报文
* @       Header中Flag第二位为 MulticastFlag
*/
struct _INFO_REPLY_SUBMESSAGE 
{
    //_SUBMESSAGE_HEADER Header;
    //_LOCATORLIST UnicastLocatorList;
    //_LOCATORLIST MulticastLocatorList;
};

/**
* @ brief 定义InfoReplyIp4子报文
* @       Header中Flag第二位为 MulticastFlag
*/
/*
struct InfoReplySubmessage {
_SUBMESSAGE_HEADER Header;
LocatorUDPv4_t UnicastLocatorList;
LocatorUDPv4_t MulticastLocatorList;
};
*/

/**
* @ brief 定义InfoSource子报文
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
* @ brief 定义InfoTimestamp子报文
* @       Header中Flag第二位为 InvalidateFlag
*/
struct _INFO_TIME_STAMP 
{
    _SUBMESSAGE_HEADER Header;
    _TIME_STAMP Timestamp;
};

struct _DATA_FRAG
{
	unsigned int uiFragmentStartingNum; //分片中起始frag的分片号
	unsigned short usFragmentsInSubmessage; //分片中包含的frag个数
	unsigned short usFragmentSize; //每个分片的大小
	unsigned int uiSampleSize; //数据原始大小
};
/**
* @ brief 定义DataFrag子报文
* @       Header中Flag第二位为 InlineQosFlag //暂不实现
* @       第三位为 DataFlag
* @       第四位为 KeyFlag
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
* @ brief 定义NackFrag子报文
* @       Header中Flag第一位为 EndiannessFlag
* @       Header中Flag第二位为 InvalidateFlag
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
* @ brief 定义GAP子报文
* @       Header中Flag第一位为 EndiannessFlag
* @       Header中Flag第二位为 InvalidateFlag
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

