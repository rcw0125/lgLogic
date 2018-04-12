// 逻辑类CDeS_Lance_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Lance_Log :
	public CL3Object
{
public:
	CDeS_Lance_Log(void);
	virtual ~CDeS_Lance_Log(void);

	DECLARE_L3CLASS(CDeS_Lance_Log,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Lance_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();
	/// <Property class="CDeS_Lance_Log" name="LanceNo" type="L3STRING">
	/// 喷枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Lance_Log" name="Status" type="L3LONG">
	/// 喷枪状态
	/// 备用
	/// 在线
	/// 待修
	/// 下线
	/// 废弃
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CDeS_Lance_Log" name="LanceAge" type="L3LONG">
	/// 喷枪枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Lance_Log" name="LanceVendor" type="L3STRING">
	/// 喷枪厂家
	/// </Property>
	DECLARE_L3PROP_STRING(LanceVendor)

	/// <Property class="CDeS_Lance_Log" name="ProcessTime" type="L3LONG">
	/// 作业时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Lance_Log" name="ProcessAmount" type="L3DOUBLE">
	/// 脱硫量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ProcessAmount)

	/// <Property class="CDeS_Lance_Log" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Lance_Log" name="Action" type="L3STRING">
	/// 操作说明
	/// </Property>
	DECLARE_L3PROP_STRING(Action)

	/// <Property class="CDeS_Lance_Log" name="Time_Change" type="L3DATETIME">
	/// 更换时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Change)

	/// <Property class="CDeS_Lance_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CDeS_Lance_Log" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Lance_Log" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)
};
