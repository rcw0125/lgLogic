// 逻辑类CLadle_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Fire :
	public CL3Object
{
public:
	CLadle_Fire(void);
	virtual ~CLadle_Fire(void);

	DECLARE_L3CLASS(CLadle_Fire,XGMESLogic\\LadleMag, FireID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Fire" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Fire" name="Fire_Type" type="L3STRING">
	/// 烘烤类别
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CLadle_Fire" name="Roaster_ID" type="L3STRING">
	/// 烘烤器台号
	/// </Property>
	DECLARE_L3PROP_STRING(Roaster_ID)

	/// <Property class="CLadle_Fire" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Fire" name="Start_Time" type="L3DATETIME">
	/// 开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CLadle_Fire" name="Start_Operator" type="L3STRING">
	/// 开始操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Start_Operator)

	/// <Property class="CLadle_Fire" name="Set_One_Time" type="L3DATETIME">
	/// 调一时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_One_Time)

	/// <Property class="CLadle_Fire" name="Set_One_Operator" type="L3STRING">
	/// 调一操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Set_One_Operator)

	/// <Property class="CLadle_Fire" name="Set_Two_Time" type="L3DATETIME">
	/// 调二时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Two_Time)

	/// <Property class="CLadle_Fire" name="Set_Two_Operator" type="L3STRING">
	/// 调二操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Two_Operator)

	/// <Property class="CLadle_Fire" name="Set_Three_Time" type="L3DATETIME">
	/// 调三时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Three_Time)

	/// <Property class="CLadle_Fire" name="Set_Three_Operator" type="L3STRING">
	/// 调三操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Three_Operator)

	/// <Property class="CLadle_Fire" name="Set_Four_Time" type="L3DATETIME">
	/// 调四时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Four_Time)

	/// <Property class="CLadle_Fire" name="Set_Four_Operator" type="L3STRING">
	/// 调四操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Four_Operator)

	/// <Property class="CLadle_Fire" name="End_Time" type="L3DATETIME">
	/// 结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CLadle_Fire" name="End_Operator" type="L3STRING">
	/// 结束操作员
	/// </Property>
	DECLARE_L3PROP_STRING(End_Operator)

	/// <Property class="CLadle_Fire" name="Suspend_Time" type="L3DATETIME">
	/// 吊包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Suspend_Time)

	/// <Property class="CLadle_Fire" name="Suspend_Operator" type="L3STRING">
	/// 吊包操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Suspend_Operator)

	/// <Property class="CLadle_Fire" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Fire" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Fire" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Fire" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Fire" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Fire" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Fire" name="FireNote" type="L3STRING">
	/// 烘烤备注
	/// </Property>
	DECLARE_L3PROP_STRING(FireNote)

	/// <Property class="CLadle_Fire" name="FireID" type="L3STRING">
	/// 烘烤编号[WorkID + Fire_Type + 序号]
	/// </Property>
	DECLARE_L3PROP_STRING(FireID)

};
