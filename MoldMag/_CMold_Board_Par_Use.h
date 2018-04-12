// 逻辑类CMold_Board_Par_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMold_Board_Par_Use :
	public CL3Object
{
public:
	CMold_Board_Par_Use(void);
	virtual ~CMold_Board_Par_Use(void);

	DECLARE_L3CLASS(CMold_Board_Par_Use,XGMESLogic\\MoldMag, InStallID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Board_Par_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMold_Board_Par_Use" name="Input_Time" type="L3DATETIME">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Board_Par_Use" name="MoldID" type="L3STRING">
	/// 结晶器编号
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Board_Par_Use" name="Copper_Fac" type="L3STRING">
	/// 铜板厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Board_Par_Use" name="Lug_Steel_Mea" type="L3DOUBLE">
	/// 铜板拉钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Lug_Steel_Mea)

	/// <Property class="CMold_Board_Par_Use" name="Inner_ID" type="L3STRING">
	/// 铜板内弧编号
	/// </Property>
	DECLARE_L3PROP_STRING(Inner_ID)

	/// <Property class="CMold_Board_Par_Use" name="Outer_ID" type="L3STRING">
	/// 铜板外弧编号
	/// </Property>
	DECLARE_L3PROP_STRING(Outer_ID)

	/// <Property class="CMold_Board_Par_Use" name="South_ID" type="L3STRING">
	/// 铜板南侧编号
	/// </Property>
	DECLARE_L3PROP_STRING(South_ID)

	/// <Property class="CMold_Board_Par_Use" name="North_ID" type="L3STRING">
	/// 铜板北侧编号
	/// </Property>
	DECLARE_L3PROP_STRING(North_ID)

	/// <Property class="CMold_Board_Par_Use" name="Cur_Use_Count" type="L3LONG">
	/// 当班使用次数
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Use_Count)

	/// <Property class="CMold_Board_Par_Use" name="Total_Use_Count" type="L3LONG">
	/// 使用次数累计
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Use_Count)

	/// <Property class="CMold_Board_Par_Use" name="Cur_Pull_Mea" type="L3DOUBLE">
	/// 当班拉钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cur_Pull_Mea)

	/// <Property class="CMold_Board_Par_Use" name="Total_Pull_Mea" type="L3DOUBLE">
	/// 拉钢量累计
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Pull_Mea)

	/// <Property class="CMold_Board_Par_Use" name="Cast_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CMold_Board_Par_Use" name="FlowID" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(FlowID)

	/// <Property class="CMold_Board_Par_Use" name="OnLine_Flag" type="L3LONG">
	/// 上线标志
	/// </Property>
	DECLARE_L3PROP_LONG(OnLine_Flag)

	/// <Property class="CMold_Board_Par_Use" name="OnLine_Time" type="L3DATETIME">
	/// 上线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(OnLine_Time)
	
	/// <Property class="CMold_Board_Par_Use" name="Stop_Reason" type="L3STRING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Reason)

	/// <Property class="CMold_Board_Par_Use" name="OffLine_Flag" type="L3LONG">
	/// 下线标志
	/// </Property>
	DECLARE_L3PROP_LONG(OffLine_Flag)

	/// <Property class="CMold_Board_Par_Use" name="OffLine_Time" type="L3DATETIME">
	/// 下线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(OffLine_Time)

	/// <Property class="CMold_Board_Par_Use" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Board_Par_Use" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Board_Par_Use" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Board_Par_Use" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Board_Par_Use" name="InStallID" type="L3STRING">
	/// 装配编号
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
	
	/// <Property class="CMold_Board_Par_Use" name="ConfirmFlag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(ConfirmFlag)

};
