/************************************************************
** 文件名：TypeSupport.h
** Copyright (c) 2011-2021 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2011-01-15
** 修改人：无
** 日  期：无
** 描  述：TypeSupport头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_TYPESUPPORT_H_INCLUDED_
#define _DDS_TYPESUPPORT_H_INCLUDED_

#include "uLinxDataType.h"
#include "BasicTypes.h"

//#include <string>
//class DomainParticipant;
#if 1  // 以上 仿照RTI TypeCode的相关的信息  
typedef enum {
	DDS_TK_NULL,
	DDS_TK_SHORT,
	DDS_TK_LONG,
	DDS_TK_USHORT,
	DDS_TK_ULONG,
	DDS_TK_FLOAT,
	DDS_TK_DOUBLE,
	DDS_TK_BOOLEAN,
	DDS_TK_CHAR,
	DDS_TK_OCTET,
	DDS_TK_STRUCT,
	DDS_TK_UNION,
	DDS_TK_ENUM,
	DDS_TK_STRING,
	DDS_TK_SEQUENCE,
	DDS_TK_ARRAY,
	DDS_TK_ALIAS,
	DDS_TK_LONGLONG,
	DDS_TK_ULONGLONG,
	DDS_TK_LONGDOUBLE,
	DDS_TK_WCHAR,
	DDS_TK_WSTRING,
	DDS_TK_VALUE,
	DDS_TK_SPARSE,
	DDS_TK_RAW_BYTES = 0x7e,
	DDS_TK_RAW_BYTES_KEYED = 0x7f,
	DDS_TK_FINAL_EXTENSIBILITY = 0x4000,
	DDS_TK_MUTABLE_EXTENSIBILITY = 0x2000,

	DDS_TK_FLAT_DATA_LANGUAGE_BINDING = 5000,
	DDS_TK_SHMEM_REF_TRANSFER_MODE = 5001

} DDS_TCKind;

////解析typecode 数据 BEGIN//
//typedef enum {
//	uDDS_CDR_TK_NULL = 0,
//	uDDS_CDR_TK_SHORT, 		   //1
//	uDDS_CDR_TK_LONG,  		   //2
//	uDDS_CDR_TK_USHORT,		   //3
//	uDDS_CDR_TK_ULONG,		   //4
//	uDDS_CDR_TK_FLOAT,		   //5
//	uDDS_CDR_TK_DOUBLE,		   //6
//	uDDS_CDR_TK_BOOLEAN,		   //7
//	uDDS_CDR_TK_CHAR,		   //8
//	uDDS_CDR_TK_OCTET,		   //9
//	uDDS_CDR_TK_STRUCT,		   //10
//	uDDS_CDR_TK_UNION,		   //11
//	uDDS_CDR_TK_ENUM,		   //12
//	uDDS_CDR_TK_STRING,		   //13
//	uDDS_CDR_TK_SEQUENCE,	   //14
//	uDDS_CDR_TK_ARRAY,		   //15
//	uDDS_CDR_TK_ALIAS,		   //16		/* typedef */
//	uDDS_CDR_TK_LONGLONG,	   //17
//	uDDS_CDR_TK_ULONGLONG,	   //18
//	uDDS_CDR_TK_LONGDOUBLE,	   //19
//	uDDS_CDR_TK_WCHAR,		   //20
//	uDDS_CDR_TK_WSTRING,		   //21
//	uDDS_CDR_TK_VALUE,		   //22	/* JD 先当 自定义的结构体用 */
//	uDDS_CDR_TK_VALUE_PARAM,	   //23
//	uDDS_CDR_TK_UNSIGNED = 0x1001, /* JD 无符号*/
//	uDDS_CDR_TK_TYPEDEF = 0x1002 /* JD typedef*/
//} uDDSCdrTCKind;

