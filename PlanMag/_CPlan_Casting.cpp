// 逻辑类CPlan_Casting源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_Casting.h"

IMPLEMENT_L3CLASS(CPlan_Casting,ProducePlan,1)

BEGIN_L3PROPTABLE(CPlan_Casting,ProducePlan)
	L3PROP_STRING(CasterID)
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(Pre_SteelGrade)
	L3PROP_STRING(Refine_Type)
	L3PROP_STRING(Pre_LotNo)
	L3PROP_STRING(PreHeatID)
	L3PROP_DOUBLE(Aim_Tapped_Weight)
	L3PROP_LONG(Proc_Seq)
	L3PROP_STRING(Plan_Ord_ID)
	L3PROP_LONG(Bloom_Count)
	L3PROP_DATETIME(Aim_Time_CastingStart)
	L3PROP_SHORT(New_BOF_Flag)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(LFID)
	L3PROP_STRING(RHID)
	L3PROP_DOUBLE(ActWeight)
END_L3PROPTABLE(CPlan_Casting)

BEGIN_L3METHODMAP(CPlan_Casting,ProducePlan)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Casting,ProducePlan)
END_L3EVENTSINK_MAP(CPlan_Casting)

CPlan_Casting::CPlan_Casting(void)
{
}

CPlan_Casting::~CPlan_Casting(void)
{
}
