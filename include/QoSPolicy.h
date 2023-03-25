#pragma once
#include "BasicTypes.h"
#include "SequenceType.h"

#include <string>
using std::string;

//const  string  USERDATA_QOS_POLICY_NAME				= "UserData";
//const  string  DURABILITY_QOS_POLICY_NAME			= "Durability";
//const  string  PRESENTATION_QOS_POLICY_NAME			= "Presentation";
//const  string  DEADLINE_QOS_POLICY_NAME				= "Deadline";
//const  string  LATENCYBUDGET_QOS_POLICY_NAME		= "LatencyBudget";
//const  string  OWNERSHIP_QOS_POLICY_NAME			= "Ownership";
//const  string  OWNERSHIPSTRENGTH_QOS_POLICY_NAME	= "OwnershipStrength";
//const  string  LIVELINESS_QOS_POLICY_NAME			= "Liveliness";
//const  string  TIMEBASEDFILTER_QOS_POLICY_NAME		= "TimeBasedFilter";
//const  string  PARTITION_QOS_POLICY_NAME			= "Partition";
//const  string  RELIABILITY_QOS_POLICY_NAME			= "Reliability";
//const  string  DESTINATIONORDER_QOS_POLICY_NAME		= "DestinationOrder";
//const  string  HISTORY_QOS_POLICY_NAME				= "History";
//const  string  RESOURCELIMITS_QOS_POLICY_NAME		= "ResourceLimits";
//const  string  ENTITYFACTORY_QOS_POLICY_NAME		= "EntityFactory";
//const  string  WRITERDATALIFECYCLE_QOS_POLICY_NAME	= "WriterDataLifecycle";
//const  string  READERDATALIFECYCLE_QOS_POLICY_NAME	= "ReaderDataLifecycle";
//const  string  TOPICDATA_QOS_POLICY_NAME			= "TopicData";
//const  string  GROUPDATA_QOS_POLICY_NAME			= "TransportPriority";
//const  string  LIFESPAN_QOS_POLICY_NAME				= "Lifespan";
//const  string  DURABILITYSERVICE_POLICY_NAME		= "DurabilityService";
//
//
////用于字符串转为枚举类型
////DDS_DurabilityQosPolicyKind
//const string S_VOLATILE_DURABILITY_QOS = "VOLATILE_DURABILITY_QOS";
//const string S_TRANSIENT_LOCAL_DURABILITY_QOS = "TRANSIENT_LOCAL_DURABILITY_QOS";
//const string S_TRANSIENT_DURABILITY_QOS = "TRANSIENT_DURABILITY_QOS";
//const string S_PERSISTENT_DURABILITY_QOS = "PERSISTENT_DURABILITY_QOS";
////DDS_HistoryQosPolicyKind
//const string S_KEEP_LAST_HISTORY_QOS = "KEEP_LAST_HISTORY_QOS";
//const string S_KEEP_ALL_HISTORY_QOS = "KEEP_ALL_HISTORY_QOS";
////DDS_LivelinessQosPolicyKind
//const string S_AUTOMATIC_LIVELINESS_QOS = "AUTOMATIC_LIVELINESS_QOS";
//const string S_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS = "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS";
//const string S_MANUAL_BY_TOPIC_LIVELINESS_QOS = "MANUAL_BY_TOPIC_LIVELINESS_QOS";
////DDS_ReliabilityQosPolicyKind
//const string S_BEST_EFFORT_RELIABILITY_QOS = "BEST_EFFORT_RELIABILITY_QOS";
//const string S_RELIABLE_RELIABILITY_QOS = "RELIABLE_RELIABILITY_QOS";
////DDS_ReliabilityQosPolicyAcknowledgmentModeKind
//const string S_PROTOCOL_ACKNOWLEDGMENT_MODE = "PROTOCOL_ACKNOWLEDGMENT_MODE";
//const string S_APPLICATION_AUTO_ACKNOWLEDGMENT_MODE = "APPLICATION_AUTO_ACKNOWLEDGMENT_MODE";
//const string S_APPLICATION_ORDERED_ACKNOWLEDGMENT_MODE = "APPLICATION_ORDERED_ACKNOWLEDGMENT_MODE";
//const string S_APPLICATION_EXPLICIT_ACKNOWLEDGMENT_MODE = "APPLICATION_EXPLICIT_ACKNOWLEDGMENT_MODE";
////DDS_DestinationOrderQosPolicyKind
//const string S_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS = "BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS";
//const string S_BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS = "BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS";
////DDS_DestinationOrderQosPolicyScopeKind
//const string S_INSTANCE_SCOPE_DESTINATIONORDER_QOS = "INSTANCE_SCOPE_DESTINATIONORDER_QOS";
//const string TOPIC_SCOPE_DESTINATIONORDER_QOS = "TOPIC_SCOPE_DESTINATIONORDER_QOS";
////DDS_RefilterQosPolicyKind
//const string S_NONE_REFILTER_QOS = "NONE_REFILTER_QOS";
//const string S_ALL_REFILTER_QOS = "ALL_REFILTER_QOS";
//const string S_ON_DEMAND_REFILTER_QOS = "ON_DEMAND_REFILTER_QOS";
////DDS_OwnershipQosPolicyKind
//const string S_SHARED_OWNERSHIP_QOS = "SHARED_OWNERSHIP_QOS";
//const string S_EXCLUSIVE_OWNERSHIP_QOS = "EXCLUSIVE_OWNERSHIP_QOS";
//
////DDS_PresentationQosPolicyAccessScopeKind
//const string S_INSTANCE_PRESENTATION_QOS = "INSTANCE_PRESENTATION_QOS";
//const string S_TOPIC_PRESENTATION_QOS = "TOPIC_PRESENTATION_QOS";
//const string S_GROUP_PRESENTATION_QOS = "GROUP_PRESENTATION_QOS";
//const string S_HIGHEST_OFFERED_PRESENTATION_QOS = "HIGHEST_OFFERED_PRESENTATION_QOS";
////DDS_PUBLISHERMASK
//const string S_MASK_NONE = "MASK_NONE";
//const string S_MASK_DEFAULT = "MASK_DEFAULT";
//const string S_MASK_ALL = "MASK_ALL";
////DDS_Priority
//const string S_THREAD_PRIORITY_DEFAULT = "THREAD_PRIORITY_DEFAULT";
//const string S_THREAD_PRIORITY_HIGH = "S_THREAD_PRIORITY_HIGH";
//const string S_THREAD_PRIORITY_ABOVE_NORMAL = "THREAD_PRIORITY_ABOVE_NORMAL";
//const string S_THREAD_PRIORITY_NORMAL = "THREAD_PRIORITY_NORMAL";
//const string S_THREAD_PRIORITY_BELOW_NORMAL = "THREAD_PRIORITY_BELOW_NORMAL";
//const string S_THREAD_PRIORITY_LOW = "THREAD_PRIORITY_LOW";
//
////DDS_RtpsAutoIdKind
//const string S_RTPS_AUTO_ID_FROM_IP = "RTPS_AUTO_ID_FROM_IP";
//const string S_TPS_AUTO_ID_FROM_MAC = "TPS_AUTO_ID_FROM_MAC";
//const string S_RTPS_AUTO_ID_FROM_UUID = "RTPS_AUTO_ID_FROM_UUID";
////DDS_ParticipantQosMask
//const string S_FLOATING_POINT = "FLOATING_POINT";
//const string S_STDIO = "STDIO";
//const string S_REALTIME_PRIORITY = "REALTIME_PRIORITY";
//const string S_PRIORITY_ENFORCE = "PRIORITY_ENFORCE";
//const string S_CANCEL_ASYNCHRONOUS = "CANCEL_ASYNCHRONOUS";
//const string S_STDIO_FLOATING_POINT = "STDIO_FLOATING_POINT";
//
////DDS_DataWriterResourceLimitsInstanceReplacementKind
//const string S_UNREGISTERED_INSTANCE_REPLACEMENT = "UNREGISTERED_INSTANCE_REPLACEMENT";
//const string S_ALIVE_INSTANCE_REPLACEMENT = "ALIVE_INSTANCE_REPLACEMENT";
//const string S_DISPOSED_INSTANCE_REPLACEMENT = "DISPOSED_INSTANCE_REPLACEMENT";
//const string S_ALIVE_THEN_DISPOSED_INSTANCE_REPLACEMENT = "ALIVE_THEN_DISPOSED_INSTANCE_REPLACEMENT";
//const string S_DISPOSED_THEN_ALIVE_INSTANCE_REPLACEMENT = "DISPOSED_THEN_ALIVE_INSTANCE_REPLACEMENT";
//const string S_ALIVE_OR_DISPOSED_INSTANCE_REPLACEMENT = "ALIVE_OR_DISPOSED_INSTANCE_REPLACEMENT";
////DDS_PublishModeQosPolicyKind
//const string S_SYNCHRONOUS_PUBLISH_MODE_QOS = "SYNCHRONOUS_PUBLISH_MODE_QOS";
//const string S_ASYNCHRONOUS_PUBLISH_MODE_QOS = "ASYNCHRONOUS_PUBLISH_MODE_QOS";
//
////DDS_TypeConsistencyKind
//const string S_DISALLOW_TYPE_COERCION = "DISALLOW_TYPE_COERCION";
//const string S_ALLOW_TYPE_COERCION = "ALLOW_TYPE_COERCION";
//const string S_AUTO_TYPE_COERCION = "AUTO_TYPE_COERCION";
//
////字符串转整型
//const string S_DURATION_ZERO_SEC = "DURATION_ZERO_SEC";//零
//const string S_DURATION_INFINITE_SEC = "DURATION_INFINITE_SEC";//无穷大(0x7fffffff)
//const string S_DURATION_ZERO_NSEC = "DURATION_ZERO_NSEC";//零
//const string S_DURATION_INFINITE_NSEC = "DURATION_INFINITE_NSEC";//无穷大(0x7fffffff)
//const string S_LENGTH_UNLIMITED = "LENGTH_UNLIMITED";//长度不限(-1)
//const string S_THREAD_STACK_SIZE_DEFAULT = "THREAD_STACK_SIZE_DEFAULT";//以运行平台为准。。。
//const string S_RTPS_AUTO_ID = "RTPS_AUTO_ID";//默认值：0
//
//typedef long QosPolicyId_t;
//const  QosPolicyId_t  INVALID_QOS_POLICY_ID = 0;
//const  QosPolicyId_t  USERDATA_QOS_POLICY_ID = 1;
//const  QosPolicyId_t  DURABILITY_QOS_POLICY_ID = 2;
//const  QosPolicyId_t  PRESENTATION_QOS_POLICY_ID = 3;
//const  QosPolicyId_t  DEADLINE_QOS_POLICY_ID = 4;
//const  QosPolicyId_t  LATENCYBUDGET_QOS_POLICY_ID = 5;
//const  QosPolicyId_t  OWNERSHIP_QOS_POLICY_ID = 6;
//const  QosPolicyId_t  OWNERSHIPSTRENGTH_QOS_POLICY_ID = 7;
//const  QosPolicyId_t  LIVELINESS_QOS_POLICY_ID = 8;
//const  QosPolicyId_t  TIMEBASEDFILTER_QOS_POLICY_ID = 9;
//const  QosPolicyId_t  PARTITION_QOS_POLICY_ID = 10;
//const  QosPolicyId_t  RELIABILITY_QOS_POLICY_ID = 11;
//const  QosPolicyId_t  DESTINATIONORDER_QOS_POLICY_ID = 12;
//const  QosPolicyId_t  HISTORY_QOS_POLICY_ID = 13;
//const  QosPolicyId_t  RESOURCELIMITS_QOS_POLICY_ID = 14;
//const  QosPolicyId_t  ENTITYFACTORY_QOS_POLICY_ID = 15;
//const  QosPolicyId_t  WRITERDATALIFECYCLE_QOS_POLICY_ID = 16;
//const  QosPolicyId_t  READERDATALIFECYCLE_QOS_POLICY_ID = 17;
//const  QosPolicyId_t  TOPICDATA_QOS_POLICY_ID = 18;
//const  QosPolicyId_t  GROUPDATA_QOS_POLICY_ID = 19;
//const  QosPolicyId_t  TRANSPORTPRIORITY_QOS_POLICY_ID = 20;
//const  QosPolicyId_t  LIFESPAN_QOS_POLICY_ID = 21;
//const  QosPolicyId_t  DURABILITYSERVICE_QOS_POLICY_ID = 22;
//
//const unsigned int LENGTH_UNLIMITED = -1;
/*  JDXCZ 2022-07-27 直接在头文件中定义常量出现问题，全部改为宏定义  */
#define  USERDATA_QOS_POLICY_NAME                   "UserData"
#define   DURABILITY_QOS_POLICY_NAME                "Durability"
#define   PRESENTATION_QOS_POLICY_NAME              "Presentation"
#define   DEADLINE_QOS_POLICY_NAME                  "Deadline"
#define   LATENCYBUDGET_QOS_POLICY_NAME             "LatencyBudget"
#define   OWNERSHIP_QOS_POLICY_NAME                 "Ownership"
#define   OWNERSHIPSTRENGTH_QOS_POLICY_NAME         "OwnershipStrength"
#define   LIVELINESS_QOS_POLICY_NAME                "Liveliness"
#define   TIMEBASEDFILTER_QOS_POLICY_NAME           "TimeBasedFilter"
#define   PARTITION_QOS_POLICY_NAME                 "Partition"
#define   RELIABILITY_QOS_POLICY_NAME               "Reliability"
#define   DESTINATIONORDER_QOS_POLICY_NAME          "DestinationOrder"
#define   HISTORY_QOS_POLICY_NAME                   "History"
#define   RESOURCELIMITS_QOS_POLICY_NAME            "ResourceLimits"
#define   ENTITYFACTORY_QOS_POLICY_NAME             "EntityFactory"
#define   WRITERDATALIFECYCLE_QOS_POLICY_NAME       "WriterDataLifecycle"
#define   READERDATALIFECYCLE_QOS_POLICY_NAME       "ReaderDataLifecycle"
#define   TOPICDATA_QOS_POLICY_NAME                 "TopicData"
#define   GROUPDATA_QOS_POLICY_NAME                 "TransportPriority"
#define   LIFESPAN_QOS_POLICY_NAME                  "Lifespan"
#define   DURABILITYSERVICE_POLICY_NAME             "DurabilityService"


