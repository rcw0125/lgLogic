// 逻辑类CEquip_Coil_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Coil_Log :
	public CL3Object
{
public:
	CEquip_Coil_Log(void);
	virtual ~CEquip_Coil_Log(void);

	DECLARE_L3CLASS(CEquip_Coil_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Coil_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Coil_Log" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Coil_Log" name="StrandNo" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Coil_Log" name="CoilNo" type="L3STRING">
	/// 线圈编号　
	/// </Property>
	DECLARE_L3PROP_STRING(CoilNo)

	/// <Property class="CEquip_Coil_Log" name="Insulating" type="L3STRING">
	/// 绝缘强度
	/// </Property>
	DECLARE_L3PROP_STRING(Insulating)

	/// <Property class="CEquip_Coil_Log" name="Elec_Intensity_Std" type="L3STRING">
	/// 电磁场强度标准值
	/// </Property>
	DECLARE_L3PROP_STRING(Elec_Intensity_Std )

	/// <Property class="CEquip_Coil_Log" name="Elec_Intensity_Act" type="L3STRING">
	/// 电磁场强度值
	/// </Property>
	DECLARE_L3PROP_STRING(Elec_Intensity_Act )

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
