// 逻辑类CQA_HeatGradeAssume_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

const int nDecideSteelGradeIndexFlag1 = 1;//决定炼钢记号产生标志(1：已经完成判定)
const int nUnitTypeID = 9;//工序标识(9：最终决定)
const int nProcessCount =0;//工序位处理次数
const int nDataLogMode = 1;//数据产生方式(0：自动计算；1：手工录入；)
const int DecideFinalFlag0 = 0;//需要终判标志(0：不需要；1：需要；)
const int DecideFinalFlag1 = 1;//需要终判标志(0：不需要；1：需要；)
const int RecommendFlag[2] = {0,1};//推荐炼钢记号标志(0:对Heat进行推荐；1:对Slab进行推荐；)
const int SlabIDModificationFlag = 1;//铸坯号变更标志；0：未变更；1：已变更
const int DecideSteelGradeIndexFlag = 0;//决定炼钢记号产生标志：0：未判；1：已经完成判定


/// <summary>
/// 可以终判钢坯类型
/// </summary>
enum FinalJudgeBloom
{
	HotChecked = 0,	// 已经热检
	WaitJudge  = 2, // 待判
	ColdCheck  = 3,	// 冷检
};


class CQA_HeatGradeAssume_Mag :
	public CL3Object
{
public:
	CQA_HeatGradeAssume_Mag(void);
	virtual ~CQA_HeatGradeAssume_Mag(void);

	DECLARE_L3CLASS(CQA_HeatGradeAssume_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeAssume_Mag)
	DECLARE_L3EVENTSINK_MAP()


	DECLARE_L3PROP_LONG (FinalJudgeEvent); //钢坯终判事件2009-01-02

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_HeatGradeAssume_Mag" name="NewHeatAbnormalEvent" type="L3STRING">
	/// 新的炉次异常产生事件
	/// </Property>
	DECLARE_L3PROP_STRING(NewHeatAbnormalEvent)

	/// <Method class="CQA_HeatGradeAssume_Mag" name="LogHeatExceptionData" type="L3SHORT">
	/// 记录炉次工艺异常
	/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
	/// <Param name="nUnitID" type="L3SHORT">工位ID</Param>
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="nProcessCount" type="L3SHORT">工序位处理次数</Param>
	/// <Param name="rsData" type="L3RECORDSET">
	/// 异常数据，必须包括：
	/// nUnitTypeID(工序标识)、nUnitID(工位ID)、strHeatID（熔炼号）、nProcessCount（工序位处理次数）、ExceptCode（异常代码）</Param>
	/// </Method>
	L3LONG LogHeatExceptionData(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatJudge" type="L3SHORT">
	/// 判定决定炼钢记号
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// <Param name="rsData" type="L3RECORDSET">
	/// 连铸判钢记录集,包括：
	/// HeatID、DecideSteelGradeIndex字段
	/// </Param>
	/// </Method>
	L3LONG HeatJudge(L3STRING strHeatID, L3STRING strSteelGradeIndex, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="LogQAOperateInfo" type="L3SHORT">
	/// 
	/// 记录质量操作信息
	/// 
    /// <Param name="rsData" type="L3RECORDSET">包括炉号、动作代码的记录集</Param>
	/// </Method>
	L3LONG LogQAOperateInfo( L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatFinalJudge" type="L3SHORT">
	/// 
	/// 炉次终判
	/// 
	/// 
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="rsData" type="L3RECORDSET">炉次终判记录集</Param>
	/// </Method>
	L3LONG HeatFinalJudge(L3STRING strHeatID, L3RECORDSET rsData,L3STRING strAppID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatGradeData" type="L3RECORDSET">
	/// 获取炉次品质判定数据
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// </Method>
	L3RECORDSET GetHeatGradeData(L3STRING strHeatID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatProcessExceptData" type="L3RECORDSET">
	/// 获取炉次工艺异常数据
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// </Method>
	L3RECORDSET GetHeatProcessExceptData(L3STRING strHeatID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatJudgeUnitInfo" type="">
	/// </Method>
	L3RECORDSET GetHeatJudgeUnitInfo();
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetUnJudgeHeatID" type="L3RECORDSET">
	/// 
	/// 获取需要判钢的炉次
	/// ARG&gt;&gt; CCMID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="CCMID" type="L3LONG">铸机号</Param>
	/// </Method>
	L3RECORDSET GetUnJudgeHeatID(L3LONG CCMID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeHeat" type="L3RECORDSET">
	/// 
	/// 获取需要终判炉次
	/// ARG&gt;&gt; strCasterID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetFinJudgeHeat(L3STRING strCasterID,L3STRING strCondition);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetSurfaceJudgeInfor" type="L3RECORDSET">
	/// 
	/// 根据炉号获取钢坯热检信息
	/// ARG&gt;&gt; strHeatID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetSurfaceJudgeInfor(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetSurfaceJudgeInfor" type="L3RECORDSET">
	/// 
	/// 根据炉号获取钢坯成分标准
	/// ARG&gt;&gt; strHeatID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetBloomStdEle(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBloomTerminalEle" type="L3RECORDSET">
	/// 
	/// 根据炉号获取钢坯终点样
	/// ARG&gt;&gt; strHeatID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetBloomTerminalEle(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeInfor" type="L3RECORDSET">
	/// 
	/// 根据炉号获取钢坯终判信息
	/// ARG&gt;&gt; strHeatID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetFinJudgeInfor(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="ModHeatGrade" type="L3SHORT">
	/// 修正当前炉次等级
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="nProcessCount" type="L3SHORT">重处理次数</Param>
	/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
	/// <Param name="rsData" type="L3RECORDSET">包括炉次等级、异常代码、处置代码、优先级</Param>
	/// </Method>
	L3LONG ModHeatGrade(L3STRING strHeatID, L3SHORT nProcessCount, L3SHORT nUnitTypeID, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="CreateQAHeatGradeData" type="L3SHORT">
	/// 建立初始炉次等级
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// <Param name="strPresetHeatID" type="L3STRING">预定炉号</Param>
	/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
	/// <Param name="nUnitID" type="L3SHORT">工位</Param>
	/// <Param name="strSteelGradeIndex" type="L3STRING">当前作业炼钢记号</Param>
	/// </Method>
	L3LONG CreateQAHeatGradeData(L3STRING strHeatID, L3STRING strPresetHeatID, L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strSteelGradeIndex);


	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetRefineThirdEle" type="L3RECORDSET">
	/// 
	/// 根据炉号获取精炼第三次成份数据
	/// ARG&gt;&gt; strHeatID：铸机号
	/// RET &lt;&lt; 成功返回过程样数据集；失败返回NULL。
	/// <Param name="strCasterID" type="L3STRING">铸机号</Param>
	/// </Method>
	L3RECORDSET GetRefineThirdEle(L3STRING strHeatID);

	//Modify begin by llj 2011-03-26 新增转炉钢水直送不锈钢产线的工艺路径，进行钢水质量判定，上传NC
	//钢水质量判定完成时自动完成钢水的入库上传NC
	/// <Method class="CQuality_Mag" name="BofSteelQualityJudge" type="L3LONG">
	/// 转炉钢水直送不锈钢质量判定
	/// <Param name="rsBofSteelInfo" type="L3RECORDSET">钢水信息</Param>
	/// </Method>
	L3LONG BofSteelQualityJudge(L3RECORDSET rsBofSteelInfo);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBofSteelJudgeHeat" type="L3RECORDSET">
	/// </Method>
	L3RECORDSET GetBofSteelJudgeHeat();
};