//用于字符串转为枚举类型
//DDS_DurabilityQosPolicyKind
#define  S_VOLATILE_DURABILITY_QOS                  "VOLATILE_DURABILITY_QOS"
#define  S_TRANSIENT_LOCAL_DURABILITY_QOS           "TRANSIENT_LOCAL_DURABILITY_QOS"
#define  S_TRANSIENT_DURABILITY_QOS                 "TRANSIENT_DURABILITY_QOS"
#define  S_PERSISTENT_DURABILITY_QOS                "PERSISTENT_DURABILITY_QOS"
//DDS_HistoryQosPolicyKind
#define  S_KEEP_LAST_HISTORY_QOS                    "KEEP_LAST_HISTORY_QOS"
#define  S_KEEP_ALL_HISTORY_QOS                     "KEEP_ALL_HISTORY_QOS"
//DDS_LivelinessQosPolicyKind
#define  S_AUTOMATIC_LIVELINESS_QOS                 "AUTOMATIC_LIVELINESS_QOS"
#define  S_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS     "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS"
#define  S_MANUAL_BY_TOPIC_LIVELINESS_QOS           "MANUAL_BY_TOPIC_LIVELINESS_QOS"
//DDS_ReliabilityQosPolicyKind
#define  S_BEST_EFFORT_RELIABILITY_QOS              "BEST_EFFORT_RELIABILITY_QOS"
#define  S_RELIABLE_RELIABILITY_QOS                 "RELIABLE_RELIABILITY_QOS"
//DDS_ReliabilityQosPolicyAcknowledgmentModeKind
#define  S_PROTOCOL_ACKNOWLEDGMENT_MODE             "PROTOCOL_ACKNOWLEDGMENT_MODE"
#define  S_APPLICATION_AUTO_ACKNOWLEDGMENT_MODE     "APPLICATION_AUTO_ACKNOWLEDGMENT_MODE"
#define  S_APPLICATION_ORDERED_ACKNOWLEDGMENT_MODE  "APPLICATION_ORDERED_ACKNOWLEDGMENT_MODE"
#define  S_APPLICATION_EXPLICIT_ACKNOWLEDGMENT_MODE "APPLICATION_EXPLICIT_ACKNOWLEDGMENT_MODE"
//DDS_DestinationOrderQosPolicyKind
#define  S_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS "BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS"
#define  S_BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS    "BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS"
//DDS_DestinationOrderQosPolicyScopeKind
#define  S_INSTANCE_SCOPE_DESTINATIONORDER_QOS         "INSTANCE_SCOPE_DESTINATIONORDER_QOS"
#define  TOPIC_SCOPE_DESTINATIONORDER_QOS              "TOPIC_SCOPE_DESTINATIONORDER_QOS"
//DDS_RefilterQosPolicyKind
#define  S_NONE_REFILTER_QOS                           "NONE_REFILTER_QOS"
#define  S_ALL_REFILTER_QOS                            "ALL_REFILTER_QOS"
#define  S_ON_DEMAND_REFILTER_QOS                      "ON_DEMAND_REFILTER_QOS"
//DDS_OwnershipQosPolicyKind
#define  S_SHARED_OWNERSHIP_QOS                        "SHARED_OWNERSHIP_QOS"
#define  S_EXCLUSIVE_OWNERSHIP_QOS                     "EXCLUSIVE_OWNERSHIP_QOS"

