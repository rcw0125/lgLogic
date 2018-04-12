// 逻辑类CAlloy_Element_Tel_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_Element_Tel_Data.h"

IMPLEMENT_L3CLASS(CAlloy_Element_Tel_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Element_Tel_Data,CL3Object)
	L3PROP_DATETIME(Rec_Time)
	L3PROP_STRING(vstobatchcode)
	L3PROP_STRING(vcheckbillcode)
	L3PROP_STRING(bcompcheck)
	L3PROP_LONG(ninassistnum)
	L3PROP_STRING(cstoreorganization)
	L3PROP_STRING(cpraycorp)
	L3PROP_STRING(ccheckbillid)
	L3PROP_STRING(cbaseid)
	L3PROP_STRING(vsamplecode)
	L3PROP_STRING(ninnum)
	L3PROP_STRING(ccheckitemid)
	L3PROP_DOUBLE(cresult)
END_L3PROPTABLE(CAlloy_Element_Tel_Data)

BEGIN_L3METHODMAP(CAlloy_Element_Tel_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Element_Tel_Data,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Element_Tel_Data)

CAlloy_Element_Tel_Data::CAlloy_Element_Tel_Data(void)
{
}

CAlloy_Element_Tel_Data::~CAlloy_Element_Tel_Data(void)
{
}
