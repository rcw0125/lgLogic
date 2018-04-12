// 逻辑类CQA_BOF_Std_Bulk头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Bulk :
	public CL3Object
{
public:
	CQA_BOF_Std_Bulk(void);
	virtual ~CQA_BOF_Std_Bulk(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Bulk,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Bulk)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Bulk" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Code" type="L3STRING">
	/// 散状料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Weight_Min" type="L3DOUBLE">
	/// 散状料1加入量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bulk_Weight_Min)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Weight_Max" type="L3DOUBLE">
	/// 散状料1加入量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bulk_Weight_Max)

};
