// 逻辑类CBOF_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_Unit_Mag.h"

IMPLEMENT_L3CLASS(CBOF_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CBOF_Unit_Mag,ProduceUnit)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(NextHeatID)
	L3PROP_LONG(Status)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(LanceAge)
	L3PROP_LONG(FurnaceAge)
	L3PROP_LONG(Campaign)
	L3PROP_LONG(Addition_Type)
	L3PROP_DOUBLE(TopFlow)
	L3PROP_DOUBLE(TopPressure)
	L3PROP_DOUBLE(BottomFlow1)
	L3PROP_DOUBLE(BottomPressure1)
	L3PROP_DOUBLE(BottomFlow2)
	L3PROP_DOUBLE(BottomPressure2)
	L3PROP_DOUBLE(BottomFlow3)
	L3PROP_DOUBLE(BottomPressure3)
	L3PROP_DOUBLE(BottomFlow4)
	L3PROP_DOUBLE(BottomPressure4)
	L3PROP_DOUBLE(BottomFlow5)
	L3PROP_DOUBLE(BottomPressure5)
	L3PROP_DOUBLE(BottomFlow6)
	L3PROP_DOUBLE(BottomPressure6)
	L3PROP_LONG(BlowTotalTime)
	L3PROP_LONG(BlowThisTime)
	L3PROP_LONG(BlowingEvent)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DOUBLE(Load)
	L3PROP_DOUBLE(CurTemp)
	L3PROP_LONG(ReSampleEvent)
	L3PROP_LONG(UndoApplyEvent)
	L3PROP_STRING(ReSampleHeatID)
	L3PROP_STRING(StartProcessTime)
	L3PROP_LONG(Taphole_Life)
	L3PROP_LONG(Equip_Status)//2009-03-02
	L3PROP_LONG(Plan_Count)
END_L3PROPTABLE(CBOF_Unit_Mag)

BEGIN_L3METHODMAP(CBOF_Unit_Mag,ProduceUnit)

	L3_METHOD(CBOF_Unit_Mag,"GetScrapesForDesignate",0,GetScrapesForDesignate,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"FeedIrons",0,FeedIrons,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"FeedElement",0,FeedElement,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"TopBlowing",0,TopBlowing,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"BottomBlowing",0,BottomBlowing,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"StartBlowing",0,StartBlowing,L3VT_BOOL,L3VTS_BOOL L3VTS_DATETIME)
	L3_METHOD(CBOF_Unit_Mag,"StopBlowing",0,StopBlowing,L3VT_BOOL,L3VTS_DATETIME)
	L3_METHOD(CBOF_Unit_Mag,"SetOxygen",0,SetOxygen,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"SetTemperature",0,SetTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"ChangeDeviceStatus",0,ChangeDeviceStatus,L3VT_BOOL,L3VTS_LONG L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"StartTapping",0,StartTapping,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"StopTapping",0,StopTapping,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"Splashing",0,Splashing,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"Dumping",0,Dumping,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"Waiting",0,Waiting,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"GetIronsForDesignate",0,GetIronsForDesignate,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"GetInputIrons",0,GetInputIrons,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"GetInputScrapes",0,GetInputScrapes,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"OnTimer",0,OnTimer,L3VT_VOID,L3VTS_BOOL)
	L3_METHOD(CBOF_Unit_Mag,"GetAddedMaterialSum",0,GetAddedMaterialSum,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"ChangeSteelGradeApp",0,ChangeSteelGradeApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE)
	L3_METHOD(CBOF_Unit_Mag,"SteelReturnApp",0,SteelReturnApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"AcceptMaterialDischargeData",0,AcceptMaterialDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"MaterialGroundDischargeData",0,MaterialGroundDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"GetExceptHeatID",0,GetExceptHeatID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"SetStackData",0,SetStackData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"LockData",0,LockData,L3VT_SHORT,L3VTS_STRING L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFStatus",0,AcceptBOFStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFBottomBlowData",0,AcceptBOFBottomBlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFTopBlowData",0,AcceptBOFTopBlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFTappedData",0,AcceptBOFTappedData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFTempData",0,AcceptBOFTempData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFOxygenData",0,AcceptBOFOxygenData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Unit_Mag,"CaculateLadleGrade",0,CaculateLadleGrade,L3VT_BOOL,L3VTS_DATETIME L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"SendCastingDataToAnaL2",0,SendCastingDataToAnaL2,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CBOF_Unit_Mag,"DesignateMainMaterial",0,DesignateMainMaterial,L3VT_LONG,L3VTS_RECORDSET L3VTS_RECORDSET L3VTS_RECORDSET)//2009-02-28
	L3_METHOD(CBOF_Unit_Mag,"GetPreThreeHeatID",0,GetPreThreeHeatID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBOF_Unit_Mag,"AcceptBOFRemainSlag",0,AcceptBOFRemainSlag,L3VT_BOOL,L3VTS_RECORDSET)//2016-08-11

	
	
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CBOF_Unit_Mag)

CBOF_Unit_Mag::CBOF_Unit_Mag(void)
{
	m_nTimer = 0;
}

CBOF_Unit_Mag::~CBOF_Unit_Mag(void)
{
}
