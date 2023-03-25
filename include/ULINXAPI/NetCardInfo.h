#pragma once
#include "RTPSBasicTypes.h"
#include "uLinxFun.h"

#ifdef ULINX_VXWORKS
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include <sockLib.h>
#include <ioLib.h>
//#include <net/if.h>
//#include <>
#include <unistd.h>



#elif	defined ULINX_LINUX
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/types.h>

//#include <linux/if.h>

#include <unistd.h>
//#include <arpa/inet.h>

#elif (defined( ULINX_WIN) ||  defined(_WIN32))
#pragma comment(lib,"Iphlpapi.lib")
#pragma comment (lib,"Advapi32.lib")
#include <Iphlpapi.h>
#include <iostream>
#endif
#include <string>
#include <map>
#include <vector>
#define BUF_SIZE 1024
using std::map;
using std::vector;
using std::string;
/* IP地址的列表 */
typedef vector<unsigned int>	_IPAddressVec_T;
/* 网卡名 和 IP列表 */
typedef map<string, _IPAddressVec_T> _NetCardAddressMap_T;
struct _NetCard
{
	string  NetCardName;
	vector<string> ipAddr; //192.168.0.1
	vector<unsigned int> uiAddr; //
};

struct _allNetcard
{
	vector<_NetCard> allNetcard_vector;
};

int find_NetCardName(_allNetcard allnetCard, string strNetName);

int UitoStrAddr(_NetCard & NetCard);
//int StrtoUiAddr(NetCard & NetCard);


class NetCardInfo
{
public:
	NetCardInfo();

	~NetCardInfo();

	//int GetNetCardAddressInfo(_NetCardAddressMap_T& NetCardAddressMap);
	
	int GetNetCardAddressInfo(_allNetcard &allnetCard);

	/* 根据网卡的名称(UUID) 获取在注册表里的名称 */
	int GetNetCardName(const string& NetName, string& name);

#if (defined(ULINX_WIN) || defined(_WIN32))
	bool GetAdapterState(DWORD index);
#else
    //bool GetAdapterState(DWORD index);
#endif // !KYLIN



};
