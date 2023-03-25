/************************************************************
** 文件名：SubscriptionsDataWriter.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-04-21
** 修改人：无
** 日  期：无
** 描  述：SubscriptionsDataWriter头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_SUBSCRIPTIONSDATAWRITER_H_INCLUDED_
#define _DDS_SUBSCRIPTIONSDATAWRITER_H_INCLUDED_

/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "DDS/DataWriter.h"
/* Nephalem 系统头文件 */

/* Nephalem 前置声明 */
class DataWriterImpl;

class SubscriptionsDataWriter : public DataWriter
{
public:
	/* Nephalem 构造函数 */
	SubscriptionsDataWriter(DataWriterImpl* pDataWriterImpl);

	/* Nephalem 析构函数 */
	virtual ~SubscriptionsDataWriter();

	/* Nephalem 类型转换 */
	static SubscriptionsDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(DiscoveredReaderData& discoverReaderData);
private:
	char pData[2048];

};

#endif
