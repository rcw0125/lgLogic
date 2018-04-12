// 逻辑类CQA_RH_Std_Proc源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_RH_Std_Proc.h"

IMPLEMENT_L3CLASS(CQA_RH_Std_Proc,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_RH_Std_Proc,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(LeaFir_Temp_Aim)
	L3PROP_LONG(LeaFir_Temp_Min)
	L3PROP_LONG(LeaFir_Temp_Max)
	L3PROP_LONG(Lea_Temp_Aim)
	L3PROP_LONG(Lea_Temp_Min)
	L3PROP_LONG(Lea_Temp_Max)
	L3PROP_DOUBLE(Depth_Min)
	L3PROP_DOUBLE(Depth_Max)
	L3PROP_DOUBLE(Vacuum_Min)
	L3PROP_DOUBLE(Vacuum_Max)
	L3PROP_DOUBLE(Up_Blow_Min)
	L3PROP_DOUBLE(Up_Blow_Aim)
	L3PROP_DOUBLE(Up_Blow_Max)
	L3PROP_LONG(Dec_Flag)
	L3PROP_LONG(Dec_Time_Min)
	L3PROP_LONG(Dec_Time_Max)
	L3PROP_LONG(Pure_Time_Min)
	L3PROP_LONG(Pure_Time_Max)
	L3PROP_LONG(Vacuum_Time_Min)
	L3PROP_LONG(Proc_Time_Min)
	L3PROP_LONG(Oxy_Flag)
	L3PROP_LONG(H_Flag)
	L3PROP_LONG(Soft_Blow_Flag)
	L3PROP_LONG(Calm_Flag)
	L3PROP_LONG(Al_Hot_Flag)
	L3PROP_STRING(Cold_Mat_Add)
	L3PROP_DOUBLE(Hold_Steel_Time_Max)
	L3PROP_DOUBLE(Stay_Steel_Time_Max)
	L3PROP_LONG(Pure_DeO_Time_Min)
END_L3PROPTABLE(CQA_RH_Std_Proc)

BEGIN_L3METHODMAP(CQA_RH_Std_Proc,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_RH_Std_Proc,CL3Object)
END_L3EVENTSINK_MAP(CQA_RH_Std_Proc)

CQA_RH_Std_Proc::CQA_RH_Std_Proc(void)
{
}

CQA_RH_Std_Proc::~CQA_RH_Std_Proc(void)
{
}
