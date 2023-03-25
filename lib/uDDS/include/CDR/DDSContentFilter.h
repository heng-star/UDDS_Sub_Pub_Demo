#pragma once

#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
/* �ж��ַ������� */
typedef enum {
	Char_Error = 1,	/* ������� */
	Char_Blank ,	/* �ո� */
	Char_Letter,	/* ��ĸ */
	Char_Percent,	/* �ٷֺ� */
	Char_Operator,	/* ����� */
	Char_Figure,		/* ���� */
	Char_Point,		/* С���㣬�����⴦�� */
	Char_Flaot,		/* ���ַ�λ e | E ��ʱ������Ǹ���������Ҫ�����⴦�� */
	// Char_Minus_Plus, /* 2.02e+10 �Ǹ����� ��-20���з�����  */
	/* �� Char_Letter���͸�����ķ��� */
	Char_Struct = 100, /* �����еĳ�Ա����	*/
	Char_SQL	= 101  /* ��SQL�Ĺؼ��� */
}_CharType;

struct StringInfo
{
	string value;	/* �ַ�������  */
	_CharType type;	/* �ַ�������  */

	StringInfo()
	{
		value = "";
		type = Char_Error;
	}
};
/* �жϷ��� */
typedef enum {
	Error_Operator,
	Greater,	/* ���� */
	GreaterEqual,	/* ���ڵ��� */
	Equal,	/* ���� */
	LessEqual,	/* С�ڵ��� */
	Less,	/* С��*/
	Between /* ������֮�䣬�������� */
}_Operator;

/*  ֻ�� �ж�����Ϊ  BETWEEN ��ʱ����е�����ֵ */
struct _Expression_Rule
{
	int _id0;		 /* expression �ڽṹ���е�λ�� ,-1��ʾ��������������ǽṹ�����*/
	int _id1;		 /*  �ڽṹ���е�λ�� -1��ʾ����һ���������ǽṹ����� */
	int _id2;		 /*  �ڽṹ���е�λ�� -1��ʾ���ڶ����������ǽṹ����� */
	string _value0;  /* ��Ҫ�жϵ�ֵ */
	string _value1;  /* ��Ҫ�жϵ�ֵ   */
	string _value2;  /* ��Ҫ�жϵ�ֵ  */
	_Operator _operator;	/* �ù�����ж����� */
	bool bAnd;		  /* �ù����� and ��� ���� or ���*/
	_Expression_Rule()
	{
		_id0 = -1;
		_id1 = -1;
		_id2 = -1;
		_value0 = "";
		_value1 = "";
		_value2 = "";
		_operator = Error_Operator;
		bAnd = false;
	}
};
const _Expression_Rule  Default_Rule = _Expression_Rule();

typedef union  _TypeCodeMember_Value
{
	short short_value;
	long long_value;
	unsigned short ushort_value;
	unsigned long ulong_value;
	float float_value;
	double double_value;
	unsigned char boolean_value;
	char char_value;
	char* string_value;
	octet octet_value;
	wchar_t wchar_value;
	long long longlong_value;
	unsigned long long ulonglong_value;
	long double longdouble_value;
}_TypeCodeMember_Value_T;

struct TypeCode;
//union TypeCodeMemberValue;
class  DDSContentFilter
{
public :
	DDSContentFilter(TypeCode* pTypeCode);
	~DDSContentFilter();
	/* ����������������͹�����������ز��� */
	int translate_expression(string expression,StringSeq expression_parameters);

	/* �������������� ���������Ƿ�Ϸ� */
	int analyse_grammar(vector<StringInfo> expressInfo, StringSeq& expression_parameters);

	_CharType JudgeCharType(char c);

	/* �ж�string �Ƿ��ǽṹ���еĳ�Ա����������Ƿ���id,������Ƿ���-1*/
	int bEffectiveVariable(string str);

	/* �ж��Ƿ��ǲ��� �� Ŀǰ��֧�� �ַ���("") �� �ַ�('') ���ֲ���  */
	int bEffectiveParamater(string strPercent);

	/* �ж��Ƿ�����Ч������ �� 1.1.1 | -1-1 | 1ee6 ��Щ������Ч������ */
	int bEffectiveFigure(string strPercent);

	bool is_relevant(char* pData, unsigned long ulLength);

private:
	
	int DealLetter(StringInfo string_info, int& num, _Expression_Rule& rule);

	int DealPercent(StringInfo string_info, int& num, _Expression_Rule& rule,StringSeq expression_parameters);

	int DealOperator(StringInfo string_info, int& num, _Expression_Rule& rule);

	int DealFigure(StringInfo string_info, int& num, _Expression_Rule& rule);

	/* �����������е� ���ֵ��ַ��� תΪ��Ӧ�ģ���������*/
	uDDSCdrTCKind StringtoTypeCodeMemberValueT(string str, _TypeCodeMember_Value_T& TypeCodeMemberValueT);

	int ChangeTypeCodeMemberValueT(_TypeCodeMember_Value_T& left, uDDSCdrTCKind tc_kind_0, uDDSCdrTCKind tc_kind_2);

	bool TypeCodeMemberValue_Greater(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_Less(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_Equal(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_GreaterEqual(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_LessEqual(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);
	 
	/* ����TypeCode,�������� */
	int Marshal(CDR* pCdr, TypeCode* pTypeCode, vector<_TypeCodeMember_Value_T>& TypeCodeMemberValueVec);

	/* �������ݹ��˴��� */
	bool StartFilter(vector<_TypeCodeMember_Value_T>& TypeCodeMemberValueVec);

	bool Compare(_TypeCodeMember_Value_T& first, _TypeCodeMember_Value_T& second, _TypeCodeMember_Value_T& third, _Operator _operator, uDDSCdrTCKind type);

	/* ����ӡ��Ϣ��ӡ���� */
	int printf_ExpressionRule(_Expression_Rule& Rule);
private:
	vector<_Expression_Rule> m_RulesVec;

	map<string, _Operator> m_StringOperatorMap;

	map<_Operator,string> m_OperatorStringMap;

	TypeCode* m_pRelateTypeCode;

};

