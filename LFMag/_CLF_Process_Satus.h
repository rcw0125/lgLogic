// 逻辑类CLF_Process_Satus头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_Process_Satus :
	public CL3Object
{
public:
	CLF_Process_Satus(void);
	virtual ~CLF_Process_Satus(void);

	DECLARE_L3CLASS(CLF_Process_Satus,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Process_Satus)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Process_Satus" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Process_Satus" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Process_Satus" name="Status" type="L3SHORT">
	/// 
	/// 状态(1:到站;
	///          2:处理开始;
	///          3:加热;
	///          4:软吹;
	///          5:处理结束)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CLF_Process_Satus" name="Change_Time" type="L3DATETIME">
	/// 状态变化时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};
