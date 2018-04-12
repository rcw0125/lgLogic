// 逻辑类CAOD_Bottom_Blowing头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Bottom_Blowing :
	public CL3Object
{
public:
	CAOD_Bottom_Blowing(void);
	virtual ~CAOD_Bottom_Blowing(void);

	DECLARE_L3CLASS(CAOD_Bottom_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Bottom_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Bottom_Blowing" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow1" type="L3DOUBLE">
	/// 流量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow1)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure1" type="L3DOUBLE">
	/// 压力1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure1)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow2" type="L3DOUBLE">
	/// 流量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow2)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure2" type="L3DOUBLE">
	/// 压力2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure2)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow3" type="L3DOUBLE">
	/// 流量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow3)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure3" type="L3DOUBLE">
	/// 压力3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure3)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow4" type="L3DOUBLE">
	/// 流量4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow4)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure4" type="L3DOUBLE">
	/// 压力4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure4)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow5" type="L3DOUBLE">
	/// 流量5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow5)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure5" type="L3DOUBLE">
	/// 压力5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure5)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow6" type="L3DOUBLE">
	/// 流量6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow6)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure6" type="L3DOUBLE">
	/// 压力6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure6)

	/// <Property class="CAOD_Bottom_Blowing" name="Gas_Type" type="L3STRING">
	/// 
	/// 介质(N2;Ar)
	/// </Property>
	DECLARE_L3PROP_STRING(Gas_Type)

	/// <Property class="CAOD_Bottom_Blowing" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CAOD_Bottom_Blowing" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

};
