// 逻辑类CAlloy_Output_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_Output_Log.h"

IMPLEMENT_L3CLASS(CAlloy_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CAlloy_Output_Log,MaterialOutputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Alloy_Code)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CAlloy_Output_Log)

BEGIN_L3METHODMAP(CAlloy_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CAlloy_Output_Log)

CAlloy_Output_Log::CAlloy_Output_Log(void)
{
}

CAlloy_Output_Log::~CAlloy_Output_Log(void)
{
}
