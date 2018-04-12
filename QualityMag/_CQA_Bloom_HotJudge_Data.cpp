// 逻辑类CQA_Bloom_HotJudge_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_Bloom_HotJudge_Data.h"

IMPLEMENT_L3CLASS(CQA_Bloom_HotJudge_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Bloom_HotJudge_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CasterID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_LONG(Bloom_Count)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_LONG(Right_Count)
	L3PROP_DOUBLE(Right_Weight)
	L3PROP_DOUBLE(Waster_Count)
	L3PROP_DOUBLE(Waster_Weight)
	L3PROP_DOUBLE(Waster_Count1)
	L3PROP_DOUBLE(Waster_Weight1)
	L3PROP_STRING(Waster_Reason1)
	L3PROP_DOUBLE(Waster_Count2)
	L3PROP_DOUBLE(Waster_Weight2)
	L3PROP_STRING(Waster_Reason2)
	L3PROP_DOUBLE(Waster_Count3)
	L3PROP_DOUBLE(Waster_Weight3)
	L3PROP_STRING(Waster_Reason3)
	L3PROP_LONG(Wrong_Count)
	L3PROP_DOUBLE(Wrong_Weight)
	L3PROP_LONG(Wrong_Count1)
	L3PROP_DOUBLE(Wrong_Weight1)
	L3PROP_STRING(Wrong_Reason1)
	L3PROP_LONG(Wrong_Count2)
	L3PROP_DOUBLE(Wrong_Weight2)
	L3PROP_STRING(Wrong_Reason2)
	L3PROP_LONG(Wrong_Count3)
	L3PROP_DOUBLE(Wrong_Weight3)
	L3PROP_STRING(Wrong_Reason3)
	L3PROP_STRING(SufaceDefactDes)
	L3PROP_DATETIME(HotJudge_Time)
	L3PROP_LONG(WaitCheckFlag)
	L3PROP_STRING(Team)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CQA_Bloom_HotJudge_Data)

BEGIN_L3METHODMAP(CQA_Bloom_HotJudge_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Bloom_HotJudge_Data,CL3Object)
END_L3EVENTSINK_MAP(CQA_Bloom_HotJudge_Data)

CQA_Bloom_HotJudge_Data::CQA_Bloom_HotJudge_Data(void)
{
}

CQA_Bloom_HotJudge_Data::~CQA_Bloom_HotJudge_Data(void)
{
}
