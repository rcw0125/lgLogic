// 逻辑类CRHL_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CRHL_Process_Data :
	public CL3Object
{
public:
	CRHL_Process_Data(void);
	virtual ~CRHL_Process_Data(void);

	DECLARE_L3CLASS(CRHL_Process_Data,XGMESLogic\\RHLMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CRHL_Process_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CRHL_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRHL_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// 到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CRHL_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// 进站温度
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CRHL_Process_Data" name="Start_Time" type="L3DATETIME">
	/// 处理开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CRHL_Process_Data" name="End_Time" type="L3DATETIME">
	/// 结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CRHL_Process_Data" name="Process_Time" type="L3LONG">
	/// 处理时间(秒)
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Time)

	/// <Property class="CRHL_Process_Data" name="Heat_Time" type="L3LONG">
	/// 加热时间
	/// </Property>
	DECLARE_L3PROP_LONG(Heat_Time)

	/// <Property class="CRHL_Process_Data" name="Heat_Count" type="L3SHORT">
	/// 加热次数
	/// </Property>
	DECLARE_L3PROP_SHORT(Heat_Count)



/// 
	DECLARE_L3PROP_DOUBLE(Current_Position)
	DECLARE_L3PROP_DOUBLE(E_V)
	DECLARE_L3PROP_DOUBLE(E_A)
	DECLARE_L3PROP_DOUBLE(O_Pressure)
	DECLARE_L3PROP_DOUBLE(O_Flow)
	DECLARE_L3PROP_DOUBLE(Gas_Pressure)
	DECLARE_L3PROP_DOUBLE(Gas_Flow)
	DECLARE_L3PROP_DOUBLE(Gas_F_Flow)
	DECLARE_L3PROP_DOUBLE(Spray_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Flow)
	DECLARE_L3PROP_DOUBLE(Bodyin_Pressure)
	DECLARE_L3PROP_DOUBLE(Bodyin_Flow)
	DECLARE_L3PROP_DOUBLE(Bodyout_Pressure)
	DECLARE_L3PROP_DOUBLE(Bodyout_Flow)
	DECLARE_L3PROP_DOUBLE(Topin_Pressure)
	DECLARE_L3PROP_DOUBLE(Topin_Flow)
	DECLARE_L3PROP_DOUBLE(Wallin_Pressure)
	DECLARE_L3PROP_DOUBLE(Wallin_Flow)
	DECLARE_L3PROP_DOUBLE(Wallout_Pressure)
	DECLARE_L3PROP_DOUBLE(Wallout_Flow)
	DECLARE_L3PROP_DOUBLE(Coldin_Pressure)
	DECLARE_L3PROP_DOUBLE(Coldin_Flow)
	DECLARE_L3PROP_DOUBLE(Coldout_Pressure)
	DECLARE_L3PROP_DOUBLE(Coldout_Flow)
	DECLARE_L3PROP_DOUBLE(Angle)
	DECLARE_L3PROP_FLOAT(Steel_Weight)
	DECLARE_L3PROP_STRING(LadleNo)
	DECLARE_L3PROP_STRING(Ladle_Grade)
};
