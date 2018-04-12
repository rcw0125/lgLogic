// 逻辑类CBOF_Oxygen_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_Oxygen_Data.h"

IMPLEMENT_L3CLASS(CBOF_Oxygen_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Oxygen_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Oxygen_Content)
	L3PROP_DATETIME(Measure_Time)
	L3PROP_LONG(Temp)
END_L3PROPTABLE(CBOF_Oxygen_Data)

BEGIN_L3METHODMAP(CBOF_Oxygen_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Oxygen_Data,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Oxygen_Data)

CBOF_Oxygen_Data::CBOF_Oxygen_Data(void)
{
}

CBOF_Oxygen_Data::~CBOF_Oxygen_Data(void)
{
}