//DDS_PresentationQosPolicyAccessScopeKind
#define  S_INSTANCE_PRESENTATION_QOS                   "INSTANCE_PRESENTATION_QOS"
#define  S_TOPIC_PRESENTATION_QOS                      "TOPIC_PRESENTATION_QOS"
#define  S_GROUP_PRESENTATION_QOS                      "GROUP_PRESENTATION_QOS"
#define  S_HIGHEST_OFFERED_PRESENTATION_QOS            "HIGHEST_OFFERED_PRESENTATION_QOS"
//DDS_PUBLISHERMASK
#define  S_MASK_NONE           "MASK_NONE"
#define  S_MASK_DEFAULT        "MASK_DEFAULT"
#define  S_MASK_ALL            "MASK_ALL"
//DDS_Priority
#define  S_THREAD_PRIORITY_DEFAULT                     "THREAD_PRIORITY_DEFAULT"
#define  S_THREAD_PRIORITY_HIGH                        "S_THREAD_PRIORITY_HIGH"
#define  S_THREAD_PRIORITY_ABOVE_NORMAL                "THREAD_PRIORITY_ABOVE_NORMAL"
#define  S_THREAD_PRIORITY_NORMAL                      "THREAD_PRIORITY_NORMAL"
#define  S_THREAD_PRIORITY_BELOW_NORMAL                "THREAD_PRIORITY_BELOW_NORMAL"
#define  S_THREAD_PRIORITY_LOW                         "THREAD_PRIORITY_LOW"

