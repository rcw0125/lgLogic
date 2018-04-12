// 逻辑类CQA_BOF_Std_Tapping头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Tapping :
	public CL3Object
{
public:
	CQA_BOF_Std_Tapping(void);
	virtual ~CQA_BOF_Std_Tapping(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Tapping,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Tapping)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Tapping" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Tapping" name="Tapping_Temp_Min" type="L3LONG">
	/// 出钢温度最小
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Temp_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="Tapping_Time_Min" type="L3LONG">
	/// 出钢时间最小
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Time_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_O2_UpLimit" type="L3DOUBLE">
	/// 终点氧含量上限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_O2_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_C_UpLimit" type="L3DOUBLE">
	/// 终点成份C上限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_C_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_C_LowLimit" type="L3DOUBLE">
	/// 终点成份C下限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_C_LowLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_S_UpLimit" type="L3DOUBLE">
	/// 终点成份S上限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_S_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_P_UpLimit" type="L3DOUBLE">
	/// 终点成份P上限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_P_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_Mn_UpLimit" type="L3DOUBLE">
	/// 终点成份Mn上限
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_Mn_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Press_Max" type="L3LONG">
	/// 出钢过程吹氩压力最大
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Max)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Press_Min" type="L3LONG">
	/// 出钢过程吹氩压力最小
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Blow_Max" type="L3DOUBLE">
	/// 出钢过程吹氩气量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Max)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Blow_Min" type="L3DOUBLE">
	/// 出钢过程吹氩气量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Min)

};
