// 逻辑类CQA_Heat_Except_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Heat_Except_Code :
	public CL3Object
{
public:
	CQA_Heat_Except_Code(void);
	virtual ~CQA_Heat_Except_Code(void);

	DECLARE_L3CLASS(CQA_Heat_Except_Code,XGMESLogic\\QualityMag, Exceptional_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Except_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Except_Code" name="Exceptional_Code" type="L3STRING">
	/// 代码、
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Except_Code" name="Exceptional_Des" type="L3STRING">
	/// 内容、
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Des)

	/// <Property class="CQA_Heat_Except_Code" name="Unit" type="L3STRING">
	/// 发生工序
	/// </Property>
	DECLARE_L3PROP_STRING(Unit)

	/// <Property class="CQA_Heat_Except_Code" name="Auto_Judge_Flag" type="L3SHORT">
	/// 自动判定标志、
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Judge_Flag)

};