//DDS_RtpsAutoIdKind
#define  S_RTPS_AUTO_ID_FROM_IP                        "RTPS_AUTO_ID_FROM_IP"
#define  S_TPS_AUTO_ID_FROM_MAC                        "TPS_AUTO_ID_FROM_MAC"
#define  S_RTPS_AUTO_ID_FROM_UUID                      "RTPS_AUTO_ID_FROM_UUID"
//DDS_ParticipantQosMask
#define  S_FLOATING_POINT                              "FLOATING_POINT"
#define  S_STDIO                                       "STDIO"
#define  S_REALTIME_PRIORITY                           "REALTIME_PRIORITY"
#define  S_PRIORITY_ENFORCE                            "PRIORITY_ENFORCE"
#define  S_CANCEL_ASYNCHRONOUS                         "CANCEL_ASYNCHRONOUS"
#define  S_STDIO_FLOATING_POINT                        "STDIO_FLOATING_POINT"

//DDS_DataWriterResourceLimitsInstanceReplacementKind
#define  S_UNREGISTERED_INSTANCE_REPLACEMENT           "UNREGISTERED_INSTANCE_REPLACEMENT"
#define  S_ALIVE_INSTANCE_REPLACEMENT                  "ALIVE_INSTANCE_REPLACEMENT"
#define  S_DISPOSED_INSTANCE_REPLACEMENT               "DISPOSED_INSTANCE_REPLACEMENT"
#define  S_ALIVE_THEN_DISPOSED_INSTANCE_REPLACEMENT    "ALIVE_THEN_DISPOSED_INSTANCE_REPLACEMENT"
#define  S_DISPOSED_THEN_ALIVE_INSTANCE_REPLACEMENT    "DISPOSED_THEN_ALIVE_INSTANCE_REPLACEMENT"
#define  S_ALIVE_OR_DISPOSED_INSTANCE_REPLACEMENT      "ALIVE_OR_DISPOSED_INSTANCE_REPLACEMENT"
//DDS_PublishModeQosPolicyKind
#define  S_SYNCHRONOUS_PUBLISH_MODE_QOS                "SYNCHRONOUS_PUBLISH_MODE_QOS"
#define  S_ASYNCHRONOUS_PUBLISH_MODE_QOS               "ASYNCHRONOUS_PUBLISH_MODE_QOS"

