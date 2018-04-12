// 逻辑类CCalibration_Set源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCalibration_Set.h"

IMPLEMENT_L3CLASS(CCalibration_Set,CL3Object,1)

BEGIN_L3PROPTABLE(CCalibration_Set,CL3Object)
	L3PROP_STRING(Location)
	L3PROP_STRING(Location_Des)
	L3PROP_STRING(Meter)
	L3PROP_STRING(Meter_Size)
	L3PROP_STRING(Range)
	L3PROP_STRING(Precision)
	L3PROP_STRING(Factory)
	L3PROP_STRING(Measure_ID)
	L3PROP_STRING(Standard_Equ)
	L3PROP_STRING(Scale_Min)
END_L3PROPTABLE(CCalibration_Set)

BEGIN_L3METHODMAP(CCalibration_Set,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCalibration_Set,CL3Object)
END_L3EVENTSINK_MAP(CCalibration_Set)

CCalibration_Set::CCalibration_Set(void)
{
}

CCalibration_Set::~CCalibration_Set(void)
{
}
