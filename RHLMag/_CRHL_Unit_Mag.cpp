// 逻辑类CRHL_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRHL_Unit_Mag.h"

IMPLEMENT_L3CLASS(CRHL_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CRHL_Unit_Mag,ProduceUnit)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(NextTreatNo)
	L3PROP_LONG(Status)
	L3PROP_STRING(NextSteel)
	L3PROP_STRING(CurArea)
	L3PROP_DATETIME(ProcStartTime)
	L3PROP_DATETIME(ProcStopTime)
	L3PROP_DATETIME(HeatStartTime)
	L3PROP_LONG(ProcTime)
	L3PROP_STRING(WeightingSteel)
	L3PROP_DOUBLE(CurTemp)
	L3PROP_STRING(ReSampleHeatID)
	L3PROP_STRING(StartProcessTime)//2008-12-26
	L3PROP_LONG(Lid_Life) //2008-12-27
	L3PROP_LONG(PoleConsume)//2009-02-28
	L3PROP_LONG(Equip_Status)
	L3PROP_STRING(Pole_Vendor)
	L3PROP_STRING(Probe_Vendor)
	L3PROP_STRING(PrevArea)
END_L3PROPTABLE(CRHL_Unit_Mag)

BEGIN_L3METHODMAP(CRHL_Unit_Mag,ProduceUnit)
	L3_METHOD(CRHL_Unit_Mag,"GetInputSteels",0,GetInputSteels,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CRHL_Unit_Mag,"DesignateForWeighting",0,DesignateForWeighting,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"SetWeight",0,SetWeight,L3VT_BOOL,L3VTS_DOUBLE)
	L3_METHOD(CRHL_Unit_Mag,"DesignateLadle",0,DesignateLadle,L3VT_BOOL,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"SteelArrived",0,SteelArrived,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"FeedElement",0,FeedElement,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"SetTemperature",0,SetTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"SetOxygen",0,SetOxygen,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"FeedWire",0,FeedWire,L3VT_BOOL,L3VTS_STRING L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"StartProcess",0,StartProcess,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"StopProcess",0,StopProcess,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CRHL_Unit_Mag,"ChangeDeviceStatus",0,ChangeDeviceStatus,L3VT_BOOL,L3VTS_LONG L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"OnTimer",0,OnTimer,L3VT_BOOL,L3VTS_ULONG)
	L3_METHOD(CRHL_Unit_Mag,"StartHeating",0,StartHeating,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CRHL_Unit_Mag,"StopHeating",0,StopHeating,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CRHL_Unit_Mag,"StartBlowing",0,StartBlowing,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"StopBlowing",0,StopBlowing,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"SteelLeave",0,SteelLeave,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"ChangeSteelGradeApp",0,ChangeSteelGradeApp,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"SteelReturnApp",0,SteelReturnApp,L3VT_BOOL,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"SteelBackApp",0,SteelBackApp,L3VT_BOOL,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CRHL_Unit_Mag,"AcceptMaterialDischargeData",0,AcceptMaterialDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"MaterialGroundDischargeData",0,MaterialGroundDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFArrivalData",0,AcceptLFArrivalData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFStartProcessData",0,AcceptLFStartProcessData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFEndProcessData",0,AcceptLFEndProcessData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFHeatData",0,AcceptLFHeatData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFStartSoftBlowData",0,AcceptLFStartSoftBlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFStopSoftBlowData",0,AcceptLFStopSoftBlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFTempData",0,AcceptLFTempData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFWireData",0,AcceptLFWireData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFOxygenData",0,AcceptLFOxygenData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFWeightData",0,AcceptLFWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"GetPreThreeHeatID",0,GetPreThreeHeatID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFBlowArData",0,AcceptLFBlowArData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFHeatGears",0,AcceptLFHeatGears,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"AcceptLFBlowArFlow",0,AcceptLFBlowArFlow,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CRHL_Unit_Mag,"ModifyLadleGrade",0,ModifyLadleGrade,L3VT_LONG,L3VTS_STRING L3VTS_STRING)//2009-03-30 Liao
	L3_METHOD(CRHL_Unit_Mag,"CalEleRateValue",0,CalEleRateValue,L3VT_FLOAT,L3VTS_STRING L3VTS_STRING L3VTS_STRING)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CRHL_Unit_Mag)

CRHL_Unit_Mag::CRHL_Unit_Mag(void)
{
	csDischargeUnit = _T("");
}

CRHL_Unit_Mag::~CRHL_Unit_Mag(void)
{
}
