// 逻辑类CBOF_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Process_Data :
	public CL3Object
{
public:
	CBOF_Process_Data(void);
	virtual ~CBOF_Process_Data(void);

	DECLARE_L3CLASS(CBOF_Process_Data,XGMESLogic\\BOFMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Process_Data" name="Charging_Start_Time" type="L3DATETIME">
	/// 
	/// 装料时刻
	/// 
	/// </Property>
	DECLARE_L3PROP_DATETIME(Charging_Start_Time)

	/// <Property class="CBOF_Process_Data" name="Blow_Start_Time" type="DischargeTime">
	/// 开吹时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Blow_Start_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_Strat_Time" type="DischargeTime">
	/// 出钢开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tapping_Strat_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_End_Time" type="L3DATETIME">
	/// 出钢结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tapping_End_Time)

	/// <Property class="CBOF_Process_Data" name="BlowO2_Time" type="L3LONG">
	/// 供氧时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowO2_Time)

	/// <Property class="CBOF_Process_Data" name="ReBlow_Time" type="L3LONG">
	/// 补吹时间
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_Time" type="L3LONG">
	/// 出钢时间
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Time)

	/// <Property class="CBOF_Process_Data" name="Splashing_Time" type="L3LONG">
	/// 溅渣时间
	/// </Property>
	DECLARE_L3PROP_LONG(Splashing_Time)

	/// <Property class="CBOF_Process_Data" name="Smelt_Period" type="L3LONG">
	/// 冶炼周期
	/// </Property>
	DECLARE_L3PROP_LONG(Smelt_Period)

	/// <Property class="CBOF_Process_Data" name="Waiting_Time" type="L3LONG">
	/// 等节奏时间
	/// </Property>
	DECLARE_L3PROP_LONG(Waiting_Time)

	/// <Property class="CBOF_Process_Data" name="Lance_Age" type="L3LONG">
	/// 枪龄
	DECLARE_L3PROP_STRING(LanceNo)
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Age)

	/// <Property class="CBOF_Process_Data" name="Furnace_Age" type="L3LONG">
	/// 炉役
	/// </Property>
	DECLARE_L3PROP_LONG(Furnace_Age)

	/// <Property class="CBOF_Process_Data" name="ReBlow_Count" type="L3SHORT">
	/// 补吹次数
	/// </Property>
	DECLARE_L3PROP_SHORT(ReBlow_Count)

	/// <Property class="CBOF_Process_Data" name="LaC_Temp" type="L3LONG">
	/// 拉碳温度
	/// </Property>
	DECLARE_L3PROP_LONG(LaC_Temp)

	/// <Property class="CBOF_Process_Data" name="Tapping_Temp" type="L3LONG">
	/// 出钢温度
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Temp)

	/// <Property class="CBOF_Process_Data" name="Single_LaC" type="L3SHORT">
	/// 一次拉碳
	/// </Property>
	DECLARE_L3PROP_SHORT(Single_LaC)

	/// <Property class="CBOF_Process_Data" name="Tapping_Oxygen" type="L3FLOAT">
	/// 出钢氧含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tapping_Oxygen)

	/// <Property class="CBOF_Process_Data" name="LadleNo" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CBOF_Process_Data" name="Ladle_Status" type="L3STRING">
	/// 钢包状况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Status)

	/// <Property class="CBOF_Process_Data" name="Taphole_Life" type="L3LONG">
	/// 出钢口寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Taphole_Life)

	/// <Property class="CBOF_Process_Data" name="Tapping_Weight" type="L3FLOAT">
	/// 出钢量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tapping_Weight)

	/// <Property class="CBOF_Process_Data" name="Furnace_Line_Status" type="L3STRING">
	/// 炉衬及砖缝情况
	/// </Property>
	DECLARE_L3PROP_STRING(Furnace_Line_Status)

	/// <Property class="CBOF_Process_Data" name="Ladle_Grade" type="L3STRING">
	/// 包况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CBOF_Process_Data" name="Ladle_Stop" type="L3DOUBLE">
	/// 钢包停用时间
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Stop)

	/// <Property class="CBOF_Process_Data" name="ScrapStatus" type="L3STRING">
	/// 废钢检查
	/// </Property>
	DECLARE_L3PROP_STRING(ScrapStatus)
    
	//2010-01-07 sun
    /// <Property class="CBOF_Process_Data" name="Carpolite" type="L3FLOAT">
	/// 石子
	/// </Property>
	DECLARE_L3PROP_FLOAT(Carpolite)


	/// <Property class="CBOF_Process_Data" name="O2Total" type="L3FLOAT">
	/// 单炉氧气消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2Total)

	/// <Property class="CBOF_Process_Data" name="RemainSlag" type="L3STRING">
	/// 是否留渣
	/// </Property>
	DECLARE_L3PROP_STRING(RemainSlag)
};
