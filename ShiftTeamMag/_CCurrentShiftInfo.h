// 逻辑类CurrentShiftInfo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCurrentShiftInfo :
	public CL3Object
{
public:
	CCurrentShiftInfo(void);
	virtual ~CCurrentShiftInfo(void);

	DECLARE_L3CLASS(CCurrentShiftInfo,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCurrentShiftInfo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCurrentShiftInfo" name="L3Index" type="L3STRING">
	/// 工序+工位
	/// </Property>
	DECLARE_L3PROP_STRING(L3Index)

	/// <Property class="CCurrentShiftInfo" name="ShiftType" type="L3STRING">
	/// 换班类型
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftType)

	/// <Property class="CCurrentShiftInfo" name="ShiftID" type="L3SHORT">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_SHORT(ShiftID)

	/// <Property class="CCurrentShiftInfo" name="TeamID" type="L3SHORT">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

	/// <Property class="CCurrentShiftInfo" name="UnitTypeID" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(UnitTypeID)

	/// <Property class="CCurrentShiftInfo" name="UnitID" type="L3STRING">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CCurrentShiftInfo" name="CurrentID" type="L3SHORT">
	/// 当前班次序号
	/// </Property>
	DECLARE_L3PROP_SHORT(CurrentID)

	/// <Property class="CCurrentShiftInfo" name="BeginProcessTime" type="L3DATETIME">
	/// 开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(BeginProcessTime)

	/// <Property class="CCurrentShiftInfo" name="EndProcessTime" type="L3DATETIME">
	/// 结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(EndProcessTime)

	/// <Property class="CCurrentShiftInfo" name="ShiftWarning" type="L3STRING">
	/// 警告标志
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftWarning)

};
