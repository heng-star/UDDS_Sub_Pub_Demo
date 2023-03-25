/************************************************************
** 文件名：ContentFilteredTopicImpl.h
** Copyright (c) 2022-2024 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2022-04-06
** 修改人：无
** 日  期：无
** 描  述：ContentFilteredTopicImpl头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _CONTENTFILTEREDTOPIC_IMPL_H
#define _CONTENTFILTEREDTOPIC_IMPL_H

#include "BasicTypes.h"
#include "IMPL/TopicDescriptionImpl.h"

class Topic;
class Filter;
class TypeCode;
class DDSContentFilter;

class ContentFilteredTopicImpl : public TopicDescriptionImpl
{
public:
	/* DDS协议相关接口 */
	/* JDXCZ 2022-04-06 获取相关联的Topic */
	TopicImpl* get_related_topic(); //

	/* JDXCZ 2022-04-06 获取过滤条件的相关参数 */
	ReturnCode_t get_expression_parameters(StringSeq& expression_parameters);

	/* JDXCZ 2022-04-06 设置过滤条件的相关参数 */
	ReturnCode_t set_expression_parameters(StringSeq& expression_parameters);

public:
	/* JD 自定义相关接口 */
	ContentFilteredTopicImpl(const string strTopicName, DomainParticipantImpl* pDomainParticipantImpl, TopicImpl* pRelated_TopicImpl, const string strFilter_Expression,  StringSeq Parameters);
	~ContentFilteredTopicImpl();

	/* JD 获取用户使用的ContentFilteredTopic */
	ContentFilteredTopic* GetUserContentFilteredTopic();

	void SetDataFilter(DDSContentFilter* pDataFilter);

	/* JD 获取数据过滤器  */
	DDSContentFilter* GetDataFilter();
	
	/* JD 获取ContentFilteredTopic 的名称 */
	string get_topic_name();

	/* JD 分析，解析设置的过滤条件 */
	ReturnCode_t deal_filter_expression(string filter_expression, StringSeq Parameters);

	/* Nephalem 获取TopicQos */
	virtual ReturnCode_t get_qos(TopicQos& QoS);


private:
	/* JD 用户使用的ContentFilteredTopic指针 */
	ContentFilteredTopic* m_pUserContentFilteredTopic;

	/* JD ContentfilteredTopic的名称 */
	string m_strContentFilteredTopicName;

	/* JD 内容过滤条件的参数 */
	StringSeq m_Parameters;

	/* JD 内容过滤条件 */
	string m_strFilter_Expression;

	/* JD 关联的TopicImpl */
	TopicImpl* m_pRelatedTopicImpl;

	/* JD  数据过滤器，用于按照数据内容过滤数据  void*  */
	DDSContentFilter* m_pDataFilter;
};
#endif //_CONTENTFILTEREDTOPIC_IMPL_H