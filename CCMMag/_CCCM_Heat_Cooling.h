// 逻辑类CCCM_Heat_Cooling头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Cooling :
	public CL3Object
{
public:
	CCCM_Heat_Cooling(void);
	virtual ~CCCM_Heat_Cooling(void);

	DECLARE_L3CLASS(CCCM_Heat_Cooling,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Cooling)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Cooling" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Cooling" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Cooling" name="StrandID" type="L3SHORT">
	/// 结晶器流号(若流号为0表示总管数据)
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_Cooling" name="Flow" type="L3FLOAT">
	/// 流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CCCM_Heat_Cooling" name="Pressure" type="L3FLOAT">
	/// 压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CCCM_Heat_Cooling" name="Temp" type="L3FLOAT">
	/// 温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Temp)

};
