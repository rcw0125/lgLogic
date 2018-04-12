// 逻辑类CQA_HeatGradeData头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_HeatGradeData :
	public CL3Object
{
public:
	CQA_HeatGradeData(void);
	virtual ~CQA_HeatGradeData(void);

	DECLARE_L3CLASS(CQA_HeatGradeData,XGMESLogic\\QualityMag, ID_Object)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeData)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_HeatGradeData" name="ID_Object" type="L3STRING">
	/// 
	/// 身份标识：
	/// 熔炼号+工序位处理次数+工序
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CQA_HeatGradeData" name="HeatID" type="L3STRING">
	/// 熔炼号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_HeatGradeData" name="ProcessCount" type="L3SHORT">
	/// 工序位处理次数
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessCount)

	/// <Property class="CQA_HeatGradeData" name="UnitTypeID" type="L3SHORT">
	/// 
	/// 工序:
	/// 9：最终决定
	/// </Property>
	DECLARE_L3PROP_LONG(UnitTypeID)

	/// <Property class="CQA_HeatGradeData" name="UnitID" type="L3SHORT">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_LONG(UnitID)

	/// <Property class="CQA_HeatGradeData" name="Exceptional_Code" type="L3STRING">
	/// 异常代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_HeatGradeData" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_HeatGradeData" name="HeatGrade" type="L3STRING">
	/// 炉次等级
	/// </Property>
	DECLARE_L3PROP_STRING(HeatGrade)

	/// <Property class="CQA_HeatGradeData" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_HeatGradeData" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CQA_HeatGradeData" name="SteelGradeIndex" type="L3STRING">
	/// 作业炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_HeatGradeData" name="DataLogMode" type="L3SHORT">
	/// 
	/// 数据产生方式:
	/// 0：自动计算；1：手工录入
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

};
