// 逻辑类CEnergyHistoryData头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEnergyHistoryData :
	public CL3Object
{
public:
	CEnergyHistoryData(void);
	virtual ~CEnergyHistoryData(void);

	DECLARE_L3CLASS(CEnergyHistoryData,XGMESLogic\\EnergyMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyHistoryData)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEnergyHistoryData" name="TagName" type="L3STRING">
	/// 标签名
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyHistoryData" name="TagType" type="L3LONG">
	/// 标签类型:1-压力;2:流量;3:消耗
	/// </Property>
	DECLARE_L3PROP_LONG(TagType)

	/// <Property class="CEnergyHistoryData" name="Consume" type="L3DOUBLE">
	/// 标签值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TagValue)

	/// <Property class="CEnergyHistoryData" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};
