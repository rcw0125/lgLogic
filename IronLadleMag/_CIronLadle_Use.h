// 逻辑类CIronLadle_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CIronLadle_Use :
	public CL3Object
{
public:
	CIronLadle_Use(void);
	virtual ~CIronLadle_Use(void);

	DECLARE_L3CLASS(CIronLadle_Use,XGMESLogic\\IronLadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Use" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CIronLadle_Use" name="IronLadleID" type="L3STRING">
	/// 铁包号
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Use" name="TieID" type="L3STRING">
	/// 铁包打结编号
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Use" name="Check_Time" type="L3DATETIME">
	/// 检查时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Time)

	/// <Property class="CIronLadle_Use" name="IronLadle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(IronLadle_Age)

	/// <Property class="CIronLadle_Use" name="Wall_TEMP" type="L3FLOAT">
	/// 包壁温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wall_TEMP)

	/// <Property class="CIronLadle_Use" name="Bottom_TEMP" type="L3FLOAT">
	/// 包底温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Bottom_TEMP)

	/// <Property class="CIronLadle_Use" name="Stop_Reason" type="L3STRING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Reason)

	/// <Property class="CIronLadle_Use" name="Throw_Time" type="L3STRING">
	/// 甩包时间
	/// </Property>
	DECLARE_L3PROP_STRING(Throw_Time)

	
	/// <Property class="CIronLadle_Use" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	
	/// <Property class="CIronLadle_Use" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CIronLadle_Use" name="Operator" type="L3STRING">
	/// 操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Use" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
