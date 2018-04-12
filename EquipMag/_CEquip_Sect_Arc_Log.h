// 逻辑类CEquip_Sect_Arc_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Sect_Arc_Log :
	public CL3Object
{
public:
	CEquip_Sect_Arc_Log(void);
	virtual ~CEquip_Sect_Arc_Log(void);

	DECLARE_L3CLASS(CEquip_Sect_Arc_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Sect_Arc_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Sect_Arc_Log" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Sect_Arc_Log" name="StrandNo" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Sect_Arc_Log" name="SectNo" type="L3STRING">
	/// 扇形段编号
	/// </Property>
	DECLARE_L3PROP_STRING(SectNo)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_1stSect_Std" type="L3STRING">
	/// 一段对弧标准
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_1stSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_1stSect_Act" type="L3STRING">
	/// 一段对弧实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_1stSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_2ndSect_Std" type="L3STRING">
	/// 二段对弧标准
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_2ndSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_2ndSect_Act" type="L3STRING">
	/// 二段对弧实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_2ndSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_3rdSect_Std" type="L3STRING">
	/// 三段对弧标准
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_3rdSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_3rdSect_Act" type="L3STRING">
	/// 三段对弧实测值
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_3rdSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Check_Date" type="L3DATETIME">
	/// 校准日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Sect_Arc_Log" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Sect_Arc_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Sect_Arc_Log" name="Status" type="L3LONG">
	/// 状态 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};
