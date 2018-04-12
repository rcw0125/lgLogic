// 逻辑类CBase_Check_Std_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Check_Std_Infor :
	public CL3Object
{
public:
	CBase_Check_Std_Infor(void);
	virtual ~CBase_Check_Std_Infor(void);

	DECLARE_L3CLASS(CBase_Check_Std_Infor,XGMESLogic\\BaseDataMag, CheckStandard_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Check_Std_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

    /// <Property class="CBase_Check_Std_Infor" name="CheckStandard_ID" type="L3LONG">
	/// 检验标准主键
	/// </Property>
	DECLARE_L3PROP_STRING(CheckStandard_ID)

	/// <Property class="CBase_Check_Std_Infor" name="Pk_Check_Std" type="L3STRING">
	/// 检验标准编码
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Check_Std)

	
	/// <Property class="CBase_Check_Std_Infor" name="Check_Std_Code" type="L3STRING">
	/// 检验标准编码
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Std_Code)

	/// <Property class="CBase_Check_Std_Infor" name="Check_Std_Name" type="L3STRING">
	/// 检验标准名称
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Std_Name)

	/// <Property class="CBase_Check_Std_Infor" name="Check_Item_Id" type="L3STRING">
	/// 检验项目主键
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Id)

	/// <Property class="CBase_Check_Std_Infor" name="bcritical" type="L3STRING">
	/// 是否关键项目
	/// </Property>
	DECLARE_L3PROP_STRING(bcritical)

	/// <Property class="CBase_Check_Std_Infor" name="Std_Value" type="L3STRING">
	/// 标准值
	/// </Property>
	DECLARE_L3PROP_STRING(Std_Value)

	/// <Property class="CBase_Check_Std_Infor" name="Std_Value_Type" type="L3STRING">
	/// 标准值类型
	/// </Property>
	DECLARE_L3PROP_STRING(Std_Value_Type)

};
