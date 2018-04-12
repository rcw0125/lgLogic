// 逻辑类CMIF_Communicator头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMIF_Communicator :
	public CL3Object
{
public:
	CMIF_Communicator(void);
	virtual ~CMIF_Communicator(void);

	DECLARE_L3CLASS(CMIF_Communicator,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CMIF_Communicator" name="OnMIFTemperature" type="L3BOOL">
	/// 混铁炉温度数据到达事件相应函数
	/// <Param name="rsTemp" type="L3RECORDSET">温度数据(炉座号,温度值,测温时刻)</Param>
	/// </Method>
	L3BOOL OnMIFTemperature(L3RECORDSET rsTemp);
	/// <Method class="CMIF_Communicator" name="OnWeight" type="L3BOOL">
	/// 称重事件到达处理函数
	/// <Param name="rsWeight" type="L3RECORDSET">称重数据</Param>
	/// </Method>
	L3BOOL OnWeight(L3RECORDSET rsWeight);
};
