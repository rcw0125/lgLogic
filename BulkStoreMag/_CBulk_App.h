// 逻辑类CBulk_App头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBulk_App :
	public CL3Object
{
public:
	CBulk_App(void);
	virtual ~CBulk_App(void);

	DECLARE_L3CLASS(CBulk_App,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_App)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_App" name="Bulk_Code" type="L3STRING">
	/// 合金代码
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_App" name="Amount" type="L3DOUBLE">
	/// 材料量。此属性对于钢卷等材料来说没有太大的实际意义，均为1；但对于类似液体、钢管、矿石等类型的材料来说，就有意义了。这类材料称为 批次材料。
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CBulk_App" name="App_Time" type="L3DATETIME">
	/// 接收时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CBulk_App" name="App_UnitID" type="L3STRING">
	/// 接收时间
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CBulk_App" name="App_Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CBulk_App" name="Confirm_Flag" type="L3LONG">
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CBulk_App" name="Confirm_Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Operator)

	/// <Property class="CBulk_App" name="Confirm_Time" type="L3DATETIME">
	/// 接收时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Confirm_Time)

};
