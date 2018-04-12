// 逻辑类CBase_Cargo_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Cargo_Infor :
	public CL3Object
{
public:
	CBase_Cargo_Infor(void);
	virtual ~CBase_Cargo_Infor(void);

	DECLARE_L3CLASS(CBase_Cargo_Infor,XGMESLogic\\BaseDataMag, Pk_Cargo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Cargo_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Cargo_Infor" name="Pk_Cargo" type="L3STRING">
	/// 货位主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Cargo)

	/// <Property class="CBase_Cargo_Infor" name="Cargo_Code" type="L3STRING">
	/// 货位编码
	/// </Property>
	DECLARE_L3PROP_STRING(Cargo_Code)

	/// <Property class="CBase_Cargo_Infor" name="Carge_name" type="L3STRING">
	/// 货位名称
	/// </Property>
	DECLARE_L3PROP_STRING(Carge_name)

	/// <Property class="CBase_Cargo_Infor" name="Pk_Stock" type="L3STRING">
	/// 所属仓库主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Stock)

};
