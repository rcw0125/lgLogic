// 逻辑类CQA_LF_Std_Ladle头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_LF_Std_Ladle :
	public CL3Object
{
public:
	CQA_LF_Std_Ladle(void);
	virtual ~CQA_LF_Std_Ladle(void);

	DECLARE_L3CLASS(CQA_LF_Std_Ladle,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Ladle)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Ladle" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Name" type="L3STRING">
	/// 钢包物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Mat_Name)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Min" type="L3DOUBLE">
	/// 钢包物料数量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Min)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Max" type="L3DOUBLE">
	/// 钢包物料数量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Max)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Aim" type="L3DOUBLE">
	/// 钢包物料数量目标
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Aim)

};
