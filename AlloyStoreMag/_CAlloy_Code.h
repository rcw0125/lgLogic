// 逻辑类CAlloy_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAlloy_Code :
	public CL3Object
{
public:
	CAlloy_Code(void);
	virtual ~CAlloy_Code(void);

	DECLARE_L3CLASS(CAlloy_Code,XGMESLogic\\AlloyStoreMag, Alloy_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Code" name="Alloy_Code" type="L3STRING">
	/// 合金代码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Code" name="Alloy_Des" type="L3STRING">
	/// 合金名称
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Des)


};
