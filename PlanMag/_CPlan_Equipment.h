// 逻辑类CPlan_Equipment头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_Equipment :
	public CL3Object
{
public:
	CPlan_Equipment(void);
	virtual ~CPlan_Equipment(void);

	DECLARE_L3CLASS(CPlan_Equipment,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Equipment)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Equipment" name="UnitID" type="L3STRING">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CPlan_Equipment" name="Unit_TypeID" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(Unit_TypeID)

	/// <Property class="CPlan_Equipment" name="EndStopTime_Aim" type="L3DATETIME">
	/// 计划处理结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(EndStopTime_Aim)

	/// <Property class="CPlan_Equipment" name="BeginStopTime_Aim" type="L3DATETIME">
	/// 检修开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(BeginStopTime_Aim)

	/// <Property class="CPlan_Equipment" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CPlan_Equipment" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CPlan_Equipment" name="Operator" type="L3STRING">
	/// 记录员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};
