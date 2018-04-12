// 逻辑类CCCM_Duty源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Duty.h"

IMPLEMENT_L3CLASS(CCCM_Duty,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Duty,CL3Object)

	L3PROP_STRING(CCMID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(Station)
	L3PROP_STRING(Operator_name)

END_L3PROPTABLE(CCCM_Duty)

BEGIN_L3METHODMAP(CCCM_Duty,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Duty,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Duty)

CCCM_Duty::CCCM_Duty(void)
{
}

CCCM_Duty::~CCCM_Duty(void)
{
}
