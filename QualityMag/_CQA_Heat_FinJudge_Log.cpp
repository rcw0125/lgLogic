// 逻辑类CQA_Heat_FinJudge_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_Heat_FinJudge_Log.h"

IMPLEMENT_L3CLASS(CQA_Heat_FinJudge_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Heat_FinJudge_Log,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Final_SteelGradeIndex)
	L3PROP_DATETIME(Judge_Date)
	L3PROP_STRING(Operator)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
END_L3PROPTABLE(CQA_Heat_FinJudge_Log)

BEGIN_L3METHODMAP(CQA_Heat_FinJudge_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Heat_FinJudge_Log,CL3Object)
END_L3EVENTSINK_MAP(CQA_Heat_FinJudge_Log)

CQA_Heat_FinJudge_Log::CQA_Heat_FinJudge_Log(void)
{
}

CQA_Heat_FinJudge_Log::~CQA_Heat_FinJudge_Log(void)
{
}
