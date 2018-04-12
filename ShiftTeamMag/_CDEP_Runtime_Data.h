// 逻辑类CDeS_Runtime_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDEP_Runtime_Data :
	public CL3Object
{
public:
	CDEP_Runtime_Data(void);
	virtual ~CDEP_Runtime_Data(void);

	DECLARE_L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDeS_Runtime_Data" name="UnitID" type="L3STRING">
	/// 脱硫工位
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)
	DECLARE_L3PROP_STRING(TreatNo)
	DECLARE_L3PROP_STRING(Materialid)
	DECLARE_L3PROP_DOUBLE(N_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Flow)
	DECLARE_L3PROP_DOUBLE(Lime_Rate)
	DECLARE_L3PROP_DOUBLE(O_Pressure)
	DECLARE_L3PROP_DOUBLE(O_Flow)
	DECLARE_L3PROP_DOUBLE(D_Value)
	DECLARE_L3PROP_LONG(Zhan_Temp)
	DECLARE_L3PROP_LONG(Ji_Temp)
	DECLARE_L3PROP_DATETIME(Catch_Time)
	
};
