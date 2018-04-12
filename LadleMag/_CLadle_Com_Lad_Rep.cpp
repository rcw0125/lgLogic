// 逻辑类CLadle_Com_Lad_Rep源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Com_Lad_Rep.h"

IMPLEMENT_L3CLASS(CLadle_Com_Lad_Rep,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Com_Lad_Rep,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_LONG(RepID)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(Water_gap_Bri_Fac)
	L3PROP_DOUBLE(Water_gap_Bri_Wast)
	L3PROP_STRING(Breathe_Bri_Fac)
	L3PROP_DOUBLE(Breathe_Bri_Wast)
	L3PROP_STRING(Cast_Fac)
	L3PROP_DOUBLE(Cast_Wast)
	L3PROP_DATETIME(Fire_Start_Time)
	L3PROP_DATETIME(Fire_End_Time)
	L3PROP_STRING(Rep_Ladle_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(Rep_Date)
	L3PROP_STRING(WorkID)
	L3PROP_LONG(Confirm_Flag)
	L3PROP_STRING(Object_ID)

END_L3PROPTABLE(CLadle_Com_Lad_Rep)

BEGIN_L3METHODMAP(CLadle_Com_Lad_Rep,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Com_Lad_Rep,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Com_Lad_Rep)

CLadle_Com_Lad_Rep::CLadle_Com_Lad_Rep(void)
{
}

CLadle_Com_Lad_Rep::~CLadle_Com_Lad_Rep(void)
{
}
