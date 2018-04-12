// 逻辑类CMIF_Temp_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMIF_Temp_Data :
	public CL3Object
{
public:
	CMIF_Temp_Data(void);
	virtual ~CMIF_Temp_Data(void);

	DECLARE_L3CLASS(CMIF_Temp_Data,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Temp_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMIF_Temp_Data" name="MIFID" type="L3STRING">
	/// 混铁炉炉座
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Temp_Data" name="Temp" type="L3LONG">
	/// 温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CMIF_Temp_Data" name="Temp_Time" type="L3DATETIME">
	/// 测温时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Temp_Time)

	/// <Property class="CMIF_Temp_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CMIF_Temp_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

};
