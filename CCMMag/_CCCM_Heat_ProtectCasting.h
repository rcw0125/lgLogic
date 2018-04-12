// 逻辑类CCCM_Heat_ProtectCasting头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_ProtectCasting :
	public CL3Object
{
public:
	CCCM_Heat_ProtectCasting(void);
	virtual ~CCCM_Heat_ProtectCasting(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectCasting,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectCasting)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ProtectCasting" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectCasting" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Start_Time" type="L3DATETIME">
	/// 保护浇注开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Stop_Time" type="L3DATETIME">
	/// 保护浇注结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Ar_Flow" type="L3FLOAT">
	/// 保护浇注氩气流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ar_Flow)

};
