// 逻辑类CPlan_Tapping_Act头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_Tapping_Act :
	public CL3Object
{
public:
	CPlan_Tapping_Act(void);
	virtual ~CPlan_Tapping_Act(void);

	DECLARE_L3CLASS(CPlan_Tapping_Act,XGMESLogic\\PlanMag, PreHeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Tapping_Act)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Tapping_Act" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CPlan_Tapping_Act" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Tapping_Act" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CPlan_Tapping_Act" name="LF_TreatNo" type="L3STRING">
	/// LF处理号
	/// </Property>
	DECLARE_L3PROP_STRING(LF_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="RH_TreatNo" type="L3STRING">
	/// RH处理号
	/// </Property>
	DECLARE_L3PROP_STRING(RH_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="Caster_TreatNo" type="L3STRING">
	/// 铸机处理号
	/// </Property>
	DECLARE_L3PROP_STRING(Caster_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_IronPrepared" type="L3DATETIME">
	/// 主原料装入时刻（铁水准备终）
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_IronPrepared)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_BOFStart" type="L3DATETIME">
	/// 吹炼始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_BOFTapped" type="L3DATETIME">
	/// 出钢终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFTapped)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_TappedSideEnd" type="L3DATETIME">
	/// 炉后处理结束
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_TappedSideEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFArrival" type="L3DATETIME">
	/// LF进站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFStart" type="L3DATETIME">
	/// LF始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFEnd" type="L3DATETIME">
	/// LF终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFLeave" type="L3DATETIME">
	/// LF出站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFLeave)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHArrival" type="L3DATETIME">
	/// RH进站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHStart" type="L3DATETIME">
	/// RH始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHEnd" type="L3DATETIME">
	/// RH终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHLeave" type="L3DATETIME">
	/// RH出站时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHLeave)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CasterArrival" type="L3DATETIME">
	/// 铸机到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CasterArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CastingStart" type="L3DATETIME">
	/// 注入始
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CastingEnd" type="L3DATETIME">
	/// 注入终
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingEnd)

	/// <Property class="CPlan_Tapping_Act" name="CreateDate" type="L3DATETIME">
	/// 创建时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)


	/// <Property class="CPlan_Tapping_Act" name="BOFID" type="L3STRING">
	/// 转炉炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_Tapping_Act" name="LFID" type="L3STRING">
	/// LF炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CPlan_Tapping_Act" name="RHID" type="L3STRING">
	/// RH炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)


};
