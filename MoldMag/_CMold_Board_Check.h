// 逻辑类CMold_Board_Check头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMold_Board_Check :
	public CL3Object
{
public:
	CMold_Board_Check(void);
	virtual ~CMold_Board_Check(void);

	DECLARE_L3CLASS(CMold_Board_Check,XGMESLogic\\MoldMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Board_Check)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMold_Board_Check" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Board_Check" name="Install_Date" type="L3DATETIME">
	/// 安装日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Date)

	/// <Property class="CMold_Board_Check" name="Check_Date" type="L3DATETIME">
	/// 检测日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CMold_Board_Check" name="MoldID" type="L3STRING">
	/// 结晶器编号
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Board_Check" name="Hit_Press_Flag" type="L3LONG">
	/// 打压是否合格
	/// </Property>
	DECLARE_L3PROP_LONG(Hit_Press_Flag)

	/// <Property class="CMold_Board_Check" name="Copper_Fac" type="L3STRING">
	/// 铜板厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Board_Check" name="Repair_Fac" type="L3STRING">
	/// 铜板修复厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Fac)

	/// <Property class="CMold_Board_Check" name="Rep_Count" type="L3LONG">
	/// 铜板修复次数
	/// </Property>
	DECLARE_L3PROP_LONG(Rep_Count)

	/// <Property class="CMold_Board_Check" name="Inner_ID" type="L3STRING">
	/// 铜板内弧编号
	/// </Property>
	DECLARE_L3PROP_STRING(Inner_ID)

	/// <Property class="CMold_Board_Check" name="Outer_ID" type="L3STRING">
	/// 铜板外弧编号
	/// </Property>
	DECLARE_L3PROP_STRING(Outer_ID)

	/// <Property class="CMold_Board_Check" name="South_ID" type="L3STRING">
	/// 铜板南侧编号
	/// </Property>
	DECLARE_L3PROP_STRING(South_ID)

	/// <Property class="CMold_Board_Check" name="North_ID" type="L3STRING">
	/// 铜板北侧编号
	/// </Property>
	DECLARE_L3PROP_STRING(North_ID)

	/// <Property class="CMold_Board_Check" name="Lug_Steel_Mea" type="L3FLOAT">
	/// 铜板拉钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Lug_Steel_Mea)

	/// <Property class="CMold_Board_Check" name="Install_Per" type="L3STRING">
	/// 装配人
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Two_Fir" type="L3FLOAT">
	/// 宽面距上口200mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Fir)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Two_Sec" type="L3FLOAT">
	/// 宽面距上口200mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Sec)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Two_Thi" type="L3FLOAT">
	/// 宽面距上口200mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Thi)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Three_Fir" type="L3FLOAT">
	/// 宽面距上口300mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Fir)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Three_Sec" type="L3FLOAT">
	/// 宽面距上口300mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Sec)

	/// <Property class="CMold_Board_Check" name="Wide_Up_Three_Thi" type="L3FLOAT">
	/// 宽面距上口300mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Thi)

	/// <Property class="CMold_Board_Check" name="Wide_Down_Eight_Fir" type="L3FLOAT">
	/// 宽面距下口80mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Fir)

	/// <Property class="CMold_Board_Check" name="Wide_Down_Eight_Sec" type="L3FLOAT">
	/// 宽面距下口80mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Sec)

	/// <Property class="CMold_Board_Check" name="Wide_Down_Eight_Thi" type="L3FLOAT">
	/// 宽面距下口80mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Thi)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Two_Fir" type="L3FLOAT">
	/// 窄面距上口200mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Fir)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Two_Sec" type="L3FLOAT">
	/// 窄面距上口200mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Sec)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Two_Thi" type="L3FLOAT">
	/// 窄面距上口200mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Thi)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Three_Fir" type="L3FLOAT">
	/// 窄面距上口300mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Fir)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Three_Sec" type="L3FLOAT">
	/// 窄面距上口300mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Sec)

	/// <Property class="CMold_Board_Check" name="Nar_Up_Three_Thi" type="L3FLOAT">
	/// 窄面距上口300mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Thi)

	/// <Property class="CMold_Board_Check" name="Nar_Down_Eight_Fir" type="L3FLOAT">
	/// 窄面距下口80mm点1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Fir)

	/// <Property class="CMold_Board_Check" name="Nar_Down_Eight_Sec" type="L3FLOAT">
	/// 窄面距下口80mm点2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Sec)

	/// <Property class="CMold_Board_Check" name="Nar_Down_Eight_Thi" type="L3FLOAT">
	/// 窄面距下口80mm点3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Thi)

	/// <Property class="CMold_Board_Check" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Board_Check" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Board_Check" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Board_Check" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Board_Check" name="InStallID" type="L3STRING">
	/// 装配编号
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
};
