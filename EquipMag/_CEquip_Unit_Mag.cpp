// 逻辑类CEquip_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Unit_Mag.h"

IMPLEMENT_L3CLASS(CEquip_Unit_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Unit_Mag,CL3Object)
END_L3PROPTABLE(CEquip_Unit_Mag)

BEGIN_L3METHODMAP(CEquip_Unit_Mag,CL3Object)
	L3_METHOD(CEquip_Unit_Mag,"NewCalibration",         0,NewCalibration,         L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"ModifyCalibration",      0,ModifyCalibration,      L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"DeleteCalibration",      0,DeleteCalibration,      L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"NewCalibrationDetail",   0,NewCalibrationDetail,   L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"ModifyCalibrationDetail",0,ModifyCalibrationDetail,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"DeleteCalibrationDetail",0,DeleteCalibrationDetail,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"QueryCalibration",       0,QueryCalibration,       L3VT_RECORDSET,L3VTS_DATETIME L3VTS_DATETIME)
	L3_METHOD(CEquip_Unit_Mag,"QueryCalibrationDetail", 0,QueryCalibrationDetail, L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CEquip_Unit_Mag,"AcceptCleaningData",     0,AcceptCleaningData,     L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"AcceptRuntimeData",      0,AcceptRuntimeData,      L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"AcceptSupplyWaterData",  0,AcceptSupplyWaterData,  L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CEquip_Unit_Mag,"AcceptSupplyWaterEndData",0,AcceptSupplyWaterEndData,     L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Unit_Mag,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Unit_Mag)

CEquip_Unit_Mag::CEquip_Unit_Mag(void)
{
}

CEquip_Unit_Mag::~CEquip_Unit_Mag(void)
{
}
