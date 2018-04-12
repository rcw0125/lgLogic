// 逻辑类CBulk_Output_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBulk_Output_Log.h"

IMPLEMENT_L3CLASS(CBulk_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CBulk_Output_Log,MaterialOutputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CBulk_Output_Log)

BEGIN_L3METHODMAP(CBulk_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CBulk_Output_Log)

CBulk_Output_Log::CBulk_Output_Log(void)
{
}

CBulk_Output_Log::~CBulk_Output_Log(void)
{
}
