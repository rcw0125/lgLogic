// 逻辑类CEquip_Pole_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Pole_Log.h"

IMPLEMENT_L3CLASS(CEquip_Pole_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Pole_Log,CL3Object)
	L3PROP_STRING(LFID)
	L3PROP_STRING(PhaseNo)
	L3PROP_STRING(Pole_Std)
	L3PROP_STRING(Pole_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Pole_Log)

BEGIN_L3METHODMAP(CEquip_Pole_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Pole_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Pole_Log)

CEquip_Pole_Log::CEquip_Pole_Log(void)
{
}

CEquip_Pole_Log::~CEquip_Pole_Log(void)
{
}
