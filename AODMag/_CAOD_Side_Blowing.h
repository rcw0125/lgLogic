// 逻辑类CAOD_Side_Blowing头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Side_Blowing :
	public CL3Object
{
public:
	CAOD_Side_Blowing(void);
	virtual ~CAOD_Side_Blowing(void);

	DECLARE_L3CLASS(CAOD_Side_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Side_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING(Treatno)
	DECLARE_L3PROP_STRING(HeatID)
	DECLARE_L3PROP_SHORT(Type)
	DECLARE_L3PROP_FLOAT(Flow)
	DECLARE_L3PROP_FLOAT(Pressure)
	DECLARE_L3PROP_SHORT(Type2)
	DECLARE_L3PROP_FLOAT(Flow2)
	DECLARE_L3PROP_FLOAT(Pressure2)

	/// <Property class="CAOD_Side_Blowing" name="Pressure" type="L3FLOAT">
	/// 主管压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Press_MainPipe)
};
