// 逻辑类CIronLadle_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CIronLadle_Fire :
	public CL3Object
{
public:
	CIronLadle_Fire(void);
	virtual ~CIronLadle_Fire(void);

	DECLARE_L3CLASS(CIronLadle_Fire,XGMESLogic\\IronLadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Fire" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CIronLadle_Fire" name="IronLadleID" type="L3STRING">
	/// 铁包号
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Fire" name="TieID" type="L3STRING">
	/// 铁包打结编号
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Fire" name="Fire_Type" type="L3STRING">
	/// 烘烤类型
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CIronLadle_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CIronLadle_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CIronLadle_Fire" name="Fire_Length" type="L3LONG">
	/// 烘烤时长
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Length)

	/// <Property class="CIronLadle_Fire" name="Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Fire" name="NOTE" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(NOTE)

	/// <Property class="CIronLadle_Fire" name="TeamID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CIronLadle_Fire" name="ShiftID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	//2009-03-17
	/// <Property class="CIronLadle_Fire" name="FireID" type="L3LONG">
	/// 烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(FireID)

	/// <Property class="CIronLadle_Fire" name="Object_ID" type="L3STRING">
	/// 关键字[TieID + Fire_Type + FireID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
