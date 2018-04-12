// 逻辑类CTap_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTap_Process_Data :
	public CL3Object
{
public:
	CTap_Process_Data(void);
	virtual ~CTap_Process_Data(void);

	DECLARE_L3CLASS(CTap_Process_Data,XGMESLogic\\TapSideMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTap_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Process_Data" name="Temp_Before_BlowAr" type="L3LONG">
	/// 氩前温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Before_BlowAr)

	/// <Property class="CTap_Process_Data" name="O2_Before_BlowAr" type="L3FLOAT">
	/// 氩前氧含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_Before_BlowAr)

	/// <Property class="CTap_Process_Data" name="Temp_BlownAr" type="L3LONG">
	/// 氩后温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_BlownAr)

	/// <Property class="CTap_Process_Data" name="O2_BlownAr" type="L3FLOAT">
	/// 氩后氧含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_BlownAr)

	/// <Property class="CTap_Process_Data" name="Blow_Mode" type="L3SHORT">
	/// 顶吹/底吹
	/// </Property>
	DECLARE_L3PROP_SHORT(Blow_Mode)

	/// <Property class="CTap_Process_Data" name="Tune_Flag" type="L3SHORT">
	/// 
	/// 是否调温
	/// 0-否
	/// 1-是
	/// </Property>
	DECLARE_L3PROP_SHORT(Tune_Flag)

	/// <Property class="CTap_Process_Data" name="BlowAr_Time" type="L3LONG">
	/// 吹氩时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowAr_Time)

	/// <Property class="CTap_Process_Data" name="Start_Time" type="L3DATETIME">
	/// 处理开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CTap_Process_Data" name="End_Time" type="L3DATETIME">
	/// 处理结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CTap_Process_Data" name="Cold_Mat_Cunsume" type="L3FLOAT">
	/// 调温加料量[kg]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cold_Mat_Cunsume)

};
