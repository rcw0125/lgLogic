// 逻辑类CDisp_Unit_ProcessTime头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_Unit_ProcessTime :
	public CL3Object
{
public:
	CDisp_Unit_ProcessTime(void);
	virtual ~CDisp_Unit_ProcessTime(void);

	DECLARE_L3CLASS(CDisp_Unit_ProcessTime,XGMESLogic\\DispatchMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Unit_ProcessTime)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_Unit_ProcessTime" name="ObjectID" type="L3STRING">
	/// 对象ID
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)//ObjectID=ProductDate+UnitID+Team+ProcessType

	/// <Property class="CDisp_Unit_ProcessTime" name="ProductDate" type="L3STRING">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_STRING(ProductDate)

	/// <Property class="CDisp_Unit_ProcessTime" name="UnitID" type="L3STRING">
	/// 机组
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Unit_ProcessTime" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Unit_ProcessTime" name="ProcessType" type="L3STRING">
	/// 作业类型
	/// </Property>
	DECLARE_L3PROP_STRING(ProcessType)

	/// <Property class="CDisp_Unit_ProcessTime" name="ProcessTime" type="L3LONG">
	/// 作业时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDisp_Unit_ProcessTime" name="CreateTime" type="L3DATETIME">
	/// 创建日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

};
