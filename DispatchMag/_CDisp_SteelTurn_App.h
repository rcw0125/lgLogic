// 逻辑类CDisp_SteelTurn_App头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_SteelTurn_App :
	public CL3Object
{
public:
	CDisp_SteelTurn_App(void);
	virtual ~CDisp_SteelTurn_App(void);

	DECLARE_L3CLASS(CDisp_SteelTurn_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelTurn_App)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelTurn_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelTurn_App" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelTurn_App" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelTurn_App" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelTurn_App" name="App_Time" type="L3DATETIME">
	/// 申请时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelTurn_App" name="App_UnitID" type="L3DATETIME">
	/// 申请工序
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)


	/// <Property class="CDisp_SteelTurn_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// 申请钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelTurn_App" name="App_Operator" type="L3STRING">
	/// 申请人
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelTurn_App" name="App_Reason" type="L3STRING">
	/// 申请原因
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Time" type="L3DATETIME">
	/// 回炉时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Turn_Time)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Operator" type="L3STRING">
	/// 回炉人
	/// </Property>
	DECLARE_L3PROP_STRING(Turn_Operator)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Flag" type="L3LONG">
	/// 回炉标志，0：未回炉，1：回炉
	/// </Property>
	DECLARE_L3PROP_LONG(Turn_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="All_Turn_Flag" type="L3LONG">
	/// 全回炉标志，0：不是全回炉，1：全回炉
	/// </Property>
	DECLARE_L3PROP_LONG(All_Turn_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="NC_Confirm_Flag" type="L3LONG">
	/// NC确认标志
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDisp_SteelTurn_App" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_STRING(Team)

};
