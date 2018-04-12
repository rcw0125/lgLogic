// 逻辑类CQA_BOF_Std_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Base :
	public CL3Object
{
public:
	CQA_BOF_Std_Base(void);
	virtual ~CQA_BOF_Std_Base(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Base,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Base" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Base" name="Valid_Date" type="L3DATETIME">
	/// 生效日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Valid_Date)

	/// <Property class="CQA_BOF_Std_Base" name="New_Code" type="L3STRING">
	/// 新试号
	/// </Property>
	DECLARE_L3PROP_STRING(New_Code)

	/// <Property class="CQA_BOF_Std_Base" name="Note" type="L3STRING">
	/// 说明
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
