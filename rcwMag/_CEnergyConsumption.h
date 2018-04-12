// 逻辑类CEnergyConsumption头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEnergyConsumption :
	public CL3Object
{
public:
	CEnergyConsumption(void);
	virtual ~CEnergyConsumption(void);

	DECLARE_L3CLASS(CEnergyConsumption,XGMESLogic\\EnergyMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyConsumption)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEnergyConsumption" name="ObjectID" type="L3STRING">
	/// 对象标识
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CEnergyConsumption" name="ProductionDate" type="L3STRING">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate) //按 yyyyMMdd 格式存储

	/// <Property class="CEnergyConsumption" name="TagName" type="L3STRING">
	/// 标签名
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyConsumption" name="TagValue" type="L3DOUBLE">
	/// 表数据
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TagValue)

	/// <Property class="CEnergyConsumption" name="DayValue" type="L3DOUBLE">
	/// 当日数据
	/// </Property>
	DECLARE_L3PROP_DOUBLE(DayValue)

	/// <Property class="CEnergyConsumption" name="MonthValue" type="L3DOUBLE">
	/// 月累数据
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MonthValue)

	/// <Property class="CEnergyConsumption" name="CreateTime" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CEnergyConsumption" name="ModifyTime" type="L3DATETIME">
	/// 变更时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(ModifyTime)

	/// <Property class="CEnergyConsumption" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)
};
