// 逻辑类CLadle_Fire源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Fire.h"

IMPLEMENT_L3CLASS(CLadle_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Fire,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Fire_Type)
	L3PROP_STRING(Roaster_ID)
	L3PROP_STRING(LadleID)
	L3PROP_DATETIME(Start_Time)
	L3PROP_STRING(Start_Operator)
	L3PROP_DATETIME(Set_One_Time)
	L3PROP_STRING(Set_One_Operator)
	L3PROP_DATETIME(Set_Two_Time)
	L3PROP_STRING(Set_Two_Operator)
	L3PROP_DATETIME(Set_Three_Time)
	L3PROP_STRING(Set_Three_Operator)
	L3PROP_DATETIME(Set_Four_Time)
	L3PROP_STRING(Set_Four_Operator)
	L3PROP_DATETIME(End_Time)
	L3PROP_STRING(End_Operator)
	L3PROP_DATETIME(Suspend_Time)
	L3PROP_STRING(Suspend_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_STRING(WorkID)
	L3PROP_LONG(Confirm_Flag)
	L3PROP_STRING(FireNote)
	L3PROP_STRING(FireID)
END_L3PROPTABLE(CLadle_Fire)

BEGIN_L3METHODMAP(CLadle_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Fire,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Fire)

CLadle_Fire::CLadle_Fire(void)
{
}

CLadle_Fire::~CLadle_Fire(void)
{
}
