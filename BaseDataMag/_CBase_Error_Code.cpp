// 逻辑类CBase_Error_Code源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBase_Error_Code.h"

IMPLEMENT_L3CLASS(CBase_Error_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Error_Code,CL3Object)
	L3PROP_STRING(Error_Code)
	L3PROP_STRING(Error_Des)
	L3PROP_STRING(Owner)
	L3PROP_STRING(Owner_Des)
	L3PROP_STRING(Error_Val_Long)
END_L3PROPTABLE(CBase_Error_Code)

BEGIN_L3METHODMAP(CBase_Error_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Error_Code,CL3Object)
END_L3EVENTSINK_MAP(CBase_Error_Code)

CBase_Error_Code::CBase_Error_Code(void)
{
}

CBase_Error_Code::~CBase_Error_Code(void)
{
}
