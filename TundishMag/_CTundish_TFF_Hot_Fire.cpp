// 逻辑类CTundish_TFF_Hot_Fire源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CTundish_TFF_Hot_Fire.h"

IMPLEMENT_L3CLASS(CTundish_TFF_Hot_Fire,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_TFF_Hot_Fire,CL3Object)
	
	L3PROP_STRING(TundishID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(VehicleID)
	L3PROP_STRING(Crane_TeamID)
	L3PROP_STRING(First_Fra_ID)
	L3PROP_STRING(Second_Fra_ID)
	L3PROP_STRING(Third_Fra_ID)
	L3PROP_STRING(Fourth_Fra_ID)
	L3PROP_DATETIME(Small_Start_Time)
	L3PROP_DATETIME(Small_End_Time)
	L3PROP_DATETIME(Mid_Start_Time)
	L3PROP_DATETIME(Mid_End_Time)
	L3PROP_DATETIME(Big_Start_Time)
	L3PROP_DATETIME(Big_End_Time)
	L3PROP_STRING(Note)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_DOUBLE(Fir_Gas_Flux)
	L3PROP_DOUBLE(Fir_Gas_Press)
	L3PROP_DOUBLE(Sec_Gas_Flux)
	L3PROP_DOUBLE(Sec_Gas_Press)
	L3PROP_DOUBLE(Thi_Gas_Flux)
	L3PROP_DOUBLE(Thi_Gas_Press)
	L3PROP_DOUBLE(Thi_Wall_Temp)
	L3PROP_DOUBLE(Thi_Gap_Temp)
	L3PROP_DOUBLE(Fou_Gas_Flux)
	L3PROP_DOUBLE(Fou_Gas_Press)
	L3PROP_DOUBLE(Fou_Wall_Temp)
	L3PROP_DOUBLE(Fou_Gap_Temp)
	L3PROP_DOUBLE(Fiv_Gas_Flux)
	L3PROP_DOUBLE(Fiv_Gas_Press)
	L3PROP_DOUBLE(Fiv_Wall_Temp)
	L3PROP_DOUBLE(Fiv_Gap_Temp)
	L3PROP_DOUBLE(Six_Gas_Flux)
	L3PROP_DOUBLE(Six_Gas_Press)
	L3PROP_DOUBLE(Six_Wall_Temp)
	L3PROP_DOUBLE(Six_Gap_Temp)
	L3PROP_DOUBLE(Sev_Gas_Flux)
	L3PROP_DOUBLE(Sev_Gas_Press)
	L3PROP_DOUBLE(Sev_Wall_Temp)
	L3PROP_DOUBLE(Sev_Gap_Temp)
	L3PROP_LONG(Confirm_Flag)
	
END_L3PROPTABLE(CTundish_TFF_Hot_Fire)

BEGIN_L3METHODMAP(CTundish_TFF_Hot_Fire,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_TFF_Hot_Fire,CL3Object)
END_L3EVENTSINK_MAP(CTundish_TFF_Hot_Fire)

CTundish_TFF_Hot_Fire::CTundish_TFF_Hot_Fire(void)
{
}

CTundish_TFF_Hot_Fire::~CTundish_TFF_Hot_Fire(void)
{
}
