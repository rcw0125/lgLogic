// 逻辑类CEnergy_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

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

class CEnergy_Unit_Mag :
	public CL3Object
{
public:
	CEnergy_Unit_Mag(void);
	virtual ~CEnergy_Unit_Mag(void);

	DECLARE_L3CLASS(CEnergy_Unit_Mag,XGMESLogic\\EnergyMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergy_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyFlowData" type="L3BOOL">
	/// 接收一级能源流量检测数据。
	/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
	/// </Method>
	L3BOOL AcceptEnergyFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyPressureData" type="L3BOOL">
	/// 接收一级能源压力检测数据。
	/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
	/// </Method>
	L3BOOL AcceptEnergyPressureData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyConsumeData" type="L3BOOL">
	/// 接收一级能源消耗检测数据。
	/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
	/// </Method>
	L3BOOL AcceptEnergyConsumeData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendGasFlowData" type="L3BOOL">
	/// 接收一级烘烤趋势煤气流量检测数据。
	/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
	/// </Method>
	L3BOOL AcceptTrendGasFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendAirFlowData" type="L3BOOL">
	/// 接收一级烘烤趋势空气流量检测数据。
	/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
	/// </Method>
	L3BOOL AcceptTrendAirFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="GetDayValue" type="L3BOOL">
	///  获取当日能耗
	/// <Param name="cscurday" type="CString">当天</Param>
	/// <Param name="csTagName" type="CString">标签点</Param>
	/// <Param name="fieldValue" type="L3FLOAT">现场数据</Param>
	/// <Param name="dayValue" type="L3FLOAT">当日数据</Param>
	/// <Param name="monthValue" type="L3FLOAT">月累数据</Param>
	/// </Method>
	L3BOOL CalculateValue(  CString cscurday,
							CString csTagName,
							L3FLOAT fieldValue,
							L3FLOAT & dayValue,
							L3FLOAT & monthValue);
	/// <Method class="CEnergy_Unit_Mag" name="NewConsumption" type="L3BOOL">
	/// 手工新增消耗数据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL NewConsumption(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="UpdateConsumption" type="L3BOOL">
	/// 手工修改消耗数据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateConsumption(L3RECORDSET rsData);
	L3BOOL UpdateAODHeatid();

	/// <Method class="CBF_Iron_Mag" name="QueryConsumptionInfo" type="L3RECORDSET">
	/// 根据时间段和去向查旬能源消耗信息
	/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
	/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
	/// </Method>
	L3RECORDSET QueryConsumptionInfo(L3DATETIME timeFrom, L3DATETIME timeTo);
	L3LONG TappingPlanGen(L3RECORDSET rsCastingPlan);
	L3LONG NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex);
	private:
	L3LONG GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,L3LONG nHeatCount,CString csSteelGradeIndex,L3DOUBLE fWeight,L3SHORT nBOFFlag);
	L3LONG CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime);
	L3LONG CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight);
};
