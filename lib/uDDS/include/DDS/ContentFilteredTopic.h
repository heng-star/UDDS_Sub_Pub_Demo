/************************************************************
** 文件名：ContentFilteredTopic.h
** Copyright (c) 2022-2024 南京磐优信息科技有限公司
** 创建人：Nephalem<250610346@qq.com>
** 日  期：2022-04-06
** 修改人：无
** 日  期：无
** 描  述：ContentFilteredTopic头文件
** 版  本：Version 0.1
**----------------------------------------------------------
************************************************************/
#ifndef _CONTENTFILTEREDTOPIC_H
#define _CONTENTFILTEREDTOPIC_H

#include "BasicTypes.h"
#include "DDS/TopicDescription.h"

class Topic;
class Filter;
class TypeCode;
class ContentFilteredTopicImpl;

class ContentFilteredTopic : public TopicDescription
{
public:
	/* DDS协议相关接口 */
	/* JDXCZ 2022-04-06 获取相关联的Topic */
	Topic* get_related_topic(); //

	/* JDXCZ 2022-04-06 获取过滤条件的相关参数 */
	ReturnCode_t get_expression_parameters(StringSeq& expression_parameters);

	/* JDXCZ 2022-04-06 设置过滤条件的相关参数 */
	ReturnCode_t set_expression_parameters(StringSeq& expression_parameters);

public:
	/* JD 自定义相关接口 */
	ContentFilteredTopic(ContentFilteredTopicImpl* pContentFilteredTopicImpl);

	~ContentFilteredTopic();

private:

	ContentFilteredTopicImpl* m_pContentFilteredTopicImpl;
};
#endif //_CONTENTFILTEREDTOPIC_H