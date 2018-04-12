// 逻辑类CMIF_Feed_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMIF_Feed_Log.h"

IMPLEMENT_L3CLASS(CMIF_Feed_Log,UnitFeedingLog,1)

BEGIN_L3PROPTABLE(CMIF_Feed_Log,UnitFeedingLog)
	L3PROP_STRING(MIFID)
	L3PROP_STRING(BFID)
	L3PROP_STRING(TAP_No)
	L3PROP_STRING(TPC_No)
END_L3PROPTABLE(CMIF_Feed_Log)

BEGIN_L3METHODMAP(CMIF_Feed_Log,UnitFeedingLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Feed_Log,UnitFeedingLog)
END_L3EVENTSINK_MAP(CMIF_Feed_Log)

CMIF_Feed_Log::CMIF_Feed_Log(void)
{
}

CMIF_Feed_Log::~CMIF_Feed_Log(void)
{
}
