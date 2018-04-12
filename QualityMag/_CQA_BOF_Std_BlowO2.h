// 逻辑类CQA_BOF_Std_BlowO2头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_BlowO2 :
	public CL3Object
{
public:
	CQA_BOF_Std_BlowO2(void);
	virtual ~CQA_BOF_Std_BlowO2(void);

	DECLARE_L3CLASS(CQA_BOF_Std_BlowO2,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_BlowO2)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_BlowO2" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_BlowO2" name="Total_O2_Press_Ctr" type="L3STRING">
	/// 总管氧压控制基准
	/// </Property>
	DECLARE_L3PROP_STRING(Total_O2_Press_Ctr)

	/// <Property class="CQA_BOF_Std_BlowO2" name="Work_O2_Press_Ctr" type="L3STRING">
	/// 工作氧压控制基准
	/// </Property>
	DECLARE_L3PROP_STRING(Work_O2_Press_Ctr)

	/// <Property class="CQA_BOF_Std_BlowO2" name="O2_Blow_Ctr" type="L3STRING">
	/// 氧气流量控制基准
	/// </Property>
	DECLARE_L3PROP_STRING(O2_Blow_Ctr)

};
