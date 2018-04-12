// 逻辑类CDutyDefinition头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDuty_Definition :
	public CL3Object
{
public:
	CDuty_Definition(void);
	virtual ~CDuty_Definition(void);

	DECLARE_L3CLASS(CDuty_Definition,XGMESLogic\\BOFMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDuty_Definition)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDuty_Definition" name="ObjectID" type="L3STRING">
	/// 主键
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDuty_Definition" name="UnitID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)


	/// <Property class="CDuty_Definition" name="Team" type="L3STRING">
	/// 
	/// 班别
	/// (1:甲
	/// 2:乙
	/// 3:丙
	/// 4:丁)
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDuty_Definition" name="HeadFurnace" type="L3STRING">
	/// 炉长
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CDuty_Definition" name="Assistant" type="L3STRING">
	/// 一助手
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CDuty_Definition" name="SecondHand" type="L3STRING">
	/// 二助手
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

};
