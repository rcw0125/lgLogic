// 逻辑类CBase_Check_Item_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Check_Item_Infor :
	public CL3Object
{
public:
	CBase_Check_Item_Infor(void);
	virtual ~CBase_Check_Item_Infor(void);

	DECLARE_L3CLASS(CBase_Check_Item_Infor,XGMESLogic\\BaseDataMag, Pk_Check_Item)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Check_Item_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Check_Item_Infor" name="Pk_Check_Item" type="L3STRING">
	/// 检验项目主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Check_Item)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Item_Code" type="L3STRING">
	/// 检验项目编码
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Code)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Item_Name" type="L3STRING">
	/// 检验项目名称
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Name)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Unit_Id" type="L3STRING">
	/// 项目单位
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Unit_Id)

};
