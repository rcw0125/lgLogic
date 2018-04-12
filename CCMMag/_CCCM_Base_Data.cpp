// 逻辑类CCCM_Base_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Base_Data.h"

IMPLEMENT_L3CLASS(CCCM_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Base_Data,CL3Object)
	///2009-02-13删除浇次号、预定包次号,添加主控工、厚度、宽度、长度
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(HeatConfirm)
	L3PROP_STRING(PreHeatID)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(Plan_SteelGrade)
	L3PROP_STRING(HeadFurnace)
	L3PROP_STRING(Ladle_Operator)
	L3PROP_STRING(Control_Operator)
	L3PROP_STRING(Cut_Operator)
	L3PROP_STRING(Tundish_1ST_Officer)
	L3PROP_STRING(Tundish_2ST_Officer)
	L3PROP_STRING(Tundish_3ST_Officer)
	L3PROP_STRING(Tundish_4ST_Officer)
	L3PROP_LONG(Thickness)
	L3PROP_LONG(Width)
	L3PROP_LONG(Length)
	L3PROP_SHORT(Locked)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_LONG(NC_Confirm_Flag)
END_L3PROPTABLE(CCCM_Base_Data)

BEGIN_L3METHODMAP(CCCM_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Base_Data)

CCCM_Base_Data::CCCM_Base_Data(void)
{
}

CCCM_Base_Data::~CCCM_Base_Data(void)
{
}
