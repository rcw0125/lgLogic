// 逻辑类CCCM_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Unit_Mag.h"

IMPLEMENT_L3CLASS(CCCM_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CCCM_Unit_Mag,ProduceUnit)
	L3PROP_LONG(Status)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(NextHeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_DOUBLE(RemainedWeight)
	L3PROP_LONG(CastingEndEvent)
	L3PROP_STRING(CutSampleHeatID)
	L3PROP_STRING(ReSampleHeatID)
	L3PROP_STRING(ArriveTime)
	L3PROP_STRING(StartCastingTime)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(NextLadleID)
	L3PROP_DOUBLE(TundishWeight)////2009-01-03
	L3PROP_STRING(EastTundishID)//2009-01-03
	L3PROP_STRING(WestTundishID)//2009-01-03
	L3PROP_DOUBLE(SteelWeight)////2009-01-03
	L3PROP_LONG(TundishTemp)////2009-01-14
	L3PROP_DOUBLE(Speed1st)////2009-01-14
	L3PROP_DOUBLE(Speed2st)////2009-01-14
	L3PROP_DOUBLE(Speed3st)////2009-01-14
	L3PROP_DOUBLE(Speed4st)////2009-01-14
	L3PROP_DOUBLE(SumCastWeight1st)////2009-02-28
	L3PROP_DOUBLE(SumCastWeight2st)////2009-02-28
	L3PROP_DOUBLE(SumCastWeight3st)////2009-02-28
	L3PROP_DOUBLE(SumCastWeight4st)////2009-02-28
	L3PROP_LONG(CastTo15Minute)////2009-02-28
	L3PROP_LONG(OnOff1st)////2009-02-28
	L3PROP_LONG(OnOff2st)////2009-02-28
	L3PROP_LONG(OnOff3st)////2009-02-28
	L3PROP_LONG(OnOff4st)////2009-02-28
	L3PROP_LONG(Equip_Status)
	L3PROP_LONG(Cut_Information)
	L3PROP_LONG(RemainCastingTime) //2009-03-20
	L3PROP_STRING(PrevHeatID)//2009-04-30
END_L3PROPTABLE(CCCM_Unit_Mag)

BEGIN_L3METHODMAP(CCCM_Unit_Mag,ProduceUnit)
	L3_METHOD(CCCM_Unit_Mag,"GetInputSteels",0,GetInputSteels,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"DesignateSteel",0,DesignateSteel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"SteelArrived",0,SteelArrived,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"StartCasting",0,StartCasting,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"CompletCasting",0,CompletCasting,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"ChangeCastingNo",0,ChangeCastingNo,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"ChangeTundishNo",0,ChangeTundishNo,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"ChangeDeviceStatus",0,ChangeDeviceStatus,L3VT_LONG,L3VTS_LONG L3VTS_STRING)
	L3_METHOD(CCCM_Unit_Mag,"DivideHeatApp",0,DivideHeatApp,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CCCM_Unit_Mag,"SteelBackApp",0,SteelBackApp,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CCCM_Unit_Mag,"SteelReturnApp",0,SteelReturnApp,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CCCM_Unit_Mag,"GenerateBlooms",0,GenerateBlooms,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"SetRemainedSteelWeight",0,SetRemainedSteelWeight,L3VT_BOOL,L3VTS_DOUBLE)
	L3_METHOD(CCCM_Unit_Mag,"GetHeatAllInformation",0,GetHeatAllInformation,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMTundishFireData",0,AcceptCCMTundishFireData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMRuntimeData",0,AcceptCCMRuntimeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMSpeedData",0,AcceptCCMSpeedData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMTundishTempData",0,AcceptCCMTundishTempData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMStatus",0,AcceptCCMStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMLadleWeightData",0,AcceptCCMLadleWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMSteelWeightData",0,AcceptCCMSteelWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"GetHeatConfirmInfor",0,GetHeatConfirmInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"GetPreThreeHeatID",0,GetPreThreeHeatID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCM5Runtime1Data",0,AcceptCCM5Runtime1Data,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCM5Runtime2Data",0,AcceptCCM5Runtime2Data,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptSteelWeight",0,AcceptSteelWeight,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"AcceptStrandStatusData",0,AcceptStrandStatusData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"ChangeCCMEquipment",0,ChangeCCMEquipment,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CCCM_Unit_Mag,"CalculateEquipmentLife",0,CalculateEquipmentLife,L3VT_LONG,L3VTS_LONG L3VTS_STRING L3VTS_LONG L3VTS_STRING)//2009-03-30 Liao
	L3_METHOD(CCCM_Unit_Mag,"CalculateRemainCastingTime",0,CalculateRemainCastingTime,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CCCM_Unit_Mag,"SendSteelWeightToPLC",0,SendSteelWeightToPLC,L3VT_BOOL,L3VTS_FLOAT)
	L3_METHOD(CCCM_Unit_Mag,"ChangeSteelGradeApp",0,ChangeSteelGradeApp,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CCCM_Unit_Mag,"ModifyStrandStatusData",0,ModifyStrandStatusData,L3VT_LONG,L3VTS_RECORDSET)//2009-04-18
	L3_METHOD(CCCM_Unit_Mag,"AcceptCCMTundishTempForRefine",0,AcceptCCMTundishTempForRefine,L3VT_BOOL,L3VTS_RECORDSET)//2009-06-02
	L3_METHOD(CCCM_Unit_Mag,"AcceptTundishWeightData",0,AcceptTundishWeightData,L3VT_BOOL,L3VTS_RECORDSET)//20160803
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CCCM_Unit_Mag)

CCCM_Unit_Mag::CCCM_Unit_Mag(void)
{
	CastNum1ST=0;
	CastNum2ST=0;
	CastNum3ST=0;
	CastNum4ST=0;
    cstrStopCastingHeatID = _T("");//2009-04-18
}

CCCM_Unit_Mag::~CCCM_Unit_Mag(void)
{
}
