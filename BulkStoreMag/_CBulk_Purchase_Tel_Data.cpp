// 逻辑类CBulk_Tel_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBulk_Purchase_Tel_Data.h"

IMPLEMENT_L3CLASS(CBulk_Purchase_Tel_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBulk_Purchase_Tel_Data,CL3Object)
	L3PROP_DATETIME(Rec_Time)
	L3PROP_STRING(vbillcode)
	L3PROP_STRING(cwarehouseid)
	L3PROP_STRING(cinventoryid)
	L3PROP_STRING(Invcode)
	L3PROP_STRING(Invname)
	L3PROP_STRING(Invspec)
	L3PROP_STRING(Invtype)
	L3PROP_DATETIME(dbizdate)
	L3PROP_DOUBLE(ninnum)
	L3PROP_LONG(ninassistnum)
	L3PROP_STRING(vuserdef1)
	L3PROP_STRING(vuserdef2)
	L3PROP_STRING(vuserdef3)
	L3PROP_STRING(vuserdef4)
	L3PROP_STRING(vuserdef5)
	L3PROP_STRING(vfree1)
	L3PROP_STRING(vfree2)
	L3PROP_STRING(vfree3)
	L3PROP_STRING(vfree4)
	L3PROP_STRING(vfree5)
	L3PROP_STRING(pk_corp)
END_L3PROPTABLE(CBulk_Purchase_Tel_Data)

BEGIN_L3METHODMAP(CBulk_Purchase_Tel_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Purchase_Tel_Data,CL3Object)
END_L3EVENTSINK_MAP(CBulk_Purchase_Tel_Data)

CBulk_Purchase_Tel_Data::CBulk_Purchase_Tel_Data(void)
{
}

CBulk_Purchase_Tel_Data::~CBulk_Purchase_Tel_Data(void)
{
}
