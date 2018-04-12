// 逻辑类CBloom_Trans_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBloom_Trans_Log.h"

IMPLEMENT_L3CLASS(CBloom_Trans_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CBloom_Trans_Log,CL3Object)
	L3PROP_STRING(MaterialType)
	L3PROP_STRING(MaterialID)
	L3PROP_STRING(Amount)
	L3PROP_STRING(SourceID)
	L3PROP_STRING(Cur_Pile_ID)
	L3PROP_STRING(Cur_Layer_ID)
	L3PROP_STRING(TargetID)
	L3PROP_STRING(Target_Pile_ID)
	L3PROP_STRING(Target_Layer_ID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Trans_Date)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
END_L3PROPTABLE(CBloom_Trans_Log)

BEGIN_L3METHODMAP(CBloom_Trans_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBloom_Trans_Log,CL3Object)
END_L3EVENTSINK_MAP(CBloom_Trans_Log)

CBloom_Trans_Log::CBloom_Trans_Log(void)
{
}

CBloom_Trans_Log::~CBloom_Trans_Log(void)
{
}
