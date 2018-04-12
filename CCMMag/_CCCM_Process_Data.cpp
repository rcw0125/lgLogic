// 逻辑类CCCM_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Process_Data.h"

IMPLEMENT_L3CLASS(CCCM_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Process_Data,CL3Object)

	///2009-02-13 删除厚宽长、预定炉号、预定包次号、产品牌号、铸造宽、铸造厚、引流次数、保护浇注、铸坯支数、
	///保护浇注、铸坯支数、粗坯量、合格支数、合格重量、不合格支数、不合格重量、甩废支数、最终切断时刻、
	///炼钢记号、甩废重量、合格支数、钢水返送区分、漏钢次数
	///添加回炉原因、中包车别

	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(TundishCar_Type)
	L3PROP_LONG(Casting_HeatNum)
	L3PROP_LONG(Tundish_HeatNum)
	L3PROP_DATETIME(CastingStartTime)//2008-12-26
	L3PROP_DATETIME(CastingStopTime)//2008-12-26
	L3PROP_SHORT(InjectionBar_BlowAr)
	L3PROP_DOUBLE(Weight_Return)
	L3PROP_STRING(Weight_Return_Reason)
	L3PROP_SHORT(Second_Cooling_Mode)
	L3PROP_SHORT(Second_Cooling_CurveNo)
	L3PROP_DOUBLE(Weight_Cut_Head)
	L3PROP_DOUBLE(Weight_Cut_Trail)
	L3PROP_LONG(Tundish_SlagThickness)
	L3PROP_LONG(Tundish_Bottom_Temp)
	L3PROP_LONG(Tundish_Wall_Temp)
	L3PROP_LONG(Tundish_Level_Mold)
	L3PROP_STRING(PlugBar_Control)
	L3PROP_STRING(Soft_Press_Flag_1)
	L3PROP_STRING(Soft_Press_Flag_2)
	L3PROP_STRING(Soft_Press_Flag_3)
	L3PROP_STRING(Soft_Press_Flag_4)
	L3PROP_STRING(SpeedChange)
END_L3PROPTABLE(CCCM_Process_Data)

BEGIN_L3METHODMAP(CCCM_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Process_Data)

CCCM_Process_Data::CCCM_Process_Data(void)
{
}

CCCM_Process_Data::~CCCM_Process_Data(void)
{
}
