// 逻辑类ShiftTeamOrder源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CShiftTeamOrder.h"

IMPLEMENT_L3CLASS(CShiftTeamOrder,CL3Object,1)

BEGIN_L3PROPTABLE(CShiftTeamOrder,CL3Object)
	L3PROP_SHORT(L3Index)
	L3PROP_STRING(ShiftType)
	L3PROP_SHORT(OrderIndex)
	L3PROP_SHORT(ShiftID)
	L3PROP_SHORT(TeamID)
END_L3PROPTABLE(CShiftTeamOrder)

BEGIN_L3METHODMAP(CShiftTeamOrder,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CShiftTeamOrder,CL3Object)
END_L3EVENTSINK_MAP(CShiftTeamOrder)

CShiftTeamOrder::CShiftTeamOrder(void)
{
}

CShiftTeamOrder::~CShiftTeamOrder(void)
{
}
