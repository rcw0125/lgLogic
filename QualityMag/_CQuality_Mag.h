// 逻辑类CQuality_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

const CString BOF_INIT_HEATGRADE	= _T("1100");//转炉初始炉次品质
const CString LF_INIT_HEATGRADE	    = _T("1200");//LF炉初始炉次品质
const CString RH_INIT_HEATGRADE		= _T("1300");//RH炉初始炉次品质
const CString CCM_INIT_HEATGRADE	= _T("1400");//铸机初始炉次品质

class CQuality_Mag :
	public CL3Object
{
public:
	CQuality_Mag(void);
	virtual ~CQuality_Mag(void);

	DECLARE_L3CLASS(CQuality_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQuality_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();



	/// <Method class="CQuality_Mag" name="BloomWaster" type="L3BOOL">
	/// 
	/// 钢坯甩废
	/// ARG&gt;&gt; rsData:甩废数据，包括：HeatID、Bloom_Count、Cal_Weight、Waster_Total_Count、Waster_Total_Weight、Waster_Reason、Cut_SteelGradeIndex 、SteelGradeIndex、Produce_Date、Length、Width、Thickness字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET">检验委托单信息</Param>
	/// </Method>
	L3BOOL BloomWaster(L3RECORDSET rsData);
	/// <Method class="CQuality_Mag" name="GetUnspecifyDutyWasterData" type="L3RECORDSET">
	/// 
	/// 获取未指定责任单位的甩废实绩数据
	/// ARG&gt;&gt;strCasterID：铸机号
	/// RET &lt;&lt; 成功返回查询数据集；失败返回NULL。
	/// <Param name="strCasterID" type=""></Param>
	/// </Method>
	L3RECORDSET GetUnspecifyDutyWasterData(L3STRING strCasterID);
	/// <Method class="CQuality_Mag" name="AddQAStdData" type="L3BOOL">
	/// 
	/// 增加作业标准数据
	/// ARG&gt;&gt; rsData:标准数据
	///        &gt;&gt; strDataType:数据类型URI
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
	L3LONG AddBOFQAStdData(L3RECORDSET rsBase,
									  L3RECORDSET rsAr,
									  L3RECORDSET rsBlow,
									  L3RECORDSET rsBlowO2,
									  L3RECORDSET rsBulk,
									  L3RECORDSET rsFeed,
									  L3RECORDSET rsInFurnace,
									  L3RECORDSET rsLadle,
									  L3RECORDSET rsSlag,
									  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="DelQAStdData" type="L3BOOL">
	/// 
	/// 删除作业标准数据
	/// ARG&gt;&gt; rsData:标准数据
	///        &gt;&gt; DataType:数据类型URI
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
    L3LONG CQuality_Mag::DelBOFQAStdData(L3RECORDSET rsBase,
										  L3RECORDSET rsAr,
										  L3RECORDSET rsBlow,
										  L3RECORDSET rsBlowO2,
										  L3RECORDSET rsBulk,
										  L3RECORDSET rsFeed,
										  L3RECORDSET rsInFurnace,
										  L3RECORDSET rsLadle,
										  L3RECORDSET rsSlag,
										  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="ModQAStdData" type="L3BOOL">
	/// 
	/// 修改作业标准数据
	/// ARG&gt;&gt; rsData:标准数据
	///        &gt;&gt; DataType:数据类型URI
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
	L3LONG CQuality_Mag::ModBOFQAStdData(L3RECORDSET rsBase,
										  L3RECORDSET rsAr,
										  L3RECORDSET rsBlow,
										  L3RECORDSET rsBlowO2,
										  L3RECORDSET rsBulk,
										  L3RECORDSET rsFeed,
										  L3RECORDSET rsInFurnace,
										  L3RECORDSET rsLadle,
										  L3RECORDSET rsSlag,
										  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="GetQAStdData" type="L3RECORDSET">
	/// 
	/// 获取质量标准数据集
	/// ARG&gt;&gt; rsCondition 包括：StdDataType
	/// RET &lt;&lt; 成功返回数据集；失败返回NULL。
	/// <Param name="rsCondition" type="L3RECORDSET"></Param>
	/// </Method>
	L3RECORDSET GetQAStdData(L3RECORDSET rsCondition);
    // 新增LF制造标准
	L3LONG AddLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);
	// 修改LF制造标准
	L3LONG ModLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);

	// 删除LF制造标准
	L3LONG DelLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);

    // 新增RH制造标准
	L3LONG AddRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);
    // 修改RH制造标准
	L3LONG ModRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);
    // 删除RH制造标准
	L3LONG DelRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);

    //新增CCM制造标准
	L3LONG AddCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);
    //修改CCM制造标准
	L3LONG ModCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);
    // 删除CCM制造标准
	L3LONG DelCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBase" type="L3RECORDSET">
	/// 获取BOF制造标准(基本数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFAr" type="L3RECORDSET">
	/// 获取BOF制造标准(吹氩数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFAr(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlow" type="L3RECORDSET">
	/// 获取BOF制造标准(吹炼数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBlow(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlowOxygen" type="L3RECORDSET">
	/// 获取BOF制造标准(吹氧数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBlowOxygen(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBulk" type="L3RECORDSET">
	/// 获取BOF制造标准(加料数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBulk(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFFeed" type="L3RECORDSET">
	/// 获取BOF制造标准(喂丝数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFInCtrlElement" type="L3RECORDSET">
	/// 获取BOF制造标准(内控成分数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFMaterial" type="L3RECORDSET">
	/// 获取BOF制造标准(来料数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFMaterial(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFLadle" type="L3RECORDSET">
	/// 获取BOF制造标准(钢包数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFLadle(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFSlagElement" type="L3RECORDSET">
	/// 获取BOF制造标准(渣成分数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFSlagElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFTapping" type="L3RECORDSET">
	/// 获取BOF制造标准(出钢数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFTapping(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFBase" type="L3RECORDSET">
	/// 获取LF制造标准(基本数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFAlloy" type="L3RECORDSET">
	/// 获取LF制造标准(合金数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFAlloy(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFFeed" type="L3RECORDSET">
	/// 获取LF制造标准(喂丝数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFInCtrlElement" type="L3RECORDSET">
	/// 获取LF制造标准(内控成分数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFLadle" type="L3RECORDSET">
	/// 获取LF制造标准(钢包数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFLadle(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFProc" type="L3RECORDSET">
	/// 获取LF制造标准(作业数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFSlag" type="L3RECORDSET">
	/// 获取LF制造标准(渣数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFSlag(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFSlagElement" type="L3RECORDSET">
	/// 获取LF制造标准(渣成分数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFSlagElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHBase" type="L3RECORDSET">
	/// 获取RH制造标准(基本数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHAlloy" type="L3RECORDSET">
	/// 获取RH制造标准(合金数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHAlloy(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHFeed" type="L3RECORDSET">
	/// 获取RH制造标准(喂丝数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHInCtrlElement" type="L3RECORDSET">
	/// 获取RH制造标准(内控数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHProc" type="L3RECORDSET">
	/// 获取RH制造标准(作业数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMFlux" type="L3RECORDSET">
	/// 获取CCM制造标准(中包覆盖剂数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMFlux(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMProc" type="L3RECORDSET">
	/// 获取CCM制造标准(作业数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMProd" type="L3RECORDSET">
	/// 获取CCM制造标准(制成数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMProd(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpec" type="L3RECORDSET">
	/// 获取CCM制造标准(规格数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMSpec(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpeed" type="L3RECORDSET">
	/// 获取CCM制造标准(拉速数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMSpeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMTundish" type="L3RECORDSET">
	/// 获取CCM制造标准(中包数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMTundish(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMBase" type="L3RECORDSET">
	/// 获取CCM制造标准(基本数据)。
	/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="BloomWasterDutySpecify" type="L3RECORDSET">
	/// 获取CCM制造标准(基本数据)。
	/// <Param name="rsData" type="L3RECORDSET">CQA_Bloom_Waster_Data主键、责任单位、责任标志=1</Param>
	/// </Method>
	L3LONG BloomWasterDutySpecify(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetSampleApplyData" type="L3RECORDSET">
	/// 按取样地点(工位)获取化验委托单数据
	/// <Param name="strSampleAddr" type="L3STRING">取样地点(工位)</Param>
	/// </Method>
	L3RECORDSET GetSampleApplyData(L3STRING strSampleAddr);

	/// <Method class="CQuality_Mag" name="GetHeatIDByAddr" type="L3RECORDSET">
	/// 通过取样地点获取工位最近三炉炉号
	/// <Param name="strSampleAddr" type="L3STRING">取样地点(工位)</Param>
	/// </Method>
	L3RECORDSET GetHeatIDByAddr(L3STRING strSampleAddr);

	/// <Method class="CQuality_Mag" name="CreateHeatGradeQAData" type="L3RECORDSET">
	/// 工序初始炉次等级创建
	/// <Param name="strUnitID" type="L3STRING">工序</Param>
	/// <Param name="rsData" type="L3RECORDSET">至少包含炉号、预定炉号、炼钢记号、预定炼钢记号的记录集</Param>
	/// </Method>
	L3SHORT CreateHeatGradeQAData(L3STRING strUnitID ,L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetCurrentHeatGradeQAData" type="L3RECORDSET">
	/// 获取工序当前炉次炉次等级
	/// <Param name="strUnitID" type="L3STRING">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3RECORDSET GetCurrentHeatGradeQAData(L3STRING strUnitID ,L3STRING strHeatID);

	/// <Method class="CQuality_Mag" name="UpdateCurrentHeatGradeData" type="L3LONG">
	/// 
	/// 修改当前炉次等级信息
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateCurrentHeatGradeData(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
	/// 通过定尺长度获取定尺标准数据。
	/// <Param name="Length" type="LONG">长度</Param>
	/// </Method>
	L3RECORDSET GetQACalWeightData(LONG Length);

	///2008-12-29 tangyi通过钢种获取该钢种可以改判的炼钢记号
	/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
	/// 通过定尺长度获取定尺标准数据。
	/// <Param name="Length" type="LONG">长度</Param>
	/// </Method>
	L3RECORDSET GetJudgedSteelGrade(L3STRING strSteelGrade,L3STRING strSteelGradeIndex);

	///// <Method class="CQuality_Mag" name="GetDeSSampleApplyData" type="L3RECORDSET">
	///// 获取化验委托单(脱硫)数据
	///// </Method>
	//L3RECORDSET GetDeSSampleApplyData();

	///2011-03-19 llj 根据炼钢记号将标准复制到新的炼钢记号上
	/// <Method class="CQuality_Mag" name="SteelGradeIndexCopy" type="L3LONG">
	/// <Param name="strNewSteelGradeIndex" type="L3STRING">新的炼钢记号</Param>
	/// <Param name="strOldSteelGradeIndex" type="L3STRING">旧的炼钢记号</Param>
	/// </Method>
	L3LONG SteelGradeIndexCopy(L3STRING strNewSteelGradeIndex, L3STRING strOldSteelGradeIndex);
};
