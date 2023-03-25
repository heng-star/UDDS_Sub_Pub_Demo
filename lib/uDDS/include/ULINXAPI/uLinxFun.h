#pragma once
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::istringstream;

#include "DDS_DLL.h"
#include "uLinxDataType.h"

namespace uLinxFun
{
	int DDS_sleep(int sec);

	DDS_DLL int DDS_msleep(int ms);

	vector<string> splite(string str, char target,int nums = 1000000);

	void getLocalSystemTime(int& year, int& month, int& day, int& hour, int& minute, int& second, int& milliseconds);

	void trim(string& data);

	int StringToInt(const string& str);
	
	unsigned int StringToUint(const string & str);

	string IntToString(const int iVal);

	/* Nephalem string ת�����������ͣ���ԱȽϺ�ʱ */
	template<typename type>
	type stringToNum(const string& str)
	{
		istringstream iss(str);
		type num;
		iss >> num;
		return num;
	}

	//
	//��ȡ����ͳ��ʱ��ĺ�����
	unsigned long getCurrentTime();

	/* Nephalem ʱ�Ӻ�������λ���� */
	void sleep(int milliSecond);

	/* Nephalem �жϱ��ش�С�� 0Ϊ��ˣ�1ΪС�� */
	DDS_DLL int LocalEndianness();

	int matchstar(int c, char *regexp, char *text);

	int matchhere(char *regexp, char *text);

	/* �ж��ַ����Ƿ���ͬ��֧��ͨ��� */
	// .        ƥ������ĵ����ַ�
	// ^        ƥ�������ַ����Ŀ�ͷ
	// $        ƥ�������ַ����Ľ�β
	// *        ƥ��ǰһ���ַ���������߶������
	DDS_DLL int match(char *regexp, char *text);
}
