// 逻辑类CQA_BOF_Std_Tapping源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_BOF_Std_Tapping.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Tapping,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Tapping,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Tapping_Temp_Min)
	L3PROP_LONG(Tapping_Time_Min)
	L3PROP_DOUBLE(End_O2_UpLimit)
	L3PROP_DOUBLE(End_C_UpLimit)
	L3PROP_DOUBLE(End_C_LowLimit)
	L3PROP_DOUBLE(End_S_UpLimit)
	L3PROP_DOUBLE(End_P_UpLimit)
	L3PROP_DOUBLE(End_Mn_UpLimit)
	L3PROP_LONG(Ar_Press_Max)
	L3PROP_LONG(Ar_Press_Min)
	L3PROP_DOUBLE(Ar_Blow_Max)
	L3PROP_DOUBLE(Ar_Blow_Min)
END_L3PROPTABLE(CQA_BOF_Std_Tapping)

BEGIN_L3METHODMAP(CQA_BOF_Std_Tapping,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Tapping,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Tapping)

CQA_BOF_Std_Tapping::CQA_BOF_Std_Tapping(void)
{
}

CQA_BOF_Std_Tapping::~CQA_BOF_Std_Tapping(void)
{
}
