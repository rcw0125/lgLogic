// 逻辑类CTundish_OT_Hot_Fire源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CTundish_OT_Hot_Fire.h"

IMPLEMENT_L3CLASS(CTundish_OT_Hot_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_OT_Hot_Fire,CL3Object)

	
	L3PROP_STRING(TundishID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(VehicleID)
	L3PROP_STRING(Adjust_Per)
	L3PROP_STRING(Adjust_TeamID)
	L3PROP_STRING(Crane_TeamID)
	L3PROP_STRING(Move_Case)
	L3PROP_STRING(Note)
	L3PROP_DOUBLE(First_Hyd_Pre)
	L3PROP_DOUBLE(Second_Hyd_Pre)
	L3PROP_DOUBLE(Third_Hyd_Pre)
	L3PROP_DOUBLE(Fourth_Hyd_Pre)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_DOUBLE(Fire_Temp)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_OT_Hot_Fire)

BEGIN_L3METHODMAP(CTundish_OT_Hot_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_OT_Hot_Fire,CL3Object)
END_L3EVENTSINK_MAP(CTundish_OT_Hot_Fire)

CTundish_OT_Hot_Fire::CTundish_OT_Hot_Fire(void)
{
}

CTundish_OT_Hot_Fire::~CTundish_OT_Hot_Fire(void)
{
}
