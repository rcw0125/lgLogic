// 逻辑类CCCM_Heat_Ladle源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_Ladle.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Ladle,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Ladle,CL3Object)
	///2009-02-13 添加是否自动下流、 非自动下流原因
	L3PROP_STRING(HeatID)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(LadleID)
	L3PROP_FLOAT(Weight)
	L3PROP_FLOAT(RemainWeight)
	L3PROP_DATETIME(Arrival_Time)
	L3PROP_STRING(LadleType)
	L3PROP_DATETIME(Departure_Time)
	L3PROP_DATETIME(Casting_Start_Time)
	L3PROP_DATETIME(Casting_Stop_Time)
	L3PROP_LONG(HoldTime)
	L3PROP_LONG(Temp)
	L3PROP_SHORT(TempUpTo)
	L3PROP_STRING(HoldTime_Reason)
	L3PROP_SHORT(Protection)
	L3PROP_STRING(UnProtection_Reason)
	L3PROP_LONG(AutoFlow)
	L3PROP_STRING(UnAutoFlow_Reason)
	L3PROP_FLOAT(CastingTundishWeight)
END_L3PROPTABLE(CCCM_Heat_Ladle)

BEGIN_L3METHODMAP(CCCM_Heat_Ladle,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Ladle,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Ladle)

CCCM_Heat_Ladle::CCCM_Heat_Ladle(void)
{
}

CCCM_Heat_Ladle::~CCCM_Heat_Ladle(void)
{
}
