// 逻辑类CQA_LF_Std_Proc头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_LF_Std_Proc :
	public CL3Object
{
public:
	CQA_LF_Std_Proc(void);
	virtual ~CQA_LF_Std_Proc(void);

	DECLARE_L3CLASS(CQA_LF_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Aim" type="L3LONG">
	/// 目标LF离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Aim)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Min" type="L3LONG">
	/// 最小LF离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Min)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Max" type="L3LONG">
	/// 最大LF离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Aim" type="L3LONG">
	/// 目标LF离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Aim)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Min" type="L3LONG">
	/// 最小LF离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Max" type="L3LONG">
	/// 最大LF离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Sample_Flag" type="L3LONG">
	/// 到站取样
	/// </Property>
	DECLARE_L3PROP_LONG(Sample_Flag)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Blow_Time_Min" type="L3LONG">
	/// 最小软吹时间
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Blow_Time_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Time_Min" type="L3LONG">
	/// 加热时间最小
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Time_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Time_Max" type="L3LONG">
	/// 加热时间最大
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Ar_Min" type="L3DOUBLE">
	/// 加热吹氩气量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hot_Ar_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Ar_Max" type="L3DOUBLE">
	/// 加热吹氩气量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hot_Ar_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Ar_Min" type="L3DOUBLE">
	/// 软吹吹氩气量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Soft_Ar_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Ar_Max" type="L3DOUBLE">
	/// 软吹吹氩气量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Soft_Ar_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// 进站压钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// 进站等钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Refine_Time_Max" type="L3DOUBLE">
	/// 精炼时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Refine_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Refine_Time_Min" type="L3DOUBLE">
	/// 精炼时间最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Refine_Time_Min)

};
