/************************************************************
** 文件名：HistoryCache.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-15
** 修改人：无
** 日  期：无
** 描  述：HistoryCache头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _CACHE_HISTORYCACHE_H_INCLUDED_
#define _CACHE_HISTORYCACHE_H_INCLUDED_


/* Nephalem 用户头文件 */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "uLinxDataType.h"
/* Nephalem 系统头文件 */

#include <map>
using std::map;
/* Nephalem 前置声明 */
class uLinX_SemMutex;
class uLinX_SemAphore;

class HistoryCache 
{
public:
    HistoryCache(unsigned long ulLength);
    virtual ~HistoryCache();

    //写入
    ReturnCode_t AddChange(_CACHE_CHANGE *W_CacheChange);
    //删除
    ReturnCode_t RemoveChange(SequenceNumber_t SeqNum);

    /* Nephalem 获取数据，返回值设置为const，防止在外部释放数据 */
    const _CACHE_CHANGE *GetChange(SequenceNumber_t SeqNum);

	/* Nephalem 取走数据，用完后返还，防止数据在使用是被删除或者修改 */
	_CACHE_CHANGE *takeChange(const SequenceNumber_t& SeqNum);

	/* Nephalem 将take的数据返还，假如该change位置已经不存在，则将数据删除 */
	ReturnCode_t return_loan_change(_CACHE_CHANGE * pCacheChange);

    /* Nephalem 获取缓冲区中数据序列号最小值 但是该序号可能没有数据 */
    SequenceNumber_t GetSeqNumMin();
    /* Nephalem 获取缓冲区中数据序列号最大值 但是该序号可能没有数据 */
    SequenceNumber_t GetSeqNumMax();

	/* Nephalem 获取可用的数据序列的最小编号 */
	SequenceNumber_t GetAvailableSeqNumMin();
	/* Nephalem 获取可用的数据缓冲的最大编号 */
	SequenceNumber_t GetAvailableSeqNumMax();

public:
	/* Nephalem 自定义接口 */
	/* Nephalem 获取缓冲区的总大小 */
	unsigned int GetCacheLength();

	/* Nephalem 获取可用数据的数量，已被take但是未return不统计在内 */
	unsigned int getUserDataNum();

	/* Nephalem 获取map的第N个数据的SeqNumber */
	SequenceNumber_t getUseDataSeqNum(unsigned int iNumber);

	/* Nephalem 判断缓冲区是否已满 */
	bool isFull();

	/* Nephalem 获取缓存中的第一个数据 */
	const _CACHE_CHANGE *GetFirstChange();

	ReturnCode_t SetDomainId(int iDomainCount,string TopicName);

	/* Nephalem 检查数据lifespan */
	void checkLifeSpan();

private:

	/* Nephalem 存放_CACHE_CHANG*，que增删效率高 */
	map<SequenceNumber_t,_CACHE_CHANGE*> m_ChangesMap;
    
	/* Nephalem 缓冲区总大小 */
    unsigned int m_uiCacheLength;

	/* Nephalem 缓冲区已用大小 已被take但是未return不统计在内 */
	unsigned int  m_uiCacheNum;

    /* Nephalem 保护m_ChangesDeque操作的互斥锁*/
	uLinX_SemMutex* m_ChangesMapMutex;

    //计数器信号量 表示是否有可用空间
	uLinX_SemAphore* m_ChangesMapSemAphore;

	int m_iDomainCount;

	string m_strTopicName;

};

#endif
