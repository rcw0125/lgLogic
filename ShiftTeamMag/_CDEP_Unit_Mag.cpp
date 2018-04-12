// 逻辑类CDEP_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDEP_Unit_Mag.h"

IMPLEMENT_L3CLASS(CDEP_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CDEP_Unit_Mag,ProduceUnit)
    L3PROP_STRING(IronLadle)
	L3PROP_STRING(IronLadleNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(NextHeatID)
	L3PROP_LONG(Status)
	L3PROP_LONG(FurnaceAge)
	/// 氧枪铁水液面
	/// </Property>
	L3PROP_LONG(Furnace_Surface)

	L3PROP_LONG(LanceAge)
	
	L3PROP_LONG(LanceNo)
	/// 扒渣耙头
	L3PROP_LONG(Slag_Head)

	L3PROP_LONG(Step)
	/// 脱硅开始时刻
	/// 
	/// </Property>
	L3PROP_DATETIME(Desi_Start_time)
		/// 脱lin开始时刻
	/// 
	/// </Property>
	L3PROP_DATETIME(Dep_Start_time)

	L3PROP_LONG(Desi_Time)
	L3PROP_LONG(Dep_Time)
	//脱磷脱硅标志  脱硅0 脱磷 1
	L3PROP_LONG(Dep_Flag)

	//脱磷脱硅标志  脱硅0 脱磷 1
	L3PROP_LONG(Return_Flag)
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
END_L3PROPTABLE(CDEP_Unit_Mag)

BEGIN_L3METHODMAP(CDEP_Unit_Mag,ProduceUnit)


	L3_METHOD(CDEP_Unit_Mag,"FeedElement",0,FeedElement,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"TopBlowing",0,TopBlowing,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"SetTemperature",0,SetTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"ChangeDeviceStatus",0,ChangeDeviceStatus,L3VT_BOOL,L3VTS_LONG L3VTS_STRING)
	L3_METHOD(CDEP_Unit_Mag,"Waiting",0,Waiting,L3VT_LONG,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"GetIronsForDesignate",0,GetIronsForDesignate,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"GetInputIrons",0,GetInputIrons,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"GetInputScrapes",0,GetInputScrapes,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"OnTimer",0,OnTimer,L3VT_VOID,L3VTS_BOOL)
	L3_METHOD(CDEP_Unit_Mag,"GetAddedMaterialSum",0,GetAddedMaterialSum,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDEP_Unit_Mag,"ChangeSteelGradeApp",0,ChangeSteelGradeApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE)
	L3_METHOD(CDEP_Unit_Mag,"SteelReturnApp",0,SteelReturnApp,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE L3VTS_STRING)
	L3_METHOD(CDEP_Unit_Mag,"AcceptMaterialDischargeData",0,AcceptMaterialDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"MaterialGroundDischargeData",0,MaterialGroundDischargeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"GetExceptHeatID",0,GetExceptHeatID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDEP_Unit_Mag,"SetStackData",0,SetStackData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"LockData",0,LockData,L3VT_SHORT,L3VTS_STRING L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CDEP_Unit_Mag,"AcceptDEPStatus",0,AcceptDEPStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"AcceptDEPTopBlowData",0,AcceptDEPTopBlowData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"AcceptDEPTappedData",0,AcceptDEPTappedData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"AcceptDEPTempData",0,AcceptDEPTempData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"AcceptDEPOxygenData",0,AcceptDEPOxygenData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"IronLadleToDEP",0,IronLadleToDEP,L3VT_LONG,L3VTS_RECORDSET)//2009-02-28
	L3_METHOD(CDEP_Unit_Mag,"GetPreThreeHeatID",0,GetPreThreeHeatID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"IronLadleToDEP",0,IronLadleToDEP,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDEP_Unit_Mag,"StartSlag",0,StartSlag,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"EndSlag",0,EndSlag,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"StartSpray",0,StartSpray,L3VT_BOOL,L3VTS_NONE)
	
	L3_METHOD(CDEP_Unit_Mag,"EndSpray",0,EndSpray,L3VT_BOOL,L3VTS_NONE)
	//L3_METHOD(CDEP_Unit_Mag,"StartSi",0,StartSi,L3VT_BOOL,L3VTS_NONE)
	//L3_METHOD(CDEP_Unit_Mag,"EndSi",0,EndSi,L3VT_BOOL,L3VTS_NONE)
	//L3_METHOD(CDEP_Unit_Mag,"StartP",0,StartP,L3VT_BOOL,L3VTS_NONE)
	//L3_METHOD(CDEP_Unit_Mag,"EndP",0,EndP,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"StartSprayP",0,StartSprayP,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"EndSprayP",0,EndSprayP,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"ReblowBeginSpray",0,ReblowBeginSpray,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"ReblowEndSpray",0,ReblowEndSpray,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDEP_Unit_Mag,"StartSlagP",0,StartSlagP,L3VT_BOOL,L3VTS_NONE)
    L3_METHOD(CDEP_Unit_Mag,"EndSlagP",0,EndSlagP,L3VT_BOOL,L3VTS_NONE)

	L3_METHOD(CDEP_Unit_Mag,"SendStatusToPLC",0,SendStatusToPLC,L3VT_BOOL,L3VTS_NONE)
	
	
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CDEP_Unit_Mag)

CDEP_Unit_Mag::CDEP_Unit_Mag(void)
{
	m_nTimer = 0;
}

CDEP_Unit_Mag::~CDEP_Unit_Mag(void)
{
}
