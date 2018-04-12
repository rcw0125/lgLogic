// 逻辑类CDisp_Exceptional源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDisp_Exceptional.h"

IMPLEMENT_L3CLASS(CDisp_Exceptional,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Exceptional,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(CreateDate)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(CreateTime)
	L3PROP_STRING(Operator)
	L3PROP_LONG(SendFlag)
END_L3PROPTABLE(CDisp_Exceptional)

BEGIN_L3METHODMAP(CDisp_Exceptional,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Exceptional,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Exceptional)

CDisp_Exceptional::CDisp_Exceptional(void)
{
}

CDisp_Exceptional::~CDisp_Exceptional(void)
{
}
