#pragma once
#include <string>
#include <vector>
struct RobotConnectInfo
{
	std::string RobotIp;
	bool State;
	std::string ConnectDesc;
};

struct RobotInfo
{
	std::string RobotName;	/* required element of type xsd:string */
	std::string RobotIp;	/* required element of type xsd:string */
	std::string CameraIp;	/* required element of type xsd:string */
	int CameraPort;	/* required element of type xsd:int */
	std::string FlirIp;	/* required element of type xsd:string */
	int FlirPort;	/* required element of type xsd:int */
	std::string VideoIp;	/* required element of type xsd:string */
	int VideoPort;	/* required element of type xsd:int */
	std::string CameraUser;	/* required element of type xsd:string */
	std::string CameraPassword;	/* required element of type xsd:string */
	std::string FlirUser;	/* required element of type xsd:string */
	std::string FlirPassword;	/* required element of type xsd:string */
	std::string VideoUser;	/* required element of type xsd:string */
	std::string VideoPassword;	/* required element of type xsd:string */
};

struct ControlMode
{
	std::string robot_ip;
	int ControlType;
};

struct SpeedInfo
{
	std::string robot_ip;
	double speed;
	double LinearVelocity;	/* required element of type xsd:double */
	double AngularVelocity;	/* required element of type xsd:double */
};

enum YuntaiControlType
{ YuntaiControlType__TurnUp = 0, YuntaiControlType__TurnDown = 1, YuntaiControlType__TurnLeft = 2, YuntaiControlType__TurnRight = 3, YuntaiControlType__TurnStop = 4, YuntaiControlType__TurnReset = 5 };

enum CameraControlType 
{ CameraControlType__ZoomUp = 0, CameraControlType__ZoomUpStop = 1, CameraControlType__ZoomDown = 2, CameraControlType__ZoomDownStop = 3, CameraControlType__FocusNear = 4, CameraControlType__FocusNearStop = 5, CameraControlType__FocusFar = 6, CameraControlType__FocusFarStop = 7, CameraControlType__CameraReset = 8 };

enum LightControlType
{ LightControlType__LightOn = 0, LightControlType__LightOff = 1 };

enum WiperControlType
{ WiperControlType__WiperOn = 0, WiperControlType__WiperOff = 1 };

enum FilrControlType
{ FilrControlType__FocusUp = 0, FilrControlType__FocusDown = 1, FilrControlType__AutoFocus = 2 };

enum LifterControlType
{ LifterControlType__LifterUp = 0, LifterControlType__LifterDown = 1, LifterControlType__LifterStop = 2 };

enum PdControlType 
{ PdControlType__PdForWard = 0, PdControlType__PdBackWord = 1, PdControlType__PdStop = 2 };

enum ControlTaskType 
{ ControlTaskType__CancelTask = 0, ControlTaskType__PauseTask = 1, ControlTaskType__ResumeTask = 2, ControlTaskType__ChargeTask = 3 };

struct BatteryInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	double BatteryValue;	/* required element of type xsd:double */
	double BatteryPercent;	/* required element of type xsd:double */
};

struct RobotState
{
	std::string RobotIp;	/* required element of type xsd:string */
	std::string TaskId;
	std::string TaskType;	/* required element of type xsd:string */
	std::string TaskDesc;	/* required element of type xsd:string */
};

struct RobotPosInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	std::string PosX;	/* required element of type xsd:string */
	std::string PosY;	/* required element of type xsd:string */
	std::string Angle;	/* required element of type xsd:string */
	std::string EdgeID;	/* required element of type xsd:string */
	std::string Precent;	/* required element of type xsd:string */
};

struct YunTaiInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	std::string PosPan;	/* required element of type xsd:string */
	std::string PosTile;	/* required element of type xsd:string */
};

struct RobotMileageInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	double Mileage;	/* required element of type xsd:double */
};

struct RobotGasInfo
{
	std::string robot_ip;	/* required element of type xsd:string */
	std::string H2S;	/* required element of type xsd:string */
	std::string CO;	/* required element of type xsd:string */
	std::string O2;	/* required element of type xsd:string */
	std::string CH4;	/* required element of type xsd:string */
	std::string TEMP;	/* required element of type xsd:string */
	std::string HUM;	/* required element of type xsd:string */
	std::string PM25;	/* required element of type xsd:string */
	std::string PM10;	/* required element of type xsd:string */
	std::string O3;	/* required element of type xsd:string */
	std::string SF6;	/* required element of type xsd:string */
	std::string Desc;	/* required element of type xsd:string */
};

struct RobotAlarmInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	std::string AlarmId;
	std::string AlarmType;	/* required element of type xsd:string */
	std::string AlarmDesc;	/* required element of type xsd:string */
	std::string AlarmTime;	/* required element of type xsd:string */
};

