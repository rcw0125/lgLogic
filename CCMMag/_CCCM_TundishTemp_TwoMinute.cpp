// 逻辑类CCCM_TundishTemp_TwoMinute源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_TundishTemp_TwoMinute.h"

IMPLEMENT_L3CLASS(CCCM_TundishTemp_TwoMinute,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_TundishTemp_TwoMinute,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Temp)
	L3PROP_DATETIME(Measure_Time)
END_L3PROPTABLE(CCCM_TundishTemp_TwoMinute)

BEGIN_L3METHODMAP(CCCM_TundishTemp_TwoMinute,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_TundishTemp_TwoMinute,CL3Object)
END_L3EVENTSINK_MAP(CCCM_TundishTemp_TwoMinute)

CCCM_TundishTemp_TwoMinute::CCCM_TundishTemp_TwoMinute(void)
{
}

CCCM_TundishTemp_TwoMinute::~CCCM_TundishTemp_TwoMinute(void)
{
}
