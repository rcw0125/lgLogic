// 逻辑类CCCM_Heat_ElecStirring头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_ElecStirring :
	public CL3Object
{
public:
	CCCM_Heat_ElecStirring(void);
	virtual ~CCCM_Heat_ElecStirring(void);

	DECLARE_L3CLASS(CCCM_Heat_ElecStirring,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ElecStirring)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ElecStirring" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ElecStirring" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ElecStirring" name="StrandID" type="L3SHORT">
	/// 结晶器流号
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_ElecStirring" name="Stirring" type="L3SHORT">
	/// 电磁搅拌(0：无、1：有)
	/// </Property>
	DECLARE_L3PROP_SHORT(Stirring)

	/// <Property class="CCCM_Heat_ElecStirring" name="Current" type="L3FLOAT">
	/// 电流
	/// </Property>
	DECLARE_L3PROP_FLOAT(Current)

	/// <Property class="CCCM_Heat_ElecStirring" name="Frequency" type="L3FLOAT">
	/// 频率
	/// </Property>
	DECLARE_L3PROP_FLOAT(Frequency)

	/// <Property class="CCCM_Heat_ElecStirring" name="Mode" type="L3SHORT">
	/// 搅拌方式
	/// </Property>
	DECLARE_L3PROP_SHORT(Mode)

};
