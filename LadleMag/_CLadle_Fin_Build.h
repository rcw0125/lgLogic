// 逻辑类CLadle_Fin_Build头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Fin_Build :
	public CL3Object
{
public:
	CLadle_Fin_Build(void);
	virtual ~CLadle_Fin_Build(void);

	DECLARE_L3CLASS(CLadle_Fin_Build,XGMESLogic\\LadleMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Fin_Build)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Fin_Build" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Fin_Build" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Fin_Build" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Fin_Build" name="Build_Start_Time" type="L3DATETIME">
	/// 砌筑开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_Fin_Build" name="Build_End_Time" type="L3DATETIME">
	/// 砌筑结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_Fin_Build" name="Water_Gap_Bri_Fac" type="L3STRING">
	/// 水口座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Water_Gap_Bri_Fac)

	/// <Property class="CLadle_Fin_Build" name="Water_Gap_Bri_Wast" type="L3DOUBLE">
	/// 水口座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_Gap_Bri_Wast)

	/// <Property class="CLadle_Fin_Build" name="Breathe_Bri_Fac" type="L3STRING">
	/// 透气座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Fin_Build" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// 透气座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bricklaying_Fac" type="L3STRING">
	/// 砌砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Bricklaying_Fac)

	/// <Property class="CLadle_Fin_Build" name="Bot_Pro_Refr_Name" type="L3STRING">
	/// 砌筑包底保护层耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Pro_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Bot_Pro_Refr_Wast" type="L3DOUBLE">
	/// 砌筑包底保护层耐材消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Pro_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bot_Woke_Refr_Name" type="L3STRING">
	/// 砌筑包底工作层耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Woke_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Bot_Woke_Refr_Wast" type="L3DOUBLE">
	/// 砌筑包底工作层耐材消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Woke_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Wall_Refr_Name" type="L3STRING">
	/// 砌筑包壁耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Wall_Refr_Wast" type="L3DOUBLE">
	/// 砌筑包壁耐材消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wall_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Slag_Line_Refe_Name" type="L3STRING">
	/// 砌筑渣线耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Slag_Line_Refe_Name)

	/// <Property class="CLadle_Fin_Build" name="Slag_Line_Refe_Wast" type="L3DOUBLE">
	/// 砌筑渣线耐材消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Slag_Line_Refe_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bot_Wall_Rep_Mat_Fac" type="L3STRING">
	/// 包底壁修补料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)

	/// <Property class="CLadle_Fin_Build" name="Bot_Wall_Rep_Mat_Wast" type="L3DOUBLE">
	/// 包底修补料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)

	/// <Property class="CLadle_Fin_Build" name="Spi_Cast_Fac" type="L3STRING">
	/// 尖晶石浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Spi_Cast_Fac)

	/// <Property class="CLadle_Fin_Build" name="Spi_Cast_Wast" type="L3DOUBLE">
	/// 尖晶石浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spi_Cast_Wast)

	/// <Property class="CLadle_Fin_Build" name="Ladle_Inner_Checker" type="L3STRING">
	/// 永久层检查
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Inner_Checker)

	/// <Property class="CLadle_Fin_Build" name="Ladle_Inner_Use_Count" type="L3LONG">
	/// 永久层使用次数
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_Fin_Build" name="Seat_Bri_Installer" type="L3STRING">
	/// 座砖安装
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Fin_Build" name="Buttom_Builder" type="L3STRING">
	/// 包底砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Buttom_Builder)

	/// <Property class="CLadle_Fin_Build" name="Wall_Builder" type="L3STRING">
	/// 包壁砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Builder)

	/// <Property class="CLadle_Fin_Build" name="Line_Refe_Builder" type="L3STRING">
	/// 渣线砌筑
	/// </Property>
	DECLARE_L3PROP_STRING(Line_Refe_Builder)

	/// <Property class="CLadle_Fin_Build" name="Rep_Ladle_Bot" type="L3STRING">
	/// 补包底
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Bot)

	/// <Property class="CLadle_Fin_Build" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Fin_Build" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Fin_Build" name="Thr_Ladle_Time" type="L3DATETIME">
	/// 甩包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Fin_Build" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Fin_Build" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Fin_Build" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Fin_Build" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Fin_Build" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)


};
