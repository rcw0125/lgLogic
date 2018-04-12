// 逻辑类CBF_IronLadle_Info源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBF_IronLadle_Info.h"

IMPLEMENT_L3CLASS(CBF_IronLadle_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CBF_IronLadle_Info,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(TPC_No)
	L3PROP_STRING(GroupNo)
	L3PROP_LONG(Order_No)
	L3PROP_DATETIME(ModifyTime)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CBF_IronLadle_Info)

BEGIN_L3METHODMAP(CBF_IronLadle_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBF_IronLadle_Info,CL3Object)
END_L3EVENTSINK_MAP(CBF_IronLadle_Info)

CBF_IronLadle_Info::CBF_IronLadle_Info(void)
{
}

CBF_IronLadle_Info::~CBF_IronLadle_Info(void)
{
}
