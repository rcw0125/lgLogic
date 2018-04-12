// 逻辑类CBase_Unit_Original_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Unit_Original_Data :
	public CL3Object
{
public:
	CBase_Unit_Original_Data(void);
	virtual ~CBase_Unit_Original_Data(void);

	DECLARE_L3CLASS(CBase_Unit_Original_Data,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Unit_Original_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Unit_Original_Data" name="UnitID" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CBase_Unit_Original_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};
