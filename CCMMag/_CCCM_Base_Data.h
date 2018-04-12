// 逻辑类CCCM_Base_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Base_Data :
	public CL3Object
{
public:
	CCCM_Base_Data(void);
	virtual ~CCCM_Base_Data(void);

	DECLARE_L3CLASS(CCCM_Base_Data,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13删除浇次号、预定包次号,添加主控工、厚度、宽度、长度

	/// <Property class="CCCM_Base_Data" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Base_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Base_Data" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)


	/// <Property class="CCCM_Base_Data" name="HeatConfirm" type="L3SHORT">
	/// 
	/// 炉次确认标志
	/// (0--未炉次确认
	///  1--正常确认
	///  2--无坯确认)
	/// </Property>
	DECLARE_L3PROP_SHORT(HeatConfirm)

	/// <Property class="CCCM_Base_Data" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)


	/// <Property class="CCCM_Base_Data" name="Production_Date" type="L3DATETIME">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CCCM_Base_Data" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)


	/// <Property class="CCCM_Base_Data" name="LadleNo" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)


	/// <Property class="CCCM_Base_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Base_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CCCM_Base_Data" name="Plan_SteelGrade" type="L3STRING">
	/// 计划钢种
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_SteelGrade)

	/// <Property class="CCCM_Base_Data" name="HeadFurnace" type="L3STRING">
	/// 机长
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CCCM_Base_Data" name="Ladle_Operator" type="L3STRING">
	/// 大包工
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Operator)

	/// <Property class="CCCM_Base_Data" name="Control_Operator" type="L3STRING">
	/// 主控工
	/// </Property>
	DECLARE_L3PROP_STRING(Control_Operator)


	/// <Property class="CCCM_Base_Data" name="Cut_Operator" type="L3STRING">
	/// 出坯工
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Operator)

	/// <Property class="CCCM_Base_Data" name="Tundish_1ST_Officer" type="L3STRING">
	/// 1ST中包工
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_1ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_2ST_Officer" type="L3STRING">
	/// 2ST中包工
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_2ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_3ST_Officer" type="L3STRING">
	/// 3ST中包工
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_3ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_4ST_Officer" type="L3STRING">
	/// 4ST中包工
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_4ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CCCM_Base_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CCCM_Base_Data" name="Length" type="L3LONG">
	/// 定尺
	/// </Property>
	DECLARE_L3PROP_LONG(Length)


	/// <Property class="CCCM_Base_Data" name="Locked" type="L3SHORT">
	/// 
	/// 封存标志(0:未锁定
	///                  1:锁定[不允许数据变更])
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)


	/// <Property class="CCCM_Base_Data" name="Shift" type="L3SHORT">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CCCM_Base_Data" name="Team" type="L3SHORT">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)


	/// <Property class="CSteel_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NC确认标志
	/// </Property>
	///2009-02-22
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)


};
