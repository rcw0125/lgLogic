// 逻辑类CTundish_Inner_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Inner_Fire :
	public CL3Object
{
public:
	CTundish_Inner_Fire(void);
	virtual ~CTundish_Inner_Fire(void);

	DECLARE_L3CLASS(CTundish_Inner_Fire,XGMESLogic\\TundishMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Inner_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_Inner_Fire" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Inner_Fire" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Inner_Fire" name="Small_Fire_Time" type="L3DATETIME">
	/// 小火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Small_Fire_Operator" type="L3STRING">
	/// 小火操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Small_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Mid_Fire_Time" type="L3DATETIME">
	/// 中火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Mid_Fire_Operator" type="L3STRING">
	/// 中火操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Mid_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Big_Fire_Time" type="L3DATETIME">
	/// 大火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Big_Fire_Operator" type="L3STRING">
	/// 大火操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Big_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Close_Fire_Time" type="L3DATETIME">
	/// 停火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Close_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Close_Fire_Operator" type="L3STRING">
	/// 停火操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Close_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Inner_Fire" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Inner_Fire" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Inner_Fire" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Inner_Fire" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};
