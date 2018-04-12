// 逻辑类CAOD_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAOD_Process_Data.h"

IMPLEMENT_L3CLASS(CAOD_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Process_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Arrival_Time)
	L3PROP_SHORT(Arrival_Temp)
	L3PROP_DATETIME(Change_Start_Time)
    L3PROP_DATETIME(Blow_Start_Time)
	L3PROP_DATETIME(C_Start_Time)
	L3PROP_DATETIME(C_End_Time)
	L3PROP_DATETIME(Tapping_Start_Time)
	L3PROP_DATETIME(Tapping_End_Time)
	L3PROP_DATETIME(Side_Start_Time)
	L3PROP_DATETIME(Side_End_Time)
	L3PROP_LONG(C_Time)
	L3PROP_LONG(Tapping_Time)
	L3PROP_LONG(Smelt_Period)
	L3PROP_DOUBLE(O_Consume)
	L3PROP_DOUBLE(N_Consume)
	L3PROP_DOUBLE(Ar_Consume)
	L3PROP_LONG(Steel_Temp)
	L3PROP_LONG(Sheet_Temp)
	L3PROP_LONG(Return_Temp)
	L3PROP_LONG(Ladle_Temp)
	L3PROP_DOUBLE(Tapping_Weight)
	L3PROP_LONG(Lance_No)
	L3PROP_LONG(Furnace_No)
	L3PROP_LONG(Furnace_Age)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(Ladle_Status)
	L3PROP_STRING(Ladle_Grade)
END_L3PROPTABLE(CAOD_Process_Data)

BEGIN_L3METHODMAP(CAOD_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Process_Data)

CAOD_Process_Data::CAOD_Process_Data(void)
{
}

CAOD_Process_Data::~CAOD_Process_Data(void)
{
}
