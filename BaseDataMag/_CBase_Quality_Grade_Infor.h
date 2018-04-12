// 逻辑类Quality_Grade_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Quality_Grade_Infor :
	public CL3Object
{
public:
	CBase_Quality_Grade_Infor(void);
	virtual ~CBase_Quality_Grade_Infor(void);

	DECLARE_L3CLASS(CBase_Quality_Grade_Infor,XGMESLogic\\BaseDataMag, Pk_Qua_Grade)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Quality_Grade_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="Quality_Grade_Infor" name="Pk_Qua_Grade" type="L3STRING">
	/// 质量等级主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Qua_Grade)

	/// <Property class="Quality_Grade_Infor" name="Qua_Grade_Name" type="L3STRING">
	/// 质量等级名称
	/// </Property>
	DECLARE_L3PROP_STRING(Qua_Grade_Name)

	/// <Property class="Quality_Grade_Infor" name="Qua_Grade_Code" type="L3STRING">
	/// 质量等级编码
	/// </Property>
	DECLARE_L3PROP_STRING(Qua_Grade_Code)

	/// <Property class="Quality_Grade_Infor" name="Qualified" type="L3STRING">
	/// 是否合格
	/// </Property>
	DECLARE_L3PROP_STRING(Qualified)

	/// <Property class="Quality_Grade_Infor" name="Pk_Qua_Grade_Group" type="L3STRING">
	/// 质量等级组主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Qua_Grade_Group)

};
