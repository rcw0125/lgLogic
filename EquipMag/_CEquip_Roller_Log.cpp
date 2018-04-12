// 逻辑类CEquip_Roller_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Roller_Log.h"

IMPLEMENT_L3CLASS(CEquip_Roller_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Roller_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(Roller_Std)
	L3PROP_STRING(Roller1_Act)
	L3PROP_STRING(Roller2_Act)
	L3PROP_STRING(Roller3_Act)
	L3PROP_STRING(Roller4_Act)
	L3PROP_STRING(Roller5_Act)
	L3PROP_STRING(Roller6_Act)
	L3PROP_STRING(Roller7_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Roller_Log)

BEGIN_L3METHODMAP(CEquip_Roller_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Roller_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Roller_Log)

CEquip_Roller_Log::CEquip_Roller_Log(void)
{
}

CEquip_Roller_Log::~CEquip_Roller_Log(void)
{
}
