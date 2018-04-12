// 逻辑类CCCM_StrandInfo源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_StrandInfo.h"

IMPLEMENT_L3CLASS(CCCM_StrandInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_StrandInfo,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_LONG(OnOff)
	L3PROP_DATETIME(ChangeTime)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CCCM_StrandInfo)

BEGIN_L3METHODMAP(CCCM_StrandInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_StrandInfo,CL3Object)
END_L3EVENTSINK_MAP(CCCM_StrandInfo)

CCCM_StrandInfo::CCCM_StrandInfo(void)
{
}

CCCM_StrandInfo::~CCCM_StrandInfo(void)
{
}
