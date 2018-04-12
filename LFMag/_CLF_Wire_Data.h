// 逻辑类CLF_Wire_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_Wire_Data :
	public CL3Object
{
public:
	CLF_Wire_Data(void);
	virtual ~CLF_Wire_Data(void);

	DECLARE_L3CLASS(CLF_Wire_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Wire_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Wire_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Wire_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Wire_Data" name="WireCode" type="L3STRING">
	/// 喂线代码
	/// </Property>
	DECLARE_L3PROP_STRING(WireCode)

	/// <Property class="CLF_Wire_Data" name="Weight" type="L3FLOAT">
	/// 喂线量[长度]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CLF_Wire_Data" name="Speed" type="L3FLOAT">
	/// 喂线速度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Speed)

	/// <Property class="CLF_Wire_Data" name="WireTime" type="L3DATETIME">
	/// 喂线时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(WireTime)

	/// <Property class="CLF_Wire_Data" name="Batch_Code" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CLF_Wire_Data" name="Vendor" type="L3STRING">
	/// 厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Vendor)

	/// <Property class="CLF_Wire_Data" name="Amount" type="L3FLOAT">
	/// 喂线量[重量]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Amount)
};
