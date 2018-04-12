// 逻辑类CRHL_Base_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CRHL_Base_Data :
	public CL3Object
{
public:
	CRHL_Base_Data(void);
	virtual ~CRHL_Base_Data(void);

	DECLARE_L3CLASS(CRHL_Base_Data,XGMESLogic\\RHLMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CRHL_Base_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CRHL_Base_Data" name="HeatID" type="L3STRING">
	///炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)


	/// <Property class="CRHL_Base_Data" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CRHL_Base_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CRHL_Base_Data" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CRHL_Base_Data" name="LadleNo" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CRHL_Base_Data" name="HeadFurnace" type="L3STRING">
	/// 炉长
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CRHL_Base_Data" name="Assistant" type="L3STRING">
	/// 一助手
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CRHL_Base_Data" name="SecondHand" type="L3STRING">
	/// 二助手
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

	/// <Property class="CRHL_Base_Data" name="ProductionDate" type="L3DATETIME">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CRHL_Base_Data" name="Locked" type="L3SHORT">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)

	/// <Property class="CRHL_Base_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CRHL_Base_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CRHL_Base_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NC确认标志
	/// </Property>
	///2009-02-25



};
