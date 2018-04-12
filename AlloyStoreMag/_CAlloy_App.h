// 逻辑类CAlloy_App头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAlloy_App :
	public CL3Object
{
public:
	CAlloy_App(void);
	virtual ~CAlloy_App(void);

	DECLARE_L3CLASS(CAlloy_App,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_App)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_App" name="Alloy_Code" type="L3STRING">
	/// 合金代码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_App" name="Amount" type="L3DOUBLE">
	/// 材料量。
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CAlloy_App" name="App_Time" type="L3DATETIME">
	/// 申请时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CAlloy_App" name="App_UnitID" type="L3STRING">
	/// 申请工序
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CAlloy_App" name="App_Operator" type="L3STRING">
	/// 申请人
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CAlloy_App" name="Confirm_Flag" type="L3STRING">
	/// 确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CAlloy_App" name="Confirm_Operator" type="L3STRING">
	/// 确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Operator)

	/// <Property class="CAlloy_App" name="Confirm_Time" type="L3DATETIME">
	/// 确认时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Confirm_Time)

};
