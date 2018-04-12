// 逻辑类CCost_Standard_Rate头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCost_Standard_Rate :
	public CL3Object
{
public:
	CCost_Standard_Rate(void);
	virtual ~CCost_Standard_Rate(void);

	DECLARE_L3CLASS(CCost_Standard_Rate,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCost_Standard_Rate)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCost_Standard_Rate" name="Cost_Item" type="L3STRING">
	/// 成本项目
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Item)

	/// <Property class="CCost_Standard_Rate" name="Cost_Center" type="L3STRING">
	/// 成本中心
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Center)

	/// <Property class="CCost_Standard_Rate" name="Pro_type" type="L3STRING">
	/// 产品类
	/// </Property>
	DECLARE_L3PROP_STRING(Pro_type)

	/// <Property class="CCost_Standard_Rate" name="Standard_Cost" type="L3FLOAT">
	/// 标准费用
	/// </Property>
	DECLARE_L3PROP_FLOAT(Standard_Cost)

};
