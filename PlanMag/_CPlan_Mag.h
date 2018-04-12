// 逻辑类CPlan_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "PlanDept.h"


//定义结构
struct BOFStatus
{
	TCHAR BOFID[4];
	L3DATETIME dtBOF0ProcessEndTime;
};


const L3LONG nNewBOF =1;
const L3LONG nOldBOF =0;


/// <summary>
/// RH区分
/// </summary>
enum BOFType
{
	BOF50t = 1,		// 不经过RH
	BOF80t = 2,			 // 1#RH
};


/// <summary>
/// 铸机区分
/// </summary>
enum CasterType
{
	NoLFCaster = 1,		// 1#2#铸机
	OldLFCaster = 2,    // 3#4#铸机
	NewLFCaster = 3,	// 5#铸机
	//Modify by llj 2011-1-18 因改造修改
	NewLFCaster6 = 4,	// 6#铸机(此铸机只用于排产，在炉后处理结束时，自动完成铸机所以操作)
	NewLFCaster7 = 5,	// 7#铸机 

};

/// <summary>
/// LF区分
/// </summary>
enum LFType
{
	NoPassLF = 1,		// 不经过LF
	OldLF = 2,			 // 1#2#LF
	NewLF = 3,			// 3#LF
};

/// <summary>
/// RH区分
/// </summary>
enum RHType
{
	NoPassRH = 1,		// 不经过RH
	PassRH = 2,			 // 1#RH
};


//铸机
const CString csCasterType1 =_T("01");//1#2#铸机
const CString csCasterType2 =_T("02");//3#4#铸机
const CString csCasterType3 =_T("03");//5#铸机
//Modify by llj 2011-1-18 因改造修改
const CString csCasterType7 =_T("07");//7#铸机

//LF
const CString csLFType1 =_T("01");//不经过LF
const CString csLFType2 =_T("02");//1#2#LF
const CString csLFType3 =_T("03");//3#LF
//Modify by llj 2011-02-11 增加5#LF修改
const CString csLFType5 =_T("05");//5#LF
//Add by hyh 2012-05-14  因改造修改
const CString csLFType4 =_T("04");//4#LF

//RH
const CString csRHType1 =_T("01");//不经过RH
const CString csRHType2 =_T("02");//1#RH


/// <summary>
/// 转炉
/// </summary>
enum HeatType
{
	CurrentHeat = 0,		// 当前炉
	LastHeat = 1,		    // 上一炉。
	NextHeat = 2,			// 下一炉。
};

