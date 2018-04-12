// 逻辑类CAlloy_PropChange_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_PropChange_Log.h"

IMPLEMENT_L3CLASS(CAlloy_PropChange_Log,MaterialPropLog,1)

BEGIN_L3PROPTABLE(CAlloy_PropChange_Log,MaterialPropLog)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CAlloy_PropChange_Log)

BEGIN_L3METHODMAP(CAlloy_PropChange_Log,MaterialPropLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_PropChange_Log,MaterialPropLog)
END_L3EVENTSINK_MAP(CAlloy_PropChange_Log)

CAlloy_PropChange_Log::CAlloy_PropChange_Log(void)
{
}

CAlloy_PropChange_Log::~CAlloy_PropChange_Log(void)
{
}
