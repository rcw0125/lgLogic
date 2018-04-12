// 逻辑类Stock_Base_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Stock_Infor :
	public CL3Object
{
public:
	CBase_Stock_Infor(void);
	virtual ~CBase_Stock_Infor(void);

	DECLARE_L3CLASS(CBase_Stock_Infor,XGMESLogic\\BaseDataMag, Pk_Stock)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Stock_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="Stock_Base_Infor" name="Pk_Stock" type="L3STRING">
	/// 仓库主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Stock)

	/// <Property class="Stock_Base_Infor" name="Stock_Code" type="L3STRING">
	/// 仓库编码
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Code)

	/// <Property class="Stock_Base_Infor" name="Stock_Name" type="L3STRING">
	/// 仓库名称
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Name)


};
