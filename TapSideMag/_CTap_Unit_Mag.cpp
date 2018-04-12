// 逻辑类CTap_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CTap_Unit_Mag.h"

IMPLEMENT_L3CLASS(CTap_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CTap_Unit_Mag,ProduceUnit)
	L3PROP_LONG(Status)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DATETIME(StartTime)
	L3PROP_DATETIME(StopTime)
	L3PROP_LONG(ProcTime)
	L3PROP_STRING(ReSampleHeatID)
	L3PROP_STRING(StartProcessTime)
END_L3PROPTABLE(CTap_Unit_Mag)

BEGIN_L3METHODMAP(CTap_Unit_Mag,ProduceUnit)
	L3_METHOD(CTap_Unit_Mag,"StartProcess",0,StartProcess,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CTap_Unit_Mag,"StopProcess",0,StopProcess,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CTap_Unit_Mag,"FeedElements",0,FeedElements,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CTap_Unit_Mag,"SetTemperature",0,SetTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CTap_Unit_Mag,"SetOxygen",0,SetOxygen,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CTap_Unit_Mag,"OnTimer",0,OnTimer,L3VT_BOOL,L3VTS_ULONG)
	L3_METHOD(CTap_Unit_Mag,"SetWeight",0,SetWeight,L3VT_BOOL,L3VTS_DOUBLE)
	L3_METHOD(CTap_Unit_Mag,"Complete",0,Complete,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CTap_Unit_Mag,"GetInputSteels",0,GetInputSteels,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CTap_Unit_Mag,"ChangeSteelGradeApp",0,ChangeSteelGradeApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE)
	L3_METHOD(CTap_Unit_Mag,"SteelReturnApp",0,SteelReturnApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE L3VTS_STRING)
	L3_METHOD(CTap_Unit_Mag,"AcceptTapSideWeightData",0,AcceptTapSideWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CTap_Unit_Mag,"AutoStartProcess",0,AutoStartProcess,L3VT_BOOL,L3VTS_NONE) //2009-01-14
	L3_METHOD(CTap_Unit_Mag,"GetPreThreeHeatID",0,GetPreThreeHeatID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CTap_Unit_Mag,"AcceptOxygenData",0,AcceptOxygenData,L3VT_BOOL,L3VTS_RECORDSET) //2009-03-16 
	L3_METHOD(CTap_Unit_Mag,"AcceptTempData",0,AcceptTempData,L3VT_BOOL,L3VTS_RECORDSET) //2009-03-16
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CTap_Unit_Mag)

CTap_Unit_Mag::CTap_Unit_Mag(void)
{
	m_iTimer = 0;
}

CTap_Unit_Mag::~CTap_Unit_Mag(void)
{
}
