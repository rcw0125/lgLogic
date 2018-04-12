// 逻辑类CLadle_Com_Lad_Rep头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Com_Lad_Rep :
	public CL3Object
{
public:
	CLadle_Com_Lad_Rep(void);
	virtual ~CLadle_Com_Lad_Rep(void);

	DECLARE_L3CLASS(CLadle_Com_Lad_Rep,XGMESLogic\\LadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Com_Lad_Rep)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Com_Lad_Rep" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="RepID" type="L3LONG">
	/// 编号
	/// </Property>
	DECLARE_L3PROP_LONG(RepID)

	/// <Property class="CLadle_Com_Lad_Rep" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Water_gap_Bri_Fac" type="L3STRING">
	/// 水口座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// 水口座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Breathe_Bri_Fac" type="L3STRING">
	/// 透气座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// 透气座砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Cast_Fac" type="L3STRING">
	/// 浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Cast_Wast" type="L3DOUBLE">
	/// 浇注料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="Rep_Ladle_Operator" type="L3STRING">
	/// 修包操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Operator)

	/// <Property class="CLadle_Com_Lad_Rep" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Com_Lad_Rep" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Com_Lad_Rep" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Com_Lad_Rep" name="Rep_Date" type="L3DATETIME">
	/// 修补日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rep_Date)

	/// <Property class="CLadle_Com_Lad_Rep" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Com_Lad_Rep" name="Object_ID" type="L3STRING">
	/// 主键[WorkID + RepID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
