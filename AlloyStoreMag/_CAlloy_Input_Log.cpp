// 逻辑类CAlloy_Input_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_Input_Log.h"

IMPLEMENT_L3CLASS(CAlloy_Input_Log,MaterialInputLog,1)

BEGIN_L3PROPTABLE(CAlloy_Input_Log,MaterialInputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Alloy_Code)
	L3PROP_STRING(Alloy_Confirm_Man)
	L3PROP_STRING(Shop_Confirm_Man)
END_L3PROPTABLE(CAlloy_Input_Log)

BEGIN_L3METHODMAP(CAlloy_Input_Log,MaterialInputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Input_Log,MaterialInputLog)
END_L3EVENTSINK_MAP(CAlloy_Input_Log)

CAlloy_Input_Log::CAlloy_Input_Log(void)
{
}

CAlloy_Input_Log::~CAlloy_Input_Log(void)
{
}
