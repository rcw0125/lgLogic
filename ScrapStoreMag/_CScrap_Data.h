// 逻辑类CScrap_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CScrap_Data :
	public Material
{
public:
	CScrap_Data(void);
	virtual ~CScrap_Data(void);

	DECLARE_L3CLASS(CScrap_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrap_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_Code" name="Amount" type="L3DOUBLE">
	/// 材料量。
	/// </Property>
	/// <Property class="CScrap_Data" name="Amount" type="L3DOUBLE">
	/// 废钢总量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

};
