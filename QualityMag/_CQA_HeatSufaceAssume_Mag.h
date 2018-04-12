// 逻辑类CQA_HeatSufaceAssume_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_HeatSufaceAssume_Mag :
	public CL3Object
{
public:
	CQA_HeatSufaceAssume_Mag(void);
	virtual ~CQA_HeatSufaceAssume_Mag(void);

	DECLARE_L3CLASS(CQA_HeatSufaceAssume_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatSufaceAssume_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();


	/// <Property class="CQA_HeatSufaceAssume_Mag" name="HeatSufaceAAssumeMag" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(HeatSufaceAAssumeMag)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="HotJudgeEvent" type="L3LONG">
	/// 热检质量判定事件
	/// </Property>
	DECLARE_L3PROP_LONG(HotJudgeEvent)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="CoolJudgeEvent" type="L3LONG">
	/// 冷检质量判定事件
	/// </Property>
	DECLARE_L3PROP_LONG(CoolJudgeEvent)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="BloomCuttingEvent" type="L3LONG">
	/// 钢坯切断事件
	/// </Property>
	DECLARE_L3PROP_LONG (BloomCuttingEvent); //钢坯切断事件

	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomHotJudge" type="L3LONG">
	/// 钢坯热检质量判定
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// 包括：HeatID、Bloom_Count、Cal_Weight、Wrong_Total_Count、Wrong_Total_Weight、
	/// Wrong_Reason、Cut_SteelGradeIndex 、SteelGradeIndex、Produce_Date、Length、Width、
	/// Thickness字段
	/// </Method>
	L3LONG BloomHotJudge(L3RECORDSET rsData);

	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomCoolJudge" type="L3LONG">
	/// 钢坯冷检质量判定
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG BloomColdJudge(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
	/// 获取冷检质量判定信息
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetHeatCoolJudgeData(L3STRING strCasterID);

	/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
	/// 获取热检质量判定信息
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetHeatHotJudgeData(L3STRING strCasterID);


	/// <Method class="CQuality_Mag" name="GetBloomWaitingSendInfor" type="">
	/// 获取待出坯钢坯信息
	/// </Method>
	L3RECORDSET GetBloomWaitingSendInfor();


	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomHotSend" type="L3BOOL">
	/// 钢坯热送
	/// </Method>
	L3LONG BloomHotSend(L3RECORDSET rsData);


	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomOffLine" type="L3BOOL">
	/// 钢坯下线
	/// </Method>
	L3LONG BloomOffLine(L3RECORDSET rsData);

};
