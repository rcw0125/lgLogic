// 逻辑类CEquip_Level_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Level_Log :
	public CL3Object
{
public:
	CEquip_Level_Log(void);
	virtual ~CEquip_Level_Log(void);

	DECLARE_L3CLASS(CEquip_Level_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Level_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Level_Log" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Level_Log" name="StrandNo" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Level_Log" name="Zero_B_Act" type="L3STRING">
	/// 清零前值
	/// </Property>
	DECLARE_L3PROP_STRING(Zero_B_Act)

	/// <Property class="CEquip_Level_Log" name="Zero_A_Act" type="L3STRING">
	/// 清零后值
	/// </Property>
	DECLARE_L3PROP_STRING(Zero_A_Act)

	/// <Property class="CEquip_Level_Log" name="Full_B_Act" type="L3STRING">
	/// 置满前值
	/// </Property>
	DECLARE_L3PROP_STRING(Full_B_Act)

	/// <Property class="CEquip_Level_Log" name="Full_A_Act" type="L3STRING">
	/// 置满后值
	/// </Property>
	DECLARE_L3PROP_STRING(Full_A_Act)

	/// <Property class="CEquip_Level_Log" name="N0_Std" type="L3STRING">
	/// N0标准值
	/// </Property>
	DECLARE_L3PROP_STRING(N0_Std)

	/// <Property class="CEquip_Level_Log" name="N0_Act" type="L3STRING">
	/// N0实测值
	/// </Property>
	DECLARE_L3PROP_STRING(N0_Act)

	/// <Property class="CEquip_Level_Log" name="N7_N8_Std" type="L3STRING">
	/// N7-N8标准值
	/// </Property>
	DECLARE_L3PROP_STRING(N7_N8_Std)

	/// <Property class="CEquip_Level_Log" name="N7_N8_Act" type="L3STRING">
	/// N7-N8实测值
	/// </Property>
	DECLARE_L3PROP_STRING(N7_N8_Act)

	/// <Property class="CEquip_Level_Log" name="N10_Std" type="L3STRING">
	/// N10标准值
	/// </Property>
	DECLARE_L3PROP_STRING(N10_Std)

	/// <Property class="CEquip_Level_Log" name="N10_Act" type="L3STRING">
	/// N10实测值
	/// </Property>
	DECLARE_L3PROP_STRING(N10_Act)

	/// <Property class="CEquip_Level_Log" name="Check_Date" type="L3DATETIME">
	/// 校准日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Level_Log" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Level_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Level_Log" name="Status" type="L3LONG">
	/// 状态 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};
