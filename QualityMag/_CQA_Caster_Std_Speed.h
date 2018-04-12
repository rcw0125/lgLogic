// 逻辑类CQA_Caster_Std_Speed头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Caster_Std_Speed :
	public CL3Object
{
public:
	CQA_Caster_Std_Speed(void);
	virtual ~CQA_Caster_Std_Speed(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Speed,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Speed)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Speed" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Fir_Min" type="L3DOUBLE">
	/// 拉速最小（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Fir_Min)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Fir_Max" type="L3DOUBLE">
	/// 拉速最大（连铸第一炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Fir_Max)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Min" type="L3DOUBLE">
	/// 拉速最小（连浇炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Min)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Max" type="L3DOUBLE">
	/// 拉速最大（连浇炉）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Max)

};
