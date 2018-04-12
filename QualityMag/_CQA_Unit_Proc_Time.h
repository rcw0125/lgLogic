// 逻辑类CQA_Unit_Proc_Time头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Unit_Proc_Time :
	public CL3Object
{
public:
	CQA_Unit_Proc_Time(void);
	virtual ~CQA_Unit_Proc_Time(void);

	DECLARE_L3CLASS(CQA_Unit_Proc_Time,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Proc_Time)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Proc_Time" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Unit_Proc_Time" name="BOF_Proc_Time" type="L3LONG">
	/// 转炉作业时间、
	/// </Property>
	DECLARE_L3PROP_LONG(BOF_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="LF_Proc_Time" type="L3LONG">
	/// LF炉作业时间、
	/// </Property>
	DECLARE_L3PROP_LONG(LF_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="RH_Proc_Time" type="L3LONG">
	/// RH炉作业时间、
	/// </Property>
	DECLARE_L3PROP_LONG(RH_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="Caster_Proc_Time" type="L3LONG">
	/// 铸机作业时间、
	/// </Property>
	DECLARE_L3PROP_LONG(Caster_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="Tapped_Proc_Time" type="L3LONG">
	/// 炉后作业时间、
	/// </Property>
	DECLARE_L3PROP_LONG(Tapped_Proc_Time)

};
