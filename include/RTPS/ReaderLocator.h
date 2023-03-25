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
    //���캯��
    ReaderLocator(Locator_t locator,bool expectsInlineQos);

 //   //��������
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
	/* Nephalem �淶�ж���ı��� */
	/* Nephalem Զ��Reader�ڴ�ReaderLocator�������writer��HistoryCache �����б�*/
	_CACHE_CHANGE_LIST_T m_RequestedChanges;

	/* Nephalem writer��HistoryCache�л�δ���͵���ReaderLocator�������б� */
	_CACHE_CHANGE_LIST_T m_UnsentChanges;

	/* Nephalem Reader�Ľ��յ�ַ */
	Locator_t			 m_Locator;

	/* Nephalem ʹ�ô˵�ַ��DataReader������ */
	unsigned int         m_LocatorCount;
};

#endif
