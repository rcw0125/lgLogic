// 逻辑类CLance_Defend源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLance_Defend.h"

IMPLEMENT_L3CLASS(CLance_Defend,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Defend,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LanceID)
	L3PROP_DATETIME(Check_Date)
	L3PROP_STRING(MakeID)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_DOUBLE(Test_Water_Pressure)
	L3PROP_DOUBLE(Nasal_Erosion)
	L3PROP_LONG(Exit_Shape)
	L3PROP_LONG(Sundry)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Defend)

BEGIN_L3METHODMAP(CLance_Defend,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Defend,CL3Object)
END_L3EVENTSINK_MAP(CLance_Defend)

CLance_Defend::CLance_Defend(void)
{
}

CLance_Defend::~CLance_Defend(void)
{
}
