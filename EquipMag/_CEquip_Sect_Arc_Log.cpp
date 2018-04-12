// 逻辑类CEquip_Sect_Arc_Log源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Sect_Arc_Log.h"

IMPLEMENT_L3CLASS(CEquip_Sect_Arc_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Sect_Arc_Log,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(StrandNo)
	L3PROP_STRING(SectNo)
	L3PROP_STRING(Arc_1stSect_Std)
	L3PROP_STRING(Arc_1stSect_Act)
	L3PROP_STRING(Arc_2ndSect_Std)
	L3PROP_STRING(Arc_2ndSect_Act)
	L3PROP_STRING(Arc_3rdSect_Std)
	L3PROP_STRING(Arc_3rdSect_Act)
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CEquip_Sect_Arc_Log)

BEGIN_L3METHODMAP(CEquip_Sect_Arc_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Sect_Arc_Log,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Sect_Arc_Log)

CEquip_Sect_Arc_Log::CEquip_Sect_Arc_Log(void)
{
}

CEquip_Sect_Arc_Log::~CEquip_Sect_Arc_Log(void)
{
}
