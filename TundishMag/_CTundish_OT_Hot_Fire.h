// 逻辑类CTundish_OT_Hot_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_OT_Hot_Fire :
	public CL3Object
{
public:
	CTundish_OT_Hot_Fire(void);
	virtual ~CTundish_OT_Hot_Fire(void);

	DECLARE_L3CLASS(CTundish_OT_Hot_Fire,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_OT_Hot_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();


	/// <Property class="CTundish_OT_Hot_Fire" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_OT_Hot_Fire" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Cast_ID" type="L3STRING">
	/// 去向
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_OT_Hot_Fire" name="VehicleID" type="L3STRING">
	/// 中包车号
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Adjust_Per" type="L3STRING">
	/// 调整人
	/// </Property>
	DECLARE_L3PROP_STRING(Adjust_Per)

	/// <Property class="CTundish_OT_Hot_Fire" name="Adjust_TeamID" type="L3STRING">
	/// 调整班组
	/// </Property>
	DECLARE_L3PROP_STRING(Adjust_TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Crane_TeamID" type="L3STRING">
	/// 吊包班组
	/// </Property>
	DECLARE_L3PROP_STRING(Crane_TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Move_Case" type="L3STRING">
	/// 调包情况
	/// </Property>
	DECLARE_L3PROP_STRING(Move_Case)

	/// <Property class="CTundish_OT_Hot_Fire" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_OT_Hot_Fire" name="First_Hyd_Pre" type="L3DOUBLE">
	/// 一流液压缸行程[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(First_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Second_Hyd_Pre" type="L3DOUBLE">
	/// 二流液压缸行程[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Second_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Third_Hyd_Pre" type="L3DOUBLE">
	/// 三流液压缸行程[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Third_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fourth_Hyd_Pre" type="L3DOUBLE">
	/// 四流液压缸行程[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fourth_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_Temp" type="L3DOUBLE">
	/// 烘烤温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fire_Temp)

	/// <Property class="CTundish_OT_Hot_Fire" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_OT_Hot_Fire" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};