//DDS_TypeConsistencyKind
#define  S_DISALLOW_TYPE_COERCION          "DISALLOW_TYPE_COERCION"
#define  S_ALLOW_TYPE_COERCION             "ALLOW_TYPE_COERCION"
#define  S_AUTO_TYPE_COERCION              "AUTO_TYPE_COERCION"

//字符串转整型
#define  S_DURATION_ZERO_SEC               "DURATION_ZERO_SEC"//零
#define  S_DURATION_INFINITE_SEC           "DURATION_INFINITE_SEC"//无穷大(0x7fffffff)
#define  S_DURATION_ZERO_NSEC              "DURATION_ZERO_NSEC"//零
#define  S_DURATION_INFINITE_NSEC          "DURATION_INFINITE_NSEC"//无穷大(0x7fffffff)
#define  S_LENGTH_UNLIMITED                "LENGTH_UNLIMITED"//长度不限(-1)
#define  S_THREAD_STACK_SIZE_DEFAULT       "THREAD_STACK_SIZE_DEFAULT"//以运行平台为准。。。
#define  S_RTPS_AUTO_ID                    "RTPS_AUTO_ID"//默认值：0

typedef long QosPolicyId_t;
#define  INVALID_QOS_POLICY_ID			   0
#define  USERDATA_QOS_POLICY_ID			   1
#define  DURABILITY_QOS_POLICY_ID		   2
#define  PRESENTATION_QOS_POLICY_ID		   3
#define  DEADLINE_QOS_POLICY_ID            4
#define  LATENCYBUDGET_QOS_POLICY_ID       5
#define  OWNERSHIP_QOS_POLICY_ID           6
#define  OWNERSHIPSTRENGTH_QOS_POLICY_ID   7
#define  LIVELINESS_QOS_POLICY_ID          8
#define  TIMEBASEDFILTER_QOS_POLICY_ID     9
#define  PARTITION_QOS_POLICY_ID           10
#define  RELIABILITY_QOS_POLICY_ID         11
#define  DESTINATIONORDER_QOS_POLICY_ID    12
#define  HISTORY_QOS_POLICY_ID             13
#define  RESOURCELIMITS_QOS_POLICY_ID      14
#define  ENTITYFACTORY_QOS_POLICY_ID       15
#define  WRITERDATALIFECYCLE_QOS_POLICY_ID 16
#define  READERDATALIFECYCLE_QOS_POLICY_ID 17
#define TOPICDATA_QOS_POLICY_ID            18
#define  GROUPDATA_QOS_POLICY_ID           19
#define  TRANSPORTPRIORITY_QOS_POLICY_ID   20
#define  LIFESPAN_QOS_POLICY_ID            21
#define  DURABILITYSERVICE_QOS_POLICY_ID   22

#define LENGTH_UNLIMITED  -1

struct UserDataQosPolicy
{
	sequence<octet>  value;
};

struct TopicDataQosPolicy
{
	sequence<octet>  value;
};

struct GroupDataQosPolicy
{
	sequence<octet>  value;
};

struct TransportPriorityQosPolicy
{
	unsigned int			value;

	TransportPriorityQosPolicy() : value(0)
	{
	};
};
struct LifespanQosPolicy
{
	Duration_t	duration;

	LifespanQosPolicy() :duration(TIME_INFINITE)
	{

	};
};

enum DurabilityQosPolicyKind
{
	/* Nephalem 默认属性，没有订阅者时数据不会缓存 */
	VOLATILE_DURABILITY_QOS,
	/* Nephalem 没有订阅者也会缓存数据，数量有history控制 */
	/* Nephalem 目前只对发布方有实际效果 */
	TRANSIENT_LOCAL_DURABILITY_QOS,
	/* Nephalem 可选，数据缓存不受DataWriter生命周期影响 */
	TRANSIENT_DURABILITY_QOS,
	/* Nephalem 可选，数据保存在硬盘中 */
	PERSISTENT_DURABILITY_QOS
};

struct DurabilityQosPolicy
{
	DurabilityQosPolicyKind  kind;

	DurabilityQosPolicy() :kind(VOLATILE_DURABILITY_QOS) {};
};
enum PresentationQosPolicyAccessScopeKind
{
	INSTANCE_PRESENTATION_QOS,
	TOPIC_PRESENTATION_QOS,
	GROUP_PRESENTATION_QOS
};
struct PresentationQosPolicy
{
	PresentationQosPolicyAccessScopeKind	access_scope;
	bool 									coherent_access;
	bool 									ordered_access;

