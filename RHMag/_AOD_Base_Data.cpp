// 逻辑类CAOD_Base_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAOD_Base_Data.h"

IMPLEMENT_L3CLASS(CAOD_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Base_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Assistant)
	L3PROP_STRING(SecondHand)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_DATETIME(StatisticsDate)
	L3PROP_SHORT(Locked)
	L3PROP_LONG(NC_Confirm_Flag)
END_L3PROPTABLE(CAOD_Base_Data)

BEGIN_L3METHODMAP(CAOD_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Base_Data)

CAOD_Base_Data::CAOD_Base_Data(void)
{
}

CAOD_Base_Data::~CAOD_Base_Data(void)
{
}
