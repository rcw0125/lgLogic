// 逻辑类CQA_SteelGradeIndex_R头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_SteelGradeIndex_R :
	public CL3Object
{
public:
	CQA_SteelGradeIndex_R(void);
	virtual ~CQA_SteelGradeIndex_R(void);

	DECLARE_L3CLASS(CQA_SteelGradeIndex_R,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_SteelGradeIndex_R)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_SteelGradeIndex_R" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_SteelGradeIndex_R" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_SteelGradeIndex_R" name="Grade_Group_Code" type="L3STRING">
	/// 异常处理钢组
	/// </Property>
	DECLARE_L3PROP_STRING(Grade_Group_Code)

	/// <Property class="CQA_SteelGradeIndex_R" name="First_Flag" type="L3SHORT">
	/// 
	/// 代表炼钢记号标志：
	/// 0：代表。1：不代表
	/// </Property>
	DECLARE_L3PROP_LONG(First_Flag)


	/// <Property class="CQA_SteelGradeIndex_R" name="Protocol" type="L3STRING">
	/// 协议
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)
	
	/// <Property class="CQA_SteelGradeIndex_R" name="NC_Zyx1" type="L3STRING">
	/// 自由项1
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Zyx1)

	/// <Property class="CQA_SteelGradeIndex_R" name="NC_Zyx2" type="L3STRING">
	/// 自由项2
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Zyx2)

	
	/// <Property class="CQA_SteelGradeIndex_R" name="Protocol" type="L3STRING">
	/// 冶炼备注
	/// </Property>
	DECLARE_L3PROP_STRING(BOF_Note)

	//Modify begin by llj 2011-03-11
	/// <Property class="CQA_SteelGradeIndex_R" name="Use_Flag" type="L3STRING">
	/// 使用标志 0:使用 1:禁用
	/// </Property>
	DECLARE_L3PROP_STRING(Use_Flag)
	//Modify end


};
