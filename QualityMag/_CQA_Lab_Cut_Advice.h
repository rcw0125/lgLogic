// 逻辑类CQA_Lab_Cut_Advice头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_Cut_Advice :
	public CL3Object
{
public:
	CQA_Lab_Cut_Advice(void);
	virtual ~CQA_Lab_Cut_Advice(void);

	DECLARE_L3CLASS(CQA_Lab_Cut_Advice,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Cut_Advice)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_Cut_Advice" name="HeatID" type="L3STRING">
	/// Sample_Code
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_Cut_Advice" name="SteelGradeIndex" type="L3STRING">
	///炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)


	/// <Property class="CQA_Lab_Cut_Advice" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Lab_Cut_Advice" name="Protocol" type="L3STRING">
	/// 协议
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)


	/// <Property class="CQA_Lab_Cut_Advice" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Count" type="L3LONG">
	/// 割样数量
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Count)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Position" type="L3STRING">
	/// 割样位置
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Position)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Dimen" type="L3STRING">
	/// 割样尺寸
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Dimen)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Mark" type="L3STRING">
	/// 割样标识
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Mark)

	/// <Property class="CQA_Lab_Cut_Advice" name="Log_Time" type="L3DATETIME">
	/// 通知时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};
