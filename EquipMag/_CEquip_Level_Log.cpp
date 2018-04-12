// 逻辑类CEquip_Level_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Level_Log.h"

IMPLEMENT_L3CLASS(CEquip_Level_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Level_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(Zero_B_Act)
	L3PROP_STRING(Zero_A_Act)
	L3PROP_STRING(Full_B_Act)
	L3PROP_STRING(Full_A_Act)
	L3PROP_STRING(N0_Std)
	L3PROP_STRING(N0_Act)
	L3PROP_STRING(N7_N8_Std)
	L3PROP_STRING(N7_N8_Act)
	L3PROP_STRING(N10_Std)
	L3PROP_STRING(N10_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Level_Log)

BEGIN_L3METHODMAP(CEquip_Level_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Level_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Level_Log)

CEquip_Level_Log::CEquip_Level_Log(void)
{
}

CEquip_Level_Log::~CEquip_Level_Log(void)
{
}
