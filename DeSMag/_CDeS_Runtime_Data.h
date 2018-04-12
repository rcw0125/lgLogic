// 逻辑类CDeS_Runtime_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Runtime_Data :
	public CL3Object
{
public:
	CDeS_Runtime_Data(void);
	virtual ~CDeS_Runtime_Data(void);

	DECLARE_L3CLASS(CDeS_Runtime_Data,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();
	/// <Property class="CDeS_Process_Data" name="ID_Object" type="L3STRING">
	/// 对象标识
	/// (铁次+罐号+喷吹号)
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CDeS_Process_Data" name="TreatNo" type="L3STRING">
	/// 喷吹号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Process_Data" name="Pressure" type="L3DOUBLE">
	/// 主吹压力(MPa)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CDeS_Process_Data" name="Flow" type="L3DOUBLE">
	/// 主吹流量(Nm3/h)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CDeS_Process_Data" name="Rate" type="L3DOUBLE">
	/// 速率(kg/min)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Rate)

	/// <Property class="CDeS_Process_Data" name="Catch_Count" type="L3LONG">
	/// 采集次数
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_Count)

	/// <Property class="CDeS_Process_Data" name="Catch_Time" type="L3LONG">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)
};
