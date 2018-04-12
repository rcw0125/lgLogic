// 逻辑类CLF_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLF_Process_Data.h"

IMPLEMENT_L3CLASS(CLF_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Process_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Arrival_Time)
	L3PROP_SHORT(Arrival_Temp)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(End_Time)
	L3PROP_LONG(Process_Time)
	L3PROP_LONG(Heat_Time)
	L3PROP_SHORT(Heat_Count)
	L3PROP_STRING(Probe_Vonder)
	L3PROP_SHORT(FeedWire_Temp)
	L3PROP_SHORT(Departure_Temp)
	L3PROP_DATETIME(SoftBlow_StartTime)
	L3PROP_DATETIME(SoftBlow_EndTime)
	L3PROP_LONG(SoftBlow_Time)
	L3PROP_SHORT(Lid_Life)
	L3PROP_LONG(HoldBack_Time)
	L3PROP_FLOAT(Steel_Weight)
	L3PROP_STRING(LadleNo)
	L3PROP_DOUBLE(CCM_Ladle_Weight)
	L3PROP_LONG(PoleConsume)
    L3PROP_STRING(Pole_Vendor)
	L3PROP_DOUBLE(Flow_BlowAr_Heat)
	L3PROP_DOUBLE(Flow_BlowAr_SoftBlow)
	L3PROP_STRING(Ladle_Grade)//2009-03-30
END_L3PROPTABLE(CLF_Process_Data)

BEGIN_L3METHODMAP(CLF_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Process_Data)

CLF_Process_Data::CLF_Process_Data(void)
{
}

CLF_Process_Data::~CLF_Process_Data(void)
{
}
