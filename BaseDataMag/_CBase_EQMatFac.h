// 逻辑类CBase_EQMatFac头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_EQMatFac :
	public CL3Object
{
public:
	CBase_EQMatFac(void);
	virtual ~CBase_EQMatFac(void);

	DECLARE_L3CLASS(CBase_EQMatFac,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_EQMatFac)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_EQMatFac" name="MatFactory" type="L3STRING">
	/// 材料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(MatFactory)

	/// <Property class="CBase_EQMatFac" name="MatName" type="L3STRING">
	/// 材料名称
	/// </Property>
	DECLARE_L3PROP_STRING(MatName)

	/// <Property class="CBase_EQMatFac" name="MatGroup_Code" type="L3STRING">
	/// 材料组
	/// </Property>
	DECLARE_L3PROP_STRING(MatGroup_Code)

	/// <Property class="CBase_EQMatFac" name="MatGroup_Des" type="L3STRING">
	/// 材料组描述
	/// </Property>
	DECLARE_L3PROP_STRING(MatGroup_Des)

};
