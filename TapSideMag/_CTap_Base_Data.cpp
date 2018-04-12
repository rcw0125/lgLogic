// 逻辑类CTap_Base_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CTap_Base_Data.h"

IMPLEMENT_L3CLASS(CTap_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Base_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(PreHeatID)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_SHORT(Locked)
END_L3PROPTABLE(CTap_Base_Data)

BEGIN_L3METHODMAP(CTap_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Base_Data)

CTap_Base_Data::CTap_Base_Data(void)
{
}

CTap_Base_Data::~CTap_Base_Data(void)
{
}
