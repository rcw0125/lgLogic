// 逻辑类CQA_Lab_S_Print源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_Lab_S_Print.h"

IMPLEMENT_L3CLASS(CQA_Lab_S_Print,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Lab_S_Print,CL3Object)
	L3PROP_STRING(AppID)
	L3PROP_DATETIME(Arrive_Date)
	L3PROP_DATETIME(Report_Date)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Sample_Address)
	L3PROP_STRING(Sample_Type)
	L3PROP_STRING(Sample_Count)
	L3PROP_STRING(Sample_Code)
	L3PROP_STRING(Shrinkage_Hole )
	L3PROP_STRING(Center_Loose)
	L3PROP_STRING(Common_Loose )
	L3PROP_STRING(Center_Crack_Lev)
	L3PROP_STRING(Center_Crack_Len)
	L3PROP_STRING(Hypo_Bubble)
	L3PROP_STRING(Center_Crack)
	L3PROP_STRING(Equiaxed_Grain )
	L3PROP_STRING(Hypo_Crack_D)
	L3PROP_STRING(Hypo_Crack_L)
	L3PROP_STRING(Hypo_Crack_Q)
	L3PROP_STRING(Hypo_Crack_Lev)
	L3PROP_STRING(Surface_Eyelet)
	L3PROP_STRING(Surface_Crack)
	L3PROP_STRING(Surface_Slag)
	L3PROP_STRING(Nonmetal_Slag)
	L3PROP_STRING(Spot)
	L3PROP_STRING(AcidTime)
	L3PROP_STRING(S_Print)
	L3PROP_DATETIME(LogTime)
	L3PROP_LONG(DataLogMode)
	L3PROP_STRING(StrandID)
	L3PROP_STRING(Size)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CQA_Lab_S_Print)

BEGIN_L3METHODMAP(CQA_Lab_S_Print,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Lab_S_Print,CL3Object)
END_L3EVENTSINK_MAP(CQA_Lab_S_Print)

CQA_Lab_S_Print::CQA_Lab_S_Print(void)
{
}

CQA_Lab_S_Print::~CQA_Lab_S_Print(void)
{
}
