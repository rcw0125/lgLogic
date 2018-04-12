// 逻辑类CDeS_Runtime_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Runtime_Data.h"

IMPLEMENT_L3CLASS(CDeS_Runtime_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Runtime_Data,CL3Object)
	L3PROP_STRING(ID_Object)
	L3PROP_STRING(TreatNo)
	L3PROP_DOUBLE(Pressure)
	L3PROP_DOUBLE(Flow)
	L3PROP_DOUBLE(Rate)
	L3PROP_LONG(Catch_Count)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CDeS_Runtime_Data)

BEGIN_L3METHODMAP(CDeS_Runtime_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Runtime_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Runtime_Data)

CDeS_Runtime_Data::CDeS_Runtime_Data(void)
{
}

CDeS_Runtime_Data::~CDeS_Runtime_Data(void)
{
}
