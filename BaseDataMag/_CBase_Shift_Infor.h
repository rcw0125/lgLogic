// 逻辑类CBase_Shift_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Shift_Infor :
	public CL3Object
{
public:
	CBase_Shift_Infor(void);
	virtual ~CBase_Shift_Infor(void);

	DECLARE_L3CLASS(CBase_Shift_Infor,XGMESLogic\\BaseDataMag, Pk_Shift)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Shift_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Shift_Infor" name="Pk_Shift" type="L3STRING">
	/// 班次主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Shift)

	/// <Property class="CBase_Shift_Infor" name="Shift_Code" type="L3STRING">
	/// 班次编码
	/// </Property>
	DECLARE_L3PROP_STRING(Shift_Code)

	/// <Property class="CBase_Shift_Infor" name="Shift_Name" type="L3STRING">
	/// 班次名称
	/// </Property>
	DECLARE_L3PROP_STRING(Shift_Name)

};
