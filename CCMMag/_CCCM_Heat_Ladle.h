// 逻辑类CCCM_Heat_Ladle头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Ladle :
	public CL3Object
{
public:
	CCCM_Heat_Ladle(void);
	virtual ~CCCM_Heat_Ladle(void);

	DECLARE_L3CLASS(CCCM_Heat_Ladle,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Ladle)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 添加是否自动下流、 非自动下流原因

	/// <Property class="CCCM_Heat_Ladle" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Ladle" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Ladle" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Ladle" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CCCM_Heat_Ladle" name="Weight" type="L3FLOAT">
	/// 大包重量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_Ladle" name="RemainWeight" type="L3FLOAT">
	/// 大包剩余钢水量
	/// </Property>
	DECLARE_L3PROP_FLOAT(RemainWeight)

	/// <Property class="CCCM_Heat_Ladle" name="Arrival_Time" type="L3DATETIME">
	/// 大包到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CCCM_Heat_Ladle" name="LadleType" type="L3STRING">
	/// 钢包类别
	/// </Property>
	DECLARE_L3PROP_STRING(LadleType)

	/// <Property class="CCCM_Heat_Ladle" name="Departure_Time" type="L3DATETIME">
	/// 大包离开时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Departure_Time)

	/// <Property class="CCCM_Heat_Ladle" name="Casting_Start_Time" type="L3DATETIME">
	/// 大包开浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Heat_Ladle" name="Casting_Stop_Time" type="L3DATETIME">
	/// 大包停浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)

	/// <Property class="CCCM_Heat_Ladle" name="HoldTime" type="L3LONG">
	/// 等压钢时间
	/// </Property>
	DECLARE_L3PROP_LONG(HoldTime)

	/// <Property class="CCCM_Heat_Ladle" name="Temp" type="L3LONG">
	/// 上机温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CCCM_Heat_Ladle" name="TempUpTo" type="L3SHORT">
	/// 
	/// 温度是否合格
	/// (1-合格
	///  0-不合格)
	/// </Property>
	DECLARE_L3PROP_SHORT(TempUpTo)

	/// <Property class="CCCM_Heat_Ladle" name="HoldTime_Reason" type="L3STRING">
	/// 等压钢超时原因
	/// </Property>
	DECLARE_L3PROP_STRING(HoldTime_Reason)

	/// <Property class="CCCM_Heat_Ladle" name="Protection" type="L3SHORT">
	/// 
	/// 是否大包保护浇注
	/// (0-否
	///  1-是)
	/// </Property>
	DECLARE_L3PROP_SHORT(Protection)

	/// <Property class="CCCM_Heat_Ladle" name="UnProtection_Reason" type="L3STRING">
	/// 
	/// 未进行大包保护浇注原因
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(UnProtection_Reason)

	/// <Property class="CCCM_Heat_Ladle" name="UnProtection_Reason" type="L3LONG">
	/// 
	/// 是否自动下流
	/// 
	/// </Property>
	DECLARE_L3PROP_LONG(AutoFlow)

	/// <Property class="CCCM_Heat_Ladle" name="UnAutoFlow_Reason" type="L3STRING">
	/// 
	/// 非自动下流原因
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(UnAutoFlow_Reason)


	/// <Property class="CCCM_Heat_Ladle" name="CastingTundishWeight" type="L3FLOAT">
	/// 大包开浇时中包重量
	/// </Property>
	DECLARE_L3PROP_FLOAT(CastingTundishWeight)

};
