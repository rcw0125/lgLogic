// 逻辑类CVacTube_Fire_Info源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Fire_Info.h"

IMPLEMENT_L3CLASS(CVacTube_Fire_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Fire_Info,CL3Object)

	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(VacTube_Code)
	L3PROP_STRING(Install_ID)
	L3PROP_LONG(Time_ID)
	L3PROP_STRING(Position)
	L3PROP_DOUBLE(Fact_Temp)
	L3PROP_DOUBLE(Gun_Height)
	L3PROP_DOUBLE(Gas_Flow)
	L3PROP_DOUBLE(O2_Flow)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Log_Per)
	L3PROP_STRING(Note)
	L3PROP_STRING(Object_ID)
	L3PROP_LONG(Fire_Soruce)
END_L3PROPTABLE(CVacTube_Fire_Info)

BEGIN_L3METHODMAP(CVacTube_Fire_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Fire_Info,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Fire_Info)

CVacTube_Fire_Info::CVacTube_Fire_Info(void)
{
}

CVacTube_Fire_Info::~CVacTube_Fire_Info(void)
{
}
