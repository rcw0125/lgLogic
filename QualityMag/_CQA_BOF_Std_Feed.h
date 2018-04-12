// 逻辑类CQA_BOF_Std_Feed头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_BOF_Std_Feed :
	public CL3Object
{
public:
	CQA_BOF_Std_Feed(void);
	virtual ~CQA_BOF_Std_Feed(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Code" type="L3STRING">
	/// 喂丝线名称
	/// </Property>
	DECLARE_L3PROP_STRING(Feed_Code)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Weight_Min" type="L3DOUBLE">
	/// 喂丝线用量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Feed_Weight_Min)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Weight_Max" type="L3DOUBLE">
	/// 喂丝线加入量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Feed_Weight_Max)

};
