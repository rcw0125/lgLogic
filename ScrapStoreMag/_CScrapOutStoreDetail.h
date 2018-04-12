// 逻辑类CScrapOutStoreDetail头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CScrapOutStoreDetail :
	public CL3Object
{
public:
	CScrapOutStoreDetail(void);
	virtual ~CScrapOutStoreDetail(void);

	DECLARE_L3CLASS(CScrapOutStoreDetail,XGMESLogic\\ScrapStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrapOutStoreDetail)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CScrapOutStoreDetail" name="SCRAP_SLOT_ID" type="L3STRING">
	/// 废钢斗ID
	/// </Property>
	DECLARE_L3PROP_STRING(SCRAP_SLOT_ID)

	/// <Property class="CScrapOutStoreDetail" name="MATERIAL" type="L3STRING">
	/// 材料类型
	/// </Property>
	DECLARE_L3PROP_STRING(MATERIAL)

	/// <Property class="CScrapOutStoreDetail" name="MATERIAL_CODE" type="L3STRING">
	/// 材料代码
	/// </Property>
	DECLARE_L3PROP_STRING(MATERIAL_CODE)

	/// <Property class="CScrapOutStoreDetail" name="AMOUNT" type="L3STRING">
	/// 重量
	/// </Property>
	DECLARE_L3PROP_STRING(AMOUNT)

};
