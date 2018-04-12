// 逻辑类CEquip_Oscillate_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Oscillate_Log.h"

IMPLEMENT_L3CLASS(CEquip_Oscillate_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Oscillate_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(Swing_Std)
	L3PROP_STRING(Swing_Act)
	L3PROP_STRING(Freq_Setup)
	L3PROP_STRING(Freq_Act)
	L3PROP_STRING(Ampl_Setup)
	L3PROP_STRING(Ampl_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Oscillate_Log)

BEGIN_L3METHODMAP(CEquip_Oscillate_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Oscillate_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Oscillate_Log)

CEquip_Oscillate_Log::CEquip_Oscillate_Log(void)
{
}

CEquip_Oscillate_Log::~CEquip_Oscillate_Log(void)
{
}
