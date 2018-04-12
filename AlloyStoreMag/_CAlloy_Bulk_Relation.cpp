// 逻辑类CAlloy_Bulk_Relation源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_Bulk_Relation.h"

IMPLEMENT_L3CLASS(CAlloy_Bulk_Relation,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Bulk_Relation,CL3Object)
	L3PROP_STRING(Alloy_Area)
	L3PROP_STRING(Alloy_Code)
	L3PROP_LONG(TopSlagFlag)
    L3PROP_STRING(Alloy_Vendor)
END_L3PROPTABLE(CAlloy_Bulk_Relation)

BEGIN_L3METHODMAP(CAlloy_Bulk_Relation,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Bulk_Relation,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Bulk_Relation)

CAlloy_Bulk_Relation::CAlloy_Bulk_Relation(void)
{
}

CAlloy_Bulk_Relation::~CAlloy_Bulk_Relation(void)
{
}