class CPlan_Mag :
	public PlanDept
{
public:
	CPlan_Mag(void);
	virtual ~CPlan_Mag(void);

	DECLARE_L3CLASS(CPlan_Mag,XGMESLogic\\PlanMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	DECLARE_L3PROP_LONG(PlanOrderEvent)               //计划订单状态变化事件
	DECLARE_L3PROP_LONG(TappingPlanEvent)      //出钢计划状态变化事件
	DECLARE_L3PROP_LONG(TappingPlanGenerateEvent)      //出钢计划生成事件
	DECLARE_L3PROP_LONG(EquipmentStatusChange)					//设备状态改变
	DECLARE_L3PROP_LONG(WriteFlag)	
	DECLARE_L3PROP_LONG(BOFChangeFlag)		        //交换炉座开始标志 
	DECLARE_L3PROP_LONG(TappingModelFlag)			//出钢模型结束标志
	DECLARE_L3PROP_LONG(PlanExeFlag)			//计划下达标志 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(PlanCancelFlag)			//计划取消标志 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(IronPlanExeFlag)			//铁水计划下达标志 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(TappingPlanFlag)			//出钢计划标志 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(BOFYieldFlag)		    //计算转炉产能 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(AddNewBOFFlag)			    //增加新炉数 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(FirstCastingHeatFlag)			    //指定浇次第一炉 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(ReFirstCastingHeatFlag)			    //重新指定浇次第一炉 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(ModifyPlanFlag)			    //修改 0,1 1:开始执行，0：执行完成
	DECLARE_L3PROP_LONG(PlanDelFlag)			//计划取消标志 0,1 1:开始执行，0：执行完成

	/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
	/// 
	/// 接收计划订单，判断计划订单的状态如果大于2则退出。新增计划订单状态为0未确认
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdRec(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// 计划订单确认，更改订单的状态为1未收池
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
	/// </Method>
	L3BOOL PlanOrdCfm(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="GetUnIntegratePlanOrd" type="L3RECORDSET">
	/// 
	/// 按照日期获取未收池计划订单
	/// ARG &gt;&gt; Condition : 收池条件。
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetUnIntegratePlanOrd(L3STRING strDate);

	/// <Method class="CPlan_Mag" name="GetIntegratedPlanOrd" type="L3RECORDSET">
	/// 
	/// 按照日期、铸机获取已经池计划订单
	/// ARG &gt;&gt; Condition : 收池条件。
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetIntegratedPlanOrd(L3STRING strBeginDate,L3STRING strEndDate,L3STRING strSteelGrade);

	/// <Method class="CPlan_Mag" name="GetIntegratedPlanOrd" type="L3RECORDSET">
	/// 
	/// 按照日期、铸机获取铸机浇钢计划
	/// ARG &gt;&gt;
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetCastingPlan(L3STRING strDate,L3STRING strCasterID);

	/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCfm" type="L3BOOL">
	/// 
	/// 计划订单收池确认，同时确定铸机号，更改订单的状态为2收池
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID\CasrterID\New_BOF_Flag字段。
	///         &gt;&gt;strCasterID ：铸机号
	///         &gt;&gt;nNewBOFFlag ：新旧转炉标志
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// <Param name="strCasterID" type="L3STRING"></Param>
	/// </Method>
	L3LONG PlanOrdIntegrateCfm(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCancel" type="L3BOOL">
	/// 
	/// 计划订单收池取消，同时取消铸机号，更改订单的状态为1未收池
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdIntegrateCancel(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="CastingPlanGen" type="L3BOOL">
	/// 
	/// 编制铸机浇钢计划，更改订单的状态为3生成浇钢计划，浇钢计划的状态为1未排产
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG CastingPlanGen(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="NewCastingPlanGen" type="L3LONG">
	/// 
	/// 新编制铸机浇钢计划，更改订单的状态为3生成浇钢计划，浇钢计划的状态为1未排产
	/// ARG&gt;&gt; rsPlan :订单记录，csSteelGradeIndex：炼钢记号。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// <Param name="strSteelGradeIndex" type="String"></Param>
	L3LONG NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex);

	/// <Method class="CPlan_Mag" name="CastingPlanCancel" type="L3BOOL">
	/// 
	/// 取消铸机浇钢计划，更改订单的状态为2
	/// ARG&gt;&gt; rsCastingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL CastingPlanCancel(L3RECORDSET rsCastingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanGen" type="L3LONG">
	/// 
	/// 编制出钢计划，更改订单，浇钢计划的状态为4已排产，新生成的出钢计划状态为1未下达
	/// ARG&gt;&gt; rsCastingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TappingPlanGen(L3RECORDSET rsCastingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanCancel" type="L3BOOL">
	/// 
	/// 取消出钢计划，更改浇钢计划的状态为1未排产，如果订单下的浇钢计划状态全为1则更改订单的状态为3
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanCancel(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanSend" type="L3BOOL">
	/// 
	/// 出钢计划下达，更改出钢计划的状态为2
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanSend(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// 出钢计划下达取消，更改出钢计划的状态为1
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanSndCancel(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanDestCfm" type="L3BOOL">
	/// 
	/// 出钢计划去向确认
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// &gt;&gt;strDestination：去向
	/// &gt;&gt;nHotFlag：热送标志
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// <Param name="strDestination" type="L3STRING"></Param>
	/// <Param name="nHotFlag" type="L3LONG"></Param>
	/// </Method>
	L3BOOL TappingPlanDestCfm(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanExchange" type="L3LONG">
	/// 
	/// 炉座交换
	/// ARG&gt;&gt; PreHeatID1 : 预定炉号1。
	///  &gt;&gt;PreHeatID2 : 预定炉号2。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="PreHeatID1" type="L3STRING">预定炉号</Param>
	/// <Param name="PreHeatID2" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3LONG TappingPlanExchange(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
	/// 
	/// 指定浇次第一炉，产生新的浇次与浇次内炉数
	/// ARG&gt;&gt; PreHeatID : 预定炉号。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3BOOL TappingPlanFirHeatDesign(L3RECORDSET strPreHeatID);
	/// <Method class="CPlan_Mag" name="TappingPlanFirHeatCancel" type="L3BOOL">
	/// 
	/// 取消浇次第一炉，清掉浇次号、浇次内炉数
	/// ARG&gt;&gt; 
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// </Method>
	L3BOOL TappingPlanFirHeatCancel(L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="AddHeatsToCasting" type="L3BOOL">
	/// 
	/// 添加炉次到最近浇次中
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// </Method>
	L3BOOL AddHeatsToCasting(L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="CalBOFIDAndReGenTappingAct" type="L3LONG">
	/// 
	/// 重新分配转炉炉座产生出钢计划实际
	/// ARG&gt;&gt; 
	/// RET &lt;&lt; 成功返回1；失败返回出错代码。
	/// </Method>
	L3LONG CalBOFIDAndReGenTappingAct();

	/// <Method class="CPlan_Mag" name="CalBOFIDAndReGenTappingAct" type="L3LONG">
	/// 
	/// 重新分配转炉炉座产生出钢计划实际
	/// ARG&gt;&gt; csNewBOFFlag:新转炉标志
	/// RET &lt;&lt; 成功返回1；失败返回出错代码。
	/// </Method>
	L3LONG CalBOFIDAndReGenTappingAct(L3SHORT nNewBOFFlag);

	/// <Method class="CPlan_Mag" name="GetCurDayTappingPlan" type="L3RECORDSET">
	/// 
	/// 获取当天出钢计划信息以及上一天未执行完成计划
	/// ARG &gt;&gt; strBofID: 转炉号。
	///         &gt;&gt;strCasterID:铸机号
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="strBofID" type="String"></Param>
	/// <Param name="strCasterID" type="String"></Param>
	/// </Method>
	L3RECORDSET GetCurDayTappingPlan(L3STRING strBofID, L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="TappingPlanChangeTimeTable" type="L3LONG">
	/// 
	/// 更改火车时刻表
	/// ARG&gt;&gt; PreHeatID1 : 预定炉号。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="PreHeatID" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3LONG TappingPlanChangeTimeTable(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="GetCurHeatPlanInfor" type="L3RECORDSET">
	/// 
	/// 获取当前炉次计划信息
	/// ARG &gt;&gt; strPreHetaID: 预定炉号。
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="strPreHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetCurHeatPlanInfor(L3STRING strPreHeatID);
	/// <Method class="CPlan_Mag" name="TappingPlanChangeRoute" type="L3LONG">
	/// 
	/// 更改工艺路径
	/// ARG&gt;&gt; rsData: 更新数据集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TappingPlanChangeRoute(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="TappingPlanExchangeTreatSeq" type="L3LONG">
	/// 
	/// 交换铸机处理顺序号
	/// ARG&gt;&gt; PreHeatID1 : 预定炉号1。
	///  &gt;&gt;PreHeatID2 : 预定炉号2。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="PreHeatID1" type="L3STRING">预定炉号</Param>
	/// <Param name="PreHeatID2" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3LONG TappingPlanExchangeTreatSeq(L3RECORDSET rsData);

	
	/// <Method class="CPlan_Mag" name="ModifyPlanExecutionStatus" type="L3BOOL">
	/// 
	/// 更改出钢计划状态
	/// ARG&gt;&gt; rsPlanExecutionData : 包括炉号\预定炉号\工序\处理号\工序状态\状态改变时间。
	/// RET &lt;&lt; 返回true。
	/// <Param name="rsPlanExecutionData" type="L3RECORDSET">计划执行数据</Param>
	/// </Method>

	L3BOOL ModifyPlanExecutionStatus(L3RECORDSET rsTappingPlan);

	/// <Method class="CPlan_Mag" name="GetUnitProcessPlan" type="L3RECORDSET">
	/// 
	/// 更改出钢计划状态
	/// ARG&gt;&gt; nUnitType : 工序。
	/// ARG&gt;&gt; strUnitID : 工位。
	/// RET &lt;&lt; 返回记录集。
	/// <Param name="nUnitType" type="L3SHORT">工序</Param>
	/// <Param name="strUnitID" type="L3SHORT">工位</Param>
	/// </Method>

	L3RECORDSET GetUnitProcessPlan(L3SHORT nUnitType, L3STRING strUnitID);


	/// <Method class="CPlan_Mag" name="ModifyUnitSteelGradeIndex" type="L3LONG">
	/// 
	/// 更改工序预定炼钢记号预定炉号
	/// ARG&gt;&gt; strHeatID : 炉号1。
	/// RET &lt;&lt; 成功0错误代码。
	/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
	/// </Method>

	L3LONG ModifyUnitSteelGradeIndex(L3STRING strHeatID);

	/// <Method class="CPlan_Mag" name="GetUnConfirmPlanOrder" type="L3RECORDSET">
	/// 
	/// 获取未确认计划订单
	/// ARG &gt;&gt; 
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetUnConfirmPlanOrder();


	private:

	/// <Method class="CPlan_Mag" name="GetSteelGradeIndexBySteelGrade" type="L3LONG">
	/// 
	/// 获取钢种代表炼钢记号
	/// ARG&gt;&gt; csSteelGrade : 钢种。
	/// RET &lt;&lt; 成功返回炼钢记号。
	/// <Param name="csSteelGrade" type="L3STRING">钢种</Param>
	/// </Method>
	CString  GetSteelGradeIndexBySteelGrade(CString csSteelGrade,CString csProtocol,CString csMaterialCode);

	/// <Method class="CPlan_Mag" name="CalculateHeatCount" type="L3LONG">
	/// 
	/// 计算炉数
	/// ARG&gt;&gt; nBOFFlag : 转炉标志。
	/// dWeight:计划订单重量
	/// RET &lt;&lt; 成功返回炼钢记号。
	/// <Param name="nBOFFlag" type="L3SHORT">转炉标志</Param>
	/// <Param name="dWeight" type="L3DOUBLE">计划订单重量</Param>
	/// </Method>
	L3LONG  CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight);

	/// <Method class="CPlan_Mag" name="GenCastingPlanOfSpecifyCasterID" type="L3LONG">
	/// 
	/// 生成指定铸机铸机浇钢计划
	/// ARG&gt;&gt; csCasterID : 铸机。
	/// rsPlanOrder:计划订单信息
	/// nHeatCount:炉数
	/// csSteelGradeIndex:炼钢记号
	/// RET &lt;&lt; 返回出错代码。
	/// <Param name="csCasterID" type="CSTRING">铸机</Param>
	/// <Param name="rsPlanOrder" type="L3RECOEDSET">计划订单信息</Param>
	/// <Param name="nHeatCount" type="L3LONG">炉数</Param>
	/// <Param name="csSteelGradeIndex" type="CSTRING">炼钢记号</Param>
	/// </Method>
	L3LONG GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,L3LONG nHeatCount,CString csSteelGradeIndex,L3DOUBLE fWeight,L3SHORT nBOFFlag);

	/// <Method class="CPlan_Mag" name="CalculateCastingTime" type="L3LONG">
	/// 计算浇钢计划铸机开浇时间
	/// ARG&gt;&gt; csCasterID : 铸机。
	/// ARG&gt;&gt; csSteelGradeIndex : 炼钢记号。
	/// ARG&gt;&gt; &dtCastingTime : 开浇时间。
	/// RET &lt;&lt; 错误返回错误代码。
	/// <Param name="csCasterID" type="CSTRING">铸机</Param>
	/// <Param name="csSteelGradeIndex" type="CSTRING">炼钢记号</Param>
	/// </Method>
	L3LONG CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime);

	/// <Method class="CPlan_Mag" name="CalcBOFProcessEndTime" type="L3LONG">
	/// 
	/// 计算转炉出钢时间
	/// ARG&gt;&gt; nBOFID : 炉座号。
	/// &gt;&gt;dtBOFProcessEndTime : 出钢时间。
	/// &gt;&gt;dtCurrIronPreparedTime：兑铁时间
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="nBOFID" type="L3STRING">炉座号</Param>
	/// <Param name="dtBOFProcessEndTime" type="L3DATETIME">出钢时间</Param>
	/// <Param name="dtCurrIronPreparedTime" type="L3DATETIME">兑铁时间</Param>
	/// </Method>

	L3LONG CalcBOFProcessEndTime(CString nBOFID, L3DATETIME &dtBOFProcessEndTime,L3DATETIME dtCurrIronPreparedTime);


	/// <Method class="CPlan_Mag" name="CalcUnitOneToOneTime" type="L3LONG">
	/// 
	/// 计算一炉的工位间移动时间
	/// ARG&gt;&gt; csPreHeatID : 预定炉号。
	/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
	/// <Param name="csPreHeatID" type="L3STRING">预定炉号</Param>
	/// </Method>
	 L3LONG CPlan_Mag::CalcUnitOneToOneTime(CString csPreHeatID);


	 /// <Method class="CPlan_Mag" name="GetUnitOneToOneTime" type="L3LONG">
	 /// 
	 /// 获取一炉的工位间移动时间
	 /// ARG&gt;&gt; StartUnit : 起始工序。
	 /// ARG&gt;&gt; EndUnit : 结束工序。
	 /// RET &lt;&lt; 成功返回移动时间。
	 /// <Param name="StartUnit" type="L3STRING">起始工序</Param>
	 /// <Param name="EndUnit" type="L3STRING">结束工序</Param>
	 /// </Method>
	 L3DATETIME GetUnitOneToOneTime(CString StartUnit,CString EndUnit);


	 /// <Method class="CPlan_Mag" name="GetHeatMaxProcessNo" type="L3LONG">
	 /// 
	 /// 得到工序位最大处理号
	 /// ARG&gt;&gt; nUnitType : 工序。
	 /// ARG&gt;&gt; csUnitID : 工位。
	 /// RET &lt;&lt; 返回最大处理号。
	 /// <Param name="nUnitType" type="L3SHORT">工序</Param>
	 /// <Param name="csUnitID" type="L3STRING">工位</Param>
	 /// </Method>
	 L3LONG GetHeatMaxProcessNo(L3SHORT nUnitType, CString csUnitID);


	 /// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
	/// 
	/// 计算新的浇次与浇次内炉数
	/// ARG&gt;&gt; PreHeatID : 预定炉号。
	/// RET &lt;&lt; 成功返回0，失败返回错误代码
	/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
	/// </Method>

	L3LONG	CaculateNewCastingNoAndHeats(CString csPresetHeatID);


	/// <Method class="CPlan_Mag" name="CalcUnitStdProcessTime" type="L3LONG">
	/// 
	/// 计算一炉各工位标准处理时刻
	/// ARG&gt;&gt; PreHeatID1 : 预定炉号。
	/// RET &lt;&lt; 成功返回0；失败返回出错代码。
	/// <Param name="PreHeatID" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3LONG CalcUnitStdProcessTime(CString csPreHeatID);



	/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
	/// 
	/// 记录钢包计划
	/// ARG&gt;&gt; strHeatID : 炉号1。
	/// RET &lt;&lt; 成功0错误代码。
	/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
	/// </Method>
	L3RECORDSET StoreLadlePlanBeforeExBOF (CString strPresetHeatID);

	
	/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
	/// 
	/// 炉座交换后，根据计划状态确定钢包计划是否重新下达
	/// ARG&gt;&gt; strHeatID : 炉号1。
	/// RET &lt;&lt; 成功0错误代码。
	/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
	/// </Method>
	L3LONG ReDownLoadLadlePlan(CString csPreHeatID,L3RECORDSET rsLadlePlan);


	//察看当前炉次上一炉次的状态
	CString GetSomeHeatStatus(CString csHeatID,L3SHORT nLastFlag);


	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// 记录转炉非作业时间
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LogBOFNunProcessTime(L3RECORDSET rsData);


	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// 修改出钢计划计划时间信息
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ModifyTappingPlanTimeInfor(L3RECORDSET rsData);

	void ChangeRsTappingPlanValue(void);


	/// <Method class="CDispatch_Mag" name="AddSteelToCache" type="L3LONG">
	/// 
	/// 将钢水从缓存中移去
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelFromCache(CString csCacheID,CString csHeatID);

	/// <Method class="CDispatch_Mag" name="AddSteelToCache" type="L3LONG">
	/// 
	/// 将钢水添加到缓存
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>
	L3LONG AddSteelToCache(CString csCacheID,CString csHeatID);


	/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
	/// 
	/// 获取钢水当前所在缓存URi
	/// ARG csHeatID：炉号
	/// RET &gt;&gt; 找到的URi
	/// </Method>
	CString GetCurSteelCache(CString csHeatID);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenSideExchangePlan" type="L3LONG">
	/// 
	/// 当炉后工序交换计划时钢水移动
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelWhenSideExchangePlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// 当RH工序交换计划时钢水移动
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelWhenRHExPlan(CString cstrURI1,CString cstrURI2);

	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// 当LF工序交换计划时钢水移动
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelWhenLFExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenBOFExPlan" type="L3LONG">
	/// 
	/// 当转炉工序交换计划时钢水移动
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelWhenBOFExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// 当大包到达时交换计划时钢水移动
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelWhenCasterExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CPlan_Mag" name="TappingPlanEnd" type="L3BOOL">
	/// 
	/// 出钢计划强制结束
	/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// <Param name="strDestination" type="L3STRING"></Param>
	/// <Param name="nHotFlag" type="L3LONG"></Param>
	/// </Method>
	L3BOOL TappingPlanEnd(L3RECORDSET rsTappingPlan);


	// <Method class="CPlan_Mag" name="ModifyLadleAllInfor" type="L3BOOL">
	/// 修改钢包相应信息
	/// </Method>

	L3BOOL ModifyLadleAllInfor(CString csUnitID,CString csHeatID,CString csPreHeatID);


	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// 删除计划订单
	/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
	/// </Method>
	L3BOOL DelPlanOrder(L3RECORDSET rsPlan);


	/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
	/// 
	/// 接收计划订单，判断计划订单的状态如果大于2则退出。新增计划订单状态为0未确认
	/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdRecFormNC(L3RECORDSET rsPlan);


	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// 关闭计划订单2009-04-19 tangyi
	/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
	/// </Method>
	L3BOOL EndPlanOrder(L3RECORDSET rsPlan);
};
