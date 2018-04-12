// 逻辑类CTap_Oxygen_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTap_Oxygen_Data :
	public CL3Object
{
public:
	CTap_Oxygen_Data(void);
	virtual ~CTap_Oxygen_Data(void);

	DECLARE_L3CLASS(CTap_Oxygen_Data,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Oxygen_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTap_Oxygen_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Oxygen_Data" name="Oxygen_Content" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Oxygen_Content)

	/// <Property class="CTap_Oxygen_Data" name="MeasureTime" type="L3DATETIME">
	/// 定氧时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(MeasureTime)

	/// <Property class="CTap_Oxygen_Data" name="Temp" type="L3LONG">
	/// 测温值
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)
};
