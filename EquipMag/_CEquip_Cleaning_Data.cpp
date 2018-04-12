// 逻辑类CEquip_Cleaning_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEquip_Cleaning_Data.h"

IMPLEMENT_L3CLASS(CEquip_Cleaning_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CEquip_Cleaning_Data,CL3Object)
	L3PROP_STRING(TagName)
	L3PROP_LONG(TagType)
	L3PROP_LONG(TagValue)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CEquip_Cleaning_Data)

BEGIN_L3METHODMAP(CEquip_Cleaning_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEquip_Cleaning_Data,CL3Object)
END_L3EVENTSINK_MAP(CEquip_Cleaning_Data)

CEquip_Cleaning_Data::CEquip_Cleaning_Data(void)
{
}

CEquip_Cleaning_Data::~CEquip_Cleaning_Data(void)
{
}
