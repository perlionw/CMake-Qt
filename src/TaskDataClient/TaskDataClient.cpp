/* TaskDataClient.cpp
   Generated by gSOAP 2.8.16 from .\taskdata.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "TaskDataH.h"

namespace TaskData {

SOAP_SOURCE_STAMP("@(#) TaskDataClient.cpp ver 2.8.16 2020-03-04 05:59:40 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetMapAreaInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetMapAreaInfo *ns4__GetMapAreaInfo, _ns4__GetMapAreaInfoResponse *ns4__GetMapAreaInfoResponse)
{	struct __ns1__GetMapAreaInfo soap_tmp___ns1__GetMapAreaInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetMapAreaInfo.ns4__GetMapAreaInfo = ns4__GetMapAreaInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetMapAreaInfo(soap, &soap_tmp___ns1__GetMapAreaInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetMapAreaInfo(soap, &soap_tmp___ns1__GetMapAreaInfo, "-ns1:GetMapAreaInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetMapAreaInfo(soap, &soap_tmp___ns1__GetMapAreaInfo, "-ns1:GetMapAreaInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetMapAreaInfoResponse)
		return soap_closesock(soap);
	ns4__GetMapAreaInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetMapAreaInfoResponse->soap_get(soap, "ns4:GetMapAreaInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetPatrolAreaInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetPatrolAreaInfo *ns4__GetPatrolAreaInfo, _ns4__GetPatrolAreaInfoResponse *ns4__GetPatrolAreaInfoResponse)
{	struct __ns1__GetPatrolAreaInfo soap_tmp___ns1__GetPatrolAreaInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetPatrolAreaInfo.ns4__GetPatrolAreaInfo = ns4__GetPatrolAreaInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetPatrolAreaInfo(soap, &soap_tmp___ns1__GetPatrolAreaInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetPatrolAreaInfo(soap, &soap_tmp___ns1__GetPatrolAreaInfo, "-ns1:GetPatrolAreaInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetPatrolAreaInfo(soap, &soap_tmp___ns1__GetPatrolAreaInfo, "-ns1:GetPatrolAreaInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetPatrolAreaInfoResponse)
		return soap_closesock(soap);
	ns4__GetPatrolAreaInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetPatrolAreaInfoResponse->soap_get(soap, "ns4:GetPatrolAreaInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetMapEdgeInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetMapEdgeInfo *ns4__GetMapEdgeInfo, _ns4__GetMapEdgeInfoResponse *ns4__GetMapEdgeInfoResponse)
{	struct __ns1__GetMapEdgeInfo soap_tmp___ns1__GetMapEdgeInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetMapEdgeInfo.ns4__GetMapEdgeInfo = ns4__GetMapEdgeInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetMapEdgeInfo(soap, &soap_tmp___ns1__GetMapEdgeInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetMapEdgeInfo(soap, &soap_tmp___ns1__GetMapEdgeInfo, "-ns1:GetMapEdgeInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetMapEdgeInfo(soap, &soap_tmp___ns1__GetMapEdgeInfo, "-ns1:GetMapEdgeInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetMapEdgeInfoResponse)
		return soap_closesock(soap);
	ns4__GetMapEdgeInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetMapEdgeInfoResponse->soap_get(soap, "ns4:GetMapEdgeInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetDockPointInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetDockPointInfo *ns4__GetDockPointInfo, _ns4__GetDockPointInfoResponse *ns4__GetDockPointInfoResponse)
{	struct __ns1__GetDockPointInfo soap_tmp___ns1__GetDockPointInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetDockPointInfo.ns4__GetDockPointInfo = ns4__GetDockPointInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetDockPointInfo(soap, &soap_tmp___ns1__GetDockPointInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetDockPointInfo(soap, &soap_tmp___ns1__GetDockPointInfo, "-ns1:GetDockPointInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetDockPointInfo(soap, &soap_tmp___ns1__GetDockPointInfo, "-ns1:GetDockPointInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetDockPointInfoResponse)
		return soap_closesock(soap);
	ns4__GetDockPointInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetDockPointInfoResponse->soap_get(soap, "ns4:GetDockPointInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetPatrolPointInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetPatrolPointInfo *ns4__GetPatrolPointInfo, _ns4__GetPatrolPointInfoResponse *ns4__GetPatrolPointInfoResponse)
{	struct __ns1__GetPatrolPointInfo soap_tmp___ns1__GetPatrolPointInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetPatrolPointInfo.ns4__GetPatrolPointInfo = ns4__GetPatrolPointInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetPatrolPointInfo(soap, &soap_tmp___ns1__GetPatrolPointInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetPatrolPointInfo(soap, &soap_tmp___ns1__GetPatrolPointInfo, "-ns1:GetPatrolPointInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetPatrolPointInfo(soap, &soap_tmp___ns1__GetPatrolPointInfo, "-ns1:GetPatrolPointInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetPatrolPointInfoResponse)
		return soap_closesock(soap);
	ns4__GetPatrolPointInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetPatrolPointInfoResponse->soap_get(soap, "ns4:GetPatrolPointInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTaskPathInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetTaskPathInfo *ns4__GetTaskPathInfo, _ns4__GetTaskPathInfoResponse *ns4__GetTaskPathInfoResponse)
{	struct __ns1__GetTaskPathInfo soap_tmp___ns1__GetTaskPathInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetTaskPathInfo.ns4__GetTaskPathInfo = ns4__GetTaskPathInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetTaskPathInfo(soap, &soap_tmp___ns1__GetTaskPathInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetTaskPathInfo(soap, &soap_tmp___ns1__GetTaskPathInfo, "-ns1:GetTaskPathInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetTaskPathInfo(soap, &soap_tmp___ns1__GetTaskPathInfo, "-ns1:GetTaskPathInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetTaskPathInfoResponse)
		return soap_closesock(soap);
	ns4__GetTaskPathInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetTaskPathInfoResponse->soap_get(soap, "ns4:GetTaskPathInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__StartTaskByPathId(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__StartTaskByPathId *ns4__StartTaskByPathId, _ns4__StartTaskByPathIdResponse *ns4__StartTaskByPathIdResponse)
{	struct __ns1__StartTaskByPathId soap_tmp___ns1__StartTaskByPathId;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__StartTaskByPathId.ns4__StartTaskByPathId = ns4__StartTaskByPathId;
	soap_serializeheader(soap);
	soap_serialize___ns1__StartTaskByPathId(soap, &soap_tmp___ns1__StartTaskByPathId);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__StartTaskByPathId(soap, &soap_tmp___ns1__StartTaskByPathId, "-ns1:StartTaskByPathId", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__StartTaskByPathId(soap, &soap_tmp___ns1__StartTaskByPathId, "-ns1:StartTaskByPathId", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__StartTaskByPathIdResponse)
		return soap_closesock(soap);
	ns4__StartTaskByPathIdResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__StartTaskByPathIdResponse->soap_get(soap, "ns4:StartTaskByPathIdResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__StartTaskByPointList(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__StartTaskByPointList *ns4__StartTaskByPointList, _ns4__StartTaskByPointListResponse *ns4__StartTaskByPointListResponse)
{	struct __ns1__StartTaskByPointList soap_tmp___ns1__StartTaskByPointList;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__StartTaskByPointList.ns4__StartTaskByPointList = ns4__StartTaskByPointList;
	soap_serializeheader(soap);
	soap_serialize___ns1__StartTaskByPointList(soap, &soap_tmp___ns1__StartTaskByPointList);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__StartTaskByPointList(soap, &soap_tmp___ns1__StartTaskByPointList, "-ns1:StartTaskByPointList", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__StartTaskByPointList(soap, &soap_tmp___ns1__StartTaskByPointList, "-ns1:StartTaskByPointList", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__StartTaskByPointListResponse)
		return soap_closesock(soap);
	ns4__StartTaskByPointListResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__StartTaskByPointListResponse->soap_get(soap, "ns4:StartTaskByPointListResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__SetTaskPathInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__SetTaskPathInfo *ns4__SetTaskPathInfo, _ns4__SetTaskPathInfoResponse *ns4__SetTaskPathInfoResponse)
{	struct __ns1__SetTaskPathInfo soap_tmp___ns1__SetTaskPathInfo;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__SetTaskPathInfo.ns4__SetTaskPathInfo = ns4__SetTaskPathInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__SetTaskPathInfo(soap, &soap_tmp___ns1__SetTaskPathInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__SetTaskPathInfo(soap, &soap_tmp___ns1__SetTaskPathInfo, "-ns1:SetTaskPathInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__SetTaskPathInfo(soap, &soap_tmp___ns1__SetTaskPathInfo, "-ns1:SetTaskPathInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__SetTaskPathInfoResponse)
		return soap_closesock(soap);
	ns4__SetTaskPathInfoResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__SetTaskPathInfoResponse->soap_get(soap, "ns4:SetTaskPathInfoResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__RobotControlTask(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__RobotControlTask *ns4__RobotControlTask, _ns4__RobotControlTaskResponse *ns4__RobotControlTaskResponse)
{	struct __ns1__RobotControlTask soap_tmp___ns1__RobotControlTask;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__RobotControlTask.ns4__RobotControlTask = ns4__RobotControlTask;
	soap_serializeheader(soap);
	soap_serialize___ns1__RobotControlTask(soap, &soap_tmp___ns1__RobotControlTask);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__RobotControlTask(soap, &soap_tmp___ns1__RobotControlTask, "-ns1:RobotControlTask", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__RobotControlTask(soap, &soap_tmp___ns1__RobotControlTask, "-ns1:RobotControlTask", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__RobotControlTaskResponse)
		return soap_closesock(soap);
	ns4__RobotControlTaskResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__RobotControlTaskResponse->soap_get(soap, "ns4:RobotControlTaskResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTaskExcuteData(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns4__GetTaskExcuteData *ns4__GetTaskExcuteData, _ns4__GetTaskExcuteDataResponse *ns4__GetTaskExcuteDataResponse)
{	struct __ns1__GetTaskExcuteData soap_tmp___ns1__GetTaskExcuteData;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:80";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__GetTaskExcuteData.ns4__GetTaskExcuteData = ns4__GetTaskExcuteData;
	soap_serializeheader(soap);
	soap_serialize___ns1__GetTaskExcuteData(soap, &soap_tmp___ns1__GetTaskExcuteData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__GetTaskExcuteData(soap, &soap_tmp___ns1__GetTaskExcuteData, "-ns1:GetTaskExcuteData", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__GetTaskExcuteData(soap, &soap_tmp___ns1__GetTaskExcuteData, "-ns1:GetTaskExcuteData", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!ns4__GetTaskExcuteDataResponse)
		return soap_closesock(soap);
	ns4__GetTaskExcuteDataResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns4__GetTaskExcuteDataResponse->soap_get(soap, "ns4:GetTaskExcuteDataResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

} // namespace TaskData


#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of TaskDataClient.cpp */