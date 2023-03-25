/************************************************************
** �ļ�����TypeSupport.h
** Copyright (c) 2011-2021 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2011-01-15
** �޸��ˣ���
** ��  �ڣ���
** ��  ����TypeSupportͷ�ļ�
** ��  ����Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _DDS_TYPESUPPORT_H_INCLUDED_
#define _DDS_TYPESUPPORT_H_INCLUDED_

#include "uLinxDataType.h"
#include "BasicTypes.h"

//#include <string>
//class DomainParticipant;
#if 1  // ���� ����RTI TypeCode����ص���Ϣ  
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

////����typecode ���� BEGIN//
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
//	uDDS_CDR_TK_VALUE,		   //22	/* JD �ȵ� �Զ���Ľṹ���� */
//	uDDS_CDR_TK_VALUE_PARAM,	   //23
//	uDDS_CDR_TK_UNSIGNED = 0x1001, /* JD �޷���*/
//	uDDS_CDR_TK_TYPEDEF = 0x1002 /* JD typedef*/
//} uDDSCdrTCKind;

// ��ö�����ֵ�����վ���ֵ��������һ��  //
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
	/* 8�ֽ� */
	uDDS_CDR_TK_DOUBLE,		   //9
	uDDS_CDR_TK_LONGLONG,	   //10
	uDDS_CDR_TK_ULONGLONG,	   //11
	uDDS_CDR_TK_LONGDOUBLE,	   //12
	/* �ǻ������������� */
	uDDS_CDR_TK_ARRAY,		   //13
	uDDS_CDR_TK_ALIAS,		   //14		/* typedef */
	uDDS_CDR_TK_WCHAR,		   //15
	uDDS_CDR_TK_WSTRING,		   //16
	uDDS_CDR_TK_STRUCT,		   //17
	uDDS_CDR_TK_UNION,		   //18
	uDDS_CDR_TK_ENUM,		   //19
	uDDS_CDR_TK_STRING,		   //20
	uDDS_CDR_TK_SEQUENCE,	   //21
	uDDS_CDR_TK_VALUE,		   //22	 /* JD �ȵ� �Զ���Ľṹ���� */
	uDDS_CDR_TK_VALUE_PARAM,	   //23

	uDDS_CDR_TK_UNSIGNED = 0x1001, /* JD �޷���*/
	uDDS_CDR_TK_TYPEDEF = 0x1002 /* JD typedef*/
} uDDSCdrTCKind;
typedef enum {
	DDS_FINAL_EXTENSIBILITY,
	DDS_EXTENSIBLE_EXTENSIBILITY,
	DDS_MUTABLE_EXTENSIBILITY
} DDS_ExtensibilityKind;

/* �������͵ı�ʶ����ʶ���ݺ������� */
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
** ���� ��TypeCodeRepresentation
** ���� ������һ��ĳ����Ա���� �� �ṹ��/ö��/������  �е���Ϣ 
****************************/
typedef struct TypeCodeRepresentation {
	unsigned long _pid; /* �����ڽṹ���е�λ��  */
	struct TypeCode*  _typeCode; /* ������TypeCode */
} TypeCodeRepresentation;


/***************************************
** JDXCZ 2022-04-07
** ���� ��TypeCodeMember
** ���� ������һ��ĳ����Ա��������Ϣ�����Ϣ 
****************************/
typedef struct TypeCodeMember {
	string _name; /* ����������  */
	unsigned char _flag;  /* JD 20220407 ��֪����ɶ�ģ���typeobject��������������ȱ���*/
	unsigned int _maxcount; /* ������� */
	struct TypeCodeRepresentation _representation; /* ��ǰ��Ա������ �ṹ���е���Ϣ  */

	//TypeCodeMember() {
	//	_name = "";
	//	_flag = 0;
	//	_maxcount = 1;	/* �������1��˵����һ������ */
	//	_representation = { 0,NULL };
	//}

} uDDSCdrTypeCodeMember;

/*************************************** 
** JDXCZ 2022-04-07
** ���� ��TypeCode
** ���� ������һ�����͵���Ϣ�����Ϣ TypeCode
****************************/
struct TypeCode
{
	uDDSCdrTCKind _kind;		/* ���ݵ����� */
	string	_name;			/* ���������� */
	unsigned long _memberCount; /* ���������� */
	//unsigned long _maxsize;	/* ���������� */
	vector<uDDSCdrTypeCodeMember> _members;/* ��������Ϣ */
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

	/* ����IDL �ļ��������浽���Ӧ�Ľṹ���� */
	int AnalyseIDL(list<string> idl_info);

	/* �������ƣ����Ҷ�Ӧ�Ľṹ���TypeCode */
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

	/* ��Ŷ������������ */
	set<string>  m_TypeNameVec;

	/* �������������,keyΪ������valueΪԭ��*/
	map<string, string> m_StringAliasMap;

	bool m_bInit;
};

#endif	// ���� ����RTI TypeCode����ص���Ϣ 


class DDS_DLL TypeSupport 
{
public:
    TypeSupport() {};
    virtual ~TypeSupport () {};

	virtual TypeCode* GetTypeCode() { return NULL; }



    ////ע���û��������������
    //static ReturnCode_t Register_Type(DomainParticipant* pDomainParticipant, char* typeName);

    ////��ȡTypeSupport���������������
    //static string Get_Type_Name();
private:
	int a;


};

#endif
