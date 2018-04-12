// 逻辑类CDutyDefinition源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDuty_Definition.h"

IMPLEMENT_L3CLASS(CDuty_Definition,CL3Object,1)

BEGIN_L3PROPTABLE(CDuty_Definition,CL3Object)
    L3PROP_STRING(ObjectID)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDuty_Definition)

BEGIN_L3METHODMAP(CDuty_Definition,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDuty_Definition,CL3Object)
END_L3EVENTSINK_MAP(CDuty_Definition)

CDuty_Definition::CDuty_Definition(void)
{
}

CDuty_Definition::~CDuty_Definition(void)
{
}
