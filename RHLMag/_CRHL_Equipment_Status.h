// 逻辑类CRHL_Equipment_Status头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CRHL_Equipment_Status :
	public CL3Object
{
public:
	CRHL_Equipment_Status(void);
	virtual ~CRHL_Equipment_Status(void);

	DECLARE_L3CLASS(CRHL_Equipment_Status,XGMESLogic\\RHLMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Equipment_Status)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CRHL_Equipment_Status" name="LFID" type="L3SHORT">
	/// 
	/// LF炉炉座号(1:LF1
	///            2:LF2
	///            3:LF3)
	/// </Property>
	DECLARE_L3PROP_SHORT(RHLID)

	/// <Property class="CRHL_Equipment_Status" name="Status" type="L3SHORT">
	/// 
	/// 设备状态
	/// (1:正常
	///  2:检修
	///  3:套管
	///  4:护炉
	///  5:故障)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CRHL_Equipment_Status" name="Log_Time" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

	/// <Property class="CRHL_Equipment_Status" name="Reason" type="L3STRING">
	/// 原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

};
