// 逻辑类CQA_Heat_Prod_Except头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Heat_Prod_Except :
	public CL3Object
{
public:
	CQA_Heat_Prod_Except(void);
	virtual ~CQA_Heat_Prod_Except(void);

	DECLARE_L3CLASS(CQA_Heat_Prod_Except,XGMESLogic\\QualityMag, ID_Object)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Prod_Except)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Prod_Except" name="ID_Object" type="L3STRING">
	/// 身份标识
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CQA_Heat_Prod_Except" name="HeatID" type="L3STRING">
	/// 熔炼号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Prod_Except" name="Process_Count" type="L3LONG">
	/// 处理次数
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Count)

	/// <Property class="CQA_Heat_Prod_Except" name="UnitTypeID" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(UnitTypeID)

	/// <Property class="CQA_Heat_Prod_Except" name="UnitID" type="L3STRING">
	/// 工位ID
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CQA_Heat_Prod_Except" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_Heat_Prod_Except" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CQA_Heat_Prod_Except" name="SteelGradeIndex" type="L3STRING">
	/// 作业炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Prod_Except" name="Exceptional_Code" type="L3STRING">
	/// 异常代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Prod_Except" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Heat_Prod_Except" name="Classify" type="L3LONG">
	/// 优先级
	/// </Property>
	DECLARE_L3PROP_LONG(Classify)

	/// <Property class="CQA_Heat_Prod_Except" name="Exceptional_Time" type="L3DATETIME">
	/// 异常产生时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Exceptional_Time)

};
