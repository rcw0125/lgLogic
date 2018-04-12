// 逻辑类CDisp_SteelExchange_App头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_SteelExchange_App :
	public CL3Object
{
public:
	CDisp_SteelExchange_App(void);
	virtual ~CDisp_SteelExchange_App(void);

	DECLARE_L3CLASS(CDisp_SteelExchange_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelExchange_App)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelExchange_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelExchange_App" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelExchange_App" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelExchange_App" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelExchange_App" name="App_UnitID" type="L3STRING">
	/// 申请工序
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CDisp_SteelExchange_App" name="App_Time" type="L3DATETIME">
	/// 申请时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelExchange_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// 申请钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelExchange_App" name="App_Operator" type="L3STRING">
	/// 申请人
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelExchange_App" name="App_Reason" type="L3STRING">
	/// 申请原因
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Time" type="L3DATETIME">
	/// 改钢时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Ex_Time)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Operator" type="L3STRING">
	/// 改钢人
	/// </Property>
	DECLARE_L3PROP_STRING(Ex_Operator)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Flag" type="L3LONG">
	/// 改钢标志
	/// </Property>
	DECLARE_L3PROP_LONG(Ex_Flag)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_SteelGradeIndex" type="L3STRING">
	/// 最终炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Ex_SteelGradeIndex)

};
