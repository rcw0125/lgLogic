// 逻辑类CLadle_Plan头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Plan :
	public CL3Object
{
public:
	CLadle_Plan(void);
	virtual ~CLadle_Plan(void);

	DECLARE_L3CLASS(CLadle_Plan,XGMESLogic\\LadleMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Plan)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Plan" name="Heat_ID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PlanID)

	/// <Property class="CLadle_Plan" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)					

	/// <Property class="CLadle_Plan" name="Input_Date" type="L3DATETIME">
	/// 产生计划时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)

	/// <Property class="CLadle_Plan" name="Heat_ID" type="L3STRING">
	/// 熔炼号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Plan" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CLadle_Plan" name="UnitID" type="L3STRING">
	/// 当前工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)							   

	/// <Property class="CLadle_Plan" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Plan" name="Ladle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLadle_Plan" name="New_BOF_Flag" type="L3LONG">
	/// 80t转炉标志
	/// </Property>
	DECLARE_L3PROP_LONG(New_BOF_Flag)

	/// <Property class="CLadle_Plan" name="Status" type="L3STRING">
	/// 计划状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLadle_Plan" name="Act_Time_IronPrepared" type="L3DATETIME">
	/// 主原料装入时刻（铁水准备终）
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_IronPrepared)

	/// <Property class="CLadle_Plan" name="Act_Time_BOFStart" type="L3DATETIME">
	/// 吹炼始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFStart)

	/// <Property class="CLadle_Plan" name="Act_Time_BOFTapped" type="L3DATETIME">
	/// 出钢终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFTapped)

	/// <Property class="CLadle_Plan" name="Act_Time_TappedSideEnd" type="L3DATETIME">
	/// 炉后处理结束
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_TappedSideEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_LFArrival" type="L3DATETIME">
	/// LF进站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_LFStart" type="L3DATETIME">
	/// LF始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFStart)

	/// <Property class="CLadle_Plan" name="Act_Time_LFEnd" type="L3DATETIME">
	/// LF终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_LFLeave" type="L3DATETIME">
	/// LF出站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFLeave)

	/// <Property class="CLadle_Plan" name="Act_Time_RHArrival" type="L3DATETIME">
	/// RH进站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_RHStart" type="L3DATETIME">
	/// RH始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHStart)

	/// <Property class="CLadle_Plan" name="Act_Time_RHEnd" type="L3DATETIME">
	/// RH终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_RHLeave" type="L3DATETIME">
	/// RH出站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHLeave)

	/// <Property class="CLadle_Plan" name="Act_Time_CasterArrival" type="L3DATETIME">
	/// 铸机到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CasterArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_CastingStart" type="L3DATETIME">
	/// 注入始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingStart)

	/// <Property class="CLadle_Plan" name="Act_Time_CastingEnd" type="L3DATETIME">
	/// 注入终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingEnd)


	/// <Property class="CLadle_Plan" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Plan" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Plan" name="Operator" type="L3STRING">
	/// 倒包确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Plan" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
