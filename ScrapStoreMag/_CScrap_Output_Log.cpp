// 逻辑类CScrap_Output_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CScrap_Output_Log.h"

IMPLEMENT_L3CLASS(CScrap_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CScrap_Output_Log,MaterialOutputLog)
	L3PROP_STRING(Scrap_Slot_ID)
	L3PROP_STRING(Car_ID)
	L3PROP_STRING(Car_Type)
	L3PROP_DOUBLE(Net_Weight)
	L3PROP_DOUBLE(Gross_Weight)
	L3PROP_DOUBLE(Tare_Weight)
	L3PROP_LONG(Iron_Flag)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CScrap_Output_Log)

BEGIN_L3METHODMAP(CScrap_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrap_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CScrap_Output_Log)

CScrap_Output_Log::CScrap_Output_Log(void)
{
}

CScrap_Output_Log::~CScrap_Output_Log(void)
{
}
