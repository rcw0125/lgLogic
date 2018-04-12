// 逻辑类CMaterial_Price头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMaterial_Price :
	public CL3Object
{
public:
	CMaterial_Price(void);
	virtual ~CMaterial_Price(void);

	DECLARE_L3CLASS(CMaterial_Price,XGMESLogic\\BaseDataMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMaterial_Price)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMaterial_Price" name="Material_Code" type="L3STRING">
	/// 物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Code)

	/// <Property class="CMaterial_Price" name="Material_Name" type="L3STRING">
	/// 物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Name)

	/// <Property class="CMaterial_Price" name="Standard_Price" type="L3DOUBLE">
	/// 标准价
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Standard_Price)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jan" type="L3DOUBLE">
	/// 一月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jan)

	/// <Property class="CMaterial_Price" name="Budget_Price_Feb" type="L3DOUBLE">
	/// 二月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Feb)

	/// <Property class="CMaterial_Price" name="Budget_Price_Mar" type="L3DOUBLE">
	/// 三月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Mar)

	/// <Property class="CMaterial_Price" name="Budget_Price_Apr" type="L3DOUBLE">
	/// 四月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Apr)

	/// <Property class="CMaterial_Price" name="Budget_Price_May" type="L3DOUBLE">
	/// 五月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_May)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jun" type="L3DOUBLE">
	/// 六月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jun)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jul" type="L3DOUBLE">
	/// 七月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jul)

	/// <Property class="CMaterial_Price" name="Budget_Price_Aug" type="L3DOUBLE">
	/// 八月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Aug)

	/// <Property class="CMaterial_Price" name="Budget_Price_Sep" type="L3DOUBLE">
	/// 九月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Sep)

	/// <Property class="CMaterial_Price" name="Budget_Price_Oct" type="L3DOUBLE">
	/// 十月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Oct)

	/// <Property class="CMaterial_Price" name="Budget_Price_Nov" type="L3DOUBLE">
	/// 十一月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Nov)

	/// <Property class="CMaterial_Price" name="Budget_Price_Dec" type="L3DOUBLE">
	/// 十二月预算价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Dec)

	/// <Property class="CMaterial_Price" name="Work_Year" type="L3STRING">
	/// 年份
	/// </Property>
	DECLARE_L3PROP_STRING(Work_Year)

	/// <Property class="CMaterial_Price" name="Latest_Price" type="L3DOUBLE">
	/// 最新价格
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Latest_Price)

	/// <Property class="CMaterial_Price" name="Object_ID" type="L3STRING">
	/// 关键字
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
