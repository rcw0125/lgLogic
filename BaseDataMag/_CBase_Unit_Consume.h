// 逻辑类CBase_Unit_Consume头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Unit_Consume :
	public CL3Object
{
public:
	CBase_Unit_Consume(void);
	virtual ~CBase_Unit_Consume(void);

	DECLARE_L3CLASS(CBase_Unit_Consume,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Unit_Consume)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Unit_Consume" name="SteelType" type="L3STRING">
	/// 产品类别
	/// </Property>
	DECLARE_L3PROP_STRING(SteelType)

	/// <Property class="CBase_Unit_Consume" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CBase_Unit_Price" name="Ele_Code" type="L3STRING">
	/// 代码
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Code)

	/// <Property class="CBase_Unit_Price" name="Ele_Des" type="L3STRING">
	/// 代码描述
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Des)

	/// <Property class="CBase_Unit_Consume" name="Unit_Consume" type="L3FLOAT">
	/// 单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(Unit_Consume)

};
