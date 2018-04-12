// 逻辑类CQA_BOF_Std_Ar头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Ar :
	public CL3Object
{
public:
	CQA_BOF_Std_Ar(void);
	virtual ~CQA_BOF_Std_Ar(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Ar,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Ar)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Ar" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Max" type="L3LONG">
	/// 氩前钢水温度最大（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Min" type="L3LONG">
	/// 氩前钢水温度最小（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Aim" type="L3LONG">
	/// 氩前钢水温度目标（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Max" type="L3LONG">
	/// 氩前钢水温度最大（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Min" type="L3LONG">
	/// 氩前钢水温度最小（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Aim" type="L3LONG">
	/// 氩前钢水温度目标（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Max" type="L3LONG">
	/// 氩后钢水温度最大（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Min" type="L3LONG">
	/// 氩后钢水温度最小（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Aim" type="L3LONG">
	/// 氩后钢水温度目标（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Max" type="L3LONG">
	/// 氩后钢水温度最大（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Min" type="L3LONG">
	/// 氩后钢水温度最小（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Aim" type="L3LONG">
	/// 氩后钢水温度目标（连浇炉）
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="Oxy_Flag" type="L3LONG">
	/// 炉后定氧否
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_Oxy_Max" type="L3DOUBLE">
	/// 氩前定氧氧含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PreAr_Oxy_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_Oxy_Min" type="L3DOUBLE">
	/// 氩前定氧氧含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PreAr_Oxy_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Time_UpLimit" type="L3LONG">
	/// 炉后吹氩时间上限
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Time_UpLimit)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Time_LowLimit" type="L3LONG">
	/// 炉后吹氩时间下限
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Time_LowLimit)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Press_Max" type="L3LONG">
	/// 炉后吹氩压力最大
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Press_Min" type="L3LONG">
	/// 炉后吹氩压力最小
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Blow_Max" type="L3DOUBLE">
	/// 炉后吹氩流量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Blow_Min" type="L3DOUBLE">
	/// 炉后吹氩流量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_Oxy_Max" type="L3DOUBLE">
	/// 氩后定氧氧含量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BeAr_Oxy_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_Oxy_Min" type="L3DOUBLE">
	/// 氩后定氧氧含量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BeAr_Oxy_Min)

};
