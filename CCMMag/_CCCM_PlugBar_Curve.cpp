// 逻辑类CCCM_PlugBar_Curve源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_PlugBar_Curve.h"

IMPLEMENT_L3CLASS(CCCM_PlugBar_Curve,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_PlugBar_Curve,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(ValueID)
	L3PROP_DATETIME(Clock)
	L3PROP_DOUBLE(Val)
END_L3PROPTABLE(CCCM_PlugBar_Curve)

BEGIN_L3METHODMAP(CCCM_PlugBar_Curve,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_PlugBar_Curve,CL3Object)
END_L3EVENTSINK_MAP(CCCM_PlugBar_Curve)

CCCM_PlugBar_Curve::CCCM_PlugBar_Curve(void)
{
}

CCCM_PlugBar_Curve::~CCCM_PlugBar_Curve(void)
{
}
