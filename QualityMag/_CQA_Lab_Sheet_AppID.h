// 逻辑类CQA_Lab_Sheet_AppID头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_Sheet_AppID :
	public CL3Object
{
public:
	CQA_Lab_Sheet_AppID(void);
	virtual ~CQA_Lab_Sheet_AppID(void);

	DECLARE_L3CLASS(CQA_Lab_Sheet_AppID,XGMESLogic\\QualityMag, Sample_Address)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Sheet_AppID)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_Sheet_AppID" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_Sheet_AppID" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)
};
