#pragma once
/* Nephalem 用户头文件 */
#include "BasicTypes.h"
#include "RTPS/MessageTransmitter.h"
#include "uLinxDataType.h"
/* Nephalem ?μí3í·???t */

/* Nephalem 前置声明 */


typedef map<unsigned int, ULINX_SOCKET> _SEND_SOCKET_MAP;
typedef map<unsigned short, ULINX_SOCKET> _RECV_SOCKET_MAP;


class MessageTransmitterUDP : public MessageTransmitter
{
public:
	//构造函数
	MessageTransmitterUDP(ReceiveBuffer *pReceiveBuffer);

	//析构函数
	virtual ~MessageTransmitterUDP();

	/* Nephalem 创建发送socket并绑定发送IP */
	ReturnCode_t SendAddrAdd(Locator_t SendAddr);

	/* Nephalem 发送报文，可使用LOCATOR_INVALID不指定网卡，或使用指定IP的网卡进行发送 */
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

	/* Nephalem 发送多播报文，可使用LOCATOR_INVALID不指定网卡，或使用指定IP的网卡进行发送 UDP发送中其实不区分单播和组播 */
	ReturnCode_t SendMultiMessage(
	    Locator_t Source,
	    Locator_t Destination,
	    char *pMessage,
	    unsigned int uiLength);
	  
	//添加监听地址
	ReturnCode_t ReceiveAddrAdd(Locator_t ReceiveAddr);

	//添加监听多播地址
	//ReturnCode_t ReceiveMultiAddrAdd(Locator_t SourceAddr, Locator_t ReceiveAddr);

	//删除监听地址
	ReturnCode_t ReceiveAddrRemove(Locator_t ReceiveAddr);

	//利用Socket API接收报文
	ReturnCode_t ReceiveMessage();

	ReturnCode_t SetDomainId(int iDomainCount);
	
private:
	/* Nephalem 创建接收socket */
	ReturnCode_t addRecvSocket(Locator_t ReceiveAddr);
	/* Nephalem 加入组播组 */
	ReturnCode_t addMemberShip(Locator_t ReceiveAddr);
	/* Nephalem 退出组播组 */
	ReturnCode_t dropMemberShip(Locator_t ReceiveAddr);

	//接收报文
	char *m_pMsgBuffer;

	/* Nephalem 发送socket，发送地址为key值 */
	_SEND_SOCKET_MAP m_SendSocketMap;

	/* Nephalem 接收socket，以端口号为key，端口号一致时，可绑定多个接收 地址*/
	_RECV_SOCKET_MAP m_ReceiveSocketMap;

	//监听的socket最大值 用于select方法中
	ULINX_SOCKET m_SocketMax;

	//监听的socket集合 用于select方法
	fd_set m_ReadSet;

	//2013-10-16 hjy modify发布订阅匹配时延，刚开始监听255.255.255.255的socket时间更长一点 
	int m_MatchTime;

    //wangyi 2021/6/25 windows closesocket() and linux close()
    void CloseSocket(ULINX_SOCKET fd);
	/* JDXCZ 记录日志所需的域 */
	int m_iDomainCount;

};
