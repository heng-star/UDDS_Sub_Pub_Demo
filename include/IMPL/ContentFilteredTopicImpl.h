/************************************************************
** �ļ�����ContentFilteredTopicImpl.h
** Copyright (c) 2022-2024 �Ͼ�������Ϣ�Ƽ����޹�˾
** �����ˣ�Nephalem<250610346@qq.com>
** ��  �ڣ�2022-04-06
** �޸��ˣ���
** ��  �ڣ���
** ��  ����ContentFilteredTopicImplͷ�ļ�
** ��  ����Version 0.1
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
	/* DDSЭ����ؽӿ� */
	/* JDXCZ 2022-04-06 ��ȡ�������Topic */
	TopicImpl* get_related_topic(); //

	/* JDXCZ 2022-04-06 ��ȡ������������ز��� */
	ReturnCode_t get_expression_parameters(StringSeq& expression_parameters);

	/* JDXCZ 2022-04-06 ���ù�����������ز��� */
	ReturnCode_t set_expression_parameters(StringSeq& expression_parameters);

public:
	/* JD �Զ�����ؽӿ� */
	ContentFilteredTopicImpl(const string strTopicName, DomainParticipantImpl* pDomainParticipantImpl, TopicImpl* pRelated_TopicImpl, const string strFilter_Expression,  StringSeq Parameters);
	~ContentFilteredTopicImpl();

	/* JD ��ȡ�û�ʹ�õ�ContentFilteredTopic */
	ContentFilteredTopic* GetUserContentFilteredTopic();

	void SetDataFilter(DDSContentFilter* pDataFilter);

	/* JD ��ȡ���ݹ�����  */
	DDSContentFilter* GetDataFilter();
	
	/* JD ��ȡContentFilteredTopic ������ */
	string get_topic_name();

	/* JD �������������õĹ������� */
	ReturnCode_t deal_filter_expression(string filter_expression, StringSeq Parameters);

	/* Nephalem ��ȡTopicQos */
	virtual ReturnCode_t get_qos(TopicQos& QoS);


private:
	/* JD �û�ʹ�õ�ContentFilteredTopicָ�� */
	ContentFilteredTopic* m_pUserContentFilteredTopic;

	/* JD ContentfilteredTopic������ */
	string m_strContentFilteredTopicName;

	/* JD ���ݹ��������Ĳ��� */
	StringSeq m_Parameters;

	/* JD ���ݹ������� */
	string m_strFilter_Expression;

	/* JD ������TopicImpl */
	TopicImpl* m_pRelatedTopicImpl;

	/* JD  ���ݹ����������ڰ����������ݹ�������  void*  */
	DDSContentFilter* m_pDataFilter;
};
#endif //_CONTENTFILTEREDTOPIC_IMPL_H