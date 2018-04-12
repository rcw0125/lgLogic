// 逻辑类CAOD_Top_Blowing头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Top_Blowing :
	public CL3Object
{
public:
	CAOD_Top_Blowing(void);
	virtual ~CAOD_Top_Blowing(void);

	DECLARE_L3CLASS(CAOD_Top_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Top_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Top_Blowing" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Top_Blowing" name="Flow" type="L3FLOAT">
	/// 流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CAOD_Top_Blowing" name="Pressure" type="L3FLOAT">
	/// 压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CAOD_Top_Blowing" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CAOD_Top_Blowing" name="Flow" type="L3FLOAT">
	/// 主管流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_MainPipe)

	/// <Property class="CAOD_Top_Blowing" name="Pressure" type="L3FLOAT">
	/// 主管压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Press_MainPipe)
};
