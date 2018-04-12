// 逻辑类CVacTube_Repair源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Repair.h"

IMPLEMENT_L3CLASS(CVacTube_Repair,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Repair,CL3Object)

	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Build_ID)
	L3PROP_STRING(VacTube_Name)
	L3PROP_STRING(VacTube_Id)
	L3PROP_STRING(Refra_Fac)
	L3PROP_LONG(RH_Age)
	L3PROP_LONG(Cir_Age)
	L3PROP_LONG(Up_Age)
	L3PROP_LONG(Down_Age)
	L3PROP_DOUBLE(InWall_Bri_Thick)
	L3PROP_DOUBLE(InBot_Bri_Thick)
	L3PROP_DOUBLE(Mg_Cr_Bri_Ele_Waste)
	L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)
	L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)
	L3PROP_DOUBLE(Mg_Cr_Fir_Waste)
	L3PROP_DOUBLE(Bear_Fir_Waste)
	L3PROP_DOUBLE(Si_Ca_Boa_Waste)
	L3PROP_DOUBLE(Light_Mat_Bri_Waste)
	L3PROP_DOUBLE(Pug_Hit_Mat_Waste)
	L3PROP_DOUBLE(Cast_Wast)
	L3PROP_STRING(Repair_Position)
	L3PROP_STRING(Repair_Case)
	L3PROP_STRING(Repair_Per)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CVacTube_Repair)

BEGIN_L3METHODMAP(CVacTube_Repair,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Repair,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Repair)

CVacTube_Repair::CVacTube_Repair(void)
{
}

CVacTube_Repair::~CVacTube_Repair(void)
{
}
