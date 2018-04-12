// 逻辑类CQA_Caster_Std_Flux头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Caster_Std_Flux :
	public CL3Object
{
public:
	CQA_Caster_Std_Flux(void);
	virtual ~CQA_Caster_Std_Flux(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Flux,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Flux)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Flux" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Flux" name="Tundish_Flux_Name" type="L3STRING">
	/// 中包覆盖剂名称、
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Flux_Name)

	/// <Property class="CQA_Caster_Std_Flux" name="Tundish_Flux_Weight" type="L3DOUBLE">
	/// 中包覆盖剂加入量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tundish_Flux_Weight)

};
