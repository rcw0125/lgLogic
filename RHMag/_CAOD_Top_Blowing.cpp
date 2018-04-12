// 逻辑类CAOD_Top_Blowing源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAOD_Top_Blowing.h"

IMPLEMENT_L3CLASS(CAOD_Top_Blowing,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Top_Blowing,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_FLOAT(Flow)
	L3PROP_FLOAT(Pressure)
	L3PROP_DATETIME(Catch_Time)
	L3PROP_DOUBLE(Flow_MainPipe)
	L3PROP_DOUBLE(Press_MainPipe)
END_L3PROPTABLE(CAOD_Top_Blowing)

BEGIN_L3METHODMAP(CAOD_Top_Blowing,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Top_Blowing,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Top_Blowing)

CAOD_Top_Blowing::CAOD_Top_Blowing(void)
{
}

CAOD_Top_Blowing::~CAOD_Top_Blowing(void)
{
}
