// 逻辑类CQA_Decide_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Decide_Code :
	public CL3Object
{
public:
	CQA_Decide_Code(void);
	virtual ~CQA_Decide_Code(void);

	DECLARE_L3CLASS(CQA_Decide_Code,XGMESLogic\\QualityMag, Decide_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Decide_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Decide_Code" name="Decide_Code" type="L3STRING">
	/// 代码、
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Decide_Code" name="Decide_Des" type="L3STRING">
	/// 内容、
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Des)

	/// <Property class="CQA_Decide_Code" name="Classify" type="L3SHORT">
	/// 优先级
	/// </Property>
	DECLARE_L3PROP_LONG(Classify)

};
