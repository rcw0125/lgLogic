// 逻辑类CEquip_Cooling_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Cooling_Log :
	public CL3Object
{
public:
	CEquip_Cooling_Log(void);
	virtual ~CEquip_Cooling_Log(void);

	DECLARE_L3CLASS(CEquip_Cooling_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Cooling_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Coil_Log" name="BOFID" type="L3STRING">
	/// 转炉
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CEquip_Coil_Log" name="Time_Chong_called" type="L3LONG">
	/// 汽包水位计冲叫时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Chong_called)

	/// <Property class="CEquip_Coil_Log" name="Time_Experiment" type="L3LONG">
	/// 安全阀手动试验时间　
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Experiment)

	/// <Property class="CEquip_Coil_Log" name="Reason_UnCleaning" type="L3STRING">
	/// 未排污原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_UnCleaning)

	/// <Property class="CEquip_Coil_Log" name="Problem_Inspection" type="L3STRING">
	/// 巡检设备问题
	/// </Property>
	DECLARE_L3PROP_STRING(Problem_Inspection)

	/// <Property class="CEquip_Coil_Log" name="Check_Date" type="L3DATETIME">
	/// 校准日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Coil_Log" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Coil_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Coil_Log" name="Status" type="L3LONG">
	/// 状态 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};
