// 逻辑类CQA_BOF_Std_Blow头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Blow :
	public CL3Object
{
public:
	CQA_BOF_Std_Blow(void);
	virtual ~CQA_BOF_Std_Blow(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Blow,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Blow)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Blow" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Blow" name="ReBlow_Cnt_Max" type="L3SHORT">
	/// 补吹次数最大
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Cnt_Max)

	/// <Property class="CQA_BOF_Std_Blow" name="Catch_C_Temp_Min" type="L3LONG">
	/// 拉碳温度最小
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_C_Temp_Min)

	/// <Property class="CQA_BOF_Std_Blow" name="ReBlow_Time_Max" type="L3SHORT">
	/// 补吹时间最大
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Time_Max)

	/// <Property class="CQA_BOF_Std_Blow" name="Bottom_Blow_Base" type="L3STRING">
	/// 底吹基准
	/// </Property>
	DECLARE_L3PROP_STRING(Bottom_Blow_Base)

};
