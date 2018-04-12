// 逻辑类CBase_Excep_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Excep_Infor :
	public CL3Object
{
public:
	CBase_Excep_Infor(void);
	virtual ~CBase_Excep_Infor(void);

	DECLARE_L3CLASS(CBase_Excep_Infor,XGMESLogic\\BaseDataMag, Pk_Exception)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Excep_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Excep_Infor" name="Pk_Exception" type="L3STRING">
	/// 异常运转项目主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Exception)

	/// <Property class="CBase_Excep_Infor" name="Exception_Code" type="L3STRING">
	/// 项目编码
	/// </Property>
	DECLARE_L3PROP_STRING(Exception_Code)

	/// <Property class="CBase_Excep_Infor" name="Exception_Name" type="L3STRING">
	/// 项目名称
	/// </Property>
	DECLARE_L3PROP_STRING(Exception_Name)

};
