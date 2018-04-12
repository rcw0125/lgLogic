// 逻辑类CEquip_Lance_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Lance_Log.h"

IMPLEMENT_L3CLASS(CEquip_Lance_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Lance_Log,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Lance_Std)
	L3PROP_STRING(Lance_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Lance_Log)

BEGIN_L3METHODMAP(CEquip_Lance_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Lance_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Lance_Log)

CEquip_Lance_Log::CEquip_Lance_Log(void)
{
}

CEquip_Lance_Log::~CEquip_Lance_Log(void)
{
}
