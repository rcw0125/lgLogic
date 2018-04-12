// 逻辑类CScrapOutStoreDetail源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CScrapOutStoreDetail.h"

IMPLEMENT_L3CLASS(CScrapOutStoreDetail,CL3Object,1)

BEGIN_L3PROPTABLE(CScrapOutStoreDetail,CL3Object)
	L3PROP_STRING(SCRAP_SLOT_ID)
	L3PROP_STRING(MATERIAL)
	L3PROP_STRING(MATERIAL_CODE)
	L3PROP_STRING(AMOUNT)
END_L3PROPTABLE(CScrapOutStoreDetail)

BEGIN_L3METHODMAP(CScrapOutStoreDetail,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrapOutStoreDetail,CL3Object)
END_L3EVENTSINK_MAP(CScrapOutStoreDetail)

CScrapOutStoreDetail::CScrapOutStoreDetail(void)
{
}

CScrapOutStoreDetail::~CScrapOutStoreDetail(void)
{
}
