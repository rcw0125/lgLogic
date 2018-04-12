// 逻辑类CLadle_Use源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Use.h"

IMPLEMENT_L3CLASS(CLadle_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Use,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(LadleID)
	L3PROP_DATETIME(Use_Date)
	L3PROP_LONG(Ladle_Age)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Steel_Grade)
	L3PROP_DATETIME(Seat_OK_Time)
	L3PROP_DATETIME(Tap_Time)
	L3PROP_DATETIME(Irr_Start_Time)
	L3PROP_DATETIME(Irr_End_Time)
	L3PROP_DATETIME(Off_Ladle_Time)
	L3PROP_DATETIME(Arrive_Time)
	L3PROP_DATETIME(Complete_Time)
	L3PROP_DOUBLE(Fire_Time_Len)
	L3PROP_DOUBLE(Stop_Time_Len)
	L3PROP_STRING(Ladle_Check)
	L3PROP_STRING(Off_Reason)
	L3PROP_STRING(Sk_Board_Keep)
	L3PROP_STRING(Ladle_Grade)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_DATETIME(Hot_Time)
	L3PROP_LONG(Frame)
	L3PROP_LONG(Splint)
	L3PROP_LONG(SpringBox)
	L3PROP_LONG(Joint)
	L3PROP_LONG(Joint_Safety_Pin)
	L3PROP_LONG(Long_Axes)
	L3PROP_LONG(Short_Axes)
	L3PROP_LONG(Chassis)
	L3PROP_LONG(Protect_Board)
	L3PROP_LONG(Up_Tighten_Machine)
	L3PROP_LONG(Breathe_Bri_Up)
	L3PROP_LONG(Breathe_Bri_Low)
	L3PROP_LONG(Water_Gap)
	L3PROP_STRING(WorkID)
	L3PROP_LONG(NewLadleFirst)
	L3PROP_LONG(NewLadleSecond)
	L3PROP_LONG(FireLadleFirst)
	L3PROP_LONG(FireLadleSecond)
	L3PROP_LONG(ReturnLadle)
	L3PROP_LONG(HookEdgeLadle)
	L3PROP_LONG(RemnantLadle)
	L3PROP_DOUBLE(RemnantWT)
	L3PROP_LONG(ComFlag)
	L3PROP_LONG(Confirm_Flag)
	L3PROP_STRING(Act_Ladle_Grade)
	L3PROP_STRING(Ladle_Check1)
END_L3PROPTABLE(CLadle_Use)

BEGIN_L3METHODMAP(CLadle_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Use,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Use)

CLadle_Use::CLadle_Use(void)
{
}

CLadle_Use::~CLadle_Use(void)
{
}
