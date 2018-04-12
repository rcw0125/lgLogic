// 逻辑类CNCCommunicator源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CNCCommunicator.h"

IMPLEMENT_L3CLASS(CNCCommunicator,CL3Object,1)

BEGIN_L3PROPTABLE(CNCCommunicator,CL3Object)
END_L3PROPTABLE(CNCCommunicator)

BEGIN_L3METHODMAP(CNCCommunicator,CL3Object)
	L3_METHOD(CNCCommunicator,"SendCastIronDataToNC",0,SendCastIronDataToNC,L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CNCCommunicator,CL3Object)
END_L3EVENTSINK_MAP(CNCCommunicator)

CNCCommunicator::CNCCommunicator(void)
{
}

CNCCommunicator::~CNCCommunicator(void)
{
}
