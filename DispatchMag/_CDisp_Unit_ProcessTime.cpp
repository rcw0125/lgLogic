// 逻辑类CDisp_Unit_ProcessTime源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDisp_Unit_ProcessTime.h"

IMPLEMENT_L3CLASS(CDisp_Unit_ProcessTime,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Unit_ProcessTime,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(ProductDate)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(ProcessType)
	L3PROP_LONG(ProcessTime)
	L3PROP_DATETIME(CreateTime)
END_L3PROPTABLE(CDisp_Unit_ProcessTime)

BEGIN_L3METHODMAP(CDisp_Unit_ProcessTime,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Unit_ProcessTime,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Unit_ProcessTime)

CDisp_Unit_ProcessTime::CDisp_Unit_ProcessTime(void)
{
}

CDisp_Unit_ProcessTime::~CDisp_Unit_ProcessTime(void)
{
}
