// 逻辑类CCCM_Heat_FaultyGoods源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_FaultyGoods.h"

IMPLEMENT_L3CLASS(CCCM_Heat_FaultyGoods,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_FaultyGoods,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(BloomID)
	L3PROP_FLOAT(Weight)
	L3PROP_STRING(Reason)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CCCM_Heat_FaultyGoods)

BEGIN_L3METHODMAP(CCCM_Heat_FaultyGoods,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_FaultyGoods,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_FaultyGoods)

CCCM_Heat_FaultyGoods::CCCM_Heat_FaultyGoods(void)
{
}

CCCM_Heat_FaultyGoods::~CCCM_Heat_FaultyGoods(void)
{
}
