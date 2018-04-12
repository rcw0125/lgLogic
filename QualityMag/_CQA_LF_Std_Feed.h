// 逻辑类CQA_LF_Std_Feed头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_LF_Std_Feed :
	public CL3Object
{
public:
	CQA_LF_Std_Feed(void);
	virtual ~CQA_LF_Std_Feed(void);

	DECLARE_L3CLASS(CQA_LF_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Feed" name="C_Absorption_Rate" type="L3DOUBLE">
	/// 碳线中碳吸收率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C_Absorption_Rate)

	/// <Property class="CQA_LF_Std_Feed" name="Al_Absorption_Rate" type="L3DOUBLE">
	/// 铝线中铝吸收率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Absorption_Rate)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1" type="L3STRING">
	/// Ca处理喂丝线1
	/// </Property>
	DECLARE_L3PROP_STRING(CaProc_Code1)

	/// <Property class="CQA_LF_Std_Feed" name="CaProcFir_Code1_Weight_Max" type="L3DOUBLE">
	/// Ca处理喂线1喂入量最大（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProcFir_Code1_Weight_Max)

	/// <Property class="CQA_LF_Std_Feed" name="CaProcFir_Code1_Weight_Min" type="L3DOUBLE">
	/// Ca处理喂线1喂入量最小（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProcFir_Code1_Weight_Min)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1_Weight_Max" type="L3DOUBLE">
	/// Ca处理喂线1喂入量最大（连浇炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code1_Weight_Max)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1_Weight_Min" type="L3DOUBLE">
	/// Ca处理喂线1喂入量最小（连浇炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code1_Weight_Min)

	/// <Property class="CQA_LF_Std_Feed" name="Oxy_Flag" type="L3SHORT">
	/// 定氧否
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

};
