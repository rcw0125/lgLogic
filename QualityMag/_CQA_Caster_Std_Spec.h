// 逻辑类CQA_Caster_Std_Spec头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Caster_Std_Spec :
	public CL3Object
{
public:
	CQA_Caster_Std_Spec(void);
	virtual ~CQA_Caster_Std_Spec(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Spec,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Spec)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Spec" name="CasterID" type="L3STRING">
	/// 连铸机号(PK1)、
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Caster_Std_Spec" name="Spec_Seq" type="L3LONG">
	/// 规格序号(PK2)、
	/// </Property>
	DECLARE_L3PROP_LONG(Spec_Seq)

	/// <Property class="CQA_Caster_Std_Spec" name="Width_Min" type="L3LONG">
	/// 宽度最小值、
	/// </Property>
	DECLARE_L3PROP_LONG(Width_Min)

	/// <Property class="CQA_Caster_Std_Spec" name="Width_Max" type="L3LONG">
	/// 宽度最大值、
	/// </Property>
	DECLARE_L3PROP_LONG(Width_Max)

	/// <Property class="CQA_Caster_Std_Spec" name="Thickness_Min" type="L3LONG">
	/// 厚度最小值、
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness_Min)

	/// <Property class="CQA_Caster_Std_Spec" name="Thickness_Max" type="L3LONG">
	/// 厚度最大值、
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness_Max)

	/// <Property class="CQA_Caster_Std_Spec" name="Length_Min" type="L3LONG">
	/// 长度最小值
	/// </Property>
	DECLARE_L3PROP_LONG(Length_Min)

	/// <Property class="CQA_Caster_Std_Spec" name="Length_Max" type="L3LONG">
	/// 长度最大值
	/// </Property>
	DECLARE_L3PROP_LONG(Length_Max)

};
