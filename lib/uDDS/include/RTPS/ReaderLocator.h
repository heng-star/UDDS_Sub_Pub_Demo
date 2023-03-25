#ifndef RTPS_READERLOCATOR_INCLUDED_H
#define RTPS_READERLOCATOR_INCLUDED_H

#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "ReturnCode.h"
#include "RTPS/Message.h"

class StatelessWriter;
class HistoryCache;

class ReaderLocator{
public:

	ReaderLocator() {};
    //构造函数
    ReaderLocator(Locator_t locator,bool expectsInlineQos);

 //   //析构函数
 //   virtual ~ReaderLocator();

	//ChangeForReader next_requested_change();

	//ChangeForReader next_unsent_change();

	//_CACHE_CHANGE_LIST_T requested_changes();

	//_CACHE_CHANGE_LIST_T unsent_changes();

	//requested_changes_set();

	unsigned int addLocatorCount();

	unsigned int reduceLocatorCount();

	bool isOneLocatorCount();
private:
	/* Nephalem 规范中定义的变量 */
	/* Nephalem 远端Reader在此ReaderLocator上请求的writer的HistoryCache 数据列表。*/
	_CACHE_CHANGE_LIST_T m_RequestedChanges;

	/* Nephalem writer的HistoryCache中还未发送到该ReaderLocator的数据列表 */
	_CACHE_CHANGE_LIST_T m_UnsentChanges;

	/* Nephalem Reader的接收地址 */
	Locator_t			 m_Locator;

	/* Nephalem 使用此地址的DataReader的数量 */
	unsigned int         m_LocatorCount;
};

#endif
