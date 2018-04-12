// 逻辑类CPlan_Tapping源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_Tapping.h"

IMPLEMENT_L3CLASS(CPlan_Tapping,ProducePlan,1)

BEGIN_L3PROPTABLE(CPlan_Tapping,ProducePlan)
	L3PROP_STRING(Pre_LotNo)
	L3PROP_STRING(PreHeatID)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(Pre_SteelGrade)
	L3PROP_DOUBLE(Aim_Tapped_Weight)
	L3PROP_STRING(CasterID)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(LFID)
	L3PROP_STRING(RHID)
	L3PROP_STRING(DEPID)
	L3PROP_STRING(RHLID)
	L3PROP_STRING(AODID)
	L3PROP_STRING(DEP_Status)
	L3PROP_STRING(RHL_Status)
	L3PROP_STRING(AOD_Status)
	L3PROP_STRING(BOF_Status)
	L3PROP_STRING(LF_Status)
	L3PROP_STRING(RH_Status)
	L3PROP_STRING(Caster_Status)
	L3PROP_STRING(Side_Status)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Casting_No)
	L3PROP_LONG(Casting_Heat_Cnt)
	L3PROP_DATETIME(Aim_Time_IronPrepared)
	L3PROP_DATETIME(Aim_Time_BOFStart)
	L3PROP_DATETIME(Aim_Time_BOFTapped)
	L3PROP_DATETIME(Aim_Time_TappedSideEnd)
	L3PROP_DATETIME(Aim_Time_LFArrival)
	L3PROP_DATETIME(Aim_Time_LFStart)
	L3PROP_DATETIME(Aim_Time_LFEnd)
	L3PROP_DATETIME(Aim_Time_LFLeave)
	L3PROP_DATETIME(Aim_Time_RHArrival)
	L3PROP_DATETIME(Aim_Time_RHStart)
	L3PROP_DATETIME(Aim_Time_RHEnd)
	L3PROP_DATETIME(Aim_Time_RHLeave)
	L3PROP_DATETIME(Aim_Time_CasterArrival)
	L3PROP_DATETIME(Aim_Time_CastingStart)
	L3PROP_DATETIME(Aim_Time_CastingEnd)
	L3PROP_LONG(Fir_Heat_Flag)
	L3PROP_STRING(Div_HeatID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Plan_Ord_ID)
	L3PROP_LONG(Hot_Send_Flag)
	L3PROP_LONG(Steel_Return_Flag)
	L3PROP_LONG(Steel_Back_Flag)
	L3PROP_STRING(Treat_Seq)
	L3PROP_STRING(Destitation)
	L3PROP_SHORT(New_BOF_Flag)
	L3PROP_STRING(Refine_Type)
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
END_L3PROPTABLE(CPlan_Tapping)

BEGIN_L3METHODMAP(CPlan_Tapping,ProducePlan)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Tapping,ProducePlan)
END_L3EVENTSINK_MAP(CPlan_Tapping)

CPlan_Tapping::CPlan_Tapping(void)
{
}

CPlan_Tapping::~CPlan_Tapping(void)
{
}
