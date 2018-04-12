// 逻辑类CLance_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Use :
	public CL3Object
{
public:
	CLance_Use(void);
	virtual ~CLance_Use(void);

	DECLARE_L3CLASS(CLance_Use,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_Use" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Use" name="LanceID" type="L3STRING">
	/// 枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Use" name="MakeID" type="L3STRING">
	/// 氧枪制作编号
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Use" name="Lance_Head_Type" type="L3STRING">
	/// 枪头型号
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Use" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLance_Use" name="Shift_Date" type="L3DATETIME">
	/// 当班日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Shift_Date)

	/// <Property class="CLance_Use" name="Cool_Water_Flow" type="L3DOUBLE">
	/// 冷却水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cool_Water_Flow)

	/// <Property class="CLance_Use" name="Cool_Water_Temp" type="L3DOUBLE">
	/// 冷却水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cool_Water_Temp)

	/// <Property class="CLance_Use" name="Oxygen_Pressure" type="L3DOUBLE">
	/// 氧气(工作)压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Oxygen_Pressure)

	/// <Property class="CLance_Use" name="Oxygen_Flow" type="L3DOUBLE">
	/// 氧气(工作)流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Oxygen_Flow)

	/// <Property class="CLance_Use" name="Furnace_Count" type="L3LONG">
	/// 当班使用炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Furnace_Count)

	/// <Property class="CLance_Use" name="Change_Lance_Reason" type="L3STRING">
	/// 换枪原因
	/// </Property>
	DECLARE_L3PROP_STRING(Change_Lance_Reason)

	/// <Property class="CLance_Use" name="Total_Lance_Age" type="L3LONG">
	/// 累计枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Lance_Age)

	/// <Property class="CLance_Use" name="Amelt_Confirm_Pepole" type="L3STRING">
	/// 冶炼确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Amelt_Confirm_Pepole)

	/// <Property class="CLance_Use" name="Maintain_Confirm_Pepole" type="L3STRING">
	/// 维修确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Maintain_Confirm_Pepole)

	/// <Property class="CLance_Use" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Use" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Use" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Use" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
