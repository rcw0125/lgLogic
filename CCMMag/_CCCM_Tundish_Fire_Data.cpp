// 逻辑类CCCM_Tundish_Fire_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Tundish_Fire_Data.h"

IMPLEMENT_L3CLASS(CCCM_Tundish_Fire_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Tundish_Fire_Data,CL3Object)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(TundishID)
	L3PROP_FLOAT(Flow_Gas)
	L3PROP_STRING(Position)
	L3PROP_STRING(Fire_Type)
	L3PROP_DATETIME(MeasureTime)
END_L3PROPTABLE(CCCM_Tundish_Fire_Data)

BEGIN_L3METHODMAP(CCCM_Tundish_Fire_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Tundish_Fire_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Tundish_Fire_Data)

CCCM_Tundish_Fire_Data::CCCM_Tundish_Fire_Data(void)
{
}

CCCM_Tundish_Fire_Data::~CCCM_Tundish_Fire_Data(void)
{
}
