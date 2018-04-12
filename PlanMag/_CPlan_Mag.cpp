// 逻辑类CPlan_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_Mag.h"

IMPLEMENT_L3CLASS(CPlan_Mag,PlanDept,1)

BEGIN_L3PROPTABLE(CPlan_Mag,PlanDept)
	L3PROP_LONG(PlanOrderEvent)               //计划订单状态变化事件
	L3PROP_LONG(TappingPlanEvent)               //出钢计划状态变化事件
	L3PROP_LONG(TappingPlanGenerateEvent)      //出钢计划生成事件
	L3PROP_LONG(EquipmentStatusChange)			//设备状态改变
	L3PROP_LONG(WriteFlag)	
	L3PROP_LONG(BOFChangeFlag)		        //交换炉座开始标志 
	L3PROP_LONG(TappingModelFlag)			//出钢模型结束标志
	L3PROP_LONG(PlanExeFlag)				//计划下达标志 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(PlanCancelFlag)			//计划取消标志 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(IronPlanExeFlag)			//铁水计划下达标志 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(TappingPlanFlag)			//出钢计划标志 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(BOFYieldFlag)			    //计算转炉产能 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(AddNewBOFFlag)			    //增加新炉数 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(FirstCastingHeatFlag)		//指定浇次第一炉 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(ReFirstCastingHeatFlag)	//重新指定浇次第一炉 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(ModifyPlanFlag)			//修改 0,1 1:开始执行，0：执行完成
	L3PROP_LONG(PlanDelFlag)				//计划取消标志 0,1 1:开始执行，0：执行完成
END_L3PROPTABLE(CPlan_Mag)

BEGIN_L3METHODMAP(CPlan_Mag,PlanDept)
	L3_METHOD(CPlan_Mag,"PlanOrdRec",0,PlanOrdRec,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdRecFormNC",0,PlanOrdRecFormNC,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdCfm",0,PlanOrdCfm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetUnIntegratePlanOrd",0,GetUnIntegratePlanOrd,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetCastingPlan",0,GetCastingPlan,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetIntegratedPlanOrd",0,GetIntegratedPlanOrd,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"PlanOrdIntegrateCfm",0,PlanOrdIntegrateCfm,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdIntegrateCancel",0,PlanOrdIntegrateCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"CastingPlanGen",0,CastingPlanGen,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"NewCastingPlanGen",0,NewCastingPlanGen,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"CastingPlanCancel",0,CastingPlanCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanGen",0,TappingPlanGen,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanCancel",0,TappingPlanCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanSend",0,TappingPlanSend,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanSndCancel",0,TappingPlanSndCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanDestCfm",0,TappingPlanDestCfm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanExchange",0,TappingPlanExchange,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanFirHeatDesign",0,TappingPlanFirHeatDesign,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanFirHeatCancel",0,TappingPlanFirHeatCancel,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"AddHeatsToCasting",0,AddHeatsToCasting,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetCurDayTappingPlan",0,GetCurDayTappingPlan,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"TappingPlanChangeTimeTable",0,TappingPlanChangeTimeTable,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetCurHeatPlanInfor",0,GetCurHeatPlanInfor,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"TappingPlanChangeRoute",0,TappingPlanChangeRoute,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanExchangeTreatSeq",0,TappingPlanExchangeTreatSeq,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyPlanExecutionStatus",0,ModifyPlanExecutionStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetUnitProcessPlan",0,GetUnitProcessPlan,L3VT_RECORDSET,L3VTS_SHORT L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetUnConfirmPlanOrder",0,GetUnConfirmPlanOrder,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CPlan_Mag,"LogBOFNunProcessTime",0,LogBOFNunProcessTime,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyTappingPlanTimeInfor",0,ModifyTappingPlanTimeInfor,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ChangeRsTappingPlanValue",0,ChangeRsTappingPlanValue,L3VT_VOID,L3VTS_NONE)
	L3_METHOD(CPlan_Mag,"TappingPlanEnd",0,TappingPlanEnd,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyUnitSteelGradeIndex",0,ModifyUnitSteelGradeIndex,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"DelPlanOrder",0,DelPlanOrder,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"EndPlanOrder",0,EndPlanOrder,L3VT_BOOL,L3VTS_RECORDSET)

	
	
	
	
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Mag,PlanDept)
END_L3EVENTSINK_MAP(CPlan_Mag)

CPlan_Mag::CPlan_Mag(void)
{
}

CPlan_Mag::~CPlan_Mag(void)
{
}