// 将枚举里的值，按照精度值重现排列一下  //
typedef enum {
	uDDS_CDR_TK_NULL = 0,
	/* 1byte */
	uDDS_CDR_TK_BOOLEAN,		   //1
	uDDS_CDR_TK_CHAR,		   //2
	uDDS_CDR_TK_OCTET,		   //3

	/* 2byte */
	uDDS_CDR_TK_SHORT, 		   //4
	uDDS_CDR_TK_USHORT,		   //5
	/* 4byte */
	uDDS_CDR_TK_LONG,  		   //6
	uDDS_CDR_TK_ULONG,		   //7
	uDDS_CDR_TK_FLOAT,		   //8
	/* 8字节 */
	uDDS_CDR_TK_DOUBLE,		   //9
	uDDS_CDR_TK_LONGLONG,	   //10
	uDDS_CDR_TK_ULONGLONG,	   //11
	uDDS_CDR_TK_LONGDOUBLE,	   //12
	/* 非基础的数据类型 */
	uDDS_CDR_TK_ARRAY,		   //13
	uDDS_CDR_TK_ALIAS,		   //14		/* typedef */
	uDDS_CDR_TK_WCHAR,		   //15
	uDDS_CDR_TK_WSTRING,		   //16
	uDDS_CDR_TK_STRUCT,		   //17
	uDDS_CDR_TK_UNION,		   //18
	uDDS_CDR_TK_ENUM,		   //19
	uDDS_CDR_TK_STRING,		   //20
	uDDS_CDR_TK_SEQUENCE,	   //21
	uDDS_CDR_TK_VALUE,		   //22	 /* JD 先当 自定义的结构体用 */
	uDDS_CDR_TK_VALUE_PARAM,	   //23

	uDDS_CDR_TK_UNSIGNED = 0x1001, /* JD 无符号*/
	uDDS_CDR_TK_TYPEDEF = 0x1002 /* JD typedef*/
} uDDSCdrTCKind;
typedef enum {
	DDS_FINAL_EXTENSIBILITY,
	DDS_EXTENSIBLE_EXTENSIBILITY,
	DDS_MUTABLE_EXTENSIBILITY
} DDS_ExtensibilityKind;

/* 数据类型的标识，标识数据何种类型 */
typedef enum {
	uDDS_XCDR_TK_NULL,
	uDDS_XCDR_TK_SHORT,
	uDDS_XCDR_TK_LONG,
	uDDS_XCDR_TK_USHORT,
	uDDS_XCDR_TK_ULONG,
	uDDS_XCDR_TK_FLOAT,
	uDDS_XCDR_TK_DOUBLE,
	uDDS_XCDR_TK_BOOLEAN,
	uDDS_XCDR_TK_CHAR,
	uDDS_XCDR_TK_OCTET,
	uDDS_XCDR_TK_STRUCT,
	uDDS_XCDR_TK_UNION,
	uDDS_XCDR_TK_ENUM,
	uDDS_XCDR_TK_STRING,
	uDDS_XCDR_TK_SEQUENCE,
	uDDS_XCDR_TK_ARRAY,
	uDDS_XCDR_TK_ALIAS,
	uDDS_XCDR_TK_LONGLONG,
	uDDS_XCDR_TK_ULONGLONG,
	uDDS_XCDR_TK_LONGDOUBLE,
	uDDS_XCDR_TK_WCHAR,
	uDDS_XCDR_TK_WSTRING,
	uDDS_XCDR_TK_VALUE,
	uDDS_XCDR_TK_SPARSE,

	uDDS_XCDR_TK_RAW_BYTES = 0x7e,
	uDDS_XCDR_TK_RAW_BYTES_KEYED = 0x7f,

	 uDDS_XCDR_TK_FLAG_IS_INDEXED = 0x8000,

	 /* only used to represent xtypes annotations */
	 uDDS_XCDR_TK_FLAGS_IS_FINAL = 0x4000,
	 uDDS_XCDR_TK_FLAGS_IS_MUTABLE = 0x2000,

	 /* only used to represent RTI-specific annotations */
	 uDDS_XCDR_TK_FLAGS_IS_FLAT_DATA = 0x10000,
	 uDDS_XCDR_TK_FLAGS_IS_SHMEM_REF = 0x20000,

	 uDDS_XCDR_TK_FLAGS_ALL = 0xfff00

} uDDSXCdrTCKind;

