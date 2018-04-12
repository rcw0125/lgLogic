// 逻辑类CBOF_MainPipe_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_MainPipe_Data :
	public CL3Object
{
public:
	CBOF_MainPipe_Data(void);
	virtual ~CBOF_MainPipe_Data(void);

	DECLARE_L3CLASS(CBOF_MainPipe_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_MainPipe_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_MainPipe_Data" name="Flow" type="L3FLOAT">
	/// 流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CBOF_MainPipe_Data" name="Pressure" type="L3FLOAT">
	/// 压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CBOF_MainPipe_Data" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};
