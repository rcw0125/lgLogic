// 逻辑类CDisp_Exceptional_Items源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDisp_Exceptional_Items.h"

IMPLEMENT_L3CLASS(CDisp_Exceptional_Items,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Exceptional_Items,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(Items)
	L3PROP_STRING(BeginTime)
	L3PROP_STRING(EndTime)
	L3PROP_LONG(TimeSpan)
	L3PROP_STRING_LEN(Note,500)
	L3PROP_STRING(CreateTime)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CDisp_Exceptional_Items)

BEGIN_L3METHODMAP(CDisp_Exceptional_Items,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Exceptional_Items,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Exceptional_Items)

CDisp_Exceptional_Items::CDisp_Exceptional_Items(void)
{
}

CDisp_Exceptional_Items::~CDisp_Exceptional_Items(void)
{
}
