// 逻辑类CLF_Heat_Gears头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_Heat_Gears :
	public CL3Object
{
public:
	CLF_Heat_Gears(void);
	virtual ~CLF_Heat_Gears(void);

	DECLARE_L3CLASS(CLF_Heat_Gears,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Heat_Gears)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Heat_Gears" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Heat_Gears" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Heat_Gears" name="Gears" type="L3LONG">
	/// 加热挡位
	/// </Property>
	DECLARE_L3PROP_LONG(Gears)

	/// <Property class="CLF_Heat_Gears" name="LogTime" type="L3DATETIME">
	/// 挡位变化记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)
};