struct TaskPathInfo
{
	std::string TaskPathId;	/* required element of type xsd:string */
	std::string TaskPathName;	/* required element of type xsd:string */
	std::vector<std::string>PointList;	/* optional element of type xsd:string */
	std::string TaskPathType;	/* required element of type xsd:string */
	std::string CreateTime;	/* required element of type xsd:string */
	int FinishAction;
};

struct MapAreaInfo
{
	std::string RobotIp;	/* required element of type xsd:string */
	std::string AreaId;	/* required element of type xsd:string */
	std::string AreaName;	/* required element of type xsd:string */
	std::string AreaMap;	/* required element of type xsd:string */
	std::string MaxX;	/* required element of type xsd:string */
	std::string MaxY;	/* required element of type xsd:string */
	std::string MinX;	/* required element of type xsd:string */
	std::string MinY;	/* required element of type xsd:string */
	std::string ParentId;	/* required element of type xsd:string */
};

struct PatrolValueInfo
{
	std::string AreaId;	/* required element of type xsd:string */
	std::string AreaName;	/* required element of type xsd:string */
	std::string ParentId;	/* required element of type xsd:string */
	std::string RobotIp;	/* required element of type xsd:string */
};

struct MapEdgeInfo
{
	std::string EdgeId;	/* required element of type xsd:string */
	std::string StartNodeId;	/* required element of type xsd:string */
	std::string EndNodeId;	/* required element of type xsd:string */
	std::string StartNodeX;	/* required element of type xsd:string */
	std::string StartNodeY;	/* required element of type xsd:string */
	std::string EndNodeX;	/* required element of type xsd:string */
	std::string EndNodeY;	/* required element of type xsd:string */
	std::string FirstControlX;	/* required element of type xsd:string */
	std::string FirstControlY;	/* required element of type xsd:string */
	std::string SecondControlX;	/* required element of type xsd:string */
	std::string SecondControlY;	/* required element of type xsd:string */
};

struct DockPointInfo
{
	std::string DockId;	/* required element of type xsd:string */
	std::string DockX;	/* required element of type xsd:string */
	std::string DockY;	/* required element of type xsd:string */
	std::vector<std::string >PointList;
};

struct PatrolPointInfo
{
	std::string PointId;	/* required element of type xsd:string */
	std::string PointName;	/* required element of type xsd:string */
	std::string PointType;	/* required element of type xsd:string */
	std::string DeviceType;
	std::string AreaId;	/* required element of type xsd:string */
	std::string DockId;	/* required element of type xsd:string */
	std::string RobotIp;	/* required element of type xsd:string */
};

struct TaskFinishInfo
{
	std::string TaskId;	/* required element of type xsd:string */
	std::string TaskName;	/* required element of type xsd:string */
	std::string TaskType;	/* required element of type xsd:string */
	std::string TaskPathId;	/* required element of type xsd:string */
	std::vector<std::string >PointList;	/* optional element of type xsd:string */
	std::string StartTime;	/* required element of type xsd:string */
	std::string EndTime;	/* required element of type xsd:string */
	std::string FinishState;	/* required element of type xsd:string */
	std::string ExcuteRobot;	/* required element of type xsd:string */
};

struct TaskExcuteInfo
{
	std::string TaskId;	/* required element of type xsd:string */
	std::string TaskName;	/* required element of type xsd:string */
	std::string TaskType;	/* required element of type xsd:string */
	std::string TaskPathId;	/* required element of type xsd:string */
	std::string TargetId;	/* required element of type xsd:string */
	std::string PointId;	/* required element of type xsd:string */
	std::string PointName;	/* required element of type xsd:string */
	std::string PointType;	/* required element of type xsd:string */
	std::string ExcuteTime;	/* required element of type xsd:string */
	std::string ExcuteValue;	/* required element of type xsd:string */
	std::string ExcuteState;	/* required element of type xsd:string */
	std::string ExcuteDesc;	/* required element of type xsd:string */
	std::string HDPicture;	/* required element of type xsd:string */
	std::string InfraredPicture;	/* required element of type xsd:string */
	std::string ExcuteUnit;
	std::string OtherFile;
};

struct TaskExcuteData
{
	std::string RobotIp; //机器人ip
	std::string TaskType; //任务类型
	std::string TaskId; //任务id
	std::string TaskName; //任务名称
	std::string PatrolDeviceName; //当前巡检点位名称
	std::string PatrolDeviceId; //当前巡检点位id
	int TotalDeviceSize; //巡检点总数
	int ErrorDeviceSize; //异常巡检点数量
	int FinishDeviceSize; //已完成巡检点数量
	int TaskFinishPercentage; //完成进度
};