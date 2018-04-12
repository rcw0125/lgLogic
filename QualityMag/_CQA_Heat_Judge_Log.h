// 逻辑类CQA_Heat_Judge_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Heat_Judge_Log :
	public CL3Object
{
public:
	CQA_Heat_Judge_Log(void);
	virtual ~CQA_Heat_Judge_Log(void);

	DECLARE_L3CLASS(CQA_Heat_Judge_Log,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Judge_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Judge_Log" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Judge_Log" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Judge_Log" name="Decide_SteelGradeIndex" type="L3STRING">
	/// 决定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_SteelGradeIndex)

	/// <Property class="CQA_Heat_Judge_Log" name="Judge_Date" type="L3DATETIME">
	/// 终判时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Judge_Date)

	/// <Property class="CQA_Heat_Judge_Log" name="Operator" type="L3STRING">
	/// 操作人员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CQA_Heat_Judge_Log" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CQA_Heat_Judge_Log" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

};
