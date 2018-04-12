// 逻辑类CDutyDefinition头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDutyDefinition :
	public CL3Object
{
public:
	CDutyDefinition(void);
	virtual ~CDutyDefinition(void);

	DECLARE_L3CLASS(CDutyDefinition,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDutyDefinition)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDutyDefinition" name="UnitID" type="L3SHORT">
	/// 
	/// 工序(1:混铁炉
	///      2:转炉
	///      3:LF炉
	///      4:RH炉
	///      5:连铸)
	/// 
	/// </Property>
	DECLARE_L3PROP_SHORT(UnitID)

	/// <Property class="CDutyDefinition" name="PlantID" type="L3SHORT">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_SHORT(PlantID)

	/// <Property class="CDutyDefinition" name="TeamID" type="L3SHORT">
	/// 
	/// 班别
	/// (1:甲
	/// 2:乙
	/// 3:丙
	/// 4:丁)
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

	/// <Property class="CDutyDefinition" name="HeadFurnace" type="L3STRING">
	/// 炉长
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CDutyDefinition" name="Assistant" type="L3STRING">
	/// 一助手
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CDutyDefinition" name="SecondHand" type="L3STRING">
	/// 二助手
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

};
