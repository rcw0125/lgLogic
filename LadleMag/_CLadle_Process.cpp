// 逻辑类CLadle_Process源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Process.h"

IMPLEMENT_L3CLASS(CLadle_Process,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Process,CL3Object)
	
	L3PROP_STRING(LadleID)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_DATETIME(Online_Time)
	L3PROP_STRING(Online_HeatID)
	L3PROP_DATETIME(Offline_Time)
	L3PROP_STRING(Offline_HeatID)
	L3PROP_LONG(Comfirm_Flag)
	L3PROP_DATETIME(Throw_Time)
	L3PROP_LONG(Ladle_Age)
END_L3PROPTABLE(CLadle_Process)

BEGIN_L3METHODMAP(CLadle_Process,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Process,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Process)

CLadle_Process::CLadle_Process(void)
{
}

CLadle_Process::~CLadle_Process(void)
{
}
