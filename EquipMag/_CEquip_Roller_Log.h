// 逻辑类CEquip_Roller_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Roller_Log :
	public CL3Object
{
public:
	CEquip_Roller_Log(void);
	virtual ~CEquip_Roller_Log(void);

	DECLARE_L3CLASS(CEquip_Roller_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Roller_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Roller_Log" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Roller_Log" name="StrandNo" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Roller_Log" name="Roller_Std" type="L3STRING">
	/// 标定值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller_Std)

	/// <Property class="CEquip_Roller_Log" name="Roller1_Act" type="L3STRING">
	/// 一号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller1_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller2_Act" type="L3STRING">
	/// 二号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller2_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller3_Act" type="L3STRING">
	/// 三号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller3_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller4_Act" type="L3STRING">
	/// 四号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller4_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller5_Act" type="L3STRING">
	/// 五号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller5_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller6_Act" type="L3STRING">
	/// 六号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller6_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller7_Act" type="L3STRING">
	/// 七号辊实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Roller7_Act)

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
