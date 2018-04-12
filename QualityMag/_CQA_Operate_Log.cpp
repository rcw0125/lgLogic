// 逻辑类CQA_Operate_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_Operate_Log.h"

IMPLEMENT_L3CLASS(CQA_Operate_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Operate_Log,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(ActionCode)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
	L3PROP_DATETIME(OpeateTime)
END_L3PROPTABLE(CQA_Operate_Log)

BEGIN_L3METHODMAP(CQA_Operate_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Operate_Log,CL3Object)
END_L3EVENTSINK_MAP(CQA_Operate_Log)

CQA_Operate_Log::CQA_Operate_Log(void)
{
}

CQA_Operate_Log::~CQA_Operate_Log(void)
{
}
