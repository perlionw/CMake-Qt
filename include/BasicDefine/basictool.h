#include <iostream>
#include <map>
#include "tool_config.h"
#pragma execution_character_set("utf-8")
#define GETDATA_TIP "���ݻ�ȡ��ʾ"
#define CONTROL_TIP "������ʾ"
#define TASK_TIP "������ʾ"

#ifdef _USRDLL
	#define METH dllexport
#else
	#define METH dllimport
#endif


#ifndef EXP
#define EXP(type) extern "C" _declspec(METH) type __stdcall
#endif