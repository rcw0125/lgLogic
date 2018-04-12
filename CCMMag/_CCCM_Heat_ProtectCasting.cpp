// 逻辑类CCCM_Heat_ProtectCasting源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_ProtectCasting.h"

IMPLEMENT_L3CLASS(CCCM_Heat_ProtectCasting,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_ProtectCasting,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(Stop_Time)
	L3PROP_FLOAT(Ar_Flow)
END_L3PROPTABLE(CCCM_Heat_ProtectCasting)

BEGIN_L3METHODMAP(CCCM_Heat_ProtectCasting,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_ProtectCasting,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_ProtectCasting)

CCCM_Heat_ProtectCasting::CCCM_Heat_ProtectCasting(void)
{
}

CCCM_Heat_ProtectCasting::~CCCM_Heat_ProtectCasting(void)
{
}
