#include "BasicDefine.h"
#include "basictool.h"
#include <vector>

EXP(int) init_robotdata_config(const char* server);

EXP(int) GetRobotConnect(std::vector<RobotConnectInfo>& connect_infos);

EXP(int) GetRobotInfo(std::vector<RobotInfo>& robot_infos);

EXP(int) GetRobotTime(std::string& robot_time);

EXP(int) SetRobotTime(std::string robot_time);

EXP(int) SetCurrentRobot(std::string robot_ip);

EXP(int) ReleaseCurrentRobot(std::string robot_ip);

EXP(int) SetControlMode(ControlMode control_mode);

EXP(int) GetControlMode(std::string robot_ip, int& control_type);

EXP(int) RobotSpeedControl(SpeedInfo speed);

EXP(int) RobotYuntaiControl(YuntaiControlType control_type);

EXP(int) RobotCameraControl(CameraControlType control_type);

EXP(int) RobotLightControl(LightControlType control_type);

EXP(int) RobotWiperControl(WiperControlType control_type);

EXP(int) RobotFlirControl(FilrControlType control_type);

EXP(int) RobotLifterControl(LifterControlType control_type);

EXP(int) RobotPdControl(PdControlType control_type);

EXP(int) GetRobotBatteryInfo(bool need_all, std::vector<BatteryInfo>& battery_infos);

EXP(int) GetRobotSpeedInfo(bool need_all, std::vector<SpeedInfo>& speed_infos);

EXP(int) GetRobotTaskState(bool need_all, std::vector<RobotState>& robot_states);

EXP(int) GetRobotPosInfo(bool need_all, std::vector<RobotPosInfo>& pos_infos);

EXP(int) GetRobotYunTaiInfo(bool need_all, std::vector<YunTaiInfo>& yuntai_infos);

EXP(int) GetRobotMileageInfo(bool need_all, std::vector<RobotMileageInfo>& mileage_infos);

EXP(int) GetRobotGasInfo(bool need_all, std::vector<RobotGasInfo>& gas_infos);

EXP(int) GetRobotAlarmInfo(bool need_all, std::vector<RobotAlarmInfo>& alarm_infos);