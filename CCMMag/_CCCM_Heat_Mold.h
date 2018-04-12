// 逻辑类CCCM_Heat_Mold头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Mold :
	public CL3Object
{
public:
	CCCM_Heat_Mold(void);
	virtual ~CCCM_Heat_Mold(void);

	DECLARE_L3CLASS(CCCM_Heat_Mold,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Mold)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Mold" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Mold" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Mold" name="StrandID" type="L3SHORT">
	/// 结晶器流号
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_Mold" name="Flow" type="L3FLOAT">
	/// 结晶器水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CCCM_Heat_Mold" name="Wide_Flow" type="L3FLOAT">
	/// 结晶器宽面水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wide_Flow)

	/// <Property class="CCCM_Heat_Mold" name="Narrow_Flow" type="L3FLOAT">
	/// 结晶器窄面水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Narrow_Flow)

	/// <Property class="CCCM_Heat_Mold" name="In_Temp" type="L3SHORT">
	/// 结晶器进水温度
	/// </Property>
	DECLARE_L3PROP_SHORT(In_Temp)

	/// <Property class="CCCM_Heat_Mold" name="Out_Temp" type="L3SHORT">
	/// 结晶器出水温度
	/// </Property>
	DECLARE_L3PROP_SHORT(Out_Temp)

	/// <Property class="CCCM_Heat_Mold" name="Diff_Temp" type="L3SHORT">
	/// 结晶器水温差
	/// </Property>
	DECLARE_L3PROP_SHORT(Diff_Temp)

};
