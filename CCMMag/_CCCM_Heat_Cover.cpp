// 逻辑类CCCM_Heat_Cover源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_Cover.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Cover,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Cover,CL3Object)
	///2009-02-13 添加批次号、使用情况
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(Element)
	L3PROP_FLOAT(Amount)
	L3PROP_STRING(Origin)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(UseInformation)
END_L3PROPTABLE(CCCM_Heat_Cover)

BEGIN_L3METHODMAP(CCCM_Heat_Cover,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Cover,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Cover)

CCCM_Heat_Cover::CCCM_Heat_Cover(void)
{
}

CCCM_Heat_Cover::~CCCM_Heat_Cover(void)
{
}
