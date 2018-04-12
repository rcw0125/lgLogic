// 逻辑类CDeS_Runtime_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDEP_Runtime_Data.h"

IMPLEMENT_L3CLASS(CDEP_Runtime_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Runtime_Data,CL3Object)
    L3PROP_STRING(ID_Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(Materialid)
	L3PROP_DOUBLE(N_Pressure)
	L3PROP_DOUBLE(Spray_Pressure)
	L3PROP_DOUBLE(Spray_Flow)
	L3PROP_DOUBLE(Lime_Rate)
	L3PROP_DOUBLE(O_Pressure)
	L3PROP_DOUBLE(O_Flow)
	L3PROP_DOUBLE(D_Value)
	L3PROP_LONG(Zhan_Temp)
	L3PROP_LONG(Ji_Temp)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CDEP_Runtime_Data)

BEGIN_L3METHODMAP(CDEP_Runtime_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Runtime_Data,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Runtime_Data)

CDEP_Runtime_Data::CDEP_Runtime_Data(void)
{
}

CDEP_Runtime_Data::~CDEP_Runtime_Data(void)
{
}
