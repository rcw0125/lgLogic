// 逻辑类CQA_Element_Std头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Element_Std :
	public CL3Object
{
public:
	CQA_Element_Std(void);
	virtual ~CQA_Element_Std(void);

	DECLARE_L3CLASS(CQA_Element_Std,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Element_Std)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	//add by hyh 2012-04-10
	//新增表用于钢种成分报警显示
	//


	/// <Property class="CQA_Element_Std" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Element_Std" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Element_Std" name="C_Max" type="L3STRING">
	/// C上限
	/// </Property>
	DECLARE_L3PROP_STRING(C_Max)

	/// <Property class="CQA_Element_Std" name="C_Min" type="L3STRING">
	/// C下限
	/// </Property>
	DECLARE_L3PROP_STRING(C_Min)

	/// <Property class="CQA_Element_Std" name="Si_Max" type="L3STRING">
	/// Si上限
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Max)

	/// <Property class="CQA_Element_Std" name="Si_Min" type="L3STRING">
	/// Si下限
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Min)

	/// <Property class="CQA_Element_Std" name="Mn_Max" type="L3STRING">
	/// Mn上限
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Max)

	/// <Property class="CQA_Element_Std" name="Mn_Min" type="L3STRING">
	/// Mn下限
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Min)

	/// <Property class="CQA_Element_Std" name="P_Max" type="L3STRING">
	/// P上限
	/// </Property>
	DECLARE_L3PROP_STRING(P_Max)

	/// <Property class="CQA_Element_Std" name="P_Min" type="L3STRING">
	/// P下限
	/// </Property>
	DECLARE_L3PROP_STRING(P_Min)

	/// <Property class="CQA_Element_Std" name="S_Max" type="L3STRING">
	/// S上限
	/// </Property>
	DECLARE_L3PROP_STRING(S_Max)

	/// <Property class="CQA_Element_Std" name="S_Min" type="L3STRING">
	/// S下限
	/// </Property>
	DECLARE_L3PROP_STRING(S_Min)

	/// <Property class="CQA_Element_Std" name="Ti_Max" type="L3STRING">
	/// Ti上限
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Max)

	/// <Property class="CQA_Element_Std" name="Ti_Min" type="L3STRING">
	/// Ti下限
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Min)

	/// <Property class="CQA_Element_Std" name="Sn_Max" type="L3STRING">
	/// Sn上限
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Max)

	/// <Property class="CQA_Element_Std" name="Sn_Min" type="L3STRING">
	/// Sn下限
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Min)

	/// <Property class="CQA_Element_Std" name="Sb_Max" type="L3STRING">
	/// Sb上限
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Max)

	/// <Property class="CQA_Element_Std" name="Sb_Min" type="L3STRING">
	/// Sb下限
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Min)

	/// <Property class="CQA_Element_Std" name="As_Max" type="L3STRING">
	/// As上限
	/// </Property>
	DECLARE_L3PROP_STRING(As_Max)

	/// <Property class="CQA_Element_Std" name="As_Min" type="L3STRING">
	/// As下限
	/// </Property>
	DECLARE_L3PROP_STRING(As_Min)

	/// <Property class="CQA_Element_Std" name="Pb_Max" type="L3STRING">
	/// Pb上限
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Max)

	/// <Property class="CQA_Element_Std" name="Pb_Min" type="L3STRING">
	/// Pb下限
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Min)

};
