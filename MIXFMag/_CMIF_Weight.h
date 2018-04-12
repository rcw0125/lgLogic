// 逻辑类CMIF_Weight头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMIF_Weight :
	public CL3Object
{
public:
	CMIF_Weight(void);
	virtual ~CMIF_Weight(void);

	DECLARE_L3CLASS(CMIF_Weight,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Weight)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMIF_Weight" name="Weight" type="L3DOUBLE">
	/// 称重数据
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CMIF_Weight" name="Weight_Time" type="L3DATETIME">
	/// 称重时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Weight_Time)

	/// <Property class="CMIF_Weight" name="Source" type="L3STRING">
	/// 
	/// 来源
	/// (1:1#MIF
	///  2:2#MIF
	///  0:直兑地磅)
	/// </Property>
	DECLARE_L3PROP_STRING(Source)

	/// <Property class="CMIF_Weight" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CMIF_Weight" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

};
