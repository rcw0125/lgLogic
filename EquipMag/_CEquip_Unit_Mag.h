// 逻辑类CEquip_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Unit_Mag :
	public CL3Object
{
public:
	CEquip_Unit_Mag(void);
	virtual ~CEquip_Unit_Mag(void);

	DECLARE_L3CLASS(CEquip_Unit_Mag,XGMESLogic\\EquipMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CEquip_Unit_Mag" name="NewCalibration" type="L3LONG">
	/// 新增校准基本信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="ModifyCalibration" type="L3LONG">
	/// 修改校准基本信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="DeleteCalibration" type="L3LONG">
	/// 删除校准基本信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="NewCalibrationDetail" type="L3LONG">
	/// 新增校准详细信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="ModifyCalibrationDetail" type="L3LONG">
	/// 修改校准详细信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="DeleteCalibrationDetail" type="L3LONG">
	/// 删除校准详细信息 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CBF_Iron_Mag" name="QueryCalibration" type="L3RECORDSET">
	/// 根据时间段查校准信息
	/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
	/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
	/// </Method>
	L3RECORDSET QueryCalibration(L3DATETIME timeFrom, L3DATETIME timeTo);

	/// <Method class="CBF_Iron_Mag" name="QueryCalibrationDetail" type="L3RECORDSET">
	/// 根据LogID查校准详细信息
	/// <Param name="strLogID" type="L3STRING">起始时间</Param>
	/// </Method>
	L3RECORDSET QueryCalibrationDetail(L3STRING strLogID);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptCleaningData" type="L3BOOL">
	/// 接收一级汽化冷却排污数据。
	/// <Param name="rsData" type="L3RECORDSET">排污数据</Param>
	/// </Method>
	L3BOOL AcceptCleaningData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptRuntimeData" type="L3BOOL">
	/// 接收一级汽化回收周期数据。
	/// <Param name="rsData" type="L3RECORDSET">周期数据</Param>
	/// </Method>
	L3BOOL AcceptRuntimeData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterData" type="L3BOOL">
	/// 接收一级汽化回收补水数据。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptSupplyWaterData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterEndData" type="L3BOOL">
	/// 接收一级汽化回收补水结束数据。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptSupplyWaterEndData(L3RECORDSET rsData);
};
