// 逻辑类CCCM_Casting_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Casting_Data :
	public CL3Object
{
public:
	CCCM_Casting_Data(void);
	virtual ~CCCM_Casting_Data(void);

	DECLARE_L3CLASS(CCCM_Casting_Data,XGMESLogic\\CCMMag, CastingNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Casting_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Casting_Data" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Casting_Data" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Casting_Data" name="Casting_Start_Time" type="L3DATETIME">
	/// 浇次开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Casting_Data" name="Casting_Stop_Time" type="L3DATETIME">
	/// 浇次结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)

	/// <Property class="CCCM_Casting_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CCCM_Casting_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CCCM_Casting_Data" name="First_HeatID" type="L3STRING">
	/// 浇次第一炉
	/// </Property>
	DECLARE_L3PROP_STRING(First_HeatID)

	/// <Property class="CCCM_Casting_Data" name="Last_HeatID" type="L3STRING">
	/// 浇次最后一炉
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

	/// <Property class="CCCM_Casting_Data" name="HeatCount" type="L3LONG">
	/// 当前浇次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(HeatCount)

};
