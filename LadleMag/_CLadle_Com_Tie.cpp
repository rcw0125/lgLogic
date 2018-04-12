// 逻辑类CLadle_Com_Tie源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Com_Tie.h"

IMPLEMENT_L3CLASS(CLadle_Com_Tie,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Com_Tie,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(LadleID)
	L3PROP_DATETIME(Tie_Start_Time)
	L3PROP_DATETIME(Tie_End_Time)
	L3PROP_STRING(Water_gap_Bri_Fac)
	L3PROP_DOUBLE(Water_gap_Bri_Wast)
	L3PROP_STRING(Breathe_Bri_Fac)
	L3PROP_DOUBLE(Breathe_Bri_Wast)
	L3PROP_STRING(Cast_Fac)
	L3PROP_DOUBLE(Cast_Wast)
	L3PROP_STRING(Squ_Lead_Fac)
	L3PROP_DOUBLE(Squ_Lead_Wast)
	L3PROP_STRING(Half_Boa_Fac)
	L3PROP_DOUBLE(Half_Boa_Wast)
	L3PROP_STRING(Crust_Checker)
	L3PROP_STRING(Ladle_Inner_Checker)
	L3PROP_STRING(Seat_Bri_Installer)
	L3PROP_STRING(Bre_Bri_Installer)
	L3PROP_STRING(Sepa_Dose_Operator)
	L3PROP_STRING(Whip_Operator)
	L3PROP_STRING(Ladle_Bot_Quiver)
	L3PROP_STRING(Seat_Tyre_Operator)
	L3PROP_STRING(Face_A__Quiver)
	L3PROP_STRING(Face_B__Quiver)
	L3PROP_DATETIME(Doff_Mod_Time)
	L3PROP_STRING(Rep_Ladle_Builder)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_DATETIME(Thr_Ladle_Time)
	L3PROP_LONG(Ladle_Inner_Use_Count)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)

END_L3PROPTABLE(CLadle_Com_Tie)

BEGIN_L3METHODMAP(CLadle_Com_Tie,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Com_Tie,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Com_Tie)

CLadle_Com_Tie::CLadle_Com_Tie(void)
{
}

CLadle_Com_Tie::~CLadle_Com_Tie(void)
{
}
