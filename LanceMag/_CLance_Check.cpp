// 逻辑类CLance_Check源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLance_Check.h"

IMPLEMENT_L3CLASS(CLance_Check,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Check,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LanceID)
	L3PROP_STRING(MakeID)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_STRING(Nozzle_Factury)
	L3PROP_DOUBLE(Nozzle_Throat_Dia)
	L3PROP_DOUBLE(Nozzle_Angle)
	L3PROP_DATETIME(Off_Date)
	L3PROP_LONG(Nasal_Erosion)
	L3PROP_LONG(Exit_Shape)
	L3PROP_DATETIME(Nozzle_Assembly_Date)
	L3PROP_LONG(Lance_Body_Shap)
	L3PROP_LONG(In_Mid_Out_Replace)
	L3PROP_LONG(Weld_Check)
	L3PROP_LONG(N2_And_Baffle_Check)
	L3PROP_LONG(Ring_Check)
	L3PROP_LONG(Flange_Check)
	L3PROP_DOUBLE(Test_Water_Pressure)
	L3PROP_DOUBLE(Keep_Pressure_Time)
	L3PROP_LONG(Test_Water_Result)
	L3PROP_STRING(Test_Water_Operator)
	L3PROP_STRING(BOFID)
	L3PROP_DATETIME(Rise_Lance_Date)
	L3PROP_STRING(On_Lance_Operator)
	L3PROP_STRING(Off_Lance_Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Check)

BEGIN_L3METHODMAP(CLance_Check,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Check,CL3Object)
END_L3EVENTSINK_MAP(CLance_Check)

CLance_Check::CLance_Check(void)
{
}

CLance_Check::~CLance_Check(void)
{
}
