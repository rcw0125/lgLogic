// 逻辑类ShiftTeamOrder头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CShiftTeamOrder :
	public CL3Object
{
public:
	CShiftTeamOrder(void);
	virtual ~CShiftTeamOrder(void);

	DECLARE_L3CLASS(CShiftTeamOrder,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CShiftTeamOrder)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CShiftTeamOrder" name="L3Index" type="L3SHORT">
	/// 主键
	/// </Property>
	DECLARE_L3PROP_SHORT(L3Index)

	/// <Property class="CShiftTeamOrder" name="ShiftType" type="L3STRING">
	/// 换班类型
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftType)

	/// <Property class="CShiftTeamOrder" name="OrderIndex" type="L3SHORT">
	/// 索引
	/// </Property>
	DECLARE_L3PROP_SHORT(OrderIndex)

	/// <Property class="CShiftTeamOrder" name="ShiftID" type="L3SHORT">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_SHORT(ShiftID)

	/// <Property class="CShiftTeamOrder" name="TeamID" type="L3SHORT">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

};
