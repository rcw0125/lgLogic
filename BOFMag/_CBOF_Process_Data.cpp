// 逻辑类CBOF_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_Process_Data.h"

IMPLEMENT_L3CLASS(CBOF_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Process_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_DATETIME(Charging_Start_Time)
	L3PROP_DATETIME(Blow_Start_Time)
	L3PROP_DATETIME(Tapping_Strat_Time)
	L3PROP_DATETIME(Tapping_End_Time)
	L3PROP_LONG(BlowO2_Time)
	L3PROP_LONG(ReBlow_Time)
	L3PROP_LONG(Tapping_Time)
	L3PROP_LONG(Splashing_Time)
	L3PROP_LONG(Smelt_Period)
	L3PROP_LONG(Waiting_Time)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(Lance_Age)
	L3PROP_LONG(Furnace_Age)
	L3PROP_SHORT(ReBlow_Count)
	L3PROP_LONG(LaC_Temp)
	L3PROP_LONG(Tapping_Temp)
	L3PROP_SHORT(Single_LaC)
	L3PROP_FLOAT(Tapping_Oxygen)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(Ladle_Status)
	L3PROP_LONG(Taphole_Life)
	L3PROP_FLOAT(Tapping_Weight)
	L3PROP_STRING(Furnace_Line_Status)
	L3PROP_STRING(Ladle_Grade)//2008-12-26 tangyi
	L3PROP_DOUBLE(Ladle_Stop)//2007-12-27 
	L3PROP_STRING(ScrapStatus)
    L3PROP_FLOAT(Carpolite)//2010-01-07 sun
    L3PROP_FLOAT(O2Total)//2016--7-23 yuan 
	L3PROP_STRING(RemainSlag)//2016-7-24 yuan
END_L3PROPTABLE(CBOF_Process_Data)

BEGIN_L3METHODMAP(CBOF_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Process_Data)

CBOF_Process_Data::CBOF_Process_Data(void)
{
}

CBOF_Process_Data::~CBOF_Process_Data(void)
{
}
