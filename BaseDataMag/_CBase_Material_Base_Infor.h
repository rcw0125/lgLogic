// 逻辑类CBase_Material_Base_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Material_Base_Infor :
	public CL3Object
{
public:
	CBase_Material_Base_Infor(void);
	virtual ~CBase_Material_Base_Infor(void);

	DECLARE_L3CLASS(CBase_Material_Base_Infor,XGMESLogic\\BaseDataMag, Pk_Material_Bas)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Material_Base_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Material_Base_Infor" name="Pk_Material_Bas" type="L3STRING">
	/// 物料编码主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Bas)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Code" type="L3STRING">
	/// 物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Code)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Name" type="L3STRING">
	/// 物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Name)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Spec" type="L3STRING">
	/// 物料规格
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Spec)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Type" type="L3STRING">
	/// 物料型号
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Type)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Type" type="L3STRING">
	/// 物料分类主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Class)

	/// <Property class="CBase_Material_Base_Infor" name="Pk_Unit" type="L3STRING">
	/// 计量单位主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Unit)

	/// <Property class="CBase_Material_Base_Infor" name="Route" type="L3STRING">
	/// 工艺路径
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(Route)

};
