// 逻辑类CCCM_Tundish_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Tundish_Data.h"

IMPLEMENT_L3CLASS(CCCM_Tundish_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Tundish_Data,CL3Object)

	///2009-02-13 删除中包工作层材质、中包工作层产地、中包挡渣墙、中包挡渣墙厂家、
	///中包挡渣墙材质、预热小火开始时刻、预热中火开始时刻、预热大火开始时刻、预热结束时刻、
	///预热结束中包工作层温度、预热结束浸入式水口温度、浸入式水口型号、浸入式水口产地、
	///塞棒型号、塞棒产地、中包盖编号、中包盖编号、中包废弃品、中包厂内废、中包覆盖剂名称、中包覆盖剂数量
	///增加：包次开始时刻、包次结束时刻、中包工作层编号

	L3PROP_STRING(TundishNo)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(Tundish_CarID)
	L3PROP_STRING(First_HeatID)
	L3PROP_STRING(Last_HeatID)
	L3PROP_LONG(HeatCount)
	L3PROP_STRING(Fender_Slag_Usage_Case)
	L3PROP_STRING(Cover_Factory)
	L3PROP_STRING(Reason_Holt_Casting)
	L3PROP_DOUBLE(Remain_Steel_Weight)
	L3PROP_DATETIME(Casting_Start_Time)
	L3PROP_DATETIME(Casting_Stop_Time)	
	L3PROP_STRING(WorkID)

END_L3PROPTABLE(CCCM_Tundish_Data)

BEGIN_L3METHODMAP(CCCM_Tundish_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Tundish_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Tundish_Data)

CCCM_Tundish_Data::CCCM_Tundish_Data(void)
{
}

CCCM_Tundish_Data::~CCCM_Tundish_Data(void)
{
}
