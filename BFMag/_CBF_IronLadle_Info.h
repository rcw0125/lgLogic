// 逻辑类CBF_IronLadle_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBF_IronLadle_Info :
	public CL3Object
{
public:
	CBF_IronLadle_Info(void);
	virtual ~CBF_IronLadle_Info(void);

	DECLARE_L3CLASS(CBF_IronLadle_Info,XGMESLogic\\BFMag, IDObject)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_IronLadle_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBF_IronLadle_Info" name="IDObject" type="L3STRING">
	/// 对象ID=分组号+组内顺序号
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CBF_IronLadle_Info" name="TPC_No" type="L3STRING">
	/// 罐号
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CBF_IronLadle_Info" name="GroupNo" type="L3STRING">
	/// 分组号
	/// </Property>
	DECLARE_L3PROP_STRING(GroupNo)

	/// <Property class="CBF_IronLadle_Info" name="OrderNo" type="L3LONG">
	/// 组内顺序号
	/// </Property>
	DECLARE_L3PROP_LONG(Order_No)

	/// <Property class="CBF_IronLadle_Info" name="ModifyTime" type="L3DATETIME">
	/// 变更时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(ModifyTime)

	/// <Property class="CBF_IronLadle_Info" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};
