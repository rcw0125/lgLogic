// 逻辑类CQA_Heat_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Heat_Data :
	public CL3Object
{
public:
	CQA_Heat_Data(void);
	virtual ~CQA_Heat_Data(void);

	DECLARE_L3CLASS(CQA_Heat_Data,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Data" name="HeatID" type="L3STRING">
	/// 熔炼号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Data" name="Proc_Cnt" type="L3LONG">
	/// 处理次数
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Cnt)

	/// <Property class="CQA_Heat_Data" name="Unit_Type" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(Unit_Type)

	/// <Property class="CQA_Heat_Data" name="UnitID" type="L3STRING">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CQA_Heat_Data" name="Except_Code" type="L3STRING">
	/// 代码、
	/// </Property>
	DECLARE_L3PROP_STRING(Except_Code)

	/// <Property class="CQA_Heat_Data" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Heat_Data" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_Heat_Data" name="Heat_Lev" type="L3STRING">
	/// 炉次等级
	/// </Property>
	DECLARE_L3PROP_STRING(Heat_Lev)

	/// <Property class="CQA_Heat_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Data" name="Act_SteelGradeIndex" type="L3STRING">
	/// 实际炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Act_SteelGradeIndex)

	/// <Property class="CQA_Heat_Data" name="Data_Mod" type="L3LONG">
	/// 数据产生模式
	/// </Property>
	DECLARE_L3PROP_LONG(Data_Mod)

};
