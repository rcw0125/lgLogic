// 逻辑类CDisp_Duty_Note头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_Duty_Note :
	public CL3Object
{
public:
	CDisp_Duty_Note(void);
	virtual ~CDisp_Duty_Note(void);

	DECLARE_L3CLASS(CDisp_Duty_Note,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Duty_Note)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_Duty_Note" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CDisp_Duty_Note" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CDisp_Duty_Note" name="CreateDate" type="L3DATETIME">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)

	/// <Property class="CDisp_Duty_Note" name="Note" type="L3STRING">
	/// 记事
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
