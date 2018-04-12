// 逻辑类CLadle_In_Build_Info源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_In_Build_Info.h"

IMPLEMENT_L3CLASS(CLadle_In_Build_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_In_Build_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_SHORT(Number)
	L3PROP_STRING(Ladle_ID)
	L3PROP_DATETIME(Build_Start_Time)
	L3PROP_DATETIME(Build_End_Time)
	L3PROP_STRING(Ato_Lig_Cast_Fac)
	L3PROP_DOUBLE(Ato_Lig_Cast_Wast)
	L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)
	L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)
	L3PROP_STRING(Spinel_Cast_Fac)
	L3PROP_DOUBLE(Spinel_Cast_Wast)
	L3PROP_STRING(Al_Mg_Brick_Fac)
	L3PROP_DOUBLE(Al_Mg_Brick_Wast)
	L3PROP_STRING(Mg_Firecaly_Fact)
	L3PROP_DOUBLE(Mg_Firecaly_Wast)
	L3PROP_SHORT(Ladle_Inner_Use_Count)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_In_Build_Info)

BEGIN_L3METHODMAP(CLadle_In_Build_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_In_Build_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_In_Build_Info)

CLadle_In_Build_Info::CLadle_In_Build_Info(void)
{
}

CLadle_In_Build_Info::~CLadle_In_Build_Info(void)
{
}
