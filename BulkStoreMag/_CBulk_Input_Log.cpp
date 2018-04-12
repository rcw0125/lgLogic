// 逻辑类CBulk_Input_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBulk_Input_Log.h"

IMPLEMENT_L3CLASS(CBulk_Input_Log,MaterialInputLog,1)

BEGIN_L3PROPTABLE(CBulk_Input_Log,MaterialInputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_STRING(Bulk_Confirm_Man)
	L3PROP_STRING(Shop_Confirm_Man)
END_L3PROPTABLE(CBulk_Input_Log)

BEGIN_L3METHODMAP(CBulk_Input_Log,MaterialInputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Input_Log,MaterialInputLog)
END_L3EVENTSINK_MAP(CBulk_Input_Log)

CBulk_Input_Log::CBulk_Input_Log(void)
{
}

CBulk_Input_Log::~CBulk_Input_Log(void)
{
}
