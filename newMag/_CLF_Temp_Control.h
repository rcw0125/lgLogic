// 逻辑类CLF_Temp_Control头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_Temp_Control :
	public CL3Object
{
public:
	CLF_Temp_Control(void);
	virtual ~CLF_Temp_Control(void);

	DECLARE_L3CLASS(CLF_Temp_Control,XGMESLogic\\EnergyMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Temp_Control)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Temp_Control" name="ObjectID" type="L3STRING">
	/// 对象标识
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)
	DECLARE_L3PROP_STRING(Reasion) 
	DECLARE_L3PROP_STRING(FlagValue)
	DECLARE_L3PROP_DATETIME(CreateTime)
	DECLARE_L3PROP_STRING(Operator)
};
