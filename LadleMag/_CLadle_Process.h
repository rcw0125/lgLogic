// 逻辑类CLadle_Process头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Process :
	public CL3Object
{
public:
	CLadle_Process(void);
	virtual ~CLadle_Process(void);

	DECLARE_L3CLASS(CLadle_Process,XGMESLogic\\LadleMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Process)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Process" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)
	
	/// <Property class="CLadle_Process" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_Process" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Process" name="Online_Time" type="L3DATETIME">
	/// 钢包上线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Online_Time)

	/// <Property class="CLadle_Process" name="Online_HeatID" type="L3STRING">
	/// 上线炉号
	/// </Property>
	DECLARE_L3PROP_STRING(Online_HeatID)

	/// <Property class="CLadle_Process" name="Offline_Time" type="L3DATETIME">
	/// 钢包下线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Offline_Time)

	/// <Property class="CLadle_Process" name="Offline_HeatID" type="L3STRING">
	/// 下线炉号
	/// </Property>
	DECLARE_L3PROP_STRING(Offline_HeatID)

	/// <Property class="CLadle_Process" name="Comfirm_Flag" type="L3LONG">
	/// 甩包状态 0为未甩包，1为已甩包
	/// </Property>
	DECLARE_L3PROP_LONG(Comfirm_Flag)

	/// <Property class="CLadle_Process" name="Throw_Time" type="L3DATETIME">
	/// 甩包时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Throw_Time)

	/// <Property class="CLadle_Process" name="Ladle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

};
