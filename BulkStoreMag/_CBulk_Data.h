// 逻辑类CBulk_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CBulk_Data :
	public Material
{
public:
	CBulk_Data(void);
	virtual ~CBulk_Data(void);

	DECLARE_L3CLASS(CBulk_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_Data" name="Bulk_Destination" type="L3STRING">
	/// 散状料去向
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Destination)

	/// <Property class="CBulk_Data" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Data" name="Bulk_Code" type="L3STRING">
	/// 散状料编码
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Data" name="Amount" type="L3DOUBLE">
	/// 材料量。
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

};
