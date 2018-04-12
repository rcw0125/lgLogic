// 逻辑类CDeS_Addition_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Addition_Data :
	public CL3Object
{
public:
	CDeS_Addition_Data(void);
	virtual ~CDeS_Addition_Data(void);

	DECLARE_L3CLASS(CDeS_Addition_Data,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDeS_Addition_Data" name="UnitID" type="L3STRING">
	/// 脱硫工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDeS_Addition_Data" name="Mat_Code" type="L3STRING">
	/// 脱硫剂代码
	/// </Property>
	DECLARE_L3PROP_STRING(Mat_Code)

	/// <Property class="CDeS_Addition_Data" name="Mat_Vendor" type="L3STRING">
	/// 脱硫剂厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Mat_Vendor)

	/// <Property class="CDeS_Addition_Data" name="Weight" type="L3FLOAT">
	/// 加料量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CDeS_Addition_Data" name="Time_Discharge" type="L3DATETIME">
	/// 加料时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Discharge)

	/// <Property class="CDeS_Addition_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Addition_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDeS_Addition_Data" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CDeS_Addition_Data" name="Time_Begin_Discharge" type="L3DATETIME">
	/// 加料开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Begin_Discharge)

	/// <Property class="CDeS_Addition_Data" name="Time_Stop_Discharge" type="L3DATETIME">
	/// 加料结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Stop_Discharge)
};
