// 逻辑类CQA_Des_Std头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Des_Std :
	public CL3Object
{
public:
	CQA_Des_Std(void);
	virtual ~CQA_Des_Std(void);

	DECLARE_L3CLASS(CQA_Des_Std,XGMESLogic\\QualityMag, Des_Proc_Mod)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Des_Std)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Des_Std" name="Des_Proc_Mod" type="L3SHORT">
	/// 脱硫处理模式号
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Proc_Mod)

	/// <Property class="CQA_Des_Std" name="Valid_Date" type="L3DATETIME">
	/// 生效日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Valid_Date)

	/// <Property class="CQA_Des_Std" name="S" type="L3DOUBLE">
	/// 铁水硫含量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CQA_Des_Std" name="Weight" type="L3DOUBLE">
	/// 铁水重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

};
