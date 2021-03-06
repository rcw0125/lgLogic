// 逻辑类CBOF_Equipment_Status头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Equipment_Status :
	public CL3Object
{
public:
	CBOF_Equipment_Status(void);
	virtual ~CBOF_Equipment_Status(void);

	DECLARE_L3CLASS(CBOF_Equipment_Status,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Equipment_Status)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Equipment_Status" name="BOFID" type="L3SHORT">
	/// 
	/// 转炉炉座号(1:BOF1
	///            2:BOF2
	///            3:BOF3
	///            4:BOF4)
	/// </Property>
	DECLARE_L3PROP_SHORT(BOFID)

	/// <Property class="CBOF_Equipment_Status" name="Status" type="L3SHORT">
	/// 
	/// 设备状态
	/// (1:正常
	///  2:检修
	///  3:套管
	///  4:护炉
	///  5:故障)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CBOF_Equipment_Status" name="Log_Time" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

	/// <Property class="CBOF_Equipment_Status" name="Reason" type="L3STRING">
	/// 原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)
};
