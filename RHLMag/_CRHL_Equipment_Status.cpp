// 逻辑类CRHL_Equipment_Status源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRHL_Equipment_Status.h"

IMPLEMENT_L3CLASS(CRHL_Equipment_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CRHL_Equipment_Status,CL3Object)
	L3PROP_SHORT(RHLID)
	L3PROP_SHORT(Status)
	L3PROP_DATETIME(Log_Time)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CRHL_Equipment_Status)

BEGIN_L3METHODMAP(CRHL_Equipment_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Equipment_Status,CL3Object)
END_L3EVENTSINK_MAP(CRHL_Equipment_Status)

CRHL_Equipment_Status::CRHL_Equipment_Status(void)
{
}

CRHL_Equipment_Status::~CRHL_Equipment_Status(void)
{
}
