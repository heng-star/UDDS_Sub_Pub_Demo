/************************************************************
** �ļ�����HistoryCache.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-15
** �޸��ˣ���
** ��  �ڣ���
** ��  ����HistoryCacheͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _CACHE_HISTORYCACHE_H_INCLUDED_
#define _CACHE_HISTORYCACHE_H_INCLUDED_


/* Nephalem �û�ͷ�ļ� */
#include "ReturnCode.h"
#include "BasicTypes.h"
#include "RTPSBasicTypes.h"
#include "uLinxDataType.h"
/* Nephalem ϵͳͷ�ļ� */

#include <map>
using std::map;
/* Nephalem ǰ������ */
class uLinX_SemMutex;
class uLinX_SemAphore;

class HistoryCache 
{
public:
    HistoryCache(unsigned long ulLength);
    virtual ~HistoryCache();

    //д��
    ReturnCode_t AddChange(_CACHE_CHANGE *W_CacheChange);
    //ɾ��
    ReturnCode_t RemoveChange(SequenceNumber_t SeqNum);

    /* Nephalem ��ȡ���ݣ�����ֵ����Ϊconst����ֹ���ⲿ�ͷ����� */
    const _CACHE_CHANGE *GetChange(SequenceNumber_t SeqNum);

	/* Nephalem ȡ�����ݣ�����󷵻�����ֹ������ʹ���Ǳ�ɾ�������޸� */
	_CACHE_CHANGE *takeChange(const SequenceNumber_t& SeqNum);

	/* Nephalem ��take�����ݷ����������changeλ���Ѿ������ڣ�������ɾ�� */
	ReturnCode_t return_loan_change(_CACHE_CHANGE * pCacheChange);

    /* Nephalem ��ȡ���������������к���Сֵ ���Ǹ���ſ���û������ */
    SequenceNumber_t GetSeqNumMin();
    /* Nephalem ��ȡ���������������к����ֵ ���Ǹ���ſ���û������ */
    SequenceNumber_t GetSeqNumMax();

	/* Nephalem ��ȡ���õ��������е���С��� */
	SequenceNumber_t GetAvailableSeqNumMin();
	/* Nephalem ��ȡ���õ����ݻ��������� */
	SequenceNumber_t GetAvailableSeqNumMax();

public:
	/* Nephalem �Զ���ӿ� */
	/* Nephalem ��ȡ���������ܴ�С */
	unsigned int GetCacheLength();

	/* Nephalem ��ȡ�������ݵ��������ѱ�take����δreturn��ͳ������ */
	unsigned int getUserDataNum();

	/* Nephalem ��ȡmap�ĵ�N�����ݵ�SeqNumber */
	SequenceNumber_t getUseDataSeqNum(unsigned int iNumber);

	/* Nephalem �жϻ������Ƿ����� */
	bool isFull();

	/* Nephalem ��ȡ�����еĵ�һ������ */
	const _CACHE_CHANGE *GetFirstChange();

	ReturnCode_t SetDomainId(int iDomainCount,string TopicName);

	/* Nephalem �������lifespan */
	void checkLifeSpan();

private:

	/* Nephalem ���_CACHE_CHANG*��que��ɾЧ�ʸ� */
	map<SequenceNumber_t,_CACHE_CHANGE*> m_ChangesMap;
    
	/* Nephalem �������ܴ�С */
    unsigned int m_uiCacheLength;

	/* Nephalem ���������ô�С �ѱ�take����δreturn��ͳ������ */
	unsigned int  m_uiCacheNum;

    /* Nephalem ����m_ChangesDeque�����Ļ�����*/
	uLinX_SemMutex* m_ChangesMapMutex;

    //�������ź��� ��ʾ�Ƿ��п��ÿռ�
	uLinX_SemAphore* m_ChangesMapSemAphore;

	int m_iDomainCount;

	string m_strTopicName;

};

#endif
