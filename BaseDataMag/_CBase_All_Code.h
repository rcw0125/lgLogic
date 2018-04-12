// 逻辑类CXGMES_All_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_All_Code :
	public CL3Object
{
public:
	CBase_All_Code(void);
	virtual ~CBase_All_Code(void);

	DECLARE_L3CLASS(CBase_All_Code,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_All_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CXGMES_All_Code" name="Code" type="L3STRING">
	/// 代码
	/// </Property>
	DECLARE_L3PROP_STRING(Code)

	/// <Property class="CXGMES_All_Code" name="Code_Des" type="L3STRING">
	/// 代码描述
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Des)

	/// <Property class="CXGMES_All_Code" name="Code_Group" type="L3STRING">
	/// 代码分组
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Group)

	/// <Property class="CXGMES_All_Code" name="Code_Group_Des" type="L3STRING">
	/// 代码分组描述
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Group_Des)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Str" type="L3STRING">
	/// 代码串值
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Val_Str)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Long" type="L3LONG">
	/// 代码整数值
	/// </Property>
	DECLARE_L3PROP_LONG(Code_Val_Long)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Double" type="L3DOUBLE">
	/// 代码浮点值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Code_Val_Double)

	/// <Property class="CXGMES_All_Code" name="Code_Function_Group" type="L3STRING">
	/// 代码功能分组
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Function_Group)

	/// <Property class="CXGMES_All_Code" name="NC_Code" type="L3STRING">
	/// NC编码
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Code)

};
