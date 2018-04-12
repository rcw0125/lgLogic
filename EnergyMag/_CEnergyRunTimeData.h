// 逻辑类CEnergyRunTimeData头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEnergyRunTimeData :
	public CL3Object
{
public:
	CEnergyRunTimeData(void);
	virtual ~CEnergyRunTimeData(void);

	DECLARE_L3CLASS(CEnergyRunTimeData,XGMESLogic\\EnergyMag, TagName)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyRunTimeData)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEnergyRunTimeData" name="TagName" type="L3STRING">
	/// 标签名
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyRunTimeData" name="TagCode" type="L3STRING">
	/// 标签代码
	/// </Property>
	DECLARE_L3PROP_STRING(TagCode)

	/// <Property class="CEnergyRunTimeData" name="TagDesc" type="L3STRING">
	/// 标签描述
	/// </Property>
	DECLARE_L3PROP_STRING(TagDesc)

	/// <Property class="CEnergyRunTimeData" name="Pressure" type="L3DOUBLE">
	/// 压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CEnergyRunTimeData" name="Flow" type="L3DOUBLE">
	/// 流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CEnergyRunTimeData" name="P_Max" type="L3DOUBLE">
	/// 压力上限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Max)

	/// <Property class="CEnergyRunTimeData" name="P_Min" type="L3DOUBLE">
	/// 压力下限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Min)

	/// <Property class="CEnergyRunTimeData" name="P_High" type="L3DOUBLE">
	/// 压力高限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_High)

	/// <Property class="CEnergyRunTimeData" name="P_Low" type="L3DOUBLE">
	/// 压力低限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Low)

	/// <Property class="CEnergyRunTimeData" name="F_Max" type="L3DOUBLE">
	/// 流量上限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Max)

	/// <Property class="CEnergyRunTimeData" name="F_Min" type="L3DOUBLE">
	/// 流量下限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Min)

	/// <Property class="CEnergyRunTimeData" name="F_High" type="L3DOUBLE">
	/// 流量高限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_High)

	/// <Property class="CEnergyRunTimeData" name="F_Low" type="L3DOUBLE">
	/// 流量低限值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Low)

	/// <Property class="CEnergyRunTimeData" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CEnergyRunTimeData" name="Multiple" type="L3DOUBLE">
	/// 倍率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Multiple)

	/// <Property class="CEnergyRunTimeData" name="MeasuringRange" type="L3DOUBLE">
	/// 现场(消耗)仪表轮回值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MeasuringRange)
};
