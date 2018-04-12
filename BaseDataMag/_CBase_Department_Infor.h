// 逻辑类Department_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Department_Infor :
	public CL3Object
{
public:
	CBase_Department_Infor(void);
	virtual ~CBase_Department_Infor(void);

	DECLARE_L3CLASS(CBase_Department_Infor,XGMESLogic\\BaseDataMag, Pk_Department)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Department_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="Department_Infor" name="Pk_Department" type="L3STRING">
	/// 部门档案主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Department)

	/// <Property class="Department_Infor" name="Department_Name" type="L3STRING">
	/// 部门名称
	/// </Property>
	DECLARE_L3PROP_STRING(Department_Name)

	/// <Property class="Department_Infor" name="Department_Code" type="L3STRING">
	/// 部门编码
	/// </Property>
	DECLARE_L3PROP_STRING(Department_Code)

};
