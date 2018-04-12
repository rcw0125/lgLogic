// 逻辑类CEquip_SupplyWater_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_SupplyWater_Data :
	public CL3Object
{
public:
	CEquip_SupplyWater_Data(void);
	virtual ~CEquip_SupplyWater_Data(void);

	DECLARE_L3CLASS(CEquip_SupplyWater_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_SupplyWater_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_SupplyWater_Data" name="UnitID" type="L3STRING">
	/// 炉座
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CEquip_SupplyWater_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_Boil" type="L3FLOAT">
	/// 汽包水位
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_Boil)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Boil" type="L3FLOAT">
	/// 汽包压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Boil)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Pump_SupplyWater" type="L3FLOAT">
	/// 给水泵压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Pump_SupplyWater)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Pump_SoftWater" type="L3FLOAT">
	/// 软水泵压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Pump_SoftWater)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_DeO2Box" type="L3FLOAT">
	/// 除氧器水箱水位
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_DeO2Box)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_SoftWaterBox" type="L3FLOAT">
	/// 软水箱水位
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_SoftWaterBox)

	/// <Property class="CEquip_SupplyWater_Data" name="P_MainPipe_Steam" type="L3FLOAT">
	/// 总蒸汽管压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_MainPipe_Steam)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Start" type="L3DATETIME">
	/// 补水开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Start)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Stop" type="L3DATETIME">
	/// 补水结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Stop)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Blow" type="L3DATETIME">
	/// 开吹时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Blow)

	/// <Property class="CEquip_SupplyWater_Data" name="EndFla" type="L3SHORT">
	/// 结束标志
	/// </Property>
	DECLARE_L3PROP_SHORT(EndFlag)

	/// <Property class="CEquip_SupplyWater_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CEquip_SupplyWater_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CEquip_SupplyWater_Data" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};
