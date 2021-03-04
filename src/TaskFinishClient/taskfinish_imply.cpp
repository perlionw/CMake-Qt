#include "taskfinish_imply.h"
#include "TaskFinishStub.h"
#include "Service.nsmap"


char server_task_finish[512] = { 0 };
std::string server_3 = "";

EXP(int) init_taskfinsih_config(const char* server)
{
	sprintf_s(server_task_finish, server);
	server_3 = server_task_finish;
	return 0;
}

EXP(int) GetTaskFinishInfoByTime(std::string start_time, std::string end_time, std::vector<TaskFinishInfo>& task_finish_infos)
{
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskFinish::_ns5__GetTaskFinishInfoByTime *send_temp = new TaskFinish::_ns5__GetTaskFinishInfoByTime;

	send_temp->StartTime = start_time;
	send_temp->EndTime = end_time;
	TaskFinish::_ns5__GetTaskFinishInfoByTimeResponse *recv_temp = new TaskFinish::_ns5__GetTaskFinishInfoByTimeResponse;

	soap_call___ns1__GetTaskFinishInfoByTime(&web_soap, server_3.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			TaskFinishInfo task_finish_info;
			task_finish_info.EndTime = recv_temp->Data->Infos[i]->EndTime;
			task_finish_info.ExcuteRobot = recv_temp->Data->Infos[i]->ExcuteRobot;
			task_finish_info.FinishState = recv_temp->Data->Infos[i]->FinishState;
			task_finish_info.PointList = recv_temp->Data->Infos[i]->PointList;
			task_finish_info.StartTime = recv_temp->Data->Infos[i]->StartTime;
			task_finish_info.TaskId = recv_temp->Data->Infos[i]->TaskId;
			task_finish_info.TaskName = recv_temp->Data->Infos[i]->TaskName;
			task_finish_info.TaskPathId = recv_temp->Data->Infos[i]->TaskPathId;
			task_finish_info.TaskType = recv_temp->Data->Infos[i]->TaskType;
			task_finish_infos.push_back(task_finish_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) GetTaskExcuteInfoByTaskId(std::string task_id, std::vector<TaskExcuteInfo>& task_excute_infos)
{
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	TaskFinish::_ns5__GetTaskExcuteInfoByTaskId *send_temp = new TaskFinish::_ns5__GetTaskExcuteInfoByTaskId;

	send_temp->TaskId = task_id;
	TaskFinish::_ns5__GetTaskExcuteInfoByTaskIdResponse *recv_temp = new TaskFinish::_ns5__GetTaskExcuteInfoByTaskIdResponse;

	soap_call___ns1__GetTaskExcuteInfoByTaskId(&web_soap, server_3.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			TaskExcuteInfo task_excute_info;
			task_excute_info.ExcuteDesc = recv_temp->Data->Infos[i]->ExcuteDesc;
			task_excute_info.ExcuteState = recv_temp->Data->Infos[i]->ExcuteState;
			task_excute_info.ExcuteTime = recv_temp->Data->Infos[i]->ExcuteTime;
			task_excute_info.ExcuteValue = recv_temp->Data->Infos[i]->ExcuteValue;
			task_excute_info.HDPicture = recv_temp->Data->Infos[i]->HDPicture;
			task_excute_info.InfraredPicture = recv_temp->Data->Infos[i]->InfraredPicture;
			task_excute_info.PointId = recv_temp->Data->Infos[i]->PointId;
			task_excute_info.PointName = recv_temp->Data->Infos[i]->PointName;
			task_excute_info.PointType = recv_temp->Data->Infos[i]->PointType;
			task_excute_info.TargetId = recv_temp->Data->Infos[i]->TargetId;
			task_excute_info.TaskId = recv_temp->Data->Infos[i]->TaskId;
			task_excute_info.TaskName = recv_temp->Data->Infos[i]->TaskName;
			task_excute_info.TaskPathId = recv_temp->Data->Infos[i]->TaskPathId;
			task_excute_info.TaskType = recv_temp->Data->Infos[i]->TaskType;
			task_excute_infos.push_back(task_excute_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}