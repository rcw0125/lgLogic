// 逻辑类Team_Base_Infor源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBase_Team_Infor.h"

IMPLEMENT_L3CLASS(CBase_Team_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Team_Infor,CL3Object)
	L3PROP_STRING(Pk_Team)
	L3PROP_STRING(Team_Code)
	L3PROP_STRING(Team_Name)
	L3PROP_STRING(Pk_Center)
	L3PROP_STRING(Pk_Department)
END_L3PROPTABLE(CBase_Team_Infor)

BEGIN_L3METHODMAP(CBase_Team_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Team_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Team_Infor)

CBase_Team_Infor::CBase_Team_Infor(void)
{
}

CBase_Team_Infor::~CBase_Team_Infor(void)
{
}
