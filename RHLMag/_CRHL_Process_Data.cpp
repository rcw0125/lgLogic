// 逻辑类CRHL_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRHL_Process_Data.h"

IMPLEMENT_L3CLASS(CRHL_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CRHL_Process_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Arrival_Time)
	L3PROP_SHORT(Arrival_Temp)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(End_Time)
	L3PROP_LONG(Process_Time)
	L3PROP_LONG(Heat_Time)
	L3PROP_SHORT(Heat_Count)

	L3PROP_DOUBLE(Current_Position)
	L3PROP_DOUBLE(E_V)
	L3PROP_DOUBLE(E_A)
	L3PROP_DOUBLE(O_Pressure)
	L3PROP_DOUBLE(O_Flow)
	L3PROP_DOUBLE(Gas_Pressure)
	L3PROP_DOUBLE(Gas_Flow)
	L3PROP_DOUBLE(Gas_F_Flow)
	L3PROP_DOUBLE(Spray_Pressure)
	L3PROP_DOUBLE(Spray_Flow)
	L3PROP_DOUBLE(Bodyin_Pressure)
	L3PROP_DOUBLE(Bodyin_Flow)
	L3PROP_DOUBLE(Bodyout_Pressure)
	L3PROP_DOUBLE(Bodyout_Flow)
	L3PROP_DOUBLE(Topin_Pressure)
	L3PROP_DOUBLE(Topin_Flow)
	L3PROP_DOUBLE(Wallin_Pressure)
	L3PROP_DOUBLE(Wallin_Flow)
	L3PROP_DOUBLE(Wallout_Pressure)
	L3PROP_DOUBLE(Wallout_Flow)
	L3PROP_DOUBLE(Coldin_Pressure)
	L3PROP_DOUBLE(Coldin_Flow)
	L3PROP_DOUBLE(Coldout_Pressure)
	L3PROP_DOUBLE(Coldout_Flow)
	L3PROP_DOUBLE(Angle)
	L3PROP_FLOAT(Steel_Weight)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(Ladle_Grade)//2009-03-30
END_L3PROPTABLE(CRHL_Process_Data)

BEGIN_L3METHODMAP(CRHL_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CRHL_Process_Data)

CRHL_Process_Data::CRHL_Process_Data(void)
{
}

CRHL_Process_Data::~CRHL_Process_Data(void)
{
}
