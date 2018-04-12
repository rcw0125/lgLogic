// 逻辑类CCost_Medium_Consume_Standard源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCost_Medium_Consume_Std.h"

IMPLEMENT_L3CLASS(CCost_Medium_Consume_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CCost_Medium_Consume_Std,CL3Object)
	L3PROP_STRING(Medium)
	L3PROP_STRING(Cost_Center)
	L3PROP_STRING(Stock_Type)
	L3PROP_FLOAT(Standard_Cost)
END_L3PROPTABLE(CCost_Medium_Consume_Std)

BEGIN_L3METHODMAP(CCost_Medium_Consume_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCost_Medium_Consume_Std,CL3Object)
END_L3EVENTSINK_MAP(CCost_Medium_Consume_Std)

CCost_Medium_Consume_Std::CCost_Medium_Consume_Std(void)
{
}

CCost_Medium_Consume_Std::~CCost_Medium_Consume_Std(void)
{
}
