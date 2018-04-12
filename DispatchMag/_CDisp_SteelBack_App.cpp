// 逻辑类CDisp_SteelBack_App源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDisp_SteelBack_App.h"

IMPLEMENT_L3CLASS(CDisp_SteelBack_App,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_SteelBack_App,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(App_UnitID)
	L3PROP_DATETIME(App_Time)
	L3PROP_DOUBLE(App_Steel_Weight)
	L3PROP_STRING(App_Operator)
	L3PROP_STRING(App_Reason)
	L3PROP_STRING(Back_UnitID)
	L3PROP_DATETIME(Back_Time)
	L3PROP_STRING(Back_Operator)
	L3PROP_LONG(Back_Flag)
END_L3PROPTABLE(CDisp_SteelBack_App)

BEGIN_L3METHODMAP(CDisp_SteelBack_App,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_SteelBack_App,CL3Object)
END_L3EVENTSINK_MAP(CDisp_SteelBack_App)

CDisp_SteelBack_App::CDisp_SteelBack_App(void)
{
}

CDisp_SteelBack_App::~CDisp_SteelBack_App(void)
{
}
