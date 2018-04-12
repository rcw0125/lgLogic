// 逻辑类CQA_BOF_Std_Slag_Ele头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Slag_Ele :
	public CL3Object
{
public:
	CQA_BOF_Std_Slag_Ele(void);
	virtual ~CQA_BOF_Std_Slag_Ele(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Slag_Ele,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Slag_Ele)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="CaO_Max" type="L3DOUBLE">
	/// 转炉炉渣CaO含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="CaO_Min" type="L3DOUBLE">
	/// 转炉炉渣CaO含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SiO2_Max" type="L3DOUBLE">
	/// 转炉炉渣SiO2含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SiO2_Min" type="L3DOUBLE">
	/// 转炉炉渣SiO2含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="MgO_Max" type="L3DOUBLE">
	/// 转炉炉渣SiO2含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="MgO_Min" type="L3DOUBLE">
	/// 转炉炉渣MgO含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="TFe_Max" type="L3DOUBLE">
	/// 转炉炉渣TFe含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TFe_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="TFe_Min" type="L3DOUBLE">
	/// 转炉炉渣TFe含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TFe_Min)

};
