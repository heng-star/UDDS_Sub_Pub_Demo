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

	/* Nephalem string 转换成其他类型，相对比较耗时 */
	template<typename type>
	type stringToNum(const string& str)
	{
		istringstream iss(str);
		type num;
		iss >> num;
		return num;
	}

	//
	//获取用于统计时差的毫秒数
	unsigned long getCurrentTime();

	/* Nephalem 时延函数，单位毫秒 */
	void sleep(int milliSecond);

	/* Nephalem 判断本地大小端 0为大端，1为小端 */
	DDS_DLL int LocalEndianness();

	int matchstar(int c, char *regexp, char *text);

	int matchhere(char *regexp, char *text);

	/* 判断字符串是否相同，支持通配符 */
	// .        匹配任意的单个字符
	// ^        匹配输入字符串的开头
	// $        匹配输入字符串的结尾
	// *        匹配前一个字符的零个或者多个出现
	DDS_DLL int match(char *regexp, char *text);
}
