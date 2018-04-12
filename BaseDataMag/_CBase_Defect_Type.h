// 逻辑类CBase_Defect_Type头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Defect_Type :
	public CL3Object
{
public:
	CBase_Defect_Type(void);
	virtual ~CBase_Defect_Type(void);

	DECLARE_L3CLASS(CBase_Defect_Type,XGMESLogic\\BaseDataMag, Pk_Defec_Type)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Defect_Type)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Defect_Type" name="Pk_Defec_Type" type="L3STRING">
	/// 不合格类型主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Defec_Type)

	/// <Property class="CBase_Defect_Type" name="Defect_Type_Code" type="L3STRING">
	/// 不合格类型编码
	/// </Property>
	DECLARE_L3PROP_STRING(Defect_Type_Code)

	/// <Property class="CBase_Defect_Type" name="Defect_Type_Name" type="L3STRING">
	/// 不合格类型名称
	/// </Property>
	DECLARE_L3PROP_STRING(Defect_Type_Name)

};
