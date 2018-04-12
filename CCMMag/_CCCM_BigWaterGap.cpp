// 逻辑类CCCM_BigWaterGap源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_BigWaterGap.h"

IMPLEMENT_L3CLASS(CCCM_BigWaterGap,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_BigWaterGap,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_STRING(GapID)
	L3PROP_STRING(Factory)
	L3PROP_STRING(MatType)
	L3PROP_LONG(GapLife)
	L3PROP_DATETIME(ChangeTime)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CCCM_BigWaterGap)

BEGIN_L3METHODMAP(CCCM_BigWaterGap,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_BigWaterGap,CL3Object)
END_L3EVENTSINK_MAP(CCCM_BigWaterGap)

CCCM_BigWaterGap::CCCM_BigWaterGap(void)
{
}

CCCM_BigWaterGap::~CCCM_BigWaterGap(void)
{
}
