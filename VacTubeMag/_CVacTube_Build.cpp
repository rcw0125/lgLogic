// 逻辑类CVacTube_Build源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Build.h"

IMPLEMENT_L3CLASS(CVacTube_Build,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Build,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Build_ID)
	L3PROP_STRING(VacTube_Name)
	L3PROP_STRING(VacTube_Id)
	L3PROP_DATETIME(Build_Start_Time)
	L3PROP_DATETIME(Build_End_Time)
	L3PROP_STRING(Refra_Fac)
	L3PROP_DOUBLE(Wall_Bri_Thick)
	L3PROP_DOUBLE(Bot_Bri_Thick)
	L3PROP_LONG(RH_Age)
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
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CVacTube_Build)

BEGIN_L3METHODMAP(CVacTube_Build,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Build,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Build)

CVacTube_Build::CVacTube_Build(void)
{
}

CVacTube_Build::~CVacTube_Build(void)
{
}
