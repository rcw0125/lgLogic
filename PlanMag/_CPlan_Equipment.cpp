// 逻辑类CPlan_Equipment源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_Equipment.h"

IMPLEMENT_L3CLASS(CPlan_Equipment,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_Equipment,CL3Object)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Unit_TypeID)
	L3PROP_DATETIME(EndStopTime_Aim)
	L3PROP_DATETIME(BeginStopTime_Aim)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CPlan_Equipment)

BEGIN_L3METHODMAP(CPlan_Equipment,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Equipment,CL3Object)
END_L3EVENTSINK_MAP(CPlan_Equipment)

CPlan_Equipment::CPlan_Equipment(void)
{
}

CPlan_Equipment::~CPlan_Equipment(void)
{
}
