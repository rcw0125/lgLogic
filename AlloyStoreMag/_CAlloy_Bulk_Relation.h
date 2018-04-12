// 逻辑类CAlloy_Bulk_Relation头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAlloy_Bulk_Relation :
	public CL3Object
{
public:
	CAlloy_Bulk_Relation(void);
	virtual ~CAlloy_Bulk_Relation(void);

	DECLARE_L3CLASS(CAlloy_Bulk_Relation,XGMESLogic\\AlloyStoreMag, Alloy_Area)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Bulk_Relation)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Area" type="L3STRING">
	/// 合金料仓编码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Area)

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Code" type="L3STRING">
	/// 合金编码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Bulk_Relation" name="TopSlagFlag" type="L3LONG">
	/// 顶渣标志
	/// </Property>
	DECLARE_L3PROP_LONG(TopSlagFlag)

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Vendor" type="L3STRING">
	/// 厂家
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Alloy_Vendor)
};