	PresentationQosPolicy() :access_scope(INSTANCE_PRESENTATION_QOS), coherent_access(0), ordered_access(0)
	{

	};
};

struct DeadlineQosPolicy
{
	Duration_t	period;

	DeadlineQosPolicy() : period(TIME_INFINITE)
	{

	};
};

struct LatencyBudgetQosPolicy
{
	Duration_t	duration;

	LatencyBudgetQosPolicy() : duration(TIME_ZERO)
	{

	};
};

enum OwnershipQosPolicyKind
{
	SHARED_OWNERSHIP_QOS,
	EXCLUSIVE_OWNERSHIP_QOS
};

struct OwnershipQosPolicy
{
	OwnershipQosPolicyKind	kind;

	OwnershipQosPolicy():kind(SHARED_OWNERSHIP_QOS)
	{

	}
};

struct OwnershipStrengthQosPolicy
{
	unsigned int		value;

	OwnershipStrengthQosPolicy() :value(0)
	{

	};
};
enum LivelinessQosPolicyKind
{
	AUTOMATIC_LIVELINESS_QOS,
	MANUAL_BY_PARTICIPANT_LIVELINESS_QOS,
	MANUAL_BY_TOPIC_LIVELINESS_QOS
};

struct LivelinessQosPolicy
{
	LivelinessQosPolicyKind		kind;
	Duration_t 					lease_duration;

	LivelinessQosPolicy() : kind(AUTOMATIC_LIVELINESS_QOS), lease_duration(TIME_INFINITE)
	{

	};
};

struct TimeBasedFilterQosPolicy
{
	Duration_t					minimum_separation;

	TimeBasedFilterQosPolicy() : minimum_separation(TIME_ZERO)
	{

	};
};
struct PartitionQosPolicy
{
	StringSeq						name;
};

enum ReliabilityQosPolicyKind
{
	BEST_EFFORT_RELIABILITY_QOS = 1,
	RELIABLE_RELIABILITY_QOS
};

struct ReliabilityQosPolicy
{
	ReliabilityQosPolicyKind 		kind;
	Duration_t 					max_blocking_time;

	ReliabilityQosPolicy()
	{
		this->kind = BEST_EFFORT_RELIABILITY_QOS;
	}
};

enum DestinationOrderQosPolicyKind
{
	BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS,
	BY_SOURCE_TIMESTAMP_DESTINATIONORDER_QOS
};

struct DestinationOrderQosPolicy
{
	DestinationOrderQosPolicyKind	kind;

	DestinationOrderQosPolicy() : kind(BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS)
	{

	};
};

enum HistoryQosPolicyKind
{
	KEEP_LAST_HISTORY_QOS,
	KEEP_ALL_HISTORY_QOS
};

struct HistoryQosPolicy
{
	HistoryQosPolicyKind			kind;
	unsigned int 					depth;

	HistoryQosPolicy()
	{
		kind = KEEP_LAST_HISTORY_QOS;
		depth = 1;
	}
};

struct ResourceLimitsQosPolicy
{
	unsigned int 				max_samples;
	unsigned int 				max_instances;
	unsigned int 				max_samples_per_instance;

	
	ResourceLimitsQosPolicy()
	{
		max_samples = LENGTH_UNLIMITED;
		max_instances = LENGTH_UNLIMITED;
		max_samples_per_instance = LENGTH_UNLIMITED;
	}
};

struct EntityFactoryQosPolicy
{
	bool 					autoenable_created_entities;

	EntityFactoryQosPolicy() :autoenable_created_entities(true)
	{

	};
};

struct WriterDataLifecycleQosPolicy
{
	bool 					autodispose_unregistered_instances;

	WriterDataLifecycleQosPolicy() :autodispose_unregistered_instances(true)
	{

	};
};

struct ReaderDataLifecycleQosPolicy
{
	Duration_t 					autopurge_nowriter_samples_delay;
	Duration_t 					autopurge_disposed_samples_delay;

	ReaderDataLifecycleQosPolicy() :
		autopurge_nowriter_samples_delay(TIME_INFINITE),
		autopurge_disposed_samples_delay(TIME_INFINITE)
	{

	}
};

struct DurabilityServiceQosPolicy
{
	Duration_t 					service_cleanup_delay;
	HistoryQosPolicyKind 		history_kind;
	unsigned int 				history_depth;
	unsigned int 				max_samples;
	unsigned int 				max_instances;
	unsigned int 				max_samples_per_instance;

	DurabilityServiceQosPolicy() :
		service_cleanup_delay(TIME_ZERO),
		history_kind(KEEP_ALL_HISTORY_QOS),
		history_depth(1),
		max_samples(LENGTH_UNLIMITED),
		max_instances(LENGTH_UNLIMITED),
		max_samples_per_instance(LENGTH_UNLIMITED)
	{

	}
};
enum TransportMulticastQosPolicyKind 
{
	DDS_AUTOMATIC_TRANSPORT_MULTICAST_QOS,

	DDS_UNICAST_ONLY_TRANSPORT_MULTICAST_QOS

} ;


struct TransportMulticastSettings
{
	///*e \dref_TransportMulticastSettings_t_transports
	//*/
	//struct DDS_StringSeq transports;

	char* receive_address;

	unsigned int  receive_port;

