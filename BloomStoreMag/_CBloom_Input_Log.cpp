// 逻辑类CBloom_Input_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBloom_Input_Log.h"

IMPLEMENT_L3CLASS(CBloom_Input_Log,MaterialInputLog,1)

BEGIN_L3PROPTABLE(CBloom_Input_Log,MaterialInputLog)
	L3PROP_LONG(Bloom_Count)
	L3PROP_DOUBLE(Waster_Count)
	L3PROP_LONG(Wrong_Count)
	L3PROP_LONG(Right_Count)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Cur_Section_ID)
	L3PROP_STRING(Cur_Bay_ID)
	L3PROP_STRING(Cur_Pile_ID)
	L3PROP_STRING(Cur_Layer_ID)
	L3PROP_LONG(Cur_Seq_ID)
	///2009-02-23增加以下字段
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_DOUBLE(Right_Weight)
	L3PROP_DOUBLE(Waster_Weight)
	L3PROP_DOUBLE(Wrong_Weight)

END_L3PROPTABLE(CBloom_Input_Log)

BEGIN_L3METHODMAP(CBloom_Input_Log,MaterialInputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBloom_Input_Log,MaterialInputLog)
END_L3EVENTSINK_MAP(CBloom_Input_Log)

CBloom_Input_Log::CBloom_Input_Log(void)
{
}

CBloom_Input_Log::~CBloom_Input_Log(void)
{
}
