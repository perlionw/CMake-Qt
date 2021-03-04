#include "taskdata_imply.h"
#include "TaskDataStub.h"
#include "Service.nsmap"
char server2[512] = { 0 };
std::string server_2 = "";

EXP(int) init_taskdata_config(const char* server)
{
	sprintf_s(server2, server);
	server_2 = server2;
	return 0;
}

EXP(int) GetMapAreaInfo(std::vector<MapAreaInfo>& map_area_infos)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetMapAreaInfo *send_temp = new TaskData::_ns4__GetMapAreaInfo;
	TaskData::_ns4__GetMapAreaInfoResponse *recv_temp = new TaskData::_ns4__GetMapAreaInfoResponse;

	soap_call___ns1__GetMapAreaInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			MapAreaInfo map_area_info;
			map_area_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			map_area_info.MaxX = recv_temp->Data->Infos[i]->MaxX;
			map_area_info.MaxY = recv_temp->Data->Infos[i]->MaxY;
			map_area_info.MinX = recv_temp->Data->Infos[i]->MinX;
			map_area_info.MinY = recv_temp->Data->Infos[i]->MinY;
			map_area_info.ParentId = recv_temp->Data->Infos[i]->ParentId;
			map_area_info.AreaId = recv_temp->Data->Infos[i]->AreaId;
			map_area_info.AreaMap = recv_temp->Data->Infos[i]->AreaMap;
			map_area_info.AreaName = recv_temp->Data->Infos[i]->AreaName;
			map_area_infos.push_back(map_area_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetPatrolAreaInfo(std::vector<PatrolValueInfo>& patrol_value_infos)
{
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetPatrolAreaInfo *send_temp = new TaskData::_ns4__GetPatrolAreaInfo;
	TaskData::_ns4__GetPatrolAreaInfoResponse *recv_temp = new TaskData::_ns4__GetPatrolAreaInfoResponse;

	soap_call___ns1__GetPatrolAreaInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			PatrolValueInfo patrol_value_info;
			patrol_value_info.AreaId = recv_temp->Data->Infos[i]->AreaId;
			patrol_value_info.ParentId = recv_temp->Data->Infos[i]->ParentId;
			patrol_value_info.AreaName = recv_temp->Data->Infos[i]->AreaName;
			patrol_value_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			patrol_value_infos.push_back(patrol_value_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetMapEdgeInfo(std::string area_id, std::vector<MapEdgeInfo>& map_edge_infos)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetMapEdgeInfo *send_temp = new TaskData::_ns4__GetMapEdgeInfo;
	send_temp->AreaId = area_id;
	TaskData::_ns4__GetMapEdgeInfoResponse *recv_temp = new TaskData::_ns4__GetMapEdgeInfoResponse;

	soap_call___ns1__GetMapEdgeInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			MapEdgeInfo map_edge_info;
			map_edge_info.EdgeId = recv_temp->Data->Infos[i]->EdgeId;
			map_edge_info.EndNodeId = recv_temp->Data->Infos[i]->EndNodeId;
			map_edge_info.EndNodeX = recv_temp->Data->Infos[i]->EndNodeX;
			map_edge_info.EndNodeY = recv_temp->Data->Infos[i]->EndNodeY;
			map_edge_info.FirstControlX = recv_temp->Data->Infos[i]->FirstControlX;
			map_edge_info.FirstControlY = recv_temp->Data->Infos[i]->FirstControlY;
			map_edge_info.SecondControlX = recv_temp->Data->Infos[i]->SecondControlX;
			map_edge_info.SecondControlY = recv_temp->Data->Infos[i]->SecondControlY;
			map_edge_info.StartNodeId = recv_temp->Data->Infos[i]->StartNodeId;
			map_edge_info.StartNodeX = recv_temp->Data->Infos[i]->StartNodeX;
			map_edge_info.StartNodeY = recv_temp->Data->Infos[i]->StartNodeY;
			map_edge_infos.push_back(map_edge_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetDockPointInfo(std::vector<DockPointInfo>& dock_point_infos)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetDockPointInfo *send_temp = new TaskData::_ns4__GetDockPointInfo;
	TaskData::_ns4__GetDockPointInfoResponse *recv_temp = new TaskData::_ns4__GetDockPointInfoResponse;

	soap_call___ns1__GetDockPointInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			DockPointInfo dock_point_info;
			dock_point_info.DockId = recv_temp->Data->Infos[i]->DockId;
			dock_point_info.DockX = recv_temp->Data->Infos[i]->DockX;
			dock_point_info.DockY = recv_temp->Data->Infos[i]->DockY;
			dock_point_info.PointList = recv_temp->Data->Infos[i]->PointList;
			dock_point_infos.push_back(dock_point_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetPatrolPointInfo(std::vector<PatrolPointInfo>& patrol_point_infos)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetPatrolPointInfo *send_temp = new TaskData::_ns4__GetPatrolPointInfo;
	TaskData::_ns4__GetPatrolPointInfoResponse *recv_temp = new TaskData::_ns4__GetPatrolPointInfoResponse;

	soap_call___ns1__GetPatrolPointInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			PatrolPointInfo patrol_point_info;
			patrol_point_info.AreaId = recv_temp->Data->Infos[i]->AreaId;
			patrol_point_info.DockId = recv_temp->Data->Infos[i]->DockId;
			patrol_point_info.PointId = recv_temp->Data->Infos[i]->PointId;
			patrol_point_info.DeviceType = recv_temp->Data->Infos[i]->DeviceType;
			patrol_point_info.PointName = recv_temp->Data->Infos[i]->PointName;
			patrol_point_info.PointType = recv_temp->Data->Infos[i]->PointType;
			patrol_point_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			patrol_point_infos.push_back(patrol_point_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetTaskPathInfo(std::vector<TaskPathInfo>& task_path_infos)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetTaskPathInfo *send_temp = new TaskData::_ns4__GetTaskPathInfo;
	TaskData::_ns4__GetTaskPathInfoResponse *recv_temp = new TaskData::_ns4__GetTaskPathInfoResponse;

	soap_call___ns1__GetTaskPathInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			TaskPathInfo task_path_info;
			task_path_info.TaskPathId = recv_temp->Data->Infos[i]->TaskPathId;
			task_path_info.CreateTime = recv_temp->Data->Infos[i]->CreateTime;
			task_path_info.PointList = recv_temp->Data->Infos[i]->PointList;
			task_path_info.TaskPathName = recv_temp->Data->Infos[i]->TaskPathName;
			task_path_info.TaskPathType = recv_temp->Data->Infos[i]->TaskPathType;
			task_path_info.FinishAction = recv_temp->Data->Infos[i]->FinishAction;
			task_path_infos.push_back(task_path_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) StartTaskByPathId(std::string task_id, std::string task_path_id)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__StartTaskByPathId *send_temp = new TaskData::_ns4__StartTaskByPathId;
	send_temp->TaskPathId = task_path_id;
	send_temp->TaskId = task_id;
	TaskData::_ns4__StartTaskByPathIdResponse *recv_temp = new TaskData::_ns4__StartTaskByPathIdResponse;

	soap_call___ns1__StartTaskByPathId(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (recv_temp->Result)
	{
		//std::cout << "soap error: " << web_soap.error << std::endl;
		result = recv_temp->Result;
	}

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) StartTaskByPointList(std::string task_id, std::vector<std::string >PointList)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__StartTaskByPointList *send_temp = new TaskData::_ns4__StartTaskByPointList;
	send_temp->TaskId = task_id;
	send_temp->PointList = PointList;
	TaskData::_ns4__StartTaskByPointListResponse *recv_temp = new TaskData::_ns4__StartTaskByPointListResponse;

	soap_call___ns1__StartTaskByPointList(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (recv_temp->Result)
	{
		//std::cout << "soap error: " << web_soap.error << std::endl;
		result = recv_temp->Result;
	}

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) RobotControlTask(ControlTaskType control_type)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__RobotControlTask *send_temp = new TaskData::_ns4__RobotControlTask;
	send_temp->Type = (TaskData::ns4__ControlTaskType)control_type;
	TaskData::_ns4__RobotControlTaskResponse *recv_temp = new TaskData::_ns4__RobotControlTaskResponse;

	soap_call___ns1__RobotControlTask(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (recv_temp->Result)
	{
		//std::cout << "soap error: " << web_soap.error << std::endl;
		result = recv_temp->Result;
	}

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetTaskExcuteData(std::string robot_ip, TaskExcuteData& task_excute_data)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__GetTaskExcuteData *send_temp = new TaskData::_ns4__GetTaskExcuteData;
	send_temp->robotIp = robot_ip;
	TaskData::_ns4__GetTaskExcuteDataResponse *recv_temp = new TaskData::_ns4__GetTaskExcuteDataResponse;

	soap_call___ns1__GetTaskExcuteData(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	else
	{
		task_excute_data.ErrorDeviceSize = recv_temp->Data->ErrorDeviceSize;
		task_excute_data.FinishDeviceSize = recv_temp->Data->FinishDeviceSize;
		task_excute_data.PatrolDeviceId = recv_temp->Data->PatrolDeviceId;
		task_excute_data.PatrolDeviceName = recv_temp->Data->PatrolDeviceName;
		task_excute_data.RobotIp = recv_temp->Data->RobotIp;
		task_excute_data.TaskFinishPercentage = recv_temp->Data->TaskFinishPercentage;
		task_excute_data.TaskId = recv_temp->Data->TaskId;
		task_excute_data.TaskName = recv_temp->Data->TaskName;
		task_excute_data.TaskType = recv_temp->Data->TaskType;
		task_excute_data.TotalDeviceSize = recv_temp->Data->TotalDeviceSize;

	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) SetTaskPathInfo(TaskPathInfo task_path_info)
{
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskData::_ns4__SetTaskPathInfo *send_temp = new TaskData::_ns4__SetTaskPathInfo;
	TaskData::ns4__TaskPathInfo* info = new TaskData::ns4__TaskPathInfo;
	info->CreateTime = task_path_info.CreateTime;
	info->FinishAction = task_path_info.FinishAction;
	info->PointList = task_path_info.PointList;
	info->TaskPathId = task_path_info.TaskPathId;
	info->TaskPathName = task_path_info.TaskPathName;
	info->TaskPathType = task_path_info.TaskPathType;
	send_temp->info = info;
	
	TaskData::_ns4__SetTaskPathInfoResponse *recv_temp = new TaskData::_ns4__SetTaskPathInfoResponse;

	soap_call___ns1__SetTaskPathInfo(&web_soap, server_2.c_str(), "", send_temp, recv_temp);

	if (recv_temp->Result)
	{
		//std::cout << "soap error: " << web_soap.error << std::endl;
		result = recv_temp->Result;
	}

	if (web_soap.error)
	{
		result = web_soap.error;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}