// 逻辑类CBOF_MainPipe_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_MainPipe_Data.h"

IMPLEMENT_L3CLASS(CBOF_MainPipe_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_MainPipe_Data,CL3Object)
	L3PROP_FLOAT(Flow)
	L3PROP_FLOAT(Pressure)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CBOF_MainPipe_Data)

BEGIN_L3METHODMAP(CBOF_MainPipe_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_MainPipe_Data,CL3Object)
END_L3EVENTSINK_MAP(CBOF_MainPipe_Data)

CBOF_MainPipe_Data::CBOF_MainPipe_Data(void)
{
}

CBOF_MainPipe_Data::~CBOF_MainPipe_Data(void)
{
}
