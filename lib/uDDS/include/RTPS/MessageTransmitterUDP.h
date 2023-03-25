#pragma once
/* Nephalem �û�ͷ�ļ� */
#include "BasicTypes.h"
#include "RTPS/MessageTransmitter.h"
#include "uLinxDataType.h"
/* Nephalem ?�̨�3����???t */

/* Nephalem ǰ������ */


typedef map<unsigned int, ULINX_SOCKET> _SEND_SOCKET_MAP;
typedef map<unsigned short, ULINX_SOCKET> _RECV_SOCKET_MAP;


class MessageTransmitterUDP : public MessageTransmitter
{
public:
	//���캯��
	MessageTransmitterUDP(ReceiveBuffer *pReceiveBuffer);

	//��������
	virtual ~MessageTransmitterUDP();

	/* Nephalem ��������socket���󶨷���IP */
	ReturnCode_t SendAddrAdd(Locator_t SendAddr);

	/* Nephalem ���ͱ��ģ���ʹ��LOCATOR_INVALID��ָ����������ʹ��ָ��IP���������з��� */
	ReturnCode_t MessageSend(
		Locator_t Source,
		Locator_t Destination,
		char *pMessage,
		unsigned int uiLength);

	virtual ReturnCode_t MessageSend(
		_LOCATOR_LIST_T& SourceList,
		_LOCATOR_LIST_T& DestinationList,
		char* pMessage,
		unsigned int uiLength
	);

	/* Nephalem ���Ͷಥ���ģ���ʹ��LOCATOR_INVALID��ָ����������ʹ��ָ��IP���������з��� UDP��������ʵ�����ֵ������鲥 */
	ReturnCode_t SendMultiMessage(
	    Locator_t Source,
	    Locator_t Destination,
	    char *pMessage,
	    unsigned int uiLength);
	  
	//��Ӽ�����ַ
	ReturnCode_t ReceiveAddrAdd(Locator_t ReceiveAddr);

	//��Ӽ����ಥ��ַ
	//ReturnCode_t ReceiveMultiAddrAdd(Locator_t SourceAddr, Locator_t ReceiveAddr);

	//ɾ��������ַ
	ReturnCode_t ReceiveAddrRemove(Locator_t ReceiveAddr);

	//����Socket API���ձ���
	ReturnCode_t ReceiveMessage();

	ReturnCode_t SetDomainId(int iDomainCount);
	
private:
	/* Nephalem ��������socket */
	ReturnCode_t addRecvSocket(Locator_t ReceiveAddr);
	/* Nephalem �����鲥�� */
	ReturnCode_t addMemberShip(Locator_t ReceiveAddr);
	/* Nephalem �˳��鲥�� */
	ReturnCode_t dropMemberShip(Locator_t ReceiveAddr);

	//���ձ���
	char *m_pMsgBuffer;

	/* Nephalem ����socket�����͵�ַΪkeyֵ */
	_SEND_SOCKET_MAP m_SendSocketMap;

	/* Nephalem ����socket���Զ˿ں�Ϊkey���˿ں�һ��ʱ���ɰ󶨶������ ��ַ*/
	_RECV_SOCKET_MAP m_ReceiveSocketMap;

	//������socket���ֵ ����select������
	ULINX_SOCKET m_SocketMax;

	//������socket���� ����select����
	fd_set m_ReadSet;

	//2013-10-16 hjy modify��������ƥ��ʱ�ӣ��տ�ʼ����255.255.255.255��socketʱ�����һ�� 
	int m_MatchTime;

    //wangyi 2021/6/25 windows closesocket() and linux close()
    void CloseSocket(ULINX_SOCKET fd);
	/* JDXCZ ��¼��־������� */
	int m_iDomainCount;

};
