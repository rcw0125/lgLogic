// 逻辑类CBulk_Trans_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBulk_Trans_Log.h"

IMPLEMENT_L3CLASS(CBulk_Trans_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CBulk_Trans_Log,CL3Object)
	L3PROP_STRING(SourceID)
	L3PROP_STRING(TargetID)
	L3PROP_STRING(MaterialID)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_DATETIME(Trans_Date)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CBulk_Trans_Log)

BEGIN_L3METHODMAP(CBulk_Trans_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Trans_Log,CL3Object)
END_L3EVENTSINK_MAP(CBulk_Trans_Log)

CBulk_Trans_Log::CBulk_Trans_Log(void)
{
}

CBulk_Trans_Log::~CBulk_Trans_Log(void)
{
}
