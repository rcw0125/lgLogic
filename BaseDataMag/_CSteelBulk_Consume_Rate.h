// 逻辑类CSteelBulk_Consume_Rate头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CSteelBulk_Consume_Rate :
	public CL3Object
{
public:
	CSteelBulk_Consume_Rate(void);
	virtual ~CSteelBulk_Consume_Rate(void);

	DECLARE_L3CLASS(CSteelBulk_Consume_Rate,XGMESLogic\\BaseDataMag, MatCode)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteelBulk_Consume_Rate)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CSteelBulk_Consume_Rate" name="MatCode" type="L3STRING">
	/// 物料代码 2009-09-07
	/// </Property>
	DECLARE_L3PROP_STRING(MatCode)

	/// <Property class="CSteelBulk_Consume_Rate" name="Unit_Consume" type="L3FLOAT">
	/// 单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(Unit_Consume)

};
