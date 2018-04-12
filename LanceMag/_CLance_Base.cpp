// 逻辑类CLance_Base源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLance_Base.h"

IMPLEMENT_L3CLASS(CLance_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Base,CL3Object)
	L3PROP_STRING(LanceID)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Status)
	L3PROP_STRING(Nozzle_Factury)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_LONG(Lance_Age)
	L3PROP_STRING(MakeID)
	L3PROP_DATETIME(Make_Start_Time)
	L3PROP_DATETIME(Make_End_Time)
END_L3PROPTABLE(CLance_Base)

BEGIN_L3METHODMAP(CLance_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Base,CL3Object)
END_L3EVENTSINK_MAP(CLance_Base)

CLance_Base::CLance_Base(void)
{
}

CLance_Base::~CLance_Base(void)
{
}
