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
    //���캯��
    StatelessWriter(GUID_t            Guid,
		const DataWriterQos&	dataWriterQoS,
		RequestScheduler  **pScheduleList);

    //��������
    virtual ~StatelessWriter();
	/* Nephalem �淶�ж���Ľӿ� */
	//���ƥ��Ķ��Ķ˵�ַ
	ReturnCode_t reader_locator_add(const Locator_t& pLocator);

	//ɾ��ƥ�䶩�Ķ˵�ַ
	ReturnCode_t reader_locator_remove(const Locator_t& locator);

	/* Nephalem ���ö��Ķ��еĴ��������ݱ�� */
	//ReturnCode_t unsent_changes_rest();

public:
	/* Nephalem �Զ���ӿ� */

	/* Nephalem ���ݷ��Ͳ��� */
	virtual ReturnCode_t DataSend(_CACHE_CHANGE* pCacheChange);

	/* Nephalem ��ȡƥ���ϵ�DataReader������ */
	virtual unsigned int GetMatchDataReaderNum();

	/* Nephalem ��ȡLocator�б� */
	_READER_LOCATOR_MAP GetLocatorList();

	/* Nephalem �ǿɿ�ģʽ�£��ýӿ�Ŀǰ�ĵ���ʵ��ûЧ�� */
	virtual ReturnCode_t remove_change(SequenceNumber_t& seq);

private:
    
	_READER_LOCATOR_MAP m_MatchedLocatorMap;

};

#endif
