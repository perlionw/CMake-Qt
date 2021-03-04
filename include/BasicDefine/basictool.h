#include <iostream>
#include <map>
#include "tool_config.h"
#pragma execution_character_set("utf-8")
#define GETDATA_TIP "数据获取提示"
#define CONTROL_TIP "控制提示"
#define TASK_TIP "任务提示"

#ifdef _USRDLL
	#define METH dllexport
#else
	#define METH dllimport
#endif


#ifndef EXP
#define EXP(type) extern "C" _declspec(METH) type __stdcall
#endif