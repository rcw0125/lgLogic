// 逻辑类CQA_LF_Std_Alloy头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_LF_Std_Alloy :
	public CL3Object
{
public:
	CQA_LF_Std_Alloy(void);
	virtual ~CQA_LF_Std_Alloy(void);

	DECLARE_L3CLASS(CQA_LF_Std_Alloy,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Alloy)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Alloy" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Flag" type="L3LONG">
	/// 合金化否
	/// </Property>
	DECLARE_L3PROP_LONG(Alloy_Flag)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Code" type="L3STRING">
	/// 合金牌号
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Yield" type="L3DOUBLE">
	/// 合金收得率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Alloy_Yield)

};
