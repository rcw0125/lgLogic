// 逻辑类CQA_LF_Std_Slag_Ele头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_LF_Std_Slag_Ele :
	public CL3Object
{
public:
	CQA_LF_Std_Slag_Ele(void);
	virtual ~CQA_LF_Std_Slag_Ele(void);

	DECLARE_L3CLASS(CQA_LF_Std_Slag_Ele,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Slag_Ele)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="CaO_Max" type="L3DOUBLE">
	/// 精炼渣CaO最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="CaO_Min" type="L3DOUBLE">
	/// 精炼渣CaO最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SiO2_Max" type="L3DOUBLE">
	/// 精炼渣SiO2最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SiO2_Min" type="L3DOUBLE">
	/// 精炼渣SiO2最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MgO_Max" type="L3DOUBLE">
	/// 精炼渣MgO最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MgO_Min" type="L3DOUBLE">
	/// 精炼渣MgO最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="Al2O3_Max" type="L3DOUBLE">
	/// 精炼渣Al2O3最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al2O3_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="Al2O3_Min" type="L3DOUBLE">
	/// 精炼渣Al2O3最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al2O3_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="S_Max" type="L3DOUBLE">
	/// 精炼渣S最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="S_Min" type="L3DOUBLE">
	/// 精炼渣S最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="P_Max" type="L3DOUBLE">
	/// 精炼渣P最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="P_Min" type="L3DOUBLE">
	/// 精炼渣P最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MnO_Max" type="L3DOUBLE">
	/// 精炼渣MnO最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MnO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MnO_Min" type="L3DOUBLE">
	/// 精炼渣MnO最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MnO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="TiO2_Max" type="L3DOUBLE">
	/// 精炼渣TiO2最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TiO2_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="TiO2_Min" type="L3DOUBLE">
	/// 精炼渣TiO2最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TiO2_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="FeO_Max" type="L3DOUBLE">
	/// 精炼渣FeO最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(FeO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="FeO_Min" type="L3DOUBLE">
	/// 精炼渣FeO最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(FeO_Min)

};
