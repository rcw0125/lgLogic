// 逻辑类CEquip_SupplyWater_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_SupplyWater_Data.h"

IMPLEMENT_L3CLASS(CEquip_SupplyWater_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_SupplyWater_Data,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Level_Boil)
	L3PROP_FLOAT(P_Boil)
	L3PROP_FLOAT(P_Pump_SupplyWater)
	L3PROP_FLOAT(P_Pump_SoftWater)
	L3PROP_FLOAT(Level_DeO2Box)
	L3PROP_FLOAT(Level_SoftWaterBox)
	L3PROP_FLOAT(P_MainPipe_Steam)
	L3PROP_DATETIME(Time_Start)
	L3PROP_DATETIME(Time_Stop)
	L3PROP_DATETIME(Time_Blow)
	L3PROP_SHORT(EndFlag)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CEquip_SupplyWater_Data)

BEGIN_L3METHODMAP(CEquip_SupplyWater_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_SupplyWater_Data,CL3Object)
END_L3EVENTSINK_MAP(CEquip_SupplyWater_Data)

CEquip_SupplyWater_Data::CEquip_SupplyWater_Data(void)
{
}

CEquip_SupplyWater_Data::~CEquip_SupplyWater_Data(void)
{
}
