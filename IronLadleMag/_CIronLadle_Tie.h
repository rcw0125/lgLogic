// 逻辑类CIronLadle_Tie头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CIronLadle_Tie :
	public CL3Object
{
public:
	CIronLadle_Tie(void);
	virtual ~CIronLadle_Tie(void);

	DECLARE_L3CLASS(CIronLadle_Tie,XGMESLogic\\IronLadleMag, TieID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Tie)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	
	/// <Property class="CIronLadle_Tie" name="InPut_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(InPut_Time)

	/// <Property class="CIronLadle_Tie" name="IronLadleID" type="L3STRING">
	/// 铁包号
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Tie" name="TieID" type="L3STRING">
	/// 铁包打结编号
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Tie" name="Refra_Produce" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Produce)

	/// <Property class="CIronLadle_Tie" name="Refra_ID" type="L3STRING">
	/// 耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)

	/// <Property class="CIronLadle_Tie" name="Consumption" type="L3FLOAT">
	/// 消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Consumption)

	/// <Property class="CIronLadle_Tie" name="Tie_Start_Time" type="L3DATETIME">
	/// 打结开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_Start_Time)

	/// <Property class="CIronLadle_Tie" name="Tie_End_Time" type="L3DATETIME">
	/// 打结结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_End_Time)

	
	/// <Property class="CIronLadle_Tie" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	
	/// <Property class="CIronLadle_Tie" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	
	/// <Property class="CIronLadle_Tie" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Tie" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CIronLadle_Tie" name="Doff_Mod_Time" type="L3DATETIME">
	/// 脱模时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Doff_Mod_Time)

};
