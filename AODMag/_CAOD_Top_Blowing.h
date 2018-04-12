// 逻辑类CAOD_Top_Blowing头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Top_Blowing :
	public CL3Object
{
public:
	CAOD_Top_Blowing(void);
	virtual ~CAOD_Top_Blowing(void);

	DECLARE_L3CLASS(CAOD_Top_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Top_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Top_Blowing" name="HeatID" type="L3STRING">
	/// 炉号
	DECLARE_L3PROP_STRING(TreatNo)
	DECLARE_L3PROP_STRING(HeatID)

	
	DECLARE_L3PROP_FLOAT(Position)
	DECLARE_L3PROP_SHORT(Air_Type)
	DECLARE_L3PROP_FLOAT(Air_Flow)
	DECLARE_L3PROP_FLOAT(Air_Pressure)
	DECLARE_L3PROP_SHORT(Inwater_Temp)
	DECLARE_L3PROP_FLOAT(Inwater_Flow)
	DECLARE_L3PROP_SHORT(Outwater_Temp)
	DECLARE_L3PROP_FLOAT(Outwater_Flow)
	DECLARE_L3PROP_DATETIME(Catch_Time)
};
