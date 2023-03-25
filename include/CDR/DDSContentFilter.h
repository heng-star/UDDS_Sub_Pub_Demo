#pragma once

#include "BasicTypes.h"
#include "DDS/TypeSupport.h"
/* 判断字符的类型 */
typedef enum {
	Char_Error = 1,	/* 错误符号 */
	Char_Blank ,	/* 空格 */
	Char_Letter,	/* 字母 */
	Char_Percent,	/* 百分号 */
	Char_Operator,	/* 运算符 */
	Char_Figure,		/* 数字 */
	Char_Point,		/* 小数点，做特殊处理 */
	Char_Flaot,		/* 当字符位 e | E 的时候可能是浮点数，需要做特殊处理 */
	// Char_Minus_Plus, /* 2.02e+10 是浮点型 ，-20是有符号数  */
	/* 对 Char_Letter类型跟具体的分类 */
	Char_Struct = 100, /* 是类中的成员变量	*/
	Char_SQL	= 101  /* 是SQL的关键字 */
}_CharType;

struct StringInfo
{
	string value;	/* 字符的名称  */
	_CharType type;	/* 字符的类型  */

	StringInfo()
	{
		value = "";
		type = Char_Error;
	}
};
/* 判断符号 */
typedef enum {
	Error_Operator,
	Greater,	/* 大于 */
	GreaterEqual,	/* 大于等于 */
	Equal,	/* 等于 */
	LessEqual,	/* 小于等于 */
	Less,	/* 小于*/
	Between /* 在两者之间，包含两者 */
}_Operator;

/*  只有 判断条件为  BETWEEN 的时候才有第三个值 */
struct _Expression_Rule
{
	int _id0;		 /* expression 在结构体中的位置 ,-1表示，第零个条件不是结构体变量*/
	int _id1;		 /*  在结构体中的位置 -1表示，第一个条件不是结构体变量 */
	int _id2;		 /*  在结构体中的位置 -1表示，第二个条件不是结构体变量 */
	string _value0;  /* 需要判断的值 */
	string _value1;  /* 需要判断的值   */
	string _value2;  /* 需要判断的值  */
	_Operator _operator;	/* 该规则的判断条件 */
	bool bAnd;		  /* 该规则是 and 语句 还是 or 语句*/
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
	/* 解析处理过滤条件和过滤条件的相关参数 */
	int translate_expression(string expression,StringSeq expression_parameters);

	/* 分析解析出来的 过滤条件是否合法 */
	int analyse_grammar(vector<StringInfo> expressInfo, StringSeq& expression_parameters);

	_CharType JudgeCharType(char c);

	/* 判断string 是否是结构体中的成员变量，如果是返回id,如果不是返回-1*/
	int bEffectiveVariable(string str);

	/* 判断是否是参数 ， 目前不支持 字符串("") 和 字符('') 两种参数  */
	int bEffectiveParamater(string strPercent);

	/* 判断是否是有效的数字 ， 1.1.1 | -1-1 | 1ee6 这些都是无效的数据 */
	int bEffectiveFigure(string strPercent);

	bool is_relevant(char* pData, unsigned long ulLength);

private:
	
	int DealLetter(StringInfo string_info, int& num, _Expression_Rule& rule);

	int DealPercent(StringInfo string_info, int& num, _Expression_Rule& rule,StringSeq expression_parameters);

	int DealOperator(StringInfo string_info, int& num, _Expression_Rule& rule);

	int DealFigure(StringInfo string_info, int& num, _Expression_Rule& rule);

	/* 将过滤条件中的 数字的字符串 转为对应的，数据类型*/
	uDDSCdrTCKind StringtoTypeCodeMemberValueT(string str, _TypeCodeMember_Value_T& TypeCodeMemberValueT);

	int ChangeTypeCodeMemberValueT(_TypeCodeMember_Value_T& left, uDDSCdrTCKind tc_kind_0, uDDSCdrTCKind tc_kind_2);

	bool TypeCodeMemberValue_Greater(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_Less(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_Equal(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_GreaterEqual(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);

	bool TypeCodeMemberValue_LessEqual(_TypeCodeMember_Value_T& left, _TypeCodeMember_Value_T& right, uDDSCdrTCKind tk_kind);
	 
	/* 按照TypeCode,解析数据 */
	int Marshal(CDR* pCdr, TypeCode* pTypeCode, vector<_TypeCodeMember_Value_T>& TypeCodeMemberValueVec);

	/* 进行数据过滤处理 */
	bool StartFilter(vector<_TypeCodeMember_Value_T>& TypeCodeMemberValueVec);

	bool Compare(_TypeCodeMember_Value_T& first, _TypeCodeMember_Value_T& second, _TypeCodeMember_Value_T& third, _Operator _operator, uDDSCdrTCKind type);

	/* 将打印信息打印出来 */
	int printf_ExpressionRule(_Expression_Rule& Rule);
private:
	vector<_Expression_Rule> m_RulesVec;

	map<string, _Operator> m_StringOperatorMap;

	map<_Operator,string> m_OperatorStringMap;

	TypeCode* m_pRelateTypeCode;

};

