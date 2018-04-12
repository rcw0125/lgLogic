// 逻辑类CDEP_HeatRemark源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDEP_HeatRemark.h"

IMPLEMENT_L3CLASS(CDEP_HeatRemark,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_HeatRemark,CL3Object)
    L3PROP_STRING(IronLadle)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(TypeID)
	L3PROP_STRING(Remark)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CDEP_HeatRemark)

BEGIN_L3METHODMAP(CDEP_HeatRemark,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_HeatRemark,CL3Object)
END_L3EVENTSINK_MAP(CDEP_HeatRemark)

CDEP_HeatRemark::CDEP_HeatRemark(void)
{
}

CDEP_HeatRemark::~CDEP_HeatRemark(void)
{
}
