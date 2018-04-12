// 逻辑类CQA_Cal_Weight_Std头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Cal_Weight_Std :
	public CL3Object
{
public:
	CQA_Cal_Weight_Std(void);
	virtual ~CQA_Cal_Weight_Std(void);

	DECLARE_L3CLASS(CQA_Cal_Weight_Std,XGMESLogic\\QualityMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Cal_Weight_Std)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-03-12 增加钢种，修改主键为钢种加定尺

	/// <Property class="CQA_Cal_Weight_Std" name="ObjectID" type="L3STRING">
	/// 主键
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CQA_Cal_Weight_Std" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Cal_Weight_Std" name="Length" type="L3LONG">
	/// 定尺（m）
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CQA_Cal_Weight_Std" name="Weight" type="L3DOUBLE">
	/// 理论重量（t）
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)


	/// <Property class="CQA_Cal_Weight_Std" name="Spec" type="L3STRING">
	/// 规格（m）
	/// </Property>
	DECLARE_L3PROP_STRING(Spec)

};
