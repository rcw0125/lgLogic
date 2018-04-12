// 逻辑类CIronLadle_Tie源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CIronLadle_Tie.h"

IMPLEMENT_L3CLASS(CIronLadle_Tie,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Tie,CL3Object)
	L3PROP_DATETIME(InPut_Time)
	L3PROP_STRING(IronLadleID)
	L3PROP_STRING(TieID)
	L3PROP_STRING(Refra_Produce)
	L3PROP_STRING(Refra_ID)
	L3PROP_FLOAT(Consumption)
	L3PROP_DATETIME(Tie_Start_Time)
	L3PROP_DATETIME(Tie_End_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(Doff_Mod_Time)
END_L3PROPTABLE(CIronLadle_Tie)

BEGIN_L3METHODMAP(CIronLadle_Tie,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Tie,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Tie)

CIronLadle_Tie::CIronLadle_Tie(void)
{
}

CIronLadle_Tie::~CIronLadle_Tie(void)
{
}
