// 逻辑类CEnergy_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEnergy_Unit_Mag.h"

IMPLEMENT_L3CLASS(CEnergy_Unit_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergy_Unit_Mag,CL3Object)
END_L3PROPTABLE(CEnergy_Unit_Mag)

BEGIN_L3METHODMAP(CEnergy_Unit_Mag,CL3Object)
	L3_METHOD(CEnergy_Unit_Mag,"AcceptEnergyFlowData",0,AcceptEnergyFlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"AcceptEnergyPressureData",0,AcceptEnergyPressureData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"AcceptEnergyConsumeData",0,AcceptEnergyConsumeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"AcceptTrendGasFlowData",0,AcceptTrendGasFlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"AcceptTrendAirFlowData",0,AcceptTrendAirFlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"NewConsumption",0,NewConsumption,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"UpdateConsumption",0,UpdateConsumption,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"QueryConsumptionInfo",0,QueryConsumptionInfo,L3VT_RECORDSET,L3VTS_DATETIME L3VTS_DATETIME)
	/*L3_METHOD(CEnergy_Unit_Mag,"UpdateAODHeatid",0,UpdateAODHeatid,L3VT_BOOL)*/
	L3_METHOD(CEnergy_Unit_Mag,"UpdateAODHeatid",0,UpdateAODHeatid,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CEnergy_Unit_Mag,"TappingPlanGen",0,TappingPlanGen,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEnergy_Unit_Mag,"NewCastingPlanGen",0,NewCastingPlanGen,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)

END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergy_Unit_Mag,CL3Object)
END_L3EVENTSINK_MAP(CEnergy_Unit_Mag)

CEnergy_Unit_Mag::CEnergy_Unit_Mag(void)
{
}

CEnergy_Unit_Mag::~CEnergy_Unit_Mag(void)
{
}
