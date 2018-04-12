// 逻辑类CBulk_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBulk_Code :
	public CL3Object
{
public:
	CBulk_Code(void);
	virtual ~CBulk_Code(void);

	DECLARE_L3CLASS(CBulk_Code,XGMESLogic\\BulkStoreMag, Bulk_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_Code" name="Bulk_Code" type="L3STRING">
	/// 散状料代码
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Code" name="Bulk_Des" type="L3STRING">
	/// 散状料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Des)

	/// <Property class="CBulk_Code" name="Amount" type="L3DOUBLE">
	/// 材料量。
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)


};
