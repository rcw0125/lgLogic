// 逻辑类CMold_Board_Install源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMold_Board_Install.h"

IMPLEMENT_L3CLASS(CMold_Board_Install,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Board_Install,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_DATETIME(Install_Date)
	L3PROP_DATETIME(Repair_Start_Time)
	L3PROP_DATETIME(Repair_End_Time)
	L3PROP_STRING(MoldID)
	L3PROP_LONG(Hit_Press_Flag)
	L3PROP_STRING(Copper_Fac)
	L3PROP_STRING(Repair_Fac)
	L3PROP_LONG(Rep_Count)
	L3PROP_STRING(Inner_ID)
	L3PROP_STRING(Outer_ID)
	L3PROP_STRING(South_ID)
	L3PROP_STRING(North_ID)
	L3PROP_DOUBLE(Lug_Steel_Mea)
	L3PROP_DOUBLE(Wide_Up_Two_Fir)
	L3PROP_DOUBLE(Wide_Up_Two_Sec)
	L3PROP_DOUBLE(Wide_Up_Two_Thi)
	L3PROP_DOUBLE(Wide_Up_Three_Fir)
	L3PROP_DOUBLE(Wide_Up_Three_Sec)
	L3PROP_DOUBLE(Wide_Up_Three_Thi)
	L3PROP_DOUBLE(Wide_Down_Eight_Fir)
	L3PROP_DOUBLE(Wide_Down_Eight_Sec)
	L3PROP_DOUBLE(Wide_Down_Eight_Thi)
	L3PROP_DOUBLE(Nar_Up_Two_Fir)
	L3PROP_DOUBLE(Nar_Up_Two_Sec)
	L3PROP_DOUBLE(Nar_Up_Two_Thi)
	L3PROP_DOUBLE(Nar_Up_Three_Fir)
	L3PROP_DOUBLE(Nar_Up_Three_Sec)
	L3PROP_DOUBLE(Nar_Up_Three_Thi)
	L3PROP_DOUBLE(Nar_Down_Eight_Fir)
	L3PROP_DOUBLE(Nar_Down_Eight_Sec)
	L3PROP_DOUBLE(Nar_Down_Eight_Thi)
	L3PROP_STRING(Install_Per)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_STRING(InStallID)
	L3PROP_LONG(ConfirmFlag)

END_L3PROPTABLE(CMold_Board_Install)

BEGIN_L3METHODMAP(CMold_Board_Install,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Board_Install,CL3Object)
END_L3EVENTSINK_MAP(CMold_Board_Install)

CMold_Board_Install::CMold_Board_Install(void)
{
}

CMold_Board_Install::~CMold_Board_Install(void)
{
}
