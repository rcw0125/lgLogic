// 逻辑类CAOD_Process_Status头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Process_Status :
	public CL3Object
{
public:
	CAOD_Process_Status(void);
	virtual ~CAOD_Process_Status(void);

	DECLARE_L3CLASS(CAOD_Process_Status,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Process_Status)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Process_Status" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Process_Status" name="Status" type="L3SHORT">
	/// 
	/// 状态(1:加废钢兑铁;
	///          2:主吹;
	///          3:补吹;
	///          4:出钢开始;
	///          5:出钢结束;
	///          6:溅渣开始;
	///          7:溅渣结束;
	///          8:倒渣开始;
	///          0:倒渣结束[等待])
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)
	DECLARE_L3PROP_SHORT(Step)

	/// <Property class="CAOD_Process_Status" name="Change_Time" type="L3DATETIME">
	/// 状态变化时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};
