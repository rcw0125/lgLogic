// 逻辑类CSteel_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CSteel_Data :
	public Material
{
public:
	CSteel_Data(void);
	virtual ~CSteel_Data(void);

	DECLARE_L3CLASS(CSteel_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:

	enum _YesOrNoEnum
	{
		No = 0,	// 无
		Yes = 1,// 有
	};
	/// <Property class="CSteel_Data" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CSteel_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Final_SteelGradeIndex" type="L3STRING">
	/// 最终炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Final_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Decide_SteelGradeIndex" type="L3STRING">
	/// 决定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CSteel_Data" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CSteel_Data" name="Weight" type="L3FLOAT">
	/// 钢水重量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CSteel_Data" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CSteel_Data" name="HeatGrade" type="L3STRING">
	/// 品质等级
	/// </Property>
	DECLARE_L3PROP_STRING(HeatGrade)

	/// <Property class="CSteel_Data" name="Classify" type="L3STRING">
	/// 异常代码分类
	/// </Property>
	DECLARE_L3PROP_STRING(Classify)

	/// <Property class="CSteel_Data" name="Exceptional_Code" type="L3STRING">
	/// 异常代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CSteel_Data" name="DecideSteelGradeIndexFlag" type="L3STRING">
	/// 决定炼钢记号产生标志
	/// </Property>
	DECLARE_L3PROP_STRING(DecideSteelGradeIndexFlag)

	/// <Property class="CSteel_Data" name="DecideFinalFlag" type="L3STRING">
	/// 需要终判标志
	/// </Property>
	DECLARE_L3PROP_STRING(DecideFinalFlag)

	/// <Property class="CSteel_Data" name="BOFFinishedFlag" type="L3STRING">
	/// 转炉实绩确认标志
	/// </Property>
	DECLARE_L3PROP_STRING(BOFFinishedFlag)

	/// <Property class="CSteel_Data" name="LFFinishedFlag" type="L3STRING">
	/// LF实绩确认标志
	/// </Property>
	DECLARE_L3PROP_STRING(LFFinishedFlag)

	/// <Property class="CSteel_Data" name="RHFinishedFlag" type="L3STRING">
	/// RH实绩确认标志
	/// </Property>
	DECLARE_L3PROP_STRING(RHFinishedFlag)

	/// <Property class="CSteel_Data" name="CCMFinishedFlag" type="L3STRING">
	/// CCM实绩确认标志
	/// </Property>
	DECLARE_L3PROP_STRING(CCMFinishedFlag)

	/// <Property class="CSteel_Data" name="FinalChemiclaFlag" type="L3STRING">
	/// 炉次确定标志
	/// </Property>
	DECLARE_L3PROP_STRING(FinalChemiclaFlag)

	/// <Property class="CSteel_Data" name="DivFinalChemiclaFlag" type="L3STRING">
	/// 炉次分割最终成分有无标志
	/// </Property>
	DECLARE_L3PROP_STRING(DivFinalChemiclaFlag)





};
