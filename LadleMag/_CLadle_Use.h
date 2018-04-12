// 逻辑类CLadle_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Use :
	public CL3Object
{
public:
	CLadle_Use(void);
	virtual ~CLadle_Use(void);

	DECLARE_L3CLASS(CLadle_Use,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Use" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Use" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Use" name="Use_Date" type="L3DATETIME">
	/// 使用日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Use_Date)

	/// <Property class="CLadle_Use" name="Ladle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLadle_Use" name="BOFID" type="L3STRING">
	/// 炉座
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CLadle_Use" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Use" name="Steel_Grade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Use" name="Seat_OK_Time" type="L3DATETIME">
	/// 座好包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Seat_OK_Time)

	/// <Property class="CLadle_Use" name="Tap_Time" type="L3DATETIME">
	/// 出钢时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tap_Time)

	/// <Property class="CLadle_Use" name="Irr_Start_Time" type="L3DATETIME">
	/// 开浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Irr_Start_Time)

	/// <Property class="CLadle_Use" name="Irr_End_Time" type="L3DATETIME">
	/// 停浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Irr_End_Time)

	/// <Property class="CLadle_Use" name="Off_Ladle_Time" type="L3DATETIME">
	/// 下包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Ladle_Time)

	/// <Property class="CLadle_Use" name="Arrive_Time" type="L3DATETIME">
	/// 到上件时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Time)

	/// <Property class="CLadle_Use" name="Complete_Time" type="L3DATETIME">
	/// 上好件时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Complete_Time)

	/// <Property class="CLadle_Use" name="Fire_Time_Len" type="L3DOUBLE">
	/// 烘烤时长
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fire_Time_Len)

	/// <Property class="CLadle_Use" name="Stop_Time_Len" type="L3DOUBLE">
	/// 停用时长
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stop_Time_Len)

	/// <Property class="CLadle_Use" name="Ladle_Check" type="L3STRING">
	/// 钢包检查(2011-03-17 by llj 此处主要用于包衬检查结果)
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Check)

	/// <Property class="CLadle_Use" name="Off_Reason" type="L3STRING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Reason)

	/// <Property class="CLadle_Use" name="Sk_Board_Keep" type="L3STRING">
	/// 滑板连用
	/// </Property>
	DECLARE_L3PROP_STRING(Sk_Board_Keep)

	/// <Property class="CLadle_Use" name="Ladle_Grade" type="L3STRING">
	/// 包况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CLadle_Use" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Use" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Use" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Use" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Use" name="Hot_Time" type="L3DATETIME">
	/// 去烘烤时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Hot_Time)

	/// <Property class="CLadle_Use" name="Frame" type="L3LONG">
	/// 框架
	/// </Property>
	DECLARE_L3PROP_LONG(Frame)

	/// <Property class="CLadle_Use" name="Splint" type="L3LONG">
	/// 托板
	/// </Property>
	DECLARE_L3PROP_LONG(Splint)

	/// <Property class="CLadle_Use" name="SpringBox" type="L3LONG">
	/// 簧盒
	/// </Property>
	DECLARE_L3PROP_LONG(SpringBox)

	/// <Property class="CLadle_Use" name="Joint" type="L3LONG">
	/// 关节
	/// </Property>
	DECLARE_L3PROP_LONG(Joint)

	/// <Property class="CLadle_Use" name="Joint_Safety_Pin" type="L3LONG">
	/// 关节保险销
	/// </Property>
	DECLARE_L3PROP_LONG(Joint_Safety_Pin)

	/// <Property class="CLadle_Use" name="Long_Axes" type="L3LONG">
	/// 长轴
	/// </Property>
	DECLARE_L3PROP_LONG(Long_Axes)

	/// <Property class="CLadle_Use" name="Short_Axes" type="L3LONG">
	/// 短轴
	/// </Property>
	DECLARE_L3PROP_LONG(Short_Axes)

	/// <Property class="CLadle_Use" name="Chassis" type="L3LONG">
	/// 底盘
	/// </Property>
	DECLARE_L3PROP_LONG(Chassis)

	/// <Property class="CLadle_Use" name="Protect_Board" type="L3LONG">
	/// 护板
	/// </Property>
	DECLARE_L3PROP_LONG(Protect_Board)

	/// <Property class="CLadle_Use" name="Up_Tighten_Machine" type="L3LONG">
	/// 顶紧器
	/// </Property>
	DECLARE_L3PROP_LONG(Up_Tighten_Machine)

	/// <Property class="CLadle_Use" name="Breathe_Bri_Up" type="L3LONG">
	/// 透气砖上
	/// </Property>
	DECLARE_L3PROP_LONG(Breathe_Bri_Up)

	/// <Property class="CLadle_Use" name="Breathe_Bri_Low" type="L3LONG">
	/// 透气砖下
	/// </Property>
	DECLARE_L3PROP_LONG(Breathe_Bri_Low)

	/// <Property class="CLadle_Use" name="Water_Gap" type="L3LONG">
	/// 上水口
	/// </Property>
	DECLARE_L3PROP_LONG(Water_Gap)
	
	/// <Property class="CLadle_Use" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Use" name="NewLadleFirst" type="L3LONG">
	/// 新包第1炉
	/// </Property>
	DECLARE_L3PROP_LONG(NewLadleFirst)

	/// <Property class="CLadle_Use" name="NewLadleSecond" type="L3LONG">
	/// 新包第2炉
	/// </Property>
	DECLARE_L3PROP_LONG(NewLadleSecond)

	/// <Property class="CLadle_Use" name="FireLadleFirst" type="L3LONG">
	/// 烘烤包第1炉
	/// </Property>
	DECLARE_L3PROP_LONG(FireLadleFirst)

	/// <Property class="CLadle_Use" name="FireLadleSecond" type="L3LONG">
	/// 烘烤包第2炉
	/// </Property>
	DECLARE_L3PROP_LONG(FireLadleSecond)

	/// <Property class="CLadle_Use" name="ReturnLadle" type="L3LONG">
	/// 回炉钢包
	/// </Property>
	DECLARE_L3PROP_LONG(ReturnLadle)

	/// <Property class="CLadle_Use" name="HookEdgeLadle" type="L3LONG">
	/// 钩包沿钢包
	/// </Property>
	DECLARE_L3PROP_LONG(HookEdgeLadle)

	/// <Property class="CLadle_Use" name="RemnantLadle" type="L3LONG">
	/// 有包底钢包
	/// </Property>
	DECLARE_L3PROP_LONG(RemnantLadle)

	/// <Property class="CLadle_Use" name="RemnantWT" type="L3DOUBLE">
	/// 包底重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(RemnantWT)

	/// <Property class="CLadle_Use" name="ComFlag" type="L3LONG">
	/// 完成标志
	/// </Property>
	DECLARE_L3PROP_LONG(ComFlag)


	/// <Property class="CLadle_Use" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)


	/// <Property class="CLadle_Use" name="Act_Ladle_Grade" type="L3STRING">
	/// 实际包况
	/// </Property>
	DECLARE_L3PROP_STRING(Act_Ladle_Grade)

	/// <Property class="CLadle_Use" name="Ladle_Check1" type="L3STRING">
	/// 钢包内部检查(2011-03-17 by llj 此处主要用于内部检查结果)
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Check1)


};
