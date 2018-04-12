// 逻辑类CDeS_Addition_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Addition_Data.h"

IMPLEMENT_L3CLASS(CDeS_Addition_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Addition_Data,CL3Object)
    L3PROP_STRING(UnitID)
	L3PROP_STRING(Mat_Code)
	L3PROP_STRING(Mat_Vendor)
	L3PROP_FLOAT(Weight)
	L3PROP_DATETIME(Time_Discharge)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
	L3PROP_DATETIME(Time_Begin_Discharge)
	L3PROP_DATETIME(Time_Stop_Discharge)
END_L3PROPTABLE(CDeS_Addition_Data)

BEGIN_L3METHODMAP(CDeS_Addition_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Addition_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Addition_Data)

CDeS_Addition_Data::CDeS_Addition_Data(void)
{
}

CDeS_Addition_Data::~CDeS_Addition_Data(void)
{
}
