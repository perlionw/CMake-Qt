#include "robotdata_imply.h"
#include "RobotDataStub.h"
#include "Service.nsmap"

char server1[512] = { 0 };
std::string server_ = "";
EXP(int) init_robotdata_config(const char* server)
{
	sprintf_s(server1, server);
	server_ = server1;
	return 0;
}

EXP(int) GetRobotConnect(std::vector<RobotConnectInfo>& connect_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotConnect *send_temp = new RobotData::_ns3__GetRobotConnect;


	RobotData::_ns3__GetRobotConnectResponse *recv_temp = new RobotData::_ns3__GetRobotConnectResponse;

	soap_call___ns1__GetRobotConnect(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			RobotConnectInfo connect_info;
			connect_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			connect_info.ConnectDesc = recv_temp->Data->Infos[i]->ConnectDesc;
			connect_info.State = recv_temp->Data->Infos[i]->State;
			connect_infos.push_back(connect_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotInfo(std::vector<RobotInfo>& robot_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotInfo *send_temp = new RobotData::_ns3__GetRobotInfo;


	RobotData::_ns3__GetRobotInfoResponse *recv_temp = new RobotData::_ns3__GetRobotInfoResponse;

	soap_call___ns1__GetRobotInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			RobotInfo robot_info;
			robot_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			robot_info.CameraIp = recv_temp->Data->Infos[i]->CameraIp;
			robot_info.CameraPassword = recv_temp->Data->Infos[i]->CameraPassword;
			robot_info.CameraPort = recv_temp->Data->Infos[i]->CameraPort;
			robot_info.CameraUser = recv_temp->Data->Infos[i]->CameraUser;
			robot_info.FlirIp = recv_temp->Data->Infos[i]->FlirIp;
			robot_info.FlirPassword = recv_temp->Data->Infos[i]->FlirPassword;
			robot_info.FlirPort = recv_temp->Data->Infos[i]->FlirPort;
			robot_info.FlirUser = recv_temp->Data->Infos[i]->FlirUser;
			robot_info.RobotName = recv_temp->Data->Infos[i]->RobotName;
			robot_infos.push_back(robot_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotTime(std::string& robot_time){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotTime *send_temp = new RobotData::_ns3__GetRobotTime;


	RobotData::_ns3__GetRobotTimeResponse *recv_temp = new RobotData::_ns3__GetRobotTimeResponse;

	soap_call___ns1__GetRobotTime(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		robot_time = recv_temp->RobotTime;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) SetRobotTime(std::string robot_time){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__SetRobotTime *send_temp = new RobotData::_ns3__SetRobotTime;
	send_temp->RobotTime = robot_time;

	RobotData::_ns3__SetRobotTimeResponse *recv_temp = new RobotData::_ns3__SetRobotTimeResponse;

	soap_call___ns1__SetRobotTime(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) SetCurrentRobot(std::string robot_ip){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__SetCurrentRobot *send_temp = new RobotData::_ns3__SetCurrentRobot;
	send_temp->RobotIp = robot_ip;

	RobotData::_ns3__SetCurrentRobotResponse *recv_temp = new RobotData::_ns3__SetCurrentRobotResponse;

	soap_call___ns1__SetCurrentRobot(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) ReleaseCurrentRobot(std::string robot_ip){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__ReleaseCurrentRobot *send_temp = new RobotData::_ns3__ReleaseCurrentRobot;
	send_temp->RobotIp = robot_ip;

	RobotData::_ns3__ReleaseCurrentRobotResponse *recv_temp = new RobotData::_ns3__ReleaseCurrentRobotResponse;

	soap_call___ns1__ReleaseCurrentRobot(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) SetControlMode(ControlMode control_mode){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__SetControlMode *send_temp = new RobotData::_ns3__SetControlMode;
	send_temp->ControlType = control_mode.ControlType;
	send_temp->RobotIp = control_mode.robot_ip;
	RobotData::_ns3__SetControlModeResponse *recv_temp = new RobotData::_ns3__SetControlModeResponse;

	soap_call___ns1__SetControlMode(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) GetControlMode(std::string robot_ip, int& control_type){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetControlMode *send_temp = new RobotData::_ns3__GetControlMode;

	send_temp->RobotIp = robot_ip; 
	RobotData::_ns3__GetControlModeResponse *recv_temp = new RobotData::_ns3__GetControlModeResponse;

	soap_call___ns1__GetControlMode(&web_soap, server_.c_str(), "", send_temp, recv_temp);

	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		control_type = recv_temp->ControlType;
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) RobotSpeedControl(SpeedInfo speed){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotSpeedControl *send_temp = new RobotData::_ns3__RobotSpeedControl;

	send_temp->AngularVelocity = speed.AngularVelocity;
	send_temp->LinearVelocity = speed.LinearVelocity;
	RobotData::_ns3__RobotSpeedControlResponse *recv_temp = new RobotData::_ns3__RobotSpeedControlResponse;

	soap_call___ns1__RobotSpeedControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotYuntaiControl(YuntaiControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotYuntaiControl *send_temp = new RobotData::_ns3__RobotYuntaiControl;
	RobotData::ns3__YuntaiControlType type = RobotData::ns3__YuntaiControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotYuntaiControlResponse *recv_temp = new RobotData::_ns3__RobotYuntaiControlResponse;
	
	soap_call___ns1__RobotYuntaiControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotCameraControl(CameraControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotCameraControl *send_temp = new RobotData::_ns3__RobotCameraControl;
	RobotData::ns3__CameraControlType type = RobotData::ns3__CameraControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotCameraControlResponse *recv_temp = new RobotData::_ns3__RobotCameraControlResponse;

	soap_call___ns1__RobotCameraControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotLightControl(LightControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotLightControl *send_temp = new RobotData::_ns3__RobotLightControl;
	RobotData::ns3__LightControlType type = RobotData::ns3__LightControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotLightControlResponse *recv_temp = new RobotData::_ns3__RobotLightControlResponse;

	soap_call___ns1__RobotLightControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotWiperControl(WiperControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotWiperControl *send_temp = new RobotData::_ns3__RobotWiperControl;
	RobotData::ns3__WiperControlType type = RobotData::ns3__WiperControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotWiperControlResponse *recv_temp = new RobotData::_ns3__RobotWiperControlResponse;

	soap_call___ns1__RobotWiperControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotFlirControl(FilrControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotFlirControl *send_temp = new RobotData::_ns3__RobotFlirControl;
	RobotData::ns3__FilrControlType type = RobotData::ns3__FilrControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotFlirControlResponse *recv_temp = new RobotData::_ns3__RobotFlirControlResponse;

	soap_call___ns1__RobotFlirControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotLifterControl(LifterControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotLifterControl *send_temp = new RobotData::_ns3__RobotLifterControl;
	RobotData::ns3__LifterControlType type = RobotData::ns3__LifterControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotLifterControlResponse *recv_temp = new RobotData::_ns3__RobotLifterControlResponse;

	soap_call___ns1__RobotLifterControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) RobotPdControl(PdControlType control_type){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__RobotPdControl *send_temp = new RobotData::_ns3__RobotPdControl;
	RobotData::ns3__PdControlType type = RobotData::ns3__PdControlType(control_type);
	send_temp->Type = type;
	RobotData::_ns3__RobotPdControlResponse *recv_temp = new RobotData::_ns3__RobotPdControlResponse;

	soap_call___ns1__RobotPdControl(&web_soap, server_.c_str(), "", send_temp, recv_temp);
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

EXP(int) GetRobotBatteryInfo(bool need_all, std::vector<BatteryInfo>& battery_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotBatteryInfo *send_temp = new RobotData::_ns3__GetRobotBatteryInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotBatteryInfoResponse *recv_temp = new RobotData::_ns3__GetRobotBatteryInfoResponse;

	soap_call___ns1__GetRobotBatteryInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			BatteryInfo battery_info;
			battery_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			battery_info.BatteryValue = recv_temp->Data->Infos[i]->BatteryValue;
			battery_info.BatteryPercent = recv_temp->Data->Infos[i]->BatteryPercent;
			battery_infos.push_back(battery_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotSpeedInfo(bool need_all, std::vector<SpeedInfo>& speed_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotSpeedInfo *send_temp = new RobotData::_ns3__GetRobotSpeedInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotSpeedInfoResponse *recv_temp = new RobotData::_ns3__GetRobotSpeedInfoResponse;

	soap_call___ns1__GetRobotSpeedInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			SpeedInfo speed_info;
			speed_info.robot_ip = recv_temp->Data->Infos[i]->RobotIp;
			speed_info.speed = recv_temp->Data->Infos[i]->Speed;
			speed_infos.push_back(speed_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotTaskState(bool need_all, std::vector<RobotState>& robot_states){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotTaskState *send_temp = new RobotData::_ns3__GetRobotTaskState;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotTaskStateResponse *recv_temp = new RobotData::_ns3__GetRobotTaskStateResponse;

	soap_call___ns1__GetRobotTaskState(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->States.size(); ++i)
		{
			RobotState robot_state;
			robot_state.RobotIp = recv_temp->Data->States[i]->RobotIp;
			robot_state.TaskId = recv_temp->Data->States[i]->TaskId;
			robot_state.TaskDesc = recv_temp->Data->States[i]->TaskDesc;
			robot_state.TaskType = recv_temp->Data->States[i]->TaskType;
			robot_states.push_back(robot_state);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) GetRobotPosInfo(bool need_all, std::vector<RobotPosInfo>& pos_infos){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotPosInfo *send_temp = new RobotData::_ns3__GetRobotPosInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotPosInfoResponse *recv_temp = new RobotData::_ns3__GetRobotPosInfoResponse;

	soap_call___ns1__GetRobotPosInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			RobotPosInfo pos_info;
			pos_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			pos_info.Angle = recv_temp->Data->Infos[i]->Angle;
			pos_info.EdgeID = recv_temp->Data->Infos[i]->EdgeID;
			pos_info.PosX = recv_temp->Data->Infos[i]->PosX;
			pos_info.PosY = recv_temp->Data->Infos[i]->PosY;
			pos_info.Precent = recv_temp->Data->Infos[i]->Precent;
			pos_infos.push_back(pos_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) GetRobotYunTaiInfo(bool need_all, std::vector<YunTaiInfo>& yuntai_infos){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotYunTaiInfo *send_temp = new RobotData::_ns3__GetRobotYunTaiInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotYunTaiInfoResponse *recv_temp = new RobotData::_ns3__GetRobotYunTaiInfoResponse;

	soap_call___ns1__GetRobotYunTaiInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			YunTaiInfo yuntai_info;
			yuntai_info.PosPan = recv_temp->Data->Infos[i]->PosPan;
			yuntai_info.PosTile = recv_temp->Data->Infos[i]->PosTile;
			yuntai_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			yuntai_infos.push_back(yuntai_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);

	return result;
}

EXP(int) GetRobotMileageInfo(bool need_all, std::vector<RobotMileageInfo>& mileage_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotMileageInfo *send_temp = new RobotData::_ns3__GetRobotMileageInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotMileageInfoResponse *recv_temp = new RobotData::_ns3__GetRobotMileageInfoResponse;

	soap_call___ns1__GetRobotMileageInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			RobotMileageInfo mileage_info;
			mileage_info.Mileage = recv_temp->Data->Infos[i]->Mileage;
			mileage_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			mileage_infos.push_back(mileage_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotGasInfo(bool need_all, std::vector<RobotGasInfo>& gas_infos){
	int result = 0;

	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotGasInfo *send_temp = new RobotData::_ns3__GetRobotGasInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotGasInfoResponse *recv_temp = new RobotData::_ns3__GetRobotGasInfoResponse;

	soap_call___ns1__GetRobotGasInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->GasContents.size(); ++i)
		{
			RobotGasInfo gas_info;
			gas_info.CH4 = recv_temp->Data->GasContents[i]->CH4;
			gas_info.CO = recv_temp->Data->GasContents[i]->CO;
			gas_info.Desc = recv_temp->Data->GasContents[i]->Desc;
			gas_info.H2S = recv_temp->Data->GasContents[i]->H2S;
			gas_info.HUM = recv_temp->Data->GasContents[i]->HUM;
			gas_info.O2 = recv_temp->Data->GasContents[i]->O2;
			gas_info.O3 = recv_temp->Data->GasContents[i]->O3;
			gas_info.PM10 = recv_temp->Data->GasContents[i]->PM10;
			gas_info.PM25 = recv_temp->Data->GasContents[i]->PM25;
			gas_info.robot_ip = recv_temp->Data->GasContents[i]->robot_ip;
			gas_info.SF6 = recv_temp->Data->GasContents[i]->SF6;
			gas_info.TEMP = recv_temp->Data->GasContents[i]->TEMP;
			gas_infos.push_back(gas_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}

EXP(int) GetRobotAlarmInfo(bool need_all, std::vector<RobotAlarmInfo>& alarm_infos){
	int result = 0;
	struct soap web_soap;
	soap_init(&web_soap);
	soap_set_mode(&web_soap, SOAP_C_UTFSTRING);//设置为utf-8格式，中文传输需要转换
	RobotData::_ns3__GetRobotAlarmInfo *send_temp = new RobotData::_ns3__GetRobotAlarmInfo;

	send_temp->NeedAll = need_all;
	RobotData::_ns3__GetRobotAlarmInfoResponse *recv_temp = new RobotData::_ns3__GetRobotAlarmInfoResponse;

	soap_call___ns1__GetRobotAlarmInfo(&web_soap, server_.c_str(), "", send_temp, recv_temp);


	if (web_soap.error)
	{
		std::cout << "soap error: " << web_soap.error << std::endl;
		result = web_soap.error;
	}
	else
	{
		for (int i = 0; i < recv_temp->Data->Infos.size(); ++i)
		{
			RobotAlarmInfo alarm_info;
			alarm_info.AlarmId = recv_temp->Data->Infos[i]->AlarmId;
			alarm_info.AlarmTime = recv_temp->Data->Infos[i]->AlarmTime;
			alarm_info.AlarmType = recv_temp->Data->Infos[i]->AlarmType;
			alarm_info.AlarmDesc = recv_temp->Data->Infos[i]->AlarmDesc;
			alarm_info.RobotIp = recv_temp->Data->Infos[i]->RobotIp;
			alarm_infos.push_back(alarm_info);
		}
	}
	soap_end(&web_soap);
	soap_done(&web_soap);
	return result;
}