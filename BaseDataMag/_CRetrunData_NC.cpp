// 逻辑类CRetrunData_NC源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRetrunData_NC.h"

IMPLEMENT_L3CLASS(CRetrunData_NC,CL3Object,1)

BEGIN_L3PROPTABLE(CRetrunData_NC,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(BillType)
	L3PROP_STRING(Flag)
	L3PROP_STRING_LEN(Remark,2000)
	L3PROP_DATETIME(CreateTime)
	L3PROP_STRING(Other1)
	L3PROP_STRING(Other2)
	L3PROP_STRING(Other3)
END_L3PROPTABLE(CRetrunData_NC)

BEGIN_L3METHODMAP(CRetrunData_NC,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRetrunData_NC,CL3Object)
END_L3EVENTSINK_MAP(CRetrunData_NC)

CRetrunData_NC::CRetrunData_NC(void)
{
}

CRetrunData_NC::~CRetrunData_NC(void)
{
}
