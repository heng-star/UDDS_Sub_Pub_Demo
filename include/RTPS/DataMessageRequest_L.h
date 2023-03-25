/**
* @ file DataMessageRequest.h
* @ brief DataMessageRequest define
* @ author xusen
* @ version 0.1
* @ history
*   1. create on 2012-12-29
*/
#ifndef _RTPS_DATAMESSAGE_REQUEST_L_H_INCLUDED_
#define _RTPS_DATAMESSAGE_REQUEST_L_H_INCLUDED_

#include "RTPS/Request.h"
#include "RTPSBasicTypes.h"

class ReaderLocator;

/* Nephalem ��ָ��ip��ַ�������ݣ����ݷ��ͺ��漴ɾ��������BEST_EFFORT�·������� */
class DataMessageRequest_L : public Request {
public:
	DataMessageRequest_L (const EntityId_t entityId,
        _CACHE_CHANGE *pCacheChange,
        MessageProcessor *pMessageProcessor,
        MessageTransmitter *pMessageTransmitter,
        Time_t StartTime,
        Time_t EndTime) :
    Request (entityId, pMessageProcessor, pMessageTransmitter, StartTime, EndTime, "Data_L") {
        m_pCacheChange = pCacheChange;
    };

    virtual ~DataMessageRequest_L() {
        if (m_pCacheChange != NULL)
        {
            delete m_pCacheChange;
            m_pCacheChange = NULL;
        }
    }

    ReturnCode_t Execute();

	ReturnCode_t sendDataMessage(unsigned int & uiShift);

	ReturnCode_t sendDataFragMessage(unsigned int & uiShift);

	_CACHE_CHANGE* GetCacheChange()
	{
		return m_pCacheChange;
	}

private:
    _CACHE_CHANGE *m_pCacheChange;
};

#endif
