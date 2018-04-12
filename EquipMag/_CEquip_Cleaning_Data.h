// 逻辑类CEquip_Cleaning_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Cleaning_Data :
	public CL3Object
{
public:
	CEquip_Cleaning_Data(void);
	virtual ~CEquip_Cleaning_Data(void);

	DECLARE_L3CLASS(CEquip_Cleaning_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Cleaning_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Cleaning_Data" name="TagName" type="L3STRING">
	/// 标签名
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEquip_Cleaning_Data" name="TagType" type="L3LONG">
	/// 标签类型
	/// </Property>
	DECLARE_L3PROP_LONG(TagType)

	/// <Property class="CEquip_Cleaning_Data" name="TagValue" type="L3LONG">
	/// 标签值
	/// </Property>
	DECLARE_L3PROP_LONG(TagValue)

	/// <Property class="CEquip_Cleaning_Data" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};
