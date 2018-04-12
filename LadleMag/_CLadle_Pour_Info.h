// 逻辑类CLadle_Pour_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Pour_Info :
	public CL3Object
{
public:
	CLadle_Pour_Info(void);
	virtual ~CLadle_Pour_Info(void);

	DECLARE_L3CLASS(CLadle_Pour_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Pour_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Pour_Info" name="Input_Time" type="L3DATETIME">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Pour_Info" name="Steel_Grade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Pour_Info" name="Out_Ladle_ID" type="L3STRING">
	/// 倒出钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(Out_Ladle_ID)

	/// <Property class="CLadle_Pour_Info" name="In_Ladle_ID" type="L3STRING">
	/// 倒入钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(In_Ladle_ID)

	/// <Property class="CLadle_Pour_Info" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Pour_Info" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Pour_Info" name="Operator" type="L3STRING">
	/// 倒包确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Pour_Info" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
