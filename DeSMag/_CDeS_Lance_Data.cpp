// 逻辑类CDeS_Lance_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Lance_Data.h"

IMPLEMENT_L3CLASS(CDeS_Lance_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Lance_Data,CL3Object)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(Status)
	L3PROP_LONG(LanceAge)
	L3PROP_STRING(LanceVendor)
	L3PROP_LONG(ProcessTime)
	L3PROP_DOUBLE(ProcessAmount)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(OpTime)
END_L3PROPTABLE(CDeS_Lance_Data)

BEGIN_L3METHODMAP(CDeS_Lance_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Lance_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Lance_Data)

CDeS_Lance_Data::CDeS_Lance_Data(void)
{
}

CDeS_Lance_Data::~CDeS_Lance_Data(void)
{
}
