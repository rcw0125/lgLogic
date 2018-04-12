// 逻辑类CCalibration_Set头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCalibration_Set :
	public CL3Object
{
public:
	CCalibration_Set(void);
	virtual ~CCalibration_Set(void);

	DECLARE_L3CLASS(CCalibration_Set,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Set)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Set" name="Location" type="L3STRING">
	/// 处所
	/// </Property>
	DECLARE_L3PROP_STRING(Location)

	/// <Property class="CCalibration_Set" name="Location_Des" type="L3STRING">
	/// 处所描述
	/// </Property>
	DECLARE_L3PROP_STRING(Location_Des)

	/// <Property class="CCalibration_Set" name="Meter" type="L3STRING">
	/// 仪表名称
	/// </Property>
	DECLARE_L3PROP_STRING(Meter)

	/// <Property class="CCalibration_Set" name="Meter_Size" type="L3STRING">
	/// 仪表型号
	/// </Property>
	DECLARE_L3PROP_STRING(Meter_Size)

	/// <Property class="CCalibration_Set" name="Range" type="L3STRING">
	/// 测量范围
	/// </Property>
	DECLARE_L3PROP_STRING(Range)

	/// <Property class="CCalibration_Set" name="Precision" type="L3STRING">
	/// 准确度
	/// </Property>
	DECLARE_L3PROP_STRING(Precision)

	/// <Property class="CCalibration_Set" name="Factory" type="L3STRING">
	/// 厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCalibration_Set" name="Measure_ID" type="L3STRING">
	/// 计量编号
	/// </Property>
	DECLARE_L3PROP_STRING(Measure_ID)

	/// <Property class="CCalibration_Set" name="Standard_Equ" type="L3STRING">
	/// 标准器
	/// </Property>
	DECLARE_L3PROP_STRING(Standard_Equ)

	/// <Property class="CCalibration_Set" name="Scale_Min" type="L3STRING">
	/// 最小分度值
	/// </Property>
	DECLARE_L3PROP_STRING(Scale_Min)

};
