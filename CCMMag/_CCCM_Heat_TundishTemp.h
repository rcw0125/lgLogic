// 逻辑类CCCM_Heat_TundishTemp头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_TundishTemp :
	public CL3Object
{
public:
	CCCM_Heat_TundishTemp(void);
	virtual ~CCCM_Heat_TundishTemp(void);

	DECLARE_L3CLASS(CCCM_Heat_TundishTemp,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_TundishTemp)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_TundishTemp" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_TundishTemp" name="CCMID" type="L3SHORT">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_TundishTemp" name="TempID" type="L3SHORT">
	/// 中包测温点
	/// </Property>
	DECLARE_L3PROP_SHORT(TempID)

	/// <Property class="CCCM_Heat_TundishTemp" name="Temp" type="L3SHORT">
	/// 测温值
	/// </Property>
	DECLARE_L3PROP_SHORT(Temp)

	/// <Property class="CCCM_Heat_TundishTemp" name="Measure_Time" type="L3DATETIME">
	/// 测温时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Measure_Time)

	/// <Property class="CCCM_Heat_TundishTemp" name="InValidFlag" type="L3SHORT">
	/// 无效(不参与统计)标志
	/// </Property>
	DECLARE_L3PROP_SHORT(InValidFlag)
};
