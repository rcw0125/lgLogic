// 逻辑类CAOD_HeatRemark源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAOD_HeatRemark.h"

IMPLEMENT_L3CLASS(CAOD_HeatRemark,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_HeatRemark,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Type)
	L3PROP_STRING(Remark)
	L3PROP_DATETIME(LogTime)
END_L3PROPTABLE(CAOD_HeatRemark)

BEGIN_L3METHODMAP(CAOD_HeatRemark,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_HeatRemark,CL3Object)
END_L3EVENTSINK_MAP(CAOD_HeatRemark)

CAOD_HeatRemark::CAOD_HeatRemark(void)
{
}

CAOD_HeatRemark::~CAOD_HeatRemark(void)
{
}