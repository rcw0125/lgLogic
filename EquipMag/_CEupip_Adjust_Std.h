// 逻辑类CEupip_Adjust_Std头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEupip_Adjust_Std :
	public CL3Object
{
public:
	CEupip_Adjust_Std(void);
	virtual ~CEupip_Adjust_Std(void);

	DECLARE_L3CLASS(CEupip_Adjust_Std,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEupip_Adjust_Std)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEupip_Adjust_Std" name="AdjustType" type="L3STRING">
	/// 分类
	/// </Property>
	DECLARE_L3PROP_STRING(AdjustType)

	/// <Property class="CEupip_Adjust_Std" name="UnitID" type="L3STRING">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CEupip_Adjust_Std" name="AdjustObject" type="L3STRING">
	/// 对象
	/// </Property>
	DECLARE_L3PROP_STRING(AdjustObject)

	/// <Property class="CEupip_Adjust_Std" name="Items" type="L3STRING">
	/// 项目
	/// </Property>
	DECLARE_L3PROP_STRING(Items)

	/// <Property class="CEupip_Adjust_Std" name="Standard" type="L3STRING">
	/// 标准
	/// </Property>
	DECLARE_L3PROP_STRING(Standard)

	/// <Property class="CEupip_Adjust_Std" name="ValidFlag" type="L3LONG">
	/// 标准
	/// </Property>
	DECLARE_L3PROP_LONG(ValidFlag)
};
