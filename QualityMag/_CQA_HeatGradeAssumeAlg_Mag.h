// 逻辑类CQA_HeatGradeAssumeAlg_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_HeatGradeAssumeAlg_Mag :
	public CL3Object
{
public:
	CQA_HeatGradeAssumeAlg_Mag(void);
	virtual ~CQA_HeatGradeAssumeAlg_Mag(void);

	DECLARE_L3CLASS(CQA_HeatGradeAssumeAlg_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeAssumeAlg_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatGrade" type="">
	/// 炉次品质判定
	/// <Param name="nUnitTypeID" type="L3SHORT">工序标识</Param>
	/// <Param name="nUnitID" type="L3SHORT">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="nProcessCount" type="L3SHORT">工序位处理次数</Param>
	/// </Method>
	L3LONG EstimateHeatGrade(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatChemical" type="L3SHORT">
	/// 比对炉次成份
	/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
	/// <Param name="nUnitID" type="L3SHORT">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="nProcessCount" type="L3SHORT">重处理次数</Param>
	/// <Param name="rsChemicalData" type="L3RECORDSET">成份数据</Param>
	/// </Method>
	L3LONG EstimateHeatChemical(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount, L3RECORDSET rsChemicalData);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateDecideHeatGrade" type="L3SHORT">
	/// 综合各工序炉次等级，生成决定等级
	/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
	/// <Param name="nUnitID" type="L3SHORT">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="nProcessCount" type="L3SHORT">重处理次数</Param>
	/// </Method>
	L3LONG EstimateDecideHeatGrade(L3SHORT nUnitTypeID,L3SHORT nUnitID,L3STRING strHeatID,L3SHORT nProcessCount);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="RecommendSteelGradeIndex" type="L3SHORT">
	/// 推荐炼钢记号
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="*rsSteelGradeIndexData" type="L3RECORDSET">重处理次数</Param>
	/// </Method>
	L3LONG RecommendSteelGradeIndex(L3STRING strHeatID,L3RECORDSET *rsSteelGradeIndexData);
};
