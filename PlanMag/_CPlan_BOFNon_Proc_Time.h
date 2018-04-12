// 逻辑类CPlan_BOFNon_Proc_Time头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_BOFNon_Proc_Time :
	public CL3Object
{
public:
	CPlan_BOFNon_Proc_Time(void);
	virtual ~CPlan_BOFNon_Proc_Time(void);

	DECLARE_L3CLASS(CPlan_BOFNon_Proc_Time,XGMESLogic\\PlanMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_BOFNon_Proc_Time)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_BOFNon_Proc_Time" name="Aim_Time_BOFRepared" type="L3DOUBLE">
	/// 计划补炉时间
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Time_BOFRepared)

	/// <Property class="CPlan_BOFNon_Proc_Time" name="Aim_Time_BlowN2" type="L3DOUBLE">
	/// 吹氮气时间
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Time_BlowN2)

	/// <Property class="CPlan_BOFNon_Proc_Time" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};
