// 逻辑类CDutyDefinition源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDutyDefinition.h"

IMPLEMENT_L3CLASS(CDutyDefinition,CL3Object,1)

BEGIN_L3PROPTABLE(CDutyDefinition,CL3Object)
	L3PROP_SHORT(UnitID)
	L3PROP_SHORT(PlantID)
	L3PROP_SHORT(TeamID)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDutyDefinition)

BEGIN_L3METHODMAP(CDutyDefinition,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDutyDefinition,CL3Object)
END_L3EVENTSINK_MAP(CDutyDefinition)

CDutyDefinition::CDutyDefinition(void)
{
}

CDutyDefinition::~CDutyDefinition(void)
{
}
