// 逻辑类CCalibration_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCalibration_Log :
	public CL3Object
{
public:
	CCalibration_Log(void);
	virtual ~CCalibration_Log(void);

	DECLARE_L3CLASS(CCalibration_Log,XGMESLogic\\EquipMag, LogID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Log" name="Location" type="L3STRING">
	/// 对象标识=处所+日期
	/// </Property>
	DECLARE_L3PROP_STRING(LogID)

	/// <Property class="CCalibration_Log" name="Location" type="L3STRING">
	/// 处所
	/// </Property>
	DECLARE_L3PROP_STRING(Location)

	/// <Property class="CCalibration_Log" name="Location_Des" type="L3STRING">
	/// 处所描述
	/// </Property>
	DECLARE_L3PROP_STRING(Location_Des)

	/// <Property class="CCalibration_Log" name="Meter" type="L3STRING">
	/// 仪表名称
	/// </Property>
	DECLARE_L3PROP_STRING(Meter)

	/// <Property class="CCalibration_Log" name="Meter_Size" type="L3STRING">
	/// 仪表型号
	/// </Property>
	DECLARE_L3PROP_STRING(Meter_Size)

	/// <Property class="CCalibration_Log" name="Range" type="L3STRING">
	/// 测量范围
	/// </Property>
	DECLARE_L3PROP_STRING(Range)

	/// <Property class="CCalibration_Log" name="Precision" type="L3STRING">
	/// 准确度
	/// </Property>
	DECLARE_L3PROP_STRING(Precision)

	/// <Property class="CCalibration_Log" name="Factory" type="L3STRING">
	/// 厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCalibration_Log" name="Measure_ID" type="L3STRING">
	/// 计量编号
	/// </Property>
	DECLARE_L3PROP_STRING(Measure_ID)

	/// <Property class="CCalibration_Log" name="Standard_Equ" type="L3STRING">
	/// 标准器
	/// </Property>
	DECLARE_L3PROP_STRING(Standard_Equ)

	/// <Property class="CCalibration_Log" name="Scale_Min" type="L3STRING">
	/// 最小分度值
	/// </Property>
	DECLARE_L3PROP_STRING(Scale_Min)

	/// <Property class="CCalibration_Log" name="Check_Date" type="L3DATETIME">
	/// 校准日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CCalibration_Log" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CCalibration_Log" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CCalibration_Log" name="Auditing_Time" type="L3DATETIME">
	/// 审核时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Auditing_Time)

	/// <Property class="CCalibration_Log" name="Assessor" type="L3STRING">
	/// 审核人
	/// </Property>
	DECLARE_L3PROP_STRING(Assessor)

	/// <Property class="CCalibration_Log" name="Result" type="L3STRING">
	/// 校验结论
	/// </Property>
	DECLARE_L3PROP_STRING(Result)

	/// <Property class="CCalibration_Log" name="Status" type="L3LONG">
	/// 状态 0-未审核　1-已审核
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

};
