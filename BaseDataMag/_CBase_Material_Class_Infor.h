// 逻辑类CBase_Material_Class_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Material_Class_Infor :
	public CL3Object
{
public:
	CBase_Material_Class_Infor(void);
	virtual ~CBase_Material_Class_Infor(void);

	DECLARE_L3CLASS(CBase_Material_Class_Infor,XGMESLogic\\BaseDataMag, Pk_Material_Class)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Material_Class_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Material_Class_Infor" name="Pk_Material_Class" type="L3STRING">
	/// 物料分类主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Class)

	/// <Property class="CBase_Material_Class_Infor" name="Material_Class_Code" type="L3STRING">
	/// 物料分类编码
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Class_Code)

	/// <Property class="CBase_Material_Class_Infor" name="Material_Class_Name" type="L3STRING">
	/// 物料分类名称
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Class_Name)

	/// <Property class="CBase_Material_Class_Infor" name="End_Flag" type="L3STRING">
	/// 是否末级分类
	/// </Property>
	DECLARE_L3PROP_STRING(End_Flag)

};
