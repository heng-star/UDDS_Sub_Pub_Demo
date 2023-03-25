/************************************************************
** �ļ�����ContentFilteredTopic.h
** Copyright (c) 2022-2024 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2022-04-06
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ContentFilteredTopicͷ�ļ�
** ��  ����Version 0.1
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
	/* DDSЭ����ؽӿ� */
	/* JDXCZ 2022-04-06 ��ȡ�������Topic */
	Topic* get_related_topic(); //

	/* JDXCZ 2022-04-06 ��ȡ������������ز��� */
	ReturnCode_t get_expression_parameters(StringSeq& expression_parameters);

	/* JDXCZ 2022-04-06 ���ù�����������ز��� */
	ReturnCode_t set_expression_parameters(StringSeq& expression_parameters);

public:
	/* JD �Զ�����ؽӿ� */
	ContentFilteredTopic(ContentFilteredTopicImpl* pContentFilteredTopicImpl);

	~ContentFilteredTopic();

private:

	ContentFilteredTopicImpl* m_pContentFilteredTopicImpl;
};
#endif //_CONTENTFILTEREDTOPIC_H