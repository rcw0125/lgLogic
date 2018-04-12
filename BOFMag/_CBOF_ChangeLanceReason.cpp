// 逻辑类CBOF_ChangeLanceReason源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_ChangeLanceReason.h"

IMPLEMENT_L3CLASS(CBOF_ChangeLanceReason,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_ChangeLanceReason,CL3Object)
	L3PROP_SHORT(BOFID)
	L3PROP_DATETIME(ChangeLance_Time)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CBOF_ChangeLanceReason)

BEGIN_L3METHODMAP(CBOF_ChangeLanceReason,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_ChangeLanceReason,CL3Object)
END_L3EVENTSINK_MAP(CBOF_ChangeLanceReason)

CBOF_ChangeLanceReason::CBOF_ChangeLanceReason(void)
{
}

CBOF_ChangeLanceReason::~CBOF_ChangeLanceReason(void)
{
}
