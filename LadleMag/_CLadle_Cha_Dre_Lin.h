// 逻辑类CLadle_Cha_Dre_Lin头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Cha_Dre_Lin :
	public CL3Object
{
public:
	CLadle_Cha_Dre_Lin(void);
	virtual ~CLadle_Cha_Dre_Lin(void);

	DECLARE_L3CLASS(CLadle_Cha_Dre_Lin,XGMESLogic\\LadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Cha_Dre_Lin)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Cha_Dre_Lin" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="ChaID" type="L3LONG">
	/// 编号
	/// </Property>
	DECLARE_L3PROP_LONG(ChaID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Slag_Line_Time" type="L3DATETIME">
	/// 换渣线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cha_Slag_Line_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Water_gap_Bri_Fac" type="L3STRING">
	/// 水口座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// 水口座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Breathe_Bri_Fac" type="L3STRING">
	/// 透气座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// 透气座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Bot_Wall_Rep_Mat_Fac" type="L3STRING">
	/// 包底壁修补料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Bot_Wall_Rep_Mat_Wast" type="L3DOUBLE">
	/// 包底修补料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Spi_Cast_Fac" type="L3STRING">
	/// 尖晶石浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Spi_Cast_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Spi_Cast_Wast" type="L3DOUBLE">
	/// 尖晶石浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spi_Cast_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Dre_Lin_Per" type="L3STRING">
	/// 渣线砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Cha_Dre_Lin_Per)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Dre_Lin_Wast" type="L3DOUBLE">
	/// 渣线消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cha_Dre_Lin_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Seat_Bri_Installer" type="L3STRING">
	/// 座砖安装
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Buttom_Builder" type="L3STRING">
	/// 包底砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Buttom_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Wall_Builder" type="L3STRING">
	/// 包壁砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Rep_Ladle_Bot" type="L3STRING">
	/// 补包底
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Bot)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Thr_Ladle_Time" type="L3DATETIME">
	/// 甩包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Cha_Dre_Lin" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Object_ID" type="L3STRING">
	/// 主键[WorkID + ChaID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
