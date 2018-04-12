// 逻辑类CCCM_Heat_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_Data.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CastingID)
	L3PROP_SHORT(CCMID)
	L3PROP_STRING(Tundish_SeqNo)
	L3PROP_STRING(TreatNo)
	L3PROP_LONG(Casting_HeatNum)
	L3PROP_LONG(Tundish_HeatNum)
	L3PROP_STRING(Pre_HeatID)
	L3PROP_STRING(Pre_LotNo)
	L3PROP_STRING(ShopSign)
	L3PROP_FLOAT(Casting_Width)
	L3PROP_FLOAT(Casting_Thickness)
	L3PROP_LONG(Introduced_Count)
	L3PROP_LONG(Protect_Casting)
	L3PROP_LONG(Blooms_Num)
	L3PROP_LONG(Primary_Weight)
	L3PROP_LONG(StdBlooms_Num)
	L3PROP_LONG(StdBlooms_Weight)
	L3PROP_LONG(SubStd_Blooms_Num)
	L3PROP_LONG(SubStd_Blooms_Weight)
	L3PROP_LONG(Waster_Num)
	L3PROP_DATETIME(FinalCut_Time)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Waster_Weight)
	L3PROP_LONG(Goods_Num)
	L3PROP_SHORT(InjectionBar_BlowAr)
	L3PROP_LONG(Thickness)
	L3PROP_LONG(Width)
	L3PROP_LONG(Length)
	L3PROP_SHORT(Steel_Return_Div)
	L3PROP_DOUBLE(Weight_Return)
	L3PROP_SHORT(Second_Cooling_Mode)
	L3PROP_SHORT(Second_Cooling_CurveNo)
	L3PROP_DOUBLE(Weight_Cut_Head)
	L3PROP_DOUBLE(Weight_Cut_Trail)
	L3PROP_LONG(Leak_Steel_Num)
END_L3PROPTABLE(CCCM_Heat_Data)

BEGIN_L3METHODMAP(CCCM_Heat_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Data)

CCCM_Heat_Data::CCCM_Heat_Data(void)
{
}

CCCM_Heat_Data::~CCCM_Heat_Data(void)
{
}
