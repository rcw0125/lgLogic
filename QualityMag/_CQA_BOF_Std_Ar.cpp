// 逻辑类CQA_BOF_Std_Ar源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_BOF_Std_Ar.h"

IMPLEMENT_L3CLASS(CQA_BOF_Std_Ar,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_BOF_Std_Ar,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Max)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Min)
	L3PROP_LONG(PreAr_SteelTemp_Fir_Aim)
	L3PROP_LONG(PreAr_SteelTemp_Max)
	L3PROP_LONG(PreAr_SteelTemp_Min)
	L3PROP_LONG(PreAr_SteelTemp_Aim)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Max)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Min)
	L3PROP_LONG(BeAr_SteelTemp_Fir_Aim)
	L3PROP_LONG(BeAr_SteelTemp_Max)
	L3PROP_LONG(BeAr_SteelTemp_Min)
	L3PROP_LONG(BeAr_SteelTemp_Aim)
	L3PROP_LONG(Oxy_Flag)
	L3PROP_DOUBLE(PreAr_Oxy_Max)
	L3PROP_DOUBLE(PreAr_Oxy_Min)
	L3PROP_LONG(Ar_Time_UpLimit)
	L3PROP_LONG(Ar_Time_LowLimit)
	L3PROP_LONG(Ar_Press_Max)
	L3PROP_LONG(Ar_Press_Min)
	L3PROP_DOUBLE(Ar_Blow_Max)
	L3PROP_DOUBLE(Ar_Blow_Min)
	L3PROP_DOUBLE(BeAr_Oxy_Max)
	L3PROP_DOUBLE(BeAr_Oxy_Min)
END_L3PROPTABLE(CQA_BOF_Std_Ar)

BEGIN_L3METHODMAP(CQA_BOF_Std_Ar,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_BOF_Std_Ar,CL3Object)
END_L3EVENTSINK_MAP(CQA_BOF_Std_Ar)

CQA_BOF_Std_Ar::CQA_BOF_Std_Ar(void)
{
}

CQA_BOF_Std_Ar::~CQA_BOF_Std_Ar(void)
{
}
