// 逻辑类CQA_RH_Std_Feed头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_RH_Std_Feed :
	public CL3Object
{
public:
	CQA_RH_Std_Feed(void);
	virtual ~CQA_RH_Std_Feed(void);

	DECLARE_L3CLASS(CQA_RH_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_RH_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_RH_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code" type="L3STRING">
	/// Ca处理喂丝线
	/// </Property>
	DECLARE_L3PROP_STRING(CaProc_Code)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code_Weight_Max" type="L3DOUBLE">
	/// Ca处理喂线喂入量最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code_Weight_Max)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code_Weight_Min" type="L3DOUBLE">
	/// Ca处理喂线喂入量最小
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code_Weight_Min)

};
