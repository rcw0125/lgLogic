// 逻辑类CQA_Heat_Except_Code_R头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Heat_Except_Code_R :
	public CL3Object
{
public:
	CQA_Heat_Except_Code_R(void);
	virtual ~CQA_Heat_Except_Code_R(void);

	DECLARE_L3CLASS(CQA_Heat_Except_Code_R,XGMESLogic\\QualityMag, Exceptional_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Except_Code_R)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Except_Code_R" name="Exceptional_Code" type="L3STRING">
	/// 异常代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Except_Code_R" name="Exceptional_Group_Code" type="L3STRING">
	/// 异常钢组代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Group_Code)

	/// <Property class="CQA_Heat_Except_Code_R" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

};
