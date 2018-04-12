// 逻辑类CCCM_WaterGap源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_WaterGap.h"

IMPLEMENT_L3CLASS(CCCM_WaterGap,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_WaterGap,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_STRING(GapID)
	L3PROP_LONG(GapLife)
	L3PROP_STRING(Factory)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(End_Time)
	L3PROP_STRING(Reason)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(MatType)
END_L3PROPTABLE(CCCM_WaterGap)

BEGIN_L3METHODMAP(CCCM_WaterGap,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_WaterGap,CL3Object)
END_L3EVENTSINK_MAP(CCCM_WaterGap)

CCCM_WaterGap::CCCM_WaterGap(void)
{
}

CCCM_WaterGap::~CCCM_WaterGap(void)
{
}
