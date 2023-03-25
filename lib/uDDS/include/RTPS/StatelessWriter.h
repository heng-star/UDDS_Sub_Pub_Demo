#ifndef _RTPS_STATELESSWRITER_INCLUDED_H
#define _RTPS_STATELESSWRITER_INCLUDED_H

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Writer.h"
#include "RTPS/Message.h"

class RequestScheduler;
class ReaderLocator;

typedef map<Locator_t, ReaderLocator> _READER_LOCATOR_MAP;

class StatelessWriter : public Writer{
public:
    //构造函数
    StatelessWriter(GUID_t            Guid,
		const DataWriterQos&	dataWriterQoS,
		RequestScheduler  **pScheduleList);

    //析构函数
    virtual ~StatelessWriter();
	/* Nephalem 规范中定义的接口 */
	//添加匹配的订阅端地址
	ReturnCode_t reader_locator_add(const Locator_t& pLocator);

	//删除匹配订阅端地址
	ReturnCode_t reader_locator_remove(const Locator_t& locator);

	/* Nephalem 重置订阅端中的待发送数据编号 */
	//ReturnCode_t unsent_changes_rest();

public:
	/* Nephalem 自定义接口 */

	/* Nephalem 数据发送操作 */
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange);

	/* Nephalem 获取匹配上的DataReader的数量 */
	virtual unsigned int GetMatchDataReaderNum();

	/* Nephalem 获取Locator列表 */
	_READER_LOCATOR_MAP GetLocatorList();

	/* Nephalem 非可靠模式下，该接口目前的调用实际没效果 */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq);

private:
    
	_READER_LOCATOR_MAP m_MatchedLocatorMap;

};

#endif
