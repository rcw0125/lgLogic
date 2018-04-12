// 逻辑类CLF_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_Process_Data :
	public CL3Object
{
public:
	CLF_Process_Data(void);
	virtual ~CLF_Process_Data(void);

	DECLARE_L3CLASS(CLF_Process_Data,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Process_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// 到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CLF_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// 进站温度
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CLF_Process_Data" name="Start_Time" type="L3DATETIME">
	/// 处理开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CLF_Process_Data" name="End_Time" type="L3DATETIME">
	/// 结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CLF_Process_Data" name="Process_Time" type="L3LONG">
	/// 处理时间(秒)
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Time)

	/// <Property class="CLF_Process_Data" name="Heat_Time" type="L3LONG">
	/// 加热时间
	/// </Property>
	DECLARE_L3PROP_LONG(Heat_Time)

	/// <Property class="CLF_Process_Data" name="Heat_Count" type="L3SHORT">
	/// 加热次数
	/// </Property>
	DECLARE_L3PROP_SHORT(Heat_Count)

	/// <Property class="CLF_Process_Data" name="Probe_Vonder" type="L3STRING">
	/// 
	/// 使用定氧探头厂家
	/// (贺利氏、北京、方舟)
	/// </Property>
	DECLARE_L3PROP_STRING(Probe_Vonder)

	/// <Property class="CLF_Process_Data" name="FeedWire_Temp" type="L3SHORT">
	/// 钙处理完毕温度
	/// </Property>
	DECLARE_L3PROP_SHORT(FeedWire_Temp)

	/// <Property class="CLF_Process_Data" name="Departure_Temp" type="L3SHORT">
	/// 离站温度
	/// </Property>
	DECLARE_L3PROP_SHORT(Departure_Temp)

	/// <Property class="CLF_Process_Data" name="SoftBlow_StartTime" type="L3DATETIME">
	/// 软吹开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(SoftBlow_StartTime)

	/// <Property class="CLF_Process_Data" name="SoftBlow_EndTime" type="L3DATETIME">
	/// 软吹结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(SoftBlow_EndTime)

	/// <Property class="CLF_Process_Data" name="SoftBlow_Time" type="L3LONG">
	/// 软吹时间
	/// </Property>
	DECLARE_L3PROP_LONG(SoftBlow_Time)

	/// <Property class="CLF_Process_Data" name="Lid_Life" type="L3SHORT">
	/// 炉盖寿命
	/// </Property>
	DECLARE_L3PROP_SHORT(Lid_Life)

	/// <Property class="CLF_Process_Data" name="HoldBack_Time" type="L3LONG">
	/// 等压钢时间
	/// </Property>
	DECLARE_L3PROP_LONG(HoldBack_Time)

	/// <Property class="CLF_Process_Data" name="Steel_Weight" type="L3FLOAT">
	/// 钢水量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Steel_Weight)

	/// <Property class="CLF_Process_Data" name="LadleNo" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CLF_Process_Data" name="CCM_Ladle_Weight" type="L3DOUBLE">
	/// LF出站时铸机大包重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CCM_Ladle_Weight)

	/// <Property class="CLF_Unit_Mag" name="PoleConsume" type="L3LONG">
	/// 电极消耗
	/// </Property>
	DECLARE_L3PROP_LONG(PoleConsume)

	/// <Property class="CLF_Process_Data" name="Pole_Vendor" type="L3STRING">
	/// 
	/// 电极厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Vendor)

	/// <Property class="CLF_Process_Data" name="Flow_BlowAr_Heat" type="L3DOUBLE">
	/// 加热时吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_Heat)

	/// <Property class="CLF_Process_Data" name="Flow_BlowAr_SoftBlow" type="L3DOUBLE">
	/// 软吹时吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_SoftBlow)
	
	//2009-03-30
	/// <Property class="CLF_Process_Data" name="Ladle_Grade" type="L3STRING">
	/// 钢包包况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

};