	TransportMulticastSettings()
	{
		receive_address = NULL;

		receive_port = 0;
	}

};

typedef sequence<TransportMulticastSettings> TransportMulticastSettingsSeq;

struct TransportMulticastQosPolicy
{

	TransportMulticastQosPolicyKind kind;

	TransportMulticastSettingsSeq value;

	TransportMulticastQosPolicy()
	{
		kind = DDS_UNICAST_ONLY_TRANSPORT_MULTICAST_QOS;
	}
};

/* 设置DataWriter为同步发送，还是异步发送 */
typedef enum {
	SYNCHRONOUS_PUBLISH_MODE_QOS, /* 同步 */
	ASYNCHRONOUS_PUBLISH_MODE_QOS /* 异步 */
} PublishModeQosPolicyKind;

struct PublishModeQosPolicy
{
	PublishModeQosPolicyKind kind;
	//char *flow_controller_name;
	//ULINX_INT32 priority;
	PublishModeQosPolicy()
	{
		kind = SYNCHRONOUS_PUBLISH_MODE_QOS;
	}
};

struct DomainParticipantFactoryQos
{
	string strStaicName;		/* JDXCZ 用于设置静态匹配的组件名 */
	
	DomainParticipantFactoryQos()
	{
		strStaicName = "";
	}
	//EntityFactoryQosPolicy 		entity_factory;
};

/* Nephalem 为与RTI兼容，添加非规范内容 */
struct DiscoveryQosPolicy
{
	/* Nephalem 发现地址列表 */
	StringSeq initial_peers;

	/* Nephalem 组播接收地址，发现其他组播的DDS节点 */
	StringSeq multicast_receive_addresses;
};


/***************************************/
struct DomainParticipantQos
{
	UserDataQosPolicy 			user_data;
	EntityFactoryQosPolicy 		entity_factory;

	/* Nephalem 自定义接口 */

	/* Nephalem 兼容RTI，设置组播接收地址*/
	TransportMulticastQosPolicy multicast;

	DiscoveryQosPolicy discovery;
	/* Nephalem uDDS独有接口 */
	const char* local_ip;

	DomainParticipantQos()
	{
		local_ip = NULL;
	}
};

struct TopicQos
{
	TopicDataQosPolicy			topic_data;
	DurabilityQosPolicy 		durability;
	DurabilityServiceQosPolicy 	durability_service;
	DeadlineQosPolicy 			deadline;
	LatencyBudgetQosPolicy		latency_budget;
	LivelinessQosPolicy 		liveliness;
	ReliabilityQosPolicy 		reliability;
	DestinationOrderQosPolicy 	destination_order;
	HistoryQosPolicy 			history;
	ResourceLimitsQosPolicy 	resource_limits;
	TransportPriorityQosPolicy 	transport_priority;
	LifespanQosPolicy 			lifespan;
	OwnershipQosPolicy 			ownership;
};

struct DataWriterQos
{
	TopicDataQosPolicy				topic_data;
	GroupDataQosPolicy				group_data;
	UserDataQosPolicy				user_data;

	DurabilityQosPolicy 			durability;
	DurabilityServiceQosPolicy 		durability_service;
	DeadlineQosPolicy 				deadline;
	LatencyBudgetQosPolicy 			latency_budget;
	LivelinessQosPolicy 			liveliness;
	ReliabilityQosPolicy 			reliability;
	DestinationOrderQosPolicy 		destination_order;
	HistoryQosPolicy 				history;
	ResourceLimitsQosPolicy 		resource_limits;
	TransportPriorityQosPolicy 		transport_priority;
	LifespanQosPolicy				lifespan;

	OwnershipQosPolicy 				ownership;
	OwnershipStrengthQosPolicy 		ownership_strength;
	WriterDataLifecycleQosPolicy 	writer_data_lifecycle;
	/* PublishModeQosPolicy */
	PublishModeQosPolicy publish_mode;
};

struct PublisherQos
{
	PresentationQosPolicy 		presentation;
	PartitionQosPolicy 			partition;
	GroupDataQosPolicy 			group_data;
	EntityFactoryQosPolicy 		entity_factory;
};

struct DataReaderQos
{
	TopicDataQosPolicy 				topic_data;
	GroupDataQosPolicy 				group_data;

	DurabilityQosPolicy 			durability;
	DeadlineQosPolicy 				deadline;
	LatencyBudgetQosPolicy 			latency_budget;
	LivelinessQosPolicy 			liveliness;
	ReliabilityQosPolicy 			reliability;
	DestinationOrderQosPolicy 		destination_order;
	HistoryQosPolicy 				history;
	ResourceLimitsQosPolicy 		resource_limits;
	UserDataQosPolicy 				user_data;
	OwnershipQosPolicy 				ownership;
	TimeBasedFilterQosPolicy 		time_based_filter;
	ReaderDataLifecycleQosPolicy	reader_data_lifecycle;

	/* Nephalem 兼容RTI，设置组播接收地址*/
	TransportMulticastQosPolicy multicast;
};

struct SubscriberQos
{
	PresentationQosPolicy 		presentation;
	PartitionQosPolicy 			partition;
	GroupDataQosPolicy 			group_data;
	EntityFactoryQosPolicy		entity_factory;
};



