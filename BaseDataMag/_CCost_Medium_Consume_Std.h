// 逻辑类CCost_Medium_Consume_Standard头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCost_Medium_Consume_Std :
	public CL3Object
{
public:
	CCost_Medium_Consume_Std(void);
	virtual ~CCost_Medium_Consume_Std(void);

	DECLARE_L3CLASS(CCost_Medium_Consume_Std,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCost_Medium_Consume_Std)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCost_Medium_Consume_Std" name="Medium" type="L3STRING">
	/// 介质
	/// </Property>
	DECLARE_L3PROP_STRING(Medium)

	/// <Property class="CCost_Medium_Consume_Std" name="Cost_Center" type="L3STRING">
	/// 成本中心
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Center)

	/// <Property class="CCost_Medium_Consume_Std" name="Stock_Type" type="L3STRING">
	/// 存货分类
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Type)

	/// <Property class="CCost_Medium_Consume_Std" name="Standard_Cost" type="L3FLOAT">
	/// 定额
	/// </Property>
	DECLARE_L3PROP_FLOAT(Standard_Cost)

};