typedef enum
{
	uDDS_XCDR_FINAL_EXTENSIBILITY,
	uDDS_XCDR_EXTENSIBLE_EXTENSIBILITY,
	uDDS_XCDR_MUTABLE_EXTENSIBILITY
} uDDSXCdrExtensibilityKind;

/***************************************
** JDXCZ 2022-04-07
** 类型 ：TypeCodeRepresentation
** 作用 ：描述一个某个成员变量 在 结构体/枚举/。。。  中的信息 
****************************/
typedef struct TypeCodeRepresentation {
	unsigned long _pid; /* 变量在结构体中的位置  */
	struct TypeCode*  _typeCode; /* 变量的TypeCode */
} TypeCodeRepresentation;


/***************************************
** JDXCZ 2022-04-07
** 类型 ：TypeCodeMember
** 作用 ：描述一个某个成员变量的信息相关信息 
****************************/
typedef struct TypeCodeMember {
	string _name; /* 变量的名称  */
	unsigned char _flag;  /* JD 20220407 不知道干啥的，看typeobject中有这个东西，先保存*/
	unsigned int _maxcount; /* 针对数组 */
	struct TypeCodeRepresentation _representation; /* 当前成员变量在 结构体中的信息  */

	//TypeCodeMember() {
	//	_name = "";
	//	_flag = 0;
	//	_maxcount = 1;	/* 如果大于1，说明是一个数组 */
	//	_representation = { 0,NULL };
	//}

} uDDSCdrTypeCodeMember;

/*************************************** 
** JDXCZ 2022-04-07
** 类型 ：TypeCode
** 作用 ：描述一个类型的信息相关信息 TypeCode
****************************/
struct TypeCode
{
	uDDSCdrTCKind _kind;		/* 数据的类型 */
	string	_name;			/* 变量的名称 */
	unsigned long _memberCount; /* 变量的数量 */
	//unsigned long _maxsize;	/* 针对数组变量 */
	vector<uDDSCdrTypeCodeMember> _members;/* 变量的信息 */
	TypeCode() 
	{
		_kind = uDDS_CDR_TK_NULL;
		_name = "";
		_memberCount = 0;
		_members.clear();
	}
};


class TypeCodeManage {	
public:
	TypeCodeManage();

	static TypeCodeManage* GetInstance();

	/* 解析IDL 文件，并保存到相对应的结构体中 */
	int AnalyseIDL(list<string> idl_info);

	/* 根据名称，查找对应的结构体的TypeCode */
	TypeCode* find_typecode(string strTypeName);

	string find_type_name(uDDSCdrTCKind tk_kind);
private:


	uDDSCdrTCKind get_cdrkind_from_string(vector<string>& strVec);

	uDDSCdrTCKind getValueType(string str);

	int get_TypeCode(TypeCode* TypeCode,string str);

	vector<string> spliteOutC(string ss, char c);

	map<string, uDDSCdrTCKind> m_StringuDDSCdrTCKindMap;

	map<uDDSCdrTCKind,string> m_uDDSCdrTCKindStringMap;

private:
	map<string, TypeCode*> m_TypeCodeMap;

	static TypeCodeManage* m_pInstance;

	/* 存放定义的数据类型 */
	set<string>  m_TypeNameVec;

	/* 别名保存的类型,key为别名，value为原名*/
	map<string, string> m_StringAliasMap;

	bool m_bInit;
};

#endif	// 以上 仿照RTI TypeCode的相关的信息 


class DDS_DLL TypeSupport 
{
public:
    TypeSupport() {};
    virtual ~TypeSupport () {};

	virtual TypeCode* GetTypeCode() { return NULL; }



    ////注册用户定义的数据类型
    //static ReturnCode_t Register_Type(DomainParticipant* pDomainParticipant, char* typeName);

    ////获取TypeSupport代表的数据类型名
    //static string Get_Type_Name();
private:
	int a;


};

#endif