struct TopicBuiltinTopicData
{
	//BuiltinTopicKey_t 			key;
	//string 						name;
	//string 						type_name;
	//DurabilityQosPolicy 			durability;
	//DurabilityServiceQosPolicy 	durability_service;
	//DeadlineQosPolicy 			deadline;
	//LatencyBudgetQosPolicy 		latency_budget;
	//LivelinessQosPolicy 			liveliness;
	//ReliabilityQosPolicy 			reliability;
	//TransportPriorityQosPolicy 	transport_priority;
	//LifespanQosPolicy 			lifespan;
	//DestinationOrderQosPolicy 	destination_order;
	//HistoryQosPolicy 			history;
	//ResourceLimitsQosPolicy 		resource_limits;
	//OwnershipQosPolicy			ownership;
	//TopicDataQosPolicy 			topic_data;
};

//#define PARTICIPANT_QOS_DEFAULT
//#define TOPIC_QOS_DEFAULT
//#define PUBLISHER_QOS_DEFAULT
//#define SUBSCRIBER_QOS_DEFAULT
//#define DATAWRITER_QOS_DEFAULT
//#define DATAREADER_QOS_DEFAULT
//#define DATAWRITER_QOS_USE_TOPIC_QOS
//#define DATAREADER_QOS_USE_TOPIC_QOS

const DomainParticipantQos PARTICIPANT_QOS_DEFAULT;
const TopicQos TOPIC_QOS_DEFAULT;
const PublisherQos PUBLISHER_QOS_DEFAULT;
const SubscriberQos SUBSCRIBER_QOS_DEFAULT;
const DataWriterQos DATAWRITER_QOS_DEFAULT;
const DataReaderQos DATAREADER_QOS_DEFAULT;


/* Nephalem 为了与RTI兼容，和RTPS规范并不是完全一致*/
struct ParticipantProxy
{
	ProtocolVersion_t		rtps_protocol_version;
	guidPrefix_t			guidPrefix;
	VendorId_t				rtps_vendor_id;
	bool					expectsInlineQos;
	BuiltinEndpointSet_t	dds_builtin_endpoints;
	/* Nephalem SEPD地址 */
	_LOCATOR_LIST_T			metatraffic_unicast_locators;
	/* Nephalem SPDP组播发现地址 默认为239.255.0.1 */
	_LOCATOR_LIST_T			metatraffic_multicast_locators;
	/* Nephalem 用户数据相关默认单播地址 */
	_LOCATOR_LIST_T			default_unicast_locators;
	_LOCATOR_LIST_T			defaultMulticastLocatorList;
	Count_t					manualLivelinessCount;

	Duration_t					lease_duration;

	/* Nephalem 新增*/
	/* Nephalem 为了作为map的key，新增GUID_t,方便查找 EntityID固定为ENTITYID_PARTICIPANT*/
	GUID_t				participantDataWriterGuid;

	/* JD 添加作为静态匹配的配置文件的md5值,用户判断两边的配置文件的版本相同 */
	/* 静态节点的标志位 0-*/
	bool				static_participant;
	string              static_match_participant_name;
	//map<string, string> static_md5_map;
	string				static_match_participant_md5;
	
	ParticipantProxy()
	{
		participantDataWriterGuid.entityId = ENTITYID_PARTICIPANT;
		static_participant = false;
		static_match_participant_name = "";
		static_match_participant_md5 = "";
	}
};

struct ParticipantBuiltinTopicData : ParticipantProxy
{
	BuiltinTopicKey_t 			key;
	UserDataQosPolicy 			user_data;
};


struct SubscriptionBuiltinTopicData
{
	BuiltinTopicKey_t 				key;
	BuiltinTopicKey_t 				participant_key;
	string 							topic_name;
	string 							type_name;
	DurabilityQosPolicy 			durability;
	DeadlineQosPolicy 				deadline;
	LatencyBudgetQosPolicy 			latency_budget;
	LivelinessQosPolicy 			liveliness;
	ReliabilityQosPolicy 			reliability;
	OwnershipQosPolicy 				ownership;
	DestinationOrderQosPolicy 		destination_order;
	UserDataQosPolicy 				user_data;
	TimeBasedFilterQosPolicy 		time_based_filter;
	PresentationQosPolicy 			presentation;
	PartitionQosPolicy 				partition;
	TopicDataQosPolicy 				topic_data;
	GroupDataQosPolicy 				group_data;
};

struct PublicationBuiltinTopicData
{
	BuiltinTopicKey_t 				key;
	BuiltinTopicKey_t 				participant_key;
	string 							topic_name;
	string 							type_name;
	DurabilityQosPolicy 			durability;
	DurabilityServiceQosPolicy		durability_service;
	DeadlineQosPolicy 				deadline;
	LatencyBudgetQosPolicy 			latency_budget;
	LivelinessQosPolicy 			liveliness;
	ReliabilityQosPolicy 			reliability;
	LifespanQosPolicy 				lifespan;
	UserDataQosPolicy 				user_data;
	OwnershipQosPolicy 				ownership;
	OwnershipStrengthQosPolicy 		ownership_strength;
	DestinationOrderQosPolicy 		destination_order;
	PresentationQosPolicy 			presentation;
	PartitionQosPolicy 				partition;
	TopicDataQosPolicy 				topic_data;
	GroupDataQosPolicy 				group_data;
};