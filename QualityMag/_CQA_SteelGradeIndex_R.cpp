// 逻辑类CQA_SteelGradeIndex_R源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_SteelGradeIndex_R.h"

IMPLEMENT_L3CLASS(CQA_SteelGradeIndex_R,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_SteelGradeIndex_R,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Grade_Group_Code)
	L3PROP_LONG(First_Flag)
	L3PROP_STRING(Protocol)
	L3PROP_STRING(NC_Zyx1)//2009-03-11 tangyi
	L3PROP_STRING(NC_Zyx2)//2009-03-11 tangyi
	L3PROP_STRING_LEN(BOF_Note,500)//2009-03-18 tangyi
	//Modify begin by llj 2011-03-11
	L3PROP_STRING_LEN(Use_Flag,1) //使用标志 0：使用 1：禁用
	//Modify end
END_L3PROPTABLE(CQA_SteelGradeIndex_R)

BEGIN_L3METHODMAP(CQA_SteelGradeIndex_R,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_SteelGradeIndex_R,CL3Object)
END_L3EVENTSINK_MAP(CQA_SteelGradeIndex_R)

CQA_SteelGradeIndex_R::CQA_SteelGradeIndex_R(void)
{
}

CQA_SteelGradeIndex_R::~CQA_SteelGradeIndex_R(void)
{
}
