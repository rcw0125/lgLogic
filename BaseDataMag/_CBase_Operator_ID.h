// 逻辑类CBase_Operator_ID头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Operator_ID :
	public CL3Object
{
public:
	CBase_Operator_ID(void);
	virtual ~CBase_Operator_ID(void);

	DECLARE_L3CLASS(CBase_Operator_ID,XGMESLogic\\BaseDataMag, Operator)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Operator_ID)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Operator_ID" name="Operator" type="L3STRING">
	/// 员工号
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBase_Operator_ID" name="Operator_Name" type="L3STRING">
	/// 员工姓名
	/// </Property>
	DECLARE_L3PROP_STRING(Operator_Name)

};
