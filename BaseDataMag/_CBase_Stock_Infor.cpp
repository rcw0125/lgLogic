// 逻辑类Stock_Base_Infor源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBase_Stock_Infor.h"

IMPLEMENT_L3CLASS(CBase_Stock_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Stock_Infor,CL3Object)
	L3PROP_STRING(Pk_Stock)
	L3PROP_STRING(Stock_Code)
	L3PROP_STRING(Stock_Name)
END_L3PROPTABLE(CBase_Stock_Infor)

BEGIN_L3METHODMAP(CBase_Stock_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Stock_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Stock_Infor)

CBase_Stock_Infor::CBase_Stock_Infor(void)
{
}

CBase_Stock_Infor::~CBase_Stock_Infor(void)
{
}
