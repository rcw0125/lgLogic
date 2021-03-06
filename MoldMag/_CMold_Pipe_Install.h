// 逻辑类CMold_Pipe_Install头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMold_Pipe_Install :
	public CL3Object
{
public:
	CMold_Pipe_Install(void);
	virtual ~CMold_Pipe_Install(void);

	DECLARE_L3CLASS(CMold_Pipe_Install,XGMESLogic\\MoldMag, InStallID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Pipe_Install)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMold_Pipe_Install" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Pipe_Install" name="Install_Date" type="L3DATETIME">
	/// 安装日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Date)

	/// <Property class="CMold_Pipe_Install" name="MoldID" type="L3STRING">
	/// 结晶器编号
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Pipe_Install" name="Hit_Press_Flag" type="L3LONG">
	/// 打压是否合格
	/// </Property>
	DECLARE_L3PROP_LONG(Hit_Press_Flag)

	/// <Property class="CMold_Pipe_Install" name="Copper_ID" type="L3STRING">
	/// 铜管编号
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CMold_Pipe_Install" name="Copper_Fac" type="L3STRING">
	/// 铜管厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Pipe_Install" name="Install_Per" type="L3STRING">
	/// 装配人
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CMold_Pipe_Install" name="Repair_Start_Time" type="L3DATETIME">
	/// 维修开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_Start_Time)

	/// <Property class="CMold_Pipe_Install" name="Repair_End_Time" type="L3DATETIME">
	/// 维修结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_End_Time)

	/// <Property class="CMold_Pipe_Install" name="Repair_Content" type="L3STRING">
	/// 维修内容
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Content)

	/// <Property class="CMold_Pipe_Install" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Pipe_Install" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Pipe_Install" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Pipe_Install" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Pipe_Install" name="InStallID" type="L3STRING">
	/// 装配编号
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
	
	/// <Property class="CMold_Pipe_Install" name="ConfirmFlag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(ConfirmFlag)

};
