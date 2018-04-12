// 逻辑类CCCM_Feed_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Feed_Data.h"

IMPLEMENT_L3CLASS(CCCM_Feed_Data,UnitFeedingLog,1)

BEGIN_L3PROPTABLE(CCCM_Feed_Data,UnitFeedingLog)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(LadleNo)
END_L3PROPTABLE(CCCM_Feed_Data)

BEGIN_L3METHODMAP(CCCM_Feed_Data,UnitFeedingLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Feed_Data,UnitFeedingLog)
END_L3EVENTSINK_MAP(CCCM_Feed_Data)

CCCM_Feed_Data::CCCM_Feed_Data(void)
{
}

CCCM_Feed_Data::~CCCM_Feed_Data(void)
{
}
