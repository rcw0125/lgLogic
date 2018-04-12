// 逻辑类CBase_Error_Code头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Error_Code :
	public CL3Object
{
public:
	CBase_Error_Code(void);
	virtual ~CBase_Error_Code(void);

	DECLARE_L3CLASS(CBase_Error_Code,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Error_Code)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Error_Code" name="Error_Code" type="L3STRING">
	/// 错误代码
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Code)

	/// <Property class="CBase_Error_Code" name="Error_Des" type="L3STRING">
	/// 代码描述
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Des)

	/// <Property class="CBase_Error_Code" name="Owner" type="L3STRING">
	/// 函数Uri
	/// </Property>
	DECLARE_L3PROP_STRING(Owner)

	/// <Property class="CBase_Error_Code" name="Owner_Des" type="L3STRING">
	/// 函数Uri描述
	/// </Property>
	DECLARE_L3PROP_STRING(Owner_Des)

	/// <Property class="CBase_Error_Code" name="Error_Val_Long" type="L3STRING">
	/// 整数值
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Val_Long)

};
