// 逻辑类CLadle_Use_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Use_Info :
	public CL3Object
{
public:
	CLadle_Use_Info(void);
	virtual ~CLadle_Use_Info(void);

	DECLARE_L3CLASS(CLadle_Use_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Use_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Use_Info" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Use_Info" name="Ladle_ID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_Use_Info" name="Use_Date" type="L3DATETIME">
	/// 使用日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Use_Date)

	/// <Property class="CLadle_Use_Info" name="Ladle_Age" type="L3SHORT">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_SHORT(Ladle_Age)

	/// <Property class="CLadle_Use_Info" name="Bof_ID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(Bof_ID)

	/// <Property class="CLadle_Use_Info" name="Steel_Grade" type="L3STRING">
	/// 钢种级别
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Use_Info" name="Seat_OK_Time" type="L3DATETIME">
	/// 座好包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Seat_OK_Time)

	/// <Property class="CLadle_Use_Info" name="Tap_Time" type="L3DATETIME">
	/// 出钢时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tap_Time)

	/// <Property class="CLadle_Use_Info" name="Irr_Time" type="L3DATETIME">
	/// 开浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Irr_Time)

	/// <Property class="CLadle_Use_Info" name="Off_Ladle_Time" type="L3DATETIME">
	/// 下包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Ladle_Time)

	/// <Property class="CLadle_Use_Info" name="Arrive_Time" type="L3DATETIME">
	/// 到上件时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Time)

	/// <Property class="CLadle_Use_Info" name="Complete_Time" type="L3DATETIME">
	/// 上好件时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Complete_Time)

	/// <Property class="CLadle_Use_Info" name="Fire_Time_Len" type="L3DOUBLE">
	/// 烘烤时长
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fire_Time_Len)

	/// <Property class="CLadle_Use_Info" name="Stop_Time_Len" type="L3DOUBLE">
	/// 停用时长
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stop_Time_Len)

	/// <Property class="CLadle_Use_Info" name="Ladle_Check" type="L3STRING">
	/// 钢包检查
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Check)

	/// <Property class="CLadle_Use_Info" name="Off_Reason" type="L3STRING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Reason)

	/// <Property class="CLadle_Use_Info" name="Sk_Board_Keep" type="L3STRING">
	/// 滑板连用
	/// </Property>
	DECLARE_L3PROP_STRING(Sk_Board_Keep)

	/// <Property class="CLadle_Use_Info" name="Ladle_Grade" type="L3STRING">
	/// 包况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CLadle_Use_Info" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Use_Info" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Use_Info" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Use_Info" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
