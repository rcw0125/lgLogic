// 逻辑类CEquip_Pole_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Pole_Log :
	public CL3Object
{
public:
	CEquip_Pole_Log(void);
	virtual ~CEquip_Pole_Log(void);

	DECLARE_L3CLASS(CEquip_Pole_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Pole_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Pole_Log" name="LFID" type="L3STRING">
	/// 精炼炉
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CEquip_Pole_Log" name="PhaseNo" type="L3STRING">
	/// 电相
	/// </Property>
	DECLARE_L3PROP_STRING(PhaseNo)

	/// <Property class="CEquip_Pole_Log" name="Pole_Std" type="L3STRING">
	/// 标定值
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Std)

	/// <Property class="CEquip_Pole_Log" name="Pole_Act" type="L3STRING">
	/// 实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Act)

	/// <Property class="CEquip_Pole_Log" name="Check_Date" type="L3DATETIME">
	/// 校准日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Pole_Log" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Pole_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Pole_Log" name="Status" type="L3LONG">
	/// 状态 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};
