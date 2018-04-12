// 逻辑类CEnergyConsumption源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEnergyConsumption.h"

IMPLEMENT_L3CLASS(CEnergyConsumption,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergyConsumption,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(ProductionDate)
	L3PROP_STRING(TagName)
	L3PROP_DOUBLE(TagValue)
	L3PROP_DOUBLE(DayValue)
	L3PROP_DOUBLE(MonthValue)
	L3PROP_DATETIME(CreateTime)
	L3PROP_DATETIME(ModifyTime)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CEnergyConsumption)

BEGIN_L3METHODMAP(CEnergyConsumption,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergyConsumption,CL3Object)
END_L3EVENTSINK_MAP(CEnergyConsumption)

CEnergyConsumption::CEnergyConsumption(void)
{
}

CEnergyConsumption::~CEnergyConsumption(void)
{
}
