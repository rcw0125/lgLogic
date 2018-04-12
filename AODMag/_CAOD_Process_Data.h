// 逻辑类CAOD_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Process_Data :
	public CL3Object
{
public:
	CAOD_Process_Data(void);
	virtual ~CAOD_Process_Data(void);

	DECLARE_L3CLASS(CAOD_Process_Data,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Process_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CAOD_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// 到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CAOD_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// 进站温度
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CAOD_Process_Data" name="Start_Time" type="L3DATETIME">
	/// 处理开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Start_Time)
    DECLARE_L3PROP_DATETIME(Blow_Start_Time)
	DECLARE_L3PROP_DATETIME(C_Start_Time)
	DECLARE_L3PROP_DATETIME(C_End_Time)
	DECLARE_L3PROP_DATETIME(Tapping_Start_Time)
	DECLARE_L3PROP_DATETIME(Tapping_End_Time)
	DECLARE_L3PROP_DATETIME(Side_Start_Time)
	DECLARE_L3PROP_DATETIME(Side_End_Time)
	DECLARE_L3PROP_LONG(C_Time)
	DECLARE_L3PROP_LONG(Tapping_Time)
	DECLARE_L3PROP_LONG(Smelt_Period)
	DECLARE_L3PROP_DOUBLE(O_Consume)
	DECLARE_L3PROP_DOUBLE(N_Consume)
	DECLARE_L3PROP_DOUBLE(Ar_Consume)
	DECLARE_L3PROP_LONG(Steel_Temp)
	DECLARE_L3PROP_LONG(Sheet_Temp)
	DECLARE_L3PROP_LONG(Return_Temp)
	DECLARE_L3PROP_LONG(Ladle_Temp)
	DECLARE_L3PROP_DOUBLE(Tapping_Weight)
	DECLARE_L3PROP_LONG(Lance_No)
	DECLARE_L3PROP_LONG(Furnace_No)
	DECLARE_L3PROP_LONG(Furnace_Age)
	DECLARE_L3PROP_STRING(LadleNo)
	DECLARE_L3PROP_STRING(Ladle_Status)
	DECLARE_L3PROP_STRING(Ladle_Grade)

};
