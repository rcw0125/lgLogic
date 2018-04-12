// 逻辑类CAlloy_App源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_App.h"

IMPLEMENT_L3CLASS(CAlloy_App,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_App,CL3Object)
	L3PROP_STRING(Alloy_Code)
	L3PROP_DOUBLE(Amount)
	L3PROP_DATETIME(App_Time)
	L3PROP_STRING(App_UnitID)
	L3PROP_STRING(App_Operator)
	L3PROP_LONG(Confirm_Flag)
	L3PROP_STRING(Confirm_Operator)
	L3PROP_DATETIME(Confirm_Time)
END_L3PROPTABLE(CAlloy_App)

BEGIN_L3METHODMAP(CAlloy_App,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_App,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_App)

CAlloy_App::CAlloy_App(void)
{
}

CAlloy_App::~CAlloy_App(void)
{
}
