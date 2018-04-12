// 逻辑类CRHL_Process_Satus源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRHL_Process_Status.h"

IMPLEMENT_L3CLASS(CRHL_Process_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CRHL_Process_Status,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CRHL_Process_Status)

BEGIN_L3METHODMAP(CRHL_Process_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Process_Status,CL3Object)
END_L3EVENTSINK_MAP(CRHL_Process_Status)

CRHL_Process_Status::CRHL_Process_Status(void)
{
}

CRHL_Process_Status::~CRHL_Process_Status(void)
{
}
