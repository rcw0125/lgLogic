// 逻辑类CMold_Board_Par_Use源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMold_Board_Par_Use.h"

IMPLEMENT_L3CLASS(CMold_Board_Par_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Board_Par_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(MoldID)
	L3PROP_STRING(Copper_Fac)
	L3PROP_STRING(Inner_ID)
	L3PROP_STRING(Outer_ID)
	L3PROP_STRING(South_ID)
	L3PROP_STRING(North_ID)
	L3PROP_DOUBLE(Lug_Steel_Mea)
	L3PROP_LONG(Cur_Use_Count)
	L3PROP_LONG(Total_Use_Count)
	L3PROP_DOUBLE(Cur_Pull_Mea)
	L3PROP_DOUBLE(Total_Pull_Mea)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(FlowID)
	L3PROP_LONG(OnLine_Flag)
	L3PROP_DATETIME(OnLine_Time)
	L3PROP_STRING(Stop_Reason)
	L3PROP_LONG(OffLine_Flag)
	L3PROP_DATETIME(OffLine_Time)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_STRING(InStallID)
	L3PROP_LONG(ConfirmFlag)
END_L3PROPTABLE(CMold_Board_Par_Use)

BEGIN_L3METHODMAP(CMold_Board_Par_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Board_Par_Use,CL3Object)
END_L3EVENTSINK_MAP(CMold_Board_Par_Use)

CMold_Board_Par_Use::CMold_Board_Par_Use(void)
{
}

CMold_Board_Par_Use::~CMold_Board_Par_Use(void)
{
}
