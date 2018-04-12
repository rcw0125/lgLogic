// 逻辑类CQA_BOF_Std_Ladle源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_BOF_Std_Ladle.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Ladle,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Ladle,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Ladle_Mat_Name)
	L3PROP_DOUBLE(Ladle_Mat_Min)
	L3PROP_DOUBLE(Ladle_Mat_Max)
	L3PROP_DOUBLE(Ladle_Mat_Aim)
END_L3PROPTABLE(CQA_BOF_Std_Ladle)

BEGIN_L3METHODMAP(CQA_BOF_Std_Ladle,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Ladle,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Ladle)

CQA_BOF_Std_Ladle::CQA_BOF_Std_Ladle(void)
{
}

CQA_BOF_Std_Ladle::~CQA_BOF_Std_Ladle(void)
{
}
