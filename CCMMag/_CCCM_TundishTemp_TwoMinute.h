// 逻辑类CCCM_TundishTemp_TwoMinute头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_TundishTemp_TwoMinute :
	public CL3Object
{
public:
	CCCM_TundishTemp_TwoMinute(void);
	virtual ~CCCM_TundishTemp_TwoMinute(void);

	DECLARE_L3CLASS(CCCM_TundishTemp_TwoMinute,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_TundishTemp_TwoMinute)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="Temp" type="L3FLOAT">
	/// 温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Temp)


	/// <Property class="CCCM_TundishTemp_TwoMinute" name="Measure_Time" type="L3DATETIME">
	/// 采集时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Measure_Time)

	

};
