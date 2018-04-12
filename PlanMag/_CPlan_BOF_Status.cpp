// 逻辑类CPlan_BOF_Status源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_BOF_Status.h"

IMPLEMENT_L3CLASS(CPlan_BOF_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_BOF_Status,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Status)
	L3PROP_SHORT(New_BOF_Flag)
END_L3PROPTABLE(CPlan_BOF_Status)

BEGIN_L3METHODMAP(CPlan_BOF_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_BOF_Status,CL3Object)
END_L3EVENTSINK_MAP(CPlan_BOF_Status)

CPlan_BOF_Status::CPlan_BOF_Status(void)
{
}

CPlan_BOF_Status::~CPlan_BOF_Status(void)
{
}
