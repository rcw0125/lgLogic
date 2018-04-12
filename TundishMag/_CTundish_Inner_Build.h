// 逻辑类CTundish_Inner_Build头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Inner_Build :
	public CL3Object
{
public:
	CTundish_Inner_Build(void);
	virtual ~CTundish_Inner_Build(void);

	DECLARE_L3CLASS(CTundish_Inner_Build,XGMESLogic\\TundishMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Inner_Build)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_Inner_Build" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Inner_Build" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Inner_Build" name="Inner_Use_Count" type="L3SHORT">
	/// 永久层使用次数
	/// </Property>
	DECLARE_L3PROP_SHORT(Inner_Use_Count)

	/// <Property class="CTundish_Inner_Build" name="Tie_Start_Time" type="L3DATETIME">
	/// 开始打结时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_Start_Time)

	/// <Property class="CTundish_Inner_Build" name="Tie_End_Time" type="L3DATETIME">
	/// 结束打结时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_End_Time)

	/// <Property class="CTundish_Inner_Build" name="Refra_Fac" type="L3STRING">
	/// 耐材产地
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CTundish_Inner_Build" name="Refra_ID" type="L3STRING">
	/// 耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)

	/// <Property class="CTundish_Inner_Build" name="Waste" type="L3DOUBLE">
	/// 消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waste)

	/// <Property class="CTundish_Inner_Build" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Inner_Build" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Inner_Build" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Inner_Build" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Inner_Build" name="Check_Date" type="L3DATETIME">
	/// 检查日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	
	/// <Property class="CTundish_Inner_Build" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	

};
