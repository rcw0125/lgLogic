// 逻辑类CLF_Wire_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLF_Wire_Data.h"

IMPLEMENT_L3CLASS(CLF_Wire_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Wire_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(WireCode)
	L3PROP_FLOAT(Weight)
	L3PROP_FLOAT(Speed)
	L3PROP_DATETIME(WireTime)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Vendor)
	L3PROP_FLOAT(Amount)
END_L3PROPTABLE(CLF_Wire_Data)

BEGIN_L3METHODMAP(CLF_Wire_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Wire_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Wire_Data)

CLF_Wire_Data::CLF_Wire_Data(void)
{
}

CLF_Wire_Data::~CLF_Wire_Data(void)
{
}
