#pragma once
#include <string>
#include <vector>
#include "BasicDefine.h"
#include "basictool.h"
EXP(int) init_taskdata_config(const char* server);

EXP(int) GetMapAreaInfo(std::vector<MapAreaInfo>& map_area_infos);

EXP(int) GetPatrolAreaInfo(std::vector<PatrolValueInfo>& patrol_value_infos);

EXP(int) GetMapEdgeInfo(std::string area_id, std::vector<MapEdgeInfo>& map_edge_infos);

EXP(int) GetDockPointInfo(std::vector<DockPointInfo>& dock_point_infos);

EXP(int) GetPatrolPointInfo(std::vector<PatrolPointInfo>& patrol_point_infos);

EXP(int) GetTaskPathInfo(std::vector<TaskPathInfo>& task_path_infos);

EXP(int) StartTaskByPathId(std::string task_id, std::string task_path_id);

EXP(int) StartTaskByPointList(std::string task_id, std::vector<std::string >PointList);

EXP(int) RobotControlTask(ControlTaskType control_type);

EXP(int) GetTaskExcuteData(std::string robot_ip, TaskExcuteData& task_excute_data);

EXP(int) SetTaskPathInfo(TaskPathInfo task_path_info);