#include "BasicDefine.h"
#include <vector>
#include "basictool.h"


EXP(int) init_taskfinsih_config(const char* server);

EXP(int) GetTaskFinishInfoByTime(std::string start_time, std::string end_time, std::vector<TaskFinishInfo>& task_finish_infos);

EXP(int) GetTaskExcuteInfoByTaskId(std::string task_id, std::vector<TaskExcuteInfo>& task_excute_infos);
