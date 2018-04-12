// 逻辑类CBase_Wire_Coefficient头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Wire_Coefficient :
	public CL3Object
{
public:
	CBase_Wire_Coefficient(void);
	virtual ~CBase_Wire_Coefficient(void);

	DECLARE_L3CLASS(CBase_Wire_Coefficient,XGMESLogic\\BaseDataMag, WireCode)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Wire_Coefficient)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Wire_Coefficient" name="WireCode" type="L3STRING">
	/// 喂线代码
	/// </Property>
	DECLARE_L3PROP_STRING(WireCode)

	/// <Property class="CBase_Wire_Coefficient" name="Coefficient" type="L3FLOAT">
	/// 喂线系数
	/// </Property>
	DECLARE_L3PROP_FLOAT(Coefficient)

};
