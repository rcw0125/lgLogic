// 逻辑类CBOF_Bottom_Blowing源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_Bottom_Blowing.h"

IMPLEMENT_L3CLASS(CBOF_Bottom_Blowing,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Bottom_Blowing,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_DOUBLE(Flow1)
	L3PROP_DOUBLE(Pressure1)
	L3PROP_DOUBLE(Flow2)
	L3PROP_DOUBLE(Pressure2)
	L3PROP_DOUBLE(Flow3)
	L3PROP_DOUBLE(Pressure3)
	L3PROP_DOUBLE(Flow4)
	L3PROP_DOUBLE(Pressure4)
	L3PROP_DOUBLE(Flow5)
	L3PROP_DOUBLE(Pressure5)
	L3PROP_DOUBLE(Flow6)
	L3PROP_DOUBLE(Pressure6)
	L3PROP_STRING(Gas_Type)
	L3PROP_DATETIME(Catch_Time)
	L3PROP_STRING(ObjectID)
END_L3PROPTABLE(CBOF_Bottom_Blowing)

BEGIN_L3METHODMAP(CBOF_Bottom_Blowing,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Bottom_Blowing,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Bottom_Blowing)

CBOF_Bottom_Blowing::CBOF_Bottom_Blowing(void)
{
}

CBOF_Bottom_Blowing::~CBOF_Bottom_Blowing(void)
{
}
