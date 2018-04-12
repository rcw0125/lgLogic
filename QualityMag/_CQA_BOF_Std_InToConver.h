// 逻辑类CQA_BOF_Std_InToConver头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_InToConver :
	public CL3Object
{
public:
	CQA_BOF_Std_InToConver(void);
	virtual ~CQA_BOF_Std_InToConver(void);

	DECLARE_L3CLASS(CQA_BOF_Std_InToConver,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_InToConver)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_InToConver" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Temp_Min" type="L3LONG">
	/// 铁水温度最小
	/// </Property>
	DECLARE_L3PROP_LONG(Iron_Temp_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Temp_Max" type="L3LONG">
	/// 铁水温度最大
	/// </Property>
	DECLARE_L3PROP_LONG(Iron_Temp_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Weight_Max" type="L3DOUBLE">
	/// 铁水装入量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Weight_Min" type="L3DOUBLE">
	/// 铁水装入量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_S_Max" type="L3DOUBLE">
	/// 铁水硫含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_S_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_S_Min" type="L3DOUBLE">
	/// 铁水硫含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_S_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_P_Max" type="L3DOUBLE">
	/// 铁水P含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_P_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_P_Min" type="L3DOUBLE">
	/// 铁水P含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_P_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Si_Max" type="L3DOUBLE">
	/// 铁水SI含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Si_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Si_Min" type="L3DOUBLE">
	/// 铁水SI含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Si_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Ti_Min" type="L3DOUBLE">
	/// 铁水Ti含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Ti_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Ti_Max" type="L3DOUBLE">
	/// 铁水Ti含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Ti_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Type" type="L3STRING">
	/// 废钢区分
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Type)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Weight_Max" type="L3DOUBLE">
	/// 废钢装入最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Scrap_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Weight_Min" type="L3DOUBLE">
	/// 废钢装入最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Scrap_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="PigIron_Weight_Max" type="L3DOUBLE">
	/// 铁块装入最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PigIron_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="PigIron_Weight_Min" type="L3DOUBLE">
	/// 铁块装入最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PigIron_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Total_Weight_Min" type="L3DOUBLE">
	/// 总装入量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Total_Weight_Max" type="L3DOUBLE">
	/// 总装入量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight_Max)

};
