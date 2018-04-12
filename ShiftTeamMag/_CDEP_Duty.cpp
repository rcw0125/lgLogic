// 逻辑类CDutyDefinition源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDEP_Duty.h"

IMPLEMENT_L3CLASS(CDEP_Duty,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Duty,CL3Object)
    L3PROP_STRING(ObjectID)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
END_L3PROPTABLE(CDEP_Duty)

BEGIN_L3METHODMAP(CDEP_Duty,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Duty,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Duty)

CDEP_Duty::CDEP_Duty(void)
{
}

CDEP_Duty::~CDEP_Duty(void)
{
}
